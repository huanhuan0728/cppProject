# 每次进行开发前必须的操作

```bash
# 获取远程的最新分支
git checkout feat/edge_pure
git pull
```

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

# 一次合并的示例

```bash
(base) xuhuanlu@xuhuandeMacBook-Pro cppProject % git branch
* leetcode
  main
  note
(base) xuhuanlu@xuhuandeMacBook-Pro cppProject % git checkout main
M       .vscode/settings.json
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
(base) xuhuanlu@xuhuandeMacBook-Pro cppProject % git pull origin
Already up to date.
# 这里报错是因为没有用提交本分支的修改
(base) xuhuanlu@xuhuandeMacBook-Pro cppProject % git merge leetcode
Auto-merging Note/gitNote.md
Merge made by the 'ort' strategy.
 Note/gitNote.md   |  8 --------
 leetcode/_707.cpp | 89 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 leetcode/_977.py  | 16 ++++++++++++++++
 3 files changed, 105 insertions(+), 8 deletions(-)
 create mode 100644 leetcode/_707.cpp
 create mode 100644 leetcode/_977.py
(base) xuhuanlu@xuhuandeMacBook-Pro cppProject % git push orgin main
fatal: 'orgin' does not appear to be a git repository
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
(base) xuhuanlu@xuhuandeMacBook-Pro cppProject % git status
On branch main
Your branch is ahead of 'origin/main' by 4 commits.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   .vscode/settings.json

no changes added to commit (use "git add" and/or "git commit -a")
(base) xuhuanlu@xuhuandeMacBook-Pro cppProject % git add .
(base) xuhuanlu@xuhuandeMacBook-Pro cppProject % git commit -m"合并了leetcode分支"
[main 1bf39c4] 合并了leetcode分支
 1 file changed, 2 insertions(+), 1 deletion(-)
(base) xuhuanlu@xuhuandeMacBook-Pro cppProject % git push origin main
Enumerating objects: 18, done.
Counting objects: 100% (16/16), done.
Delta compression using up to 8 threads
Compressing objects: 100% (8/8), done.
Writing objects: 100% (8/8), 878 bytes | 878.00 KiB/s, done.
Total 8 (delta 6), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (6/6), completed with 5 local objects.
To https://github.com/huanhuan0728/cppProject.git
   3c71c6a..1bf39c4  main -> main
```

# 报错

## error: Your local changes to the following files would be overwritten by checkout:

```bash
(base) xuhuanlu@xuhuandeMacBook-Pro cppProject % git checkout Note
error: Your local changes to the following files would be overwritten by checkout:
        Note/gitNote.md
Please commit your changes or stash them before you switch branches.
Aborting
```

这里报错是因为我在切换回 Note 分支前修改了 main 分支里的 gitNote.md 的内容，如果切换过去这些修改还没有提交到 main，会被覆盖。

我应该先切换到 Note 分支，合并 main 分支，再写笔记，提交、合并到 main

## fatal: unable to access 'https://git.ngsk.tech/ngskcloud/lift_runtime.git/': LibreSSL SSL_connect: SSL_ERROR_SYSCALL in connection to git.ngsk.tech:443

这里是因为设置了代理，用下面的命令行取消就好

```bash
git config --global --get http.proxy
git config --global --get https.proxy
```

## fatal: 'origin/feat/edge_pure_dev' is not a commit and a branch 'feat/edge_pure_dev' cannot be created from it

```bash
(base) xuhuanlu@xuhuandeMacBook-Pro lift_runtime % git checkout -b feat/edge_pure_dev origin/feat/edge_pure_dev
fatal: 'origin/feat/edge_pure_dev' is not a commit and a branch 'feat/edge_pure_dev' cannot be created from it
```

`fatal: 'origin/feat/edge_pure_dev' is not a commit：Git` 没有找到一个名为 origin/feat/edge_pure_dev 的远程分支或者提交。
`and a branch 'feat/edge_pure_dev' cannot be created from it`：因此，无法从该远程分支创建本地分支。

# 拉取远程仓库的新分支

```bash
# 确保远程分支都是最新的
git fetch origin

# 检查远程分支是否存在
git git ls-remote origin

# 手动抓取单个分支，并且建立跟踪分支
git fetch origin feat/edge_pure_dev:refs/remotes/origin/feat/edge_pure_dev

# 切换到本地同名分支
git checkout feat/edge_pure_dev
```

# git 提交规范

- **`type` (类型)**: 表明提交的类别。常见的类型有：
  - `feat`: A new feature (新功能)
  - `fix`: A bug fix (修复 bug)
  - `docs`: Documentation only changes (文档修改)
  - `style`: Changes that do not affect the meaning of the code (white-space, formatting, missing semi-colons, etc) (代码格式修改，不影响代码逻辑)
  - `refactor`: A code change that neither fixes a bug nor adds a feature (代码重构，既不是新功能也不是 bug 修复)
  - `perf`: A code change that improves performance (性能优化)
  - `test`: Adding missing tests or correcting existing tests (增加或修改测试)
  - `build`: Changes that affect the build system or external dependencies (e.g. gulp, broccoli, npm) (影响构建系统或外部依赖的更改)
  - `ci`: Changes to our CI configuration files and scripts (e.g. Travis, Circle, BrowserStack, SauceLabs) (CI 配置文件和脚本的更改)
  - `chore`: Other changes that don't modify `src` or `test` files (其他不修改源文件或测试文件的更改，如更新构建任务、包管理器配置等)
  - `revert`: Reverts a previous commit (回滚提交)
- **`optional scope` (可选范围)**: 括号内，表示提交影响的范围/模块，例如 `feat(parser): add ability to parse arrays`。
- **`description` (描述)**: 简短的提交描述，使用祈使句，现在时态，首字母小写。
- **`optional body` (可选正文)**: 更详细的解释性文字，可以包含动机、与之前行为的对比等。
- **`optional footer(s)` (可选脚注)**:
  - **Breaking Changes (破坏性变更)**: 以 `BREAKING CHANGE:` 开头，后跟描述。或者在 `type(scope)!:` 中使用 `!` 表示。
  - **Issue tracking IDs**: 例如 `Closes #123`, `Fixes #456`。

**使用特定前缀（遵循 Conventional Commits）的好处：**

1.  **自动化生成 CHANGELOGS**:

    - 这是最显著的好处之一。工具（如 `conventional-changelog`）可以根据这些结构化的提交消息自动生成项目变更日志。例如，`feat` 类型的提交会列在新功能部分，`fix` 类型的提交会列在 Bug 修复部分。

2.  **自动化语义化版本控制 (Semantic Versioning - SemVer)**:

    - 根据提交的类型，可以自动确定下一个版本号：
      - 包含 `BREAKING CHANGE` (或 `type!`) 的提交 -> **MAJOR** 版本升级 (例如 1.x.x -> 2.0.0)
      - `feat` 类型的提交 -> **MINOR** 版本升级 (例如 1.0.x -> 1.1.0)
      - `fix` 类型的提交 -> **PATCH** 版本升级 (例如 1.0.0 -> 1.0.1)
      - 其他类型如 `docs`, `style`, `refactor`, `test`, `chore` 等通常不触发版本升级，除非它们包含 `BREAKING CHANGE`。

3.  **提高提交历史的可读性和可维护性**:

    - 快速浏览提交历史（`git log`）时，前缀能让你一眼看出每次提交的主要目的。
    - 这使得查找特定类型的更改（例如，只看所有的新功能或所有的 bug 修复）变得更加容易。

4.  **简化团队协作和沟通**:

    - 为团队提供了一套共享的提交语言，减少了沟通成本和歧义。
    - 代码审查者可以更快地理解提交的意图和影响范围。

5.  **更容易地进行代码回溯和问题定位**:

    - 当出现问题时，结构化的提交历史可以帮助更快地定位引入问题的提交。例如，如果一个功能出错了，可以重点关注 `feat` 和 `fix` 相关的提交。

6.  **触发构建和部署流程**:

    - CI/CD 系统可以根据提交消息的类型或范围来触发特定的构建、测试或部署流程。例如，只有 `feat` 或 `fix` 类型的提交才触发生产部署。

7.  **与其他工具的集成**:
    - 许多现代开发工具和平台（如 GitLab, GitHub, Jira 等）可以更好地解析和利用这种结构化的提交信息。

**示例：**

- 修复了一个 bug: `fix: correct minor typos in code`
- 增加了一个新功能，并指明了范围: `feat(lang): add Polish language`
- 文档修改: `docs: explain foo_bar function in README`
- 一个包含破坏性变更的重构:

  ```
  refactor!: drop support for Node 6

  BREAKING CHANGE: The `foo()` method now requires a new parameter `bar`.
  ```
