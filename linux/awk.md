## awk


## 使用awk产生伪随机数
```bash
# 产生一个范围在 0 - 1 之间的伪随机数
# 缺点：同一秒内生成的随机数相同
echo | awk '{ srand(); print rand() }'
```

> awk的工作方式是读取数据文件，将每一行数据视为一条记录(record)，每笔记录以字段分隔符分成若干字段，然后输出各个字段的值  
> awk对每一条记录，都会套用一个“样式{操作}”。如果该行符合样式，就执行指定的操作。样式或操作之一，可以省略。**如果只有样式，表示要显示符合样式的数据行；如果只有操作，表示对每一数据行都执行该项操作**
> awk常用的作用格式:  
> 1. awk “样式” 文件：把符合样式的数据行显示出来  
> 2. awk '{操作}' 文件：对每一行都执行{}中的操作  
> 3. awk '样式{操作}' 文件：对符合样式的数据行，执行{}中的操作


```bash
awk '/hello/{ print $1 }' file  ## 将含有hello关键词的数据行的第1及第2个字段显示出来

awk '{ print $1, $2, $3 }' file
awk '{ print $1$2, $3 }' file

awk '$3 ~ /hello/ {print NR }' file
awk '$3!~/hello/ { print NR }' file

awk '!/hello/' file             ## 相当于grep -v 'hello' file

awk 'NR!=1{if($6 ~ /TIME|ESTABLISHED/) print > "1.txt";
          else if($6 ~ /LISTEN/) print > "2.txt";
          else print > "3.txt" }' netstat.txt
	  
## 统计每个用户的进程占了多少内存，(i in a): i指的是索引	  
ps aux | awk 'NR!=1 {a[$1]+=$6;} END{ for(i in a) print i ", " a[i]"KB";}'

{ print NF, $1, $(NF - 1) }     ## any expression can be after $ to denote a field number

## 字符串连接
cat emp.data  | awk '{ names = names $1 " " } END { print names }'

## Exchange the first two fields of every line and then print the line
{ temp = $1; $1 = $2; $2 = temp; print }  ## 默认打印方式为 print $1,$2,...,$NF

cat file | awk '{ print }'      ## 按原样打印
cat file | awk '{ tmp = $1; $1 = $2; $2 = tmp; print }'  ## 如同print $1,$2,...,$NF

## 当awk读取一个field，会自动设置它的类型为string，
## 如果这个string可以转换成一个机器可读的number时，awk就赋予这个field为numeric type

if (index in Array)             ## test if 'index' exists in Array
delete Array[i]

echo | awk '{ while ("cat filename" | getline x > 0) { print; }}' ## "cat filename"只运行一次，while只针对getline

```

Expression        | Parameters to set
----------------- | -----------------
getline           | $0, NF, NR, FNR
getline var       | var, NR, FNR
getline <file     | $0, NF
getline var <file | var
cmd|getline       | $0, NF
cmd|getline var   | var


### Awk 内建变量
Parameter | Value
--------- | --------
$0        | 整个行的内容
$1 - $n   | 当前记录的第n个字段，字段间由FS分隔
FS        | 输入字段分隔符，默认是空格或Tab
NF        | 当前记录中的字段个数
NR        | 已读出的记录数，即行号，从1开始，若有多个文件，则不间断累加
FNR       | 当前记录数，与NR不同的是，这个值会是各个文件自己的行号
RS        | 输入记录分隔符，默认为换行符
OFS       | 输出字段分隔符，默认是空格
ORS       | 输出记录分隔符，默认为换行符 
FILENAME  | 当前输入文件的名字
