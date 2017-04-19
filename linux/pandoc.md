# 常见用法

## 转成 pdf

``` sh
    pandoc -N -s --toc --smart --latex-engine=xelatex -V CJKmainfont='PingFang SC' -V mainfont='Monaco' -V geometry:margin=1in my.md  -o output.pdf
```

``` sh
    pandoc -N -s --toc --smart --latex-engine=xelatex -V documentclass=report -V CJKmainfont='PingFang SC' -V mainfont='Monaco' -V geometry:margin=1in my.md  -o output.pdf
```
