## Curl

```bash
curl -L <site>       ## 支持跳转
curl -I <site>       ## 显示http response头信息
curl -v <site>       ## 显示一次http通信整个过程
curl --trace output.txt <site>
curl --trace-ascii output.txt <site>
curl -x <proxy>
curl -D cookie.txt <site>   ## 保存cookie
curl -b cookie.txt <site>   ## 使用cookie
curl -C <site>              ## 续传
curl -r <range> <site>      ## 分部分下载
curl ifconfig.me            ## 机器在内网，查看外网的ip
curl -o #2_#1.jpg http://site/{a,b}/[1-6].jpg
```
