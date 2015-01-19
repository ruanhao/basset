## SSH

```bash
ssh user@server bash < /path/to/local/script.sh                      ## 在远程机器上运行一段脚本（不必把脚本拷贝到远程机器上)
ssh user@host cat /path/to/remotefile | diff /path/to/localfile -    ## 比较一个远程文件个一个本地文件
ssh user@host 'mkdir -p .ssh && cat >> .ssh/authorized_keys' < ~/.ssh/id_rsa.pub 
ssh -n user@host emacs &                                             ## 在本地运行远端的应用程序
ssh -X user@host                                                     ## 用这种方式登录host，就可以在本地执行host上的GUI程序。
```

> 动态端口转发：ssh -D [local_bind_address:]local_port user@host  
> 动态端口转发需要socks协议支持，工作原理可以理解为：将<dest IP>和<data packet>通过socks协议发往host上，然后在host上将<data packet>发向<dest IP>，之后返回的数据再通过隧道返回到localhost的应用程序上。(注：应用程序需要额外配置socks代理，若应用程序不支持代理配置则该功能无法使用)

> 本地端口转发：ssh -L [bind_addr]:port:dest_host:dest_host_port user@agent_server  
> 绑定本地端口port，当有连接请求到port时，则通过agent_server，发送至dest_host:dest_host_port上去

> 远端端口转发：ssh -R remote_port:desthost:dest_port user@agent  
> 当访问agent的remote_port时，数据通过本机，转发到desthost:desthost_port上


* N参数，表示只连接远程主机，不打开远程shell；
* T参数，表示不为这个连接分配TTY。NT参数一起用，代表这个SSH连接至用来传数据，不执行远程操作。如：ssh -NT -D 8080 host
* f参数，表示SSH连接成功后，转入后台运行，通常和N连用。这样一来，可以在不中断SSH连接的情况下，在本地shell中执行其他操作。如：ssh -f -D 8080 host (要关闭这个后台连接，就只有用kill命令去杀掉进程)




ssh -t reachable_host ssh unreachable_host

### Reference
[SSH port forwarding](http://www.liugj.com/2013/04/SSH-port-forwarding)  

[Yifeng Ruan](http://www.ruanyifeng.com/blog/2011/12/ssh_port_forwarding.html)
