## Curl

```bash
curl -L <site>       ## 有的网址是自动跳转的, 使用-L参数, curl就会跳转到新的网址

curl -I <site>       ## 显示http response头信息
curl -v <site>       ## 显示一次http通信整个过程
curl --trace output.txt <site>
curl --trace-ascii output.txt <site>
curl -x <proxy>
curl -D cookie.txt <site>   ## 保存cookie
curl -b cookie.txt <site>   ## 使用cookie

curl -r <range> <site>      ## 分部分下载
curl -r 0-10240     -o "mp3.part0" http://music.org/music.mp3 &
curl -r 10241-20480 -o "mp3.part1" http://music.org/music.mp3 &
curl -r 20481-40960 -o "mp3.part2" http://music.org/music.mp3 &
curl -r 40961-      -o "mp3.part3" http://music.org/music.mp3 &
cat mp3.part* > music.mp3

curl ifconfig.me            ## 机器在内网，查看外网的ip

curl -o #2_#1.jpg http://site/{a,b}/[1-6].jpg
curl -o #2-#1.jpg http://cgi2.tky.3web.ne.jp/~{zzh,nick}/[001-201].JPG
curl -O http://cgi2.tky.3web.ne.jp/~zzh/screen[1-10].JPG


cat <<EOF | curl --header "Content-Type:application/xml" -d@- localhost:8080/pnp/WORK-RESPONSE 2>/dev/null | python -c 'import sys;import xml.dom.minidom;s=sys.stdin.read();print xml.dom.minidom.parseString(s).toprettyxml()'
<pnp xmlns="urn:cisco:pnp" version="1.0" udi="PID:WS-C3750X-24T-E,VID:V04,SN:FDO1703P2EB">
    <response correlator="CiscoPnP-1.0-1465-25A1212C" xmlns="urn:cisco:pnp:cli-exec" version="1.0" success="1"/>
</pnp>
EOF


curl -X POST   www.example.com
curl -X DELETE www.example.com


curl -k --cert ./client.pem --key ./client.key.pem https://hao.cisco.com:8866

export CURL_CA_BUNDLE=/usr/local/etc/openssl/certs/cacert.pem ## Install root CA certs from http://curl.haxx.se/ca/cacert.pem into /usr/local/etc/openssl/certs/cacert.pem

```
