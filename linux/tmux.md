## Tmux

```bash
tmux new -s <name>
tmux ls
tmux attach [-d] -t <session_name>
tmux kill-session -t <session_name>
tmux new -s <session_name> -n <first_window_name>

PREFIX $     ## rename current session
PREFIX c     ## create new window
PREFIX &     ## close current window
PREFIX ,     ## rename current window
PREFIX f     ## find a window by name
PREFIX w     ## display a visual menu of windows
PREFIX &     ## close current window
PREFIX %     ## split into panes 
PREFIX "     ## split into panes
PREFIX o     ## cycle through panes
PREFIX space ## cycle through layout
PREFIX x     ## kill pane
PREFIX ?     ## list of predefined tmux keybindings and associated commands
PREFIX C-o   ## rotate without move pane
PREFIX [     ## copy mode
```


### Tmux Powerline

- 安装 Powerline

  #+BEGIN_SRC sh
    pip install powerline-status
    pip show powerline-status # 查看安装路径
  #+END_SRC

- 安装 Terminal 字体

  #+BEGIN_SRC sh
    git clone https://github.com/powerline/fonts.git
    cd fonts
    ./install.sh
  #+END_SRC

- 复制配置文件

  #+BEGIN_SRC sh
    cp ~/.emacs.d/microcebus/tmux.conf ~/.tmux.conf
    cp ~/.emacs.d/microcebus/tmux.conf.local ~/.tmux.conf.local
    cp ~/.emacs.d/microcebus/tmux.conf.user ~/.tmux.conf.user
  #+END_SRC
