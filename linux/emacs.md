## Emacs


```bash
(concat "hello " "world")

(buffer-name)
(buffer-file-name)
(current-buffer)    ## 缓冲区对象
(other-buffer)
(switch-to-buffer "scratch") ## (switch-to-buffer (other-buffer))
(set-buffer)        ## 切换buffer, 但不改变终端显示
(buffer-size)       ## Number of characters in current buffer
(get-buffer-create buffer-name) ## Get buffer or create it
(last-command)

(mark-whole-buffer)  ## C-x h

(interactive "p")    ## 将interactive输入值作为参数
(interactive "r")    ## 将region的开始point和结束point作为函数两个参数
(interactive "BAppend to buffer:") ## 小缓冲区提示用户输入缓冲区的名字
(interactive "BAppend to buffer: \nr") ## 3个参量，\n作为分隔作用
(interactive "c")                 ## 输入字符
(interactive "*bInsert buffer: ") ## *表示若输入buffer是只读的，则给出警告
                                  ## b表示输入的buffer必须是存在的
				  ## B表示输入的buffer可以是不存在的

(center-region)
(count-lines-region)
(kill-region)
(print-region)
(push-mark)  ## 当前位置设置标记，并保存到标记环中

(insert-buffer-substring oldbuf start end)


(what-line)

(let ((v1 value1)
      (v2 value2)
       v3)           ## v1 = value1; v2 = value2; v3 = nil
      body...)

(if true-or-false-test
    action-to-carry-out-if-test-is-true)

(if true-or-false-test
    action-to-carry-out-if-test-is-true
  action-to-carry-out-if-test-is-false)

(save-excursion
  body...)

(save-restriction
  body...)            ## 若同时(紧跟)使用save-excursion和save-restriction，则先用前者再跟后者
  

(defun funcname (&optional arg)
  "documentation"
  (interactive "P") ## P表示传递前缀参量，即Meta，或C-u带的值
                    ## arg若要使用，必须用(prefix-numeric-value arg)的返回值
		    ## p表示经过处理的前缀参量，可以直接使用
  body...)

(progn
  body1
  body2
  ...)

DEFUN ("delete-region", Fdelete_region, Sdelete_region, 2, 2, "r",
       "documentation")
第一部分是Lisp中的函数名，delete-region
第二部分是C语言中的函数名，Fdelete_region，习惯上以F开头
第三部分是C constant结构名，这些常数结构在函数内部记录信息，以S开头
第四，第五部分指定函数中允许的参量数据的最小值和最大值
第六部分和(interactive)的参量含义一样
第七部分是文档字符串

(defvar var)
如果变量已经有值了，defvar就不会覆盖已经存在的值
defvar有文档字符串

(cond
 ((first-test  first-consequent)
  (second-test second-consequent)
  (third-test  third-consequent)))

(lambda (arg-list)
  "documentation string"
   body...)

(funcall (lambda (name)
           (message "hello, %s"  name)) "world")
lambda表达式最常用的是作为参数传递给其它函数，比如mapc  
```


```bash
C-x 8 C-h                   # 特殊字符
C-x 8 <Enter>               # 输入特殊字符
C-x [ENTER] f unix [ENTER]  # dos2unix
C-x i	                    # insert-file
C-_                         # redo

C-x z                       # Repeat the previous emacs command

C-M-@  # 全选括号表达式
M-s o  # occurs

C-x <tab> # 整体缩进

C-x r N # insert line nums
```


```bash
(require 'package)
(add-to-list 'package-archives
             '("melpa" . "http://melpa.milkbox.net/packages/") t)
;; M-x package-install
;; use 'i' to mark, use 'x' to execute

```



