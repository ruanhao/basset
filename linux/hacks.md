## Hacks

```bash
echo ∴ → ☿ ★ | hexdump -C   ## 查看字符的 binary 表示方法
			      
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
netstat -tuln                 ## 查询目前主机所有开启的网络服务端口，
                              ## IP 部分说明的是该服务位于哪个介面上，
			      ## 若为 127.0.0.1 则是仅针对本机开放，
			      ## 若是 0.0.0.0 或 ::: 则代表对整个 Internet 开放
## 查看连接某服务端口最多的IP地址
netstat -nat | grep "192.168.1.15:22" | awk '{print $5}' | awk -F: '{print $1}' | sort | uniq -c | sort -nr | head -20

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
/usr/share/dict               ## 存放字典
## 内核模块(驱动模块)目录
/lib/modules/$(uname -r)/kernel
/etc/sysctl.conf              ## 定义最大句柄数:
                              ## echo "fs.file-max = <number>" >> /etc/sysctl.conf, 运行sysctl -e -p 使之生效
                              ## 查看当前最大句柄数: 
                              ## cat /proc/sys/fs/file-max

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

yum install yum-downloadonly
yum install <package> --downloadonly --downloaddir=<dir> -y
yum update <package> --downloadonly --downloaddir=<dir> -y
## place to put packages
/var/cache/yum/update/packages

rpm -qi <package>             ## information
rpm -e <package>              ## remove
rpm -qf <cmd>                 ## check which package this cmd belongs to
rpm -qfi <cmd>                ## information about the package this cmd belongs to
rpm -ivh --force <package>    ## force to install even if this package has already been installed
rpm -ivh --no-deps <package>  ## install package regardless of dependency
rpm -qa                       ## query all packages installed
rpm -qp <package>             ## query package that is not install but exsists

w                             ## 显示用户登录名、终端标志、星期几登录和具体登录时间、
                              ## 闲置时间、用户正在执行的程序、占用CPU时间、系统的运行时间和平均负载
who                           ## 显示用户登录名、终端标志、和登录日期和时间
who am i                      ## 显示当前用户正使用的终端和登录时间

#ascii -> alphabet:
printf \\$(printf '%03o' <ascii>)
#alphabet -> ascii:
printf '%d' "'<ascii>"

read -r line < file           ## 读取文件的首行并赋值给变量

echo hello{,,,,,}	      ## 重复n次

var=hello
declare -u var=$var	      ## 大写, 反之: declare -l
echo ${var^^}                 ## 这样也可以, 反之: echo ${var,,}

```

> 在shell的hash表中，记录指定命令的路径名，所以在shell或脚本中调用这个命令的话，就不需要再在$PATH中重新搜索这个命令了  
> 如果不带参数地调用hash命令，它将列出所有已经被hash的命令。-r 选项会重新设置hash表

------

> disown 的作用是使一个后台进程不属于当前 shell 的管辖，可能使这个后台进程变成 orphan process  
> 可以使用 wait 命令来防止在后台作业没完成之前退出脚本，wait可以接受一个作业标示符作为参数，比如 wait %1 或者 wait $PPID



mount | column -t ## currently mounted filesystems in nice layout

while sleep 1;do tput sc;tput cup 0 $(($(tput cols)-29));date;tput rc;done &
## Put a console clock in top right corner

lsof -i ## List programs with open ports and connections
lsof -P -i -n ## show apps that use internet connection at the moment
lsof -i tcp:80 ## which program is this port belongs to
lsof -c <command> ## list all files opened by a particular command

ss -p # show apps that use internet connection at the moment

nc -v -l 80 < file.ext ## sharing file through http 80 port

rm !(*.foo|*.bar|*.baz)


fuser -k filename ## kill a process that is locking a file  


strace -ff -e trace=write -e write=1,2 -p SOME_PID
## intercept stdout/stderr of another process


script -qf | tee >(nc -kl 5000) >(nc -kl 5001) >(nc -kl 5002)
## run 'nc yourip 5000', 'nc yourip 5001' or 'nc yourip 5002' elsewhere
## will produce an exact same mirror of your shell.
## This is handy when you want to show someone else some amazing stuff
## in your shell without giving them control over it.
mkfifo foo; script -f foo


lsmod | perl -e 'print "digraph \"lsmod\" {";<>;while(<>){@_=split/\s+/; print "\"$_[0]\" -> \"$_\"\n" for split/,/,$_[3]}print "}"' | dot -Tpng | display -
##  Draw kernel module dependancy graph. parse `lsmod' output and pass to `dot' drawing utility then finally pass it to an image viewer


find . -type d -empty -delete

cp /work/host/phone/ui/main.cpp !#$:s/host/target
## using `!#$' to referance backward-word

grep ^Dirty /proc/meminfo ## find out how much data is waiting to be written to disk


showkey -a  ## Quick access to ASCII code of a key

bind -x '"\C-l":ls -l' ## bind a key with a command

file -s /dev/sd*
## use file to view device information

nmap -sP 192.168.1.0/24  ## list alive hosts in specific subnet

ps hax -o user | sort | uniq -c   ## process per user counter

strings /dev/mem  ## A fun thing to do with ram is actually open it up and take a peek. This command will show you all the string (plain text) values in ram


------
