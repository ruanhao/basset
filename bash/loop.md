## loop

### for
```bash
# 基本用法
for arg; do
    ## to do
done [ | command ] ## arg 默认为轮询所有位置参数，
                   ## 循环的输出可以通过管道传递到一个或多个命令中

# 两种循环到10得方法
echo 
for a in {1..10}; do
    echo -n "$a "
done

## 以下使用C语言风格
LIMIT=10
for ((a = 1; a <= LIMIT; a++)); do
    echo -n "$a "
done

## 使用C语言的‘逗号操作符’
for ((a = 1, b = 1; a <= LIMIT; a++, b++)); do
    echo -n "$a-$b "
done
exit 0
```

### while
```bash
# 基本用法
while read line; do
    # to do
done

LIMIT=10
a=1
while [ "$a" -le $LIMIT]; do
    echo -n "$a "
    let "a+=1"
done

# 使用C语法
(( a = 1 ))
while (( a <= LIMIT )); do
    echo -n "$a "
    (( a += 1 ))
done
exit 0

# 在循环内部设置$IFS变量
# 而不用把原始的$IFS保存到临时变量中
echo "List of all users:"
while IFS=: read name passwd uid gid fullname ignore; do
    echo "$name ($fullname)"
done </etc/passwd
echo "\$IFS still $IFS"
exit 0
```

### continue & break
> * break命令可以带一个参数，一个不带参数的break命令只能退出最内层的循环，而break N可以退出N层循环
> * continue命令也可以像break命令一样带一个参数，不带参数的continue命令只会去掉本次循环的剩余代码，而continue N将会把N层循环的剩余代码都去掉

### case & select
```bash
case $var in
    $pattern)
        # to do;;
esac

select $var [in list]; do
    # to do
    break
done
```
