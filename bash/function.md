## function

> * return 只能用在函数或被 source 的脚本中
> * 函数如果在一行内定义，记得加分号：hello() { true; }

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
