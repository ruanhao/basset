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

## 变量赋值
```bash
var=$( <FileName ) ## 将FileName中的内容赋给变量var
                   ## 变量替换也允许将一个loop的输出设置到一个变量中，
                   ## 这么做的关键是将循环中echo命令的输出全部截取
                   
eval var1=\$$var2  ## 间接引用，同：var1=${!var2}
```

## Misc
```bash
: ${variable?error_msg} ## 一种检查变量是否设置的方法，
                        ## 若没有设置，则error_msg会输出到std_err中
                        
num=$#; ${!num}         ## 最后一个参数  
                        ## 不能直接写作${!$#}，这是一种**间接引用**  
                        ## ruanhao: ${$num}是不允许的，因为变量替换不能嵌套，
                        ## 但是类似${var:$len}是可行的
                        
## **赋值时变量不扩展**
var1="hello world"
var2=$var1    ## var2: "hello world"
echo $var1    ## equals 'echo hello world'
## **数组赋值例外**
b=( 1 2 3 )
a=( ${b[*]} ) ## a has 3 elements, not "1 2 3"

${!varprefix*} ## 匹配所有之前声明过的，并且以varprefix开头的变量
${!varprefix@} ## 同上
xyz23=whatever
xyz24=
a=${!xyz*}                     ## 展开所有以"xyz"开头的，并且之前声明过的变量名
echo "a = $a"                  ## a = xyz23 xyz24
a=${!xyz@}                     ## 同上
```

## 字符串
```bash
${#var}            ## 字符串var的长度
expr "$var" : '.*' ## 同上
expr length $var   ## 同上

## 匹配字符串**开头**的子串长度:
expr match "$string" '$regex'
expr "$string" : '$regex'
stringZ=abcABC123ABCabc
#       =======
echo `expr match "$stringZ" 'abc[A-Z]*.2'`
echo `expr "$stringZ" : 'abc[A-Z]*.2'`

## 在字符串$string中所匹配到的$regex第一次出现的位置
expr index $string $regex
stringZ=abcABC123ABCabc
echo `expr index "$stringZ" C12` # 6
echo `expr index "$stringZ" 1c`  # 3, 'c' (in #3 position) matches before '1'

## 提取子串
${string:position}
${string:position:length}  ## 在$string中从位置$position开始提取子串
                           ## 如果$string是*或者@，那么将会从位置$position开始的位置参数

## 从字符串右边开始提取子串
echo ${stringZ:-4}   ## 提取了整个字符串:(
echo ${stringZ:(-4)} ## right :)
echo ${stringZ: -4}  ## right :)

## 从$string的**开始位置**提取$substring，$substring是正则表达式
expr "$string" : '\($substring\)'
stringZ=abcABC123ABCabc
#       =======
echo `expr match "$stringZ" '\(.[b-c]*[A-Z]..[0-9]\)'` # abcABC1
echo `expr "$stringZ" : '\(.[b-c]*[A-Z]..[0-9]\)'`
echo `expr "$stringZ" : '\(.......\)'`

## 从$string的**结尾**提取$substring，$substring是正则表达式  
expr "$string" : '.*\($substring\)'
stringZ=abcABC123ABCabc
#                ======
echo `expr match "$stringZ" '.*\([A-C][A-C][A-C][a-c]*\)'`
echo `expr "$stringZ" : '.*\(......\)'`

## 子串消除  
${string#substring}  ## 从$string的**开头位置**截掉最短匹配的$substring
${string##substring} ## 从$string的**开头位置**截掉最长匹配的$substring
${string%substring}  ## 从$string的**结尾位置**截掉最短匹配的$substring
${string%%substring} ## 从$string的**结尾位置**截掉最长匹配的$substring

## 子串替换
${string/substring/replacement}  ## 使用$replacement来替换**第一个匹配**的$substring
${string//substring/replacement} ## 使用$replacement来替换**所有匹配**的$substring
${string/#substring/replacement} ## 如果$substring匹配$string的**开头部分**，那么就用$replacement替换$substring
${string/%substring/replacement} ## 如果$substring匹配$string的**结尾部分**，那么就用$replacement替换$substring
```

## 数组变量
```bash
echo ${array[*]}                  ## 打印所有数组
${#array[*]} **and** ${#array[@]} ## 数组中元素的个数
${#array}                         ## 数组中**第一个元素**的长度
```

## 特殊变量
```bash
$DIRSTACK ## 内建数组，记录目录栈
$#        ## 参数数量
$$        ## shell进程ID
$-        ## 当前shell的选项标识
$_        ## 上一条命令的参数
$!        ## 上一个在后台运行的作业的pid
$@        ## "$@" 等价于 "$1" "$2" "$3",
          ## 按照空格来分隔，就算IFS用别的字符，"$@"还是按照空格来判断参数的个数,
          ## $@ 也可以用来获取传递给脚本的输入，cat $@ 可以接受从 stdin 传递给脚本的输入，也可以接受从参数中指定的文件中传递给脚本的输入,
          ## *$@ 与 $* 中的参数只有在被双引号引用起来的时候才会不同
${#*}     ## 位置参数的个数
${#@}     ## 同上
```
