```bash


## Location of networking configuration files

Interface definitions                   <=> /etc/sysconfig/network-scripts/ifcfg-*
Hostname and default gateway definition <=> /etc/sysconfig/network



ip [-s] link show eth0
ip      link set  eth0 [up|down]
ip      link set  eth0 mtu     1000
ip      link set  eth0 name    <if-name>        # 设置接口名
ip      link set  eth0 address aa:aa:aa:aa:aa:aa


ip neigh # 查看接入所在的局域网的设备的MAC地址



#It is also possible to view netlink messages with ip command.
#The monitor option allows you to see the state of your network devices.
#For instance a computer on your LAN could be categorized as REACHABLE or STALE depending on its status.
#The command can be used as follows:
ip monitor all


ip addr show [eth0]
ip addr add 192.168.50.50/24 broadcast + dev eth0 label eth0:<alias> # 设定广播地址，如果设定值是 + 表示让系统自动计算
ip addr del 192.168.50.50/24 dev eth0


ip route show
ip route add 192.168.5.0/24 dev eth0                    # 设定外出接口
ip route add 192.168.10.0/24 via 192.168.5.100 dev eth0 # 设定路由器地址
ip route get <ip-addr>                                  # 列出路由所使用的接口
ip route add default via <router-addr>                  # 更改默认路由



```
