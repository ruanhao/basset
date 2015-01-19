GPG
===

```

1, 生成钥匙对
gpg --gen-key

2, 查看本机钥匙信息
gpg --list-keys

3, 导出公钥
gpg -a --output key.public --export <UID>
## -a       表示输出文本文件格式
## --output 指定输出文件的名字
## --export 表示执行输出公钥操作

4, 把公钥发布到公钥服务器
gpg --keyserver keys.gnupg.net --send-key <UID>
## --keyserver 用于指定公钥服务器
## --send-key  用于指定待发布的公钥的id



5, 在公钥服务器搜索作者的公钥并导入到本机
gpg --keyserver keys.gnupg.net --search-key <UID>
## --search-key 用于指定搜索关键字
## --keyserver  可以是pgp.mit.edu
## 如果你确切知道要导入的公钥的id，也可以跳过搜索这步而直接使用如下的命令导入:
## gpg --keyserver keys.gnupg.net --recv-key 72E75B05
## 如果有文件，运行如下命令就可以导入公钥:
## gpg --import key.public

6, 下面命令可以查看指纹值
gpg --fingerprint

7, 确定取得的公钥是真货之后，使用如下命令对这个公钥进行签收(sign key):
gpg --sign-key <UID>

8, 加密一个文件
gpg -a --output message-ciper.txt -r <UID> -e message.txt
## -a       表示输出文本文件格式
## --output 指定输出(即加密后)的文件名
## -r       指定信息的接收者(recipient)公钥的uid, 可以是名字也可以是email地址
## -e       表示这次要执行的是加密(encrypt)操作
##          注:如果你要加密的是一个二进制文件, 则可以省略-a参数, 这样产生的加密文件的体积会小一些

9, 解密一个文件
gpg --output message-plain.txt -d message-ciper.txt
## --output 指定输出的文件名
## -d       表示这次要执行的是解密操作





```



```
o export a public key into file public.key:
gpg --export -a "User Name" > public.key
This will create a file called public.key with the ascii representation of the public key for User Name. This is a variation on:
gpg --export
which by itself is basically going to print out a bunch of crap to your screen. I recommend against doing this.
gpg --export -a "User Name"
prints out the public key for User Name to the command line, which is only semi-useful

to export a private key:
gpg --export-secret-key -a "User Name" > private.key
This will create a file called private.key with the ascii representation of the private key for User Name.
It's pretty much like exporting a public key, but you have to override some default protections. There's a note (*) at the bottom explaining why you may want to do this.

to import a public key:
gpg --import public.key
This adds the public key in the file "public.key" to your public key ring.

to import a private key:
gpg --allow-secret-key-import --import private.key
This adds the private key in the file "private.key" to your private key ring. There's a note (*) at the bottom explaining why you may want to do this.

```


Ref: http://www.williamlong.info/archives/3439.html