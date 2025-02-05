# 如果我不添加 std::, 会报错如下，为什么？vector 不是模板 C/C++(864)

你遇到的错误是因为 **C++ 标准库中的容器（如 `vector`、`unordered_map`）都定义在 `std` 命名空间中**。如果不显式指定 `std::`，编译器将无法识别这些类型，导致报错 `vector 不是模板`。以下是详细解释和解决方案：

---

### 错误原因分析

在 C++ 中，标准库的组件（如容器、算法等）都位于 `std` 命名空间中。例如：

- `vector` 的实际名称是 `std::vector`
- `unordered_map` 的实际名称是 `std::unordered_map`

如果你在代码中直接写 `vector` 而不是 `std::vector`，编译器会在全局命名空间中查找 `vector` 的定义，但显然找不到，因此报错：**“vector 不是模板”**（即编译器认为 `vector` 未被定义）。

---

### 解决方案

#### 方法 1：显式使用 `std::`

在每次使用标准库组件时，加上 `std::` 前缀：

```cpp
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3};  // 正确：使用 std::vector
    return 0;
}
```

#### 方法 2：使用 `using namespace std;`（不推荐）

在代码开头添加 `using namespace std;`，告诉编译器从 `std` 命名空间中查找未限定的名称：

```cpp
#include <vector>
using namespace std;  // 引入整个 std 命名空间

int main() {
    vector<int> nums = {1, 2, 3};  // 正确：编译器知道 vector 是 std::vector
    return 0;
}
```

**为什么不推荐此方法？**  
在大型项目中，`using namespace std;` 可能导致命名冲突（例如，如果你定义了一个自己的 `vector` 类，编译器将无法区分它与 `std::vector`）。

#### 方法 3：使用 `using` 声明（推荐）

仅引入需要的名称，而不是整个命名空间：

```cpp
#include <vector>
using std::vector;  // 只引入 std::vector

int main() {
    vector<int> nums = {1, 2, 3};  // 正确
    return 0;
}
```

---

### 关键点总结

1. **必须包含头文件**：确保代码中包含了 `<vector>` 和 `<unordered_map>`。
2. **显式使用 `std::`**：所有标准库组件都需要通过 `std::` 访问。
3. **避免全局 `using namespace std;`**：虽然可以简化代码，但在实际项目中容易引发命名冲突。

通过以上修改，你的代码将不再报错 `vector 不是模板`。

---

# 移动文件位置后导致的 zsh: permission denied: ./twoSum

移动文件位置可能会导致 `zsh: permission denied` 问题，主要原因有以下几种可能：

### **可能的原因**

1. **文件丢失或路径错误**

   - 你在终端执行 `./twoSum`，默认是在当前目录查找 `twoSum`，但如果你移动了文件，它可能已经不在当前目录了。
   - 运行以下命令检查文件是否还在：
     ```bash
     ls -l ./twoSum
     ```
   - 如果显示 `No such file or directory`，说明文件不在这个路径，你需要找到它：
     ```bash
     find ~ -name "twoSum"
     ```

2. **文件移动后权限发生变化**

   - 某些情况下，文件移动到新目录后，可能会继承该目录的权限，导致 `zsh: permission denied`。
   - 解决方法：
     ```bash
     chmod +x twoSum  # 重新赋予可执行权限
     ./twoSum
     ```

3. **移动到系统受保护的目录**

   - 如果你把 `twoSum` 移动到了 `~/Library`, `/System`, `/usr`, `/bin`, `/Applications` 等 **受 macOS 保护的目录**，可能会导致无法执行。
   - 解决方法：把 `twoSum` 移回 **普通目录**（如 `~/Desktop` 或 `~/Downloads`）：
     ```bash
     mv /path/to/twoSum ~/Desktop/
     cd ~/Desktop/
     chmod +x twoSum
     ./twoSum
     ```

4. **文件系统的 `com.apple.quarantine` 标记**
   - macOS **安全机制** 可能给你移动的文件加上了 `quarantine` 标记，导致无法执行。
   - 解决方法：
     ```bash
     xattr -d com.apple.quarantine twoSum
     ./twoSum
     ```

---

### **完整解决方案**

按顺序尝试：

```bash
ls -l ./twoSum  # 确保文件存在
chmod +x twoSum  # 赋予执行权限
./twoSum  # 运行文件
```

ls -l 是检查文件权限，示例输出

```bash
-rw-r--r--  1 xuhuanlu  staff  12345  Feb 5  12:00 twoSum

```

-rw-r--r-- 说明：

rw-（所有者）有 读（r）写（w）权限，但没有执行权限（x）。
r--（同组用户）只有读权限。
r--（其他人）只有读权限。

chmod（change mode）是更改文件权限的命令, +x 表示添加执行权限
基本语法：

```bash
chmod [权限修改] [文件名]

```
