## variable

### variable substitute

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

### 变量赋值
```bash
var=$( <FileName ) ## 将FileName中的内容赋给变量var
                   ## 变量替换也允许将一个loop的输出设置到一个变量中，
                   ## 这么做的关键是将循环中echo命令的输出全部截取
                   
eval var1=\$$var2  ## 间接引用，同：var1=${!var2}
```

### 字符串变量
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

### 数组变量
```bash
${array[Idx]}                     ## 数组元素访问形式
arr=( 1 2 3 4 5 )                 ## 给数组赋值
arr=( [Idx1]=v1 [Idx2]=v2 )       ## 给数组赋值

echo ${array[*]}                  ## 打印所有数组
${#array[*]} **and** ${#array[@]} ## 数组中元素的个数
${#array}                         ## 数组中**第一个元素**的长度

## Bash允许把变量当成数组来操作，即使这个变量没有明确地被声明为数组
string=abcABC123ABCabc
echo ${string[@]}       ## abcABC123ABCabc
echo ${string[*]}       ## abcABC123ABCabc
echo ${string[0]}       ## abcABC123ABCabc
echo ${string[1]}       ## 没有输出
echo ${#string[@]}      ## 1
                        ## 数组中只有一个元素，就是这个字符串本身

## "${array[*]}" 和 "${array[@]}" 的差别类似于 "$*" 和 "$@" 之间的差别
			
## 大部分标准字符串操作都可以用于数组中
array=( zero one two three four fiive )
${array[0]}         ## zero
${array}            ## 同上
${array:1}          ## ero
$(array[0]:1}       ## 同上
${#array[0]}        ## 等同于 ${#array}
${array[@]:0}       ## 所有元素
${array[@]:1}       ## element[0] 后面的所有元素
${array[@]:1:2}
${array[@]#f*r}
${array[@]%%t*e}
${array[@]/#fi/XY}
${array[@]/%ve/ZZ}  ## 这类操作其实都是对每个 element 做轮询，
                    ## 而不是针对整个 array，
                    ## 如 ${array[*]#*ree}，只是删除 three

## 删除数组
unset array[2]      ## 删除数组第3个元素
unset array         ## 删除整个数组

## 扩展数组
new_array=( "${old_array[@]}" new_element )
array[${#array[*]}]=new_element
new_array="${old_array[@]}"  ## 复制数组(但是如果在”缺项“数组中使用的话，将会失败，新数组中的某个元素会没被赋值)
                             ## ruanhao: 这种方式别用，还是用 new=( ${old[*]} )
			     
## 数组声明时添加一个额外的declare -a语句，可以加速后续的数组操作速度，
## 如 declare -a arr=( /dev/* )
```

### 特殊变量
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
$RANDOM   ## 0 - 32767
```

### 环境变量
```bash
## 某些情况下，使用export var=something，与先设置变量，然后export变量的效果不同
export var=(a b); echo ${var[0]}       ## (a b)
var=(a b); export var; echo ${var[0]}  ## a
```
