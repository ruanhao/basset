# Git

## git config
* git config --global user.name `Name`
* git config --global user.email `Email`

## git commit
* git commit -m `Msg`
* git commit --amend -m `Msg`

## git branch
* git branch -D `BranchToDelete`

## git push
* git push origin :`BranchOrTagToDelete` ->  Delete branch/tag on remote repo

## git tag
* git tag -m `Msg` `Tag`
* git tag -d `TagToDelete`
* git tag -n -> Show all tags
* **annotated tag**保存为一个tag对象，而轻量级的tag作为某个commit对象的别名

## git clean
* git clean -fd -> 清除当前工作区中没有加入版本库的文件和目录（非跟踪文件和目录）

## git rm
* git rm --cached `File` ->  删除暂存区文件，工作区保持不变

## git diff
* git diff -> workspace & stage
* git diff `Commit` -> workspace & `Commit`
* git diff `Commit1` `Commit2` `Filename`
* git diff --cached(--staged) -> stage & HEAD
* git diff --cached `Commit` -> stage & Commit

## git cat-file
* git rev-parse `Commit:/path/to/file` ->  得到文件对应的SHA
* git cat-file -p `SHA` -> 查看SHA对应的内容，即历史文件
* git cat-file -p `:/path/to/file` -> 查看暂存区中的文件对象
* git cat-file -p `Commit:/path/to/file` -> 查看commit中的文件对象
* git cat-file **equals** git show
* git cat-file `Commit` -> 查看commit对象
* git cat-file`Commit:` **or** git cat-file -p `Commit^{tree}` -> 查看commit对象对应的树对象

## git ls-*
* git ls-tree -r `Commit` -> 显示commit指向的目录树
* git ls-files -s -> 显示暂存区的目录树
* git ls-remote `Remote`

## git reset
* git reset --hard `Commit` -> 替换HEAD，替换暂存区，替换工作区
* git reset --soft `Commit` -> 替换HEAD，暂存区和工作区不变
* git reset `Commit` -> 替换HEAD，替换暂存区，工作区不变
* git reset -- `Filename` -> 对Filename的改动撤出暂存区

## git checkout
* git checkout -- `Filename` -> 暂存区中的Filename覆盖工作区中的Filename
* git checkout `Branch` -- `Filename` -> HEAD不变，用Branch指向的Filename替换暂存区和工作区中的文件
* git checkout -- . **or** git checkout . -> 用暂存区中的所有文件覆盖工作区中的文件
* git checkout **or** git checkout HEAD -> 汇总显示工作区，暂存区和HEAD的差异

## git revert
* git revert -n

## git log
* git log --oneline `Commit^@` -> 某次提交的历史提交，自身除外，用语法Commit^@表示
* git log --oneline `Commit^!` -> 只要提交本身，不包括其历史提交，用语法Commit^!表示

## git blame
* git blame -L `Line,+Incr` `Filename`

## git rebase
* git rebase `Since` **equals** git rebase --onto `Since` `Since` HEAD
  git rebase 的归一化形式：git rebase --onto `NewBase` `Since` `Till`
  变基操作过程：
  1. 首先执行 git checkout `Till`
  2. 将`Since`..`Till`标识的提交范围写到一个临时文件中
  3. git reset --hard `NewBase`
  4. 从保存在临时文件中的提交列表中，将提交逐一按顺序重新提交到重置后的分支上
  5. 如果遇到提交已经在分支中包含，则跳过改提交
  6. 如果在提交过程遇到冲突，则变基过程暂停；
     用户解决冲突后，执行 git rebase --continue 继续变基操作；
     或者执行git rebase --skip 跳过该次提交；
     或者执行 git rebase --abort 就此终止变基操作切换到变基前的分支上

## git remote
* git remote show `Remote` -> Show status of remote
