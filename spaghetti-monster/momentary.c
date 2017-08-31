/*
 * Momentary: Very simple example UI for SpaghettiMonster.
 * Is intended to be the simplest possible FSM e-switch UI.
 * The light is on while the button is held; off otherwise.
 *
 * Copyright (C) 2017 Selene ToyKeeper
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define FSM_EMISAR_D4_DRIVER
#define USE_LVP
#define USE_DEBUG_BLINK
#define USE_DELAY_4MS
#include "spaghetti-monster.h"

volatile uint8_t brightness;
volatile uint8_t on_now;

void light_on() {
    on_now = 1;
    PWM1_LVL = brightness;
    PWM2_LVL = 0;
}

void light_off() {
    on_now = 0;
    PWM1_LVL = 0;
    PWM2_LVL = 0;
}

uint8_t momentary_state(EventPtr event, uint16_t arg) {

    if (event == EV_click1_press) {
        brightness = 255;
        light_on();
        empty_event_sequence();  // don't attempt to parse multiple clicks
        return 0;
    }

    else if (event == EV_release) {
        light_off();
        empty_event_sequence();  // don't attempt to parse multiple clicks
        standby_mode();  // sleep while light is off
        return 0;
    }

    return 1;  // event not handled
}

// LVP / low-voltage protection
void low_voltage() {
    if (brightness > 0) {
        debug_blink(3);
        brightness >>= 1;
        if (on_now) light_on();
    } else {
        debug_blink(8);
        light_off();
        standby_mode();
    }
}

void setup() {
    debug_blink(2);
    push_state(momentary_state, 0);
}

void loop() { }

