## Trap

```bash
trap <function_name> <signal>  ## 当收到 signal 中断时，执行function_name

trap : <signal>                ## 不指定处理动作，删除之前设置的handler，使用系统默认的handler

trap '' <signal>               ## handler设置为空函数，相当于屏蔽了sig_num，
                               ## 可以保护脚本中某些部分的操作不受意外的中断骚扰:
trap '' 2                      ## 信号2就是 Ctrl-C，现在被禁用了
command                        ## 执行一些命令
trap 2                         ## 重新恢复 Ctrl-C，恢复为**系统默认**的

trap 'commands' EXIT           ## EXIT是脚本中 exit 命令所产生信号的名字，这样可以捕捉任何 exit

trap 'my_function' DEBUG        ## 每个命令执行后，都会执行一遍 my_function
```
