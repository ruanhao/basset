## declare

* declare 和 typeset 命令两者是**完全一样**的
* declare -r `Variable` 等价于 readonly `Variable`
* declare -p `Variable` -> 查看变量声明类型
* declare -i `Variable` -> 如果把一个变量指定为整形的话，即使没有expr或者let命令，也允许使用特定的算术运算
* declare -a `Array` -> 变量Array将被视为数组
* declare -f `[FunctionName]` -> 如果不提供FunctionName，将会列出这个脚本之前定义的所有函数，若提供函数名，则给出这个函数的相关信息
* declare -x var=<value> -> 申明一个变量，并作为这个脚本的环境变量被导出

```bash
## 使用declare命令也可以限制变量的作用域
foo() {
    declare FOO="bar"
}
bar() {
    foo
    echo $FOO
}
bar ## output nothing
```
