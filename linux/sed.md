## Sed

> sed默认的匹配方式是基本**正则表达式**
> 用基本正则表达式匹配时.* ^ $ [ ] \这些字符默认为表示元字符含义，若要表示原来字面上的意思就必须转义，其它字符如，( ) + ? | { } < >在基本正则表达式中表示字面上的意思不需要转义  
> **但表示元字符的意思时需要转义, 其中\<表示词首， 如\<abc表示以abc为首的词，\>表示词尾**

------

> 而在sed使用**扩展正则表达式**时除了. * ^ $ [ ] \是表示元字符含义，其他字符如，( ) + ? | { }也是表示元字符含义，若要表示字符字面上的意思也必须转义，sed通过 -r 选项使用扩展正则表达式

------

> sed的工作模式是，比对每一数据行，若符合样式，就执行指定的操作

```bash
sed '1,4d' file                            ## 删除1-4行
sed '/hello/d' file                        ## 把含有hello的行删除，//代表搜索
sed '/hello/!d' file
sed -n '/hello/p' file                     ## sed默认也会显示不符合的数据行，所以用-n加以规避
sed '/[0-9]\{3\}/d' file
sed -n 's/hello/world/gp' file             ## s表示替换，g表示global，若不加g则表示只替换一处
sed -n 's/hello/world/2' file              ## 只替换每一行第2个hello
sed -n 's/hello/world/3g' file             ## 只替换每一行第3个及以后的hello
sed '1,3s/hello/world/g; 3,$s/shanghai/china/g' file    ## 多个模式。
sed 's/hello/[&]/g' file -> 将hello替换成[hello]，&来当做被匹配的变量
sed -n '/hello/s/world/world_sub/p' file   ## 找到含有hello的那一行之后，将world换成hello_sub
sed -n '/hello/,/world/s/AAA/BBB/p' file   ## 将含有hello到含有world的那几行，将其中的AAA换成BBB
sed -n '2,6s/AAA/BBB/p' file
sed 's/hello/world' file 和 sed 's/hello/world/' <file  ## 效果不同，后者直接改了file

sed 'N; s/\n/,/; s/hello/world/2' file     ## N命令表示将下一行的内容纳入pattern space来做匹配，
                                           ## 相当于把偶数行纳入奇数行做匹配，可用于两行合并成一行的场景，
					   ## 同时在这个例子中发现所谓第几次替换是针对‘第几次匹配到’而言的，
					   ## 所以要替换一处hello的话，次数需写2，体会下

sed '[line_range]a blablah' file           ## 某行后插入一行(i: 行前插入, d: 删除行, c: 替换行，p: 打印行)
sed '/hello/a blablah' file
sed '3,6 {/hello/d} file                   ## 如果没有‘3,6'，则等效于sed '{/hello/d}' file，
                                           ## 继而等效于sed '/hello/d' file，{}是嵌套命令
					   
sed '3,6 {/hello/{/world/d}}' file         ## 3到6行，匹配hello成功后，再匹配world，如果成功，则执行d命令
                                           ## cmd可以有多个，它们可以用分号分开（参见上面的示例），
					   ## 也可以用大括号括起来作为嵌套命令
					   
sed '1,$ {/hello/d; s/^[[:space:]]*//g}' file
sed G file                                 ## 每行后添加一空行
sed '/^[[:space:]]*$/d; G' file            ## 每行空一格，删除多余空行，d会跳过G直接进入next cycle，见man，可以使用b
sed 'n;d' file                             ## 删除偶数行，n的作用：打印当前pattern_space，然后读入下一行，
                                           ## 可理解为只对偶数行进行操作
sed 'n;=' file                             ## 给偶数行打行号
sed '2,$n;='                               ## 给奇数行打行号






Flag 'I' makes the pattern match case insensitive. This will match abc, aBc, ABC, AbC, etc.:

sed -n '/abc/I p' <old >new

Note that a space after the '/I' and the 'p' (print) command emphasizes that the 'p' is not a modifier of the pattern matching process, but a command to execute after the pattern matching. 




















## Hold Space
g:  将hold space中的内容拷贝到pattern space中，原来pattern space里的内容清除
G:  将hold space中的内容append到pattern space\n后
h:  将pattern space中的内容拷贝到hold space中，原来的hold space里的内容被清除
H:  将pattern space中的内容append到hold space\n后
x:  交换pattern space和hold space的内容
```


```c
// sed处理文本的伪代码
foreach line in file {
    //放入把行Pattern_Space
    Pattern_Space <= line;
    // 对每个pattern space执行sed命令
    Pattern_Space <= EXEC(sed_cmd, Pattern_Space);
    // 如果没有指定 -n 则输出处理后的Pattern_Space
    if (sed option hasn't "-n") {
       print Pattern_Space
    }
}
```
