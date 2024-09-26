# How to build Anduril 2 PDF/HTML manuals from Markdown

## Table of Content

<!-- MarkdownTOC -->

- [Requirements](#requirements)
- [Recommended Markdown editor and linter](#recommended-markdown-editor-and-linter)
- [Build](#build)
    - [PDF](#pdf)
    - [HTML5](#html5)
    - [DOC](#doc)

<!-- /MarkdownTOC -->

## Requirements

- pandoc : <https://pandoc.org/installing.html>
- esvogel : <https://github.com/Wandmalfarbe/pandoc-latex-template>
- Linux :  
    - TexLive with core, fonts, latex
- Windows (untested, I use Arch Linux) :  
    - MiKTeX

## Recommended Markdown editor and linter

Auto-updates the Markdown TOC, fixes errors to produce the best possible
HTML and PDF, and improves various quality of life features.

- Sublime Text
- Sublime Text Plugins :
    - MarkdownTOC
    - MarkdowPreview
    - MarkdowLivePreview
    - SublimeLinter
    - SublimeLinter-contrib-markdownlint
        - markdownlint-cli
    - Pandoc plugin

## Build

### PDF

```bash
export REPO=class101
pandoc README.md \
docs/anduril-manual.md \
docs/per-user-config.md \
docs/which-hex-file.md \
--data-dir=/usr/share/pandoc/data \
--resource-path=docs \
-f markdown -t pdf \
--template eisvogel \
--listings \
-V book \
-o README.pdf 
```

### HTML5

- --css=styling-benjam.css \
- --css=styling-killercup.css \

```bash
export REPO=class101
sed -E -i 's#\(([^\)]+?\.md)\)#(https://github.com/'"$REPO"'/anduril-manual-pdf/tree/trunk/\1)#g' README.md
pandoc README.md \
docs/anduril-manual.md \
docs/per-user-config.md \
docs/which-hex-file.md \
--css=styling-benjam.css \
-s \
-V lang=en \
-V highlighting-css= \
-V linkcolor:blue \
--mathjax \
--resource-path=docs \
-f markdown -t html5 \
--toc \
-o README.html
sed -E -i 's#https://github.com/'"$REPO"'/anduril-manual-pdf/tree/trunk/##g' README.md
```

### DOC

```bash
export REPO=TKlamp
sed -E -i 's#\(([^\)]+?\.md)\)#(https://github.com/'"$REPO"'/anduril-manual-pdf/tree/trunk/\1)#g' README.md
pandoc README.md \
docs/anduril-manual.md \
docs/per-user-config.md \
docs/which-hex-file.md \
--resource-path=docs \
-f markdown -t docx \
-V geometry:margin=1.5cm \
--toc \
-V linkcolor:blue \
-o README.docx
sed -E -i 's#https://github.com/'"$REPO"'/anduril-manual-pdf/tree/trunk/##g' README.md
```

---

That's all folks.

I use Arch btw :)

--class101
