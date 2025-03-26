# leetcode27（双指针、原地删除）

```
    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
    假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
    更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
    返回 k。
```

双指针法，左指针找到第一个值为 val 的元素，右指针找到第一个值不为 val 的元素，交换二者

## while(A && B) while(B && A)

有区别，第一个条件为假的时候第二个条件不再检查
在 leetcode27：
版本 1（安全）：先检查边界再检查元素

```python
    // 正确顺序：先检查 left <= right，再访问元素
    while (left <= right && nums[right] == val)
```

版本 2（危险）：先访问元素，再检查边界

```python
    // 错误顺序：先访问元素，再检查 left <= right
    while (nums[left] != val && left <= right)
```
