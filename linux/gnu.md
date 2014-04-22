## GNU

### Compile
```bash
## Normal compile process
DIR=/path/to/lib
CFLAGS="-I$DIR/include" LDFLAGS="-L$DIR/lib" ./configure 
```

### Runtime
```bash
LD_DEBUG=libs <Command>                                  ## 运行 Command 时查看加载过程信息
LD_LIBRARY_PATH=/path/to/lib:$LD_LIBRARY_PATH <Command>  ## 运行 Command 时提供动态加载库搜索路径
```
