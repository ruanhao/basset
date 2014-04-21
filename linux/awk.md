## awk


## 使用awk产生伪随机数
```bash
# 产生一个范围在 0 - 1 之间的伪随机数
# 缺点：同一秒内生成的随机数相同
echo | awk '{ srand(); print rand() }'
```
