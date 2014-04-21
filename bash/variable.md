## variable substitute

way              | str `not set`         | str `empty string`      | str `set & not empty string`
---------------- | --------------------- | ----------------------- | ----------------------------
var=${str-expr}  | var=expr              | var=""                  | var=$str
var=${str:-expr} | var=expr              | var=expr                | var=$str
var=${str+expr}  | var=""                | var=expr                | var=expr
var=${str:+expr} | var=""                | var=""                  | var=expr
var=${str=expr}  | str=expr; var=expr    | str `unchanged`; var="" | str `unchanged`; var=$str
var=${str:=expr} | str=expr; var=expr    | str=expr; var=expr      | str `unchanged`; var=$str
var=${str?expr}  | output expr to stderr | var=""                  | var=$str
var=${str:?expr} | output expr to stderr | output expr to stderr   | var=$str

