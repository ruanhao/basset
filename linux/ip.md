```bash



ip [-s] link show eth0

ip      link set  eth0 [up|down]
ip      link set  eth0 mtu     1000
ip      link set  eth0 name    <if-name> # 设置接口名
ip      link set  eth0 address aa:aa:aa:aa:aa:aa




ip address show [eth0]
# 设定广播地址，如果设定值是 + 表示'让系统自动计算'
ip address add 192.168.50.50/24 broadcast + dev eth0 label eth0:<alias>
ip address del 192.168.50.50/24 dev eth0


ip route show
ip route add 192.168.5.0/24 dev eth0 # 针对本机直接沟通的网域设定好路由，不需要透过外部的路由器
ip route add 192.168.10.0/24 via 192.168.5.100 dev eth0 # 需设定路由器地址



```
