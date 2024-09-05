# How to build Anduril 2 PDF/HTML manuals from Markdown

## Summary

<!-- MarkdownTOC -->

- [Requirements](#requirements)
- [Recommended Markdown editor and linter](#recommended-markdown-editor-and-linter)
- [Build](#build)
    - [PDF](#pdf)
    - [HTML](#html)
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
pandoc anduril-manual.md \
-f markdown -t pdf \
--template eisvogel \
--listings \
-V book \
-o anduril-manual.pdf
```

_esvogel requires the following fixes as of writing, very trivial to do it
yourself_  
<https://github.com/Wandmalfarbe/pandoc-latex-template/issues/391#issuecomment-2195937041>

or

```bash
pandoc anduril-manual.md \
-f markdown -t pdf \
--toc \
-V linkcolor:blue \
-o anduril-manual.pdf
```

### HTML

```bash
pandoc anduril-manual.md \
-f markdown -t html \
--toc \
-V linkcolor:blue \
-o anduril-manual.html
```

Or with the MarkdowPreview : Save To HTML plugin from the awesome SublimeText
is beautiful too, a version is provided in anduril-manual-2.html

### DOC

```bash
pandoc anduril-manual.md \
-f markdown -t docx \
-V geometry:margin=1.5cm \
--toc \
-V linkcolor:blue \
-o anduril-manual.docx
```

---

That's all folks.

I use Arch btw :)

--class101
