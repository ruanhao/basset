## function

> * return 只能用在函数或被 source 的脚本中
> * 函数如果在一行内定义，记得加分号：hello() { true; }
> * 代码块 {}，又被称为内部组，实际上是创建了一个匿名函数，与“标准“函数不同的是，在其中申明的变量，对脚本其他部分的代码而言是可见的

```bash
## 可以在 if/then 结构中定义函数
if ["$USER" = root]; then
    greet() {
        echo hello
    }
fi

Function() {
    {
        echo $*
    } | tr a b  ## 这样做是可行的
}
Function() {
    echo $*
} | tr a b      ## 这样做不可行

## 函数指针的用法
declare -f f_point
f_point=function_name
$f_point arg1 arg2
```
