## disown

> * disown 的作用是使一个后台进程不属于当前 shell 的管辖，可能使这个后台进程变成 orphan process
> * 可以使用 wait 命令来防止在后台作业没完成之前退出脚本，wait可以接受一个作业标示符作为参数，比如 wait %1 或者 wait $PPID
