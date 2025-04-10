# 创建新分支

```bash
# 查看当前分支
git branch

# 查看是否有为提交的修改
git status

# 创建新分支
git branch new

# 切换到新分支
git checkout new

# 一步创建并切换
git checkout -b new

# 提交修改
git add .
git commit -m"描述修改内容"

# 推送到远程分支
git push origin main

```

# 下拉最新分支并且解决冲突并合并

要从远程仓库拉取最新的分支，可以使用以下 Git 命令：

### 1. **获取远程仓库的最新信息**

```bash
git fetch
```

这不会自动合并或切换分支，只是更新远程分支的引用。

### 2. **查看远程分支列表**

```bash
git branch -r
```

如果你想查看所有分支（包括本地和远程），可以使用：

```bash
git branch -a
```

### 3. **切换到远程的新分支**

如果你想拉取一个新的远程分支 `new-branch`，你可以使用：

```bash
git checkout -b new-branch origin/new-branch
```

或者：

```bash
git switch -c new-branch origin/new-branch
```

### 4. **更新当前分支到最新**

如果你当前在 `main` 分支上，并希望拉取远程最新的 `main` 分支：

```bash
git pull origin main
```

如果你不确定当前在哪个分支，可以用 `git branch` 检查。

### 5. **拉取所有远程分支（不切换）**

如果你只是想同步所有远程分支到本地但不切换：

```bash
git fetch --all
```

这个错误提示说明你的本地分支和远程分支各自有不同的提交（即“分叉”了），Git 无法自动决定该如何整合它们。也就是说，你的本地分支和远程的 main 分支都各自有独立的发展历史，所以在执行 `git pull` 时，Git 需要你明确指定合并方式。

# 合并

```bash
# 简单版
git checkout main
git pull origin main
git merge new
```

1. **合并（merge）**  
   通过合并将远程的更改和本地的提交整合到一个新的合并提交中。  
   配置命令：

   ```bash
   git config pull.rebase false
   ```

   或者在命令行中直接执行：

   ```bash
   git pull --no-rebase origin main
   ```

2. **变基（rebase）**  
   通过变基，将你的本地提交放到远程分支的最新提交之后，从而形成一条更直线的历史记录。  
   配置命令：

   ```bash
   git config pull.rebase true
   ```

   或者直接：

   ```bash
   git pull --rebase origin main
   ```

3. **仅快进（fast-forward only）**  
   如果两边的提交可以快进合并，则合并，否则就报错。  
   配置命令：
   ```bash
   git config pull.ff only
   ```
   或者直接：
   ```bash
   git pull --ff-only origin main
   ```

你可以根据自己的工作流和团队协作约定来选择合适的方式。如果不确定，默认的合并方式（merge）通常是最简单的选择。如果你希望保持更简洁的提交历史，则可以选择变基（rebase）。

这样做之后，下次执行 `git pull origin main` 时，Git 就会按照你配置的方式来处理分叉情况。
