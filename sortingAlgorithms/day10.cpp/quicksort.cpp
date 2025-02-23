#include <iostream>
#include <vector>

using namespace std;

int partion(vector<int> &arr, int high, int low)
{
    // 分区函数
    int pivot = arr[high]; // 选取最后元素为基准
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// 快速排序

void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partion(arr, high, low);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quicksort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}