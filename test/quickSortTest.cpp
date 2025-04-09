#include <iostream>
#include <vector>
#include "QuickSort.h"

void printArray(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};

    SortLxh *sorter = new QuickSort(); // 使用快速排序
    sorter->sort(arr);
    std::cout << "QuickSort Result: ";
    printArray(arr);

    delete sorter;
    return 0;
}
