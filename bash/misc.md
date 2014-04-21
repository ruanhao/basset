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

(( t = a < 1 ? 2 : 3 ))        ## C语言风格的三元操作

: $(( n = 3 ))     ## 这里利用了$(())的副作用
(( n = 3 ))        ## 上一条的简便写法
: $[ n = 3 ]       ## 少用这种形式
```
