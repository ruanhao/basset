## bc

```bash
v1=23.53
v2=17.881
v3=83.501
v4=171.63

var2=$(bc << EOF
scale = 4
a = ( $v1 + $v2 )
b = ( $v3 * $v4 )
a * b + 15.35
EOF)
echo $var2 ## 593487.8452

var3=$(bc -l << EOF
scale = 9
s(1.7)
EOF) ## -l 选项将调用 bc 算数库
echo $var3 ## .991664810
```
