## xargs

```bash

ls *.bak | xargs -I % cp % /tmp/test

xargs -r				     ## --no-run-if-empty

xargs -d'\n'				     ## delimiter

find . -name "*.c" -print0 | xargs -0 rm -rf ## 如果檔名包含空白，會造成 rm 指令無法正確刪除該檔案
                                             ## 可以將 find 指令加上 -print0 參數，另外將 xargs 指令加上 -0 參數



xargs --show-limits                          ## 使用 --show-limits 參數可以查看系統對於命令列長度的限制
      					     ## 這些限制會跟 xargs 的運作情況有關，如果要處理很大量的資料時，這些限制要注意一下

```
