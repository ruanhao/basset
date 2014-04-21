## test

### 基于文件类型

Flags | Comment
----- | ------------------------------
-e    | 文件是否存在
-f    | 文件是否存在且为文件（file）
-d    | 文件是否存在且为目录（directory）
-b    | 文件是否存在且为 block device 
-c    | 文件是否存在且为 character device
-S    | 文件是否存在且为 Socket
-p    | 文件是否存在且为 FIFO (pipe)
-L    | 文件是否存在且为 link

### 基于文件权限

Flags | Comment
----- | ------------------------------
-r    | 文件是否存在且具有`可读`权限
-w    | 文件是否存在且具有`可写`权限
-x    | 文件是否存在且具有`可运行`权限
-u    | 文件是否存在且具有`SUID`权限 
-g    | 文件是否存在且具有`SGID`权限
-k    | 文件是否存在且具有`Sticky bit`权限
-s    | 文件是否存在且为`非空白文件`

### 文件之间比较

Flags  | Comment
------ | ------------------------------------------------------
-nt    | 判断file1是否比file2新
-ot    | 判断file1是否比file2旧
-ef    | 判断file1与file2是否为同一文件（两个文件是否均指向同一个inode）

### 整数之间判定

Flags  | Comment
------ | ------------------
-eq    | equal
-ne    | not equal
-gt    | great than
-lt    | less than
-ge    | great than or equal
-le    | less than or equal

### 字符串之间判定

Flags             | Comment
----------------- | --------------------------------------
test -s string    | 若string为空字符串，则为true
test -n string    | 若string为空字符串，则为false，（-n 可省略）
test str1 = str2  | 若str1等于str2，则为true
test str1 != str2 | 若str1等于str2，则为false

### 多重条件判定

Flags  | Comment
------ | ----------------------------
-a     | eg: test -r file -a -x file
-o     | eg: test -r file -o -x file
!      | eg: test ! -x file
