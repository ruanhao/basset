## Web

```bash
##  通过 Bash 访问 Web 站点

$ exec 3<>/dev/tcp/www.google.com/80
$ echo -e "GET / HTTP/1.1\n\n" >&3
$ cat <&3

## Bash 将/dev/tcp/host/port当作一种特殊的文件，它并不需要实际存在于系统中，这种类型的特殊文件是给 Bash 建立 tcp 连接用的。
## 
## 在这个例子中，我们首先以读写的方式打开文件描述符 3，并把它指向/dev/tcp/www.google.com/80，后者是一个连接，表示连接到 www.google.com 的 80端口。
## 
## 接下来，我们往文件描述符 3 写GET / HTTP/1.1\n\n。完成之后，我们使用cat命令从同样的地方读取返回内容。
## 
## 类似的，你也可以通过/dev/udp/host/port 来创建一个 UDP 连接。
## 
## 使用/dev/tcp/host/port，你甚至可以使用 Bash 写一个端口扫描程序。

```
