## Hacks

```bash
echo ∴ → ☿ ★ | hexdump -C     ## 查看字符的 binary 表示方法
			      
look <Arg>                    ## 查找以参数开头的单词
			      
pstree -pH <pid>	      
			      
> filename                    ## 快速创建一个文件
cat /dev/null > filename      ## 清空一个文件
: > filename                  ## 作用和上条命令一样，但是由于:是内置命令，所以不会产生新的进程
			      
ps aus | sort -nk +4 | tail   ## 列出前十个最耗内存的进程

## 列出10个最大的系统中已打开的文件
lsof / | awk '{ if($7 > 1048576) print $7/1048576 "MB "$9 }' | sort -n -u | tail
			      
man ascii                     ## 列出ASCII码
			      
Ctrl-x-e                      ## 快速启动编辑器($EDITOR)

netstat -tlnp                 ## 列出本机进程监听的端口号
netstat -anop                 ## 显示侦听在这个端口上的进程

lsof -i                       ## 实时查看本机网络服务的活动状态

kill -s <Signal> <Pid>
kill -0 <Pid>                 ## 可用来测试process是否还在运行，如果process终止了，则$?不为0

id -nu                        ## 获取用户名

getent                        ## 显示所有用户

## 显示空余内存
free -m | grep cache | awk '/[0-9]/{ print $4" MB" }'
## get total physical memory size
free -m | grep "Mem" | awk '{print $2}'

stat -c %U <filename>         ## 显示文件所有者

printf '%100s\n' | tr ' ' =   ##  打印水平行

lsblk -f                      ## 列出块设备

time <command>                ## 计算命令运算时间
times

nmap <server-ip>              ## 扫描一个服务器来定位打开的端口，并定位与这些端口相关的服务

/usr/share/doc                ## doc dir
/etc/sysconfig/i18n           ## encoding setup
/usr/share/dict                ## 存放字典

tput longname                 ## 查看xterm信息

ldd                           ## 显示一个可执行文件和它所需要共享库之间的依赖关系

umask 022                     ## 使得新文件的权限最多为755(777与022进行'与非'操作)

cut -d ' ' -f1,2 /etc/mtab    ## 用cut来获得所有mount上的文件系统的列表

## 产生一个随机数
head -c4 /dev/urandom | od -An -tu4

pkill -kill -t <tty>          ## kick user, like 'pkill -kill -t pts/2'

write <user> <tty>            ## send msg to user, like 'write root pts/2'
mesg [y/n]                    ## 允许/禁止其他终端将信息显示在本地终端

## 大文件切分与合并(也可以按行数来划分 -l <line_num>)
split -b 300k <file> <file_name_prefix>
cat <file_name_prefix>* >> <file_name>

tcpdump -i any -s 0 -w <file_to_store>

ethtool -i eth0               ## 查看网卡信息
```

> 在shell的hash表中，记录指定命令的路径名，所以在shell或脚本中调用这个命令的话，就不需要再在$PATH中重新搜索这个命令了。如果不带参数地调用hash命令，它将列出所有已经被hash的命令。-r 选项会重新设置hash表  

> disown 的作用是使一个后台进程不属于当前 shell 的管辖，可能使这个后台进程变成 orphan process  
> 可以使用 wait 命令来防止在后台作业没完成之前退出脚本，wait可以接受一个作业标示符作为参数，比如 wait %1 或者 wait $PPID
