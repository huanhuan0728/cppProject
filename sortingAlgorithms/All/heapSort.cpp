#include <iostream>
#include <vector>
using namespace std;

class HeapSort
{
private:
    void heapify(vector<int> &arr, int n, int root)
    {
        int largest = root;
        int left = largest * 2 + 1;
        int right = largest * 2 + 2;

        // 找出根节点、左子节点和右子节点中的最大值
        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        // 如果最大值不是根节点，则交换并继续调整
        if (largest != root)
        {
            swap(arr[root], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void buildHeap(vector<int> &arr, int n)
    {
        // 从最后一个非叶子节点开始，自底向上构建最大堆
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

public:
    void sort(vector<int> &arr)
    {
        int n = arr.size();
        buildHeap(arr, n);

        // 从后向前，逐个将最大值（堆顶）放到数组末尾
        for (int i = n - 1; i > 0; i--)
        {
            // 将当前堆顶（最大值）与末尾元素交换
            swap(arr[0], arr[i]);
            // 对剩余元素重新构建最大堆
            heapify(arr, i, 0);
        }
    }
};

class bubbleSort
{
public:
    void sort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

class selectionSort
{
public:
    void sort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
};

// 打印数组的辅助函数
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    // 测试用例1：随机数组
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    cout << "原始数组: ";
    printArray(arr1);

    // 测试堆排序
    HeapSort heapSort;
    vector<int> arr1_heap = arr1;
    heapSort.sort(arr1_heap);
    cout << "堆排序后: ";
    printArray(arr1_heap);

    // 测试冒泡排序
    bubbleSort bubble;
    vector<int> arr1_bubble = arr1;
    bubble.sort(arr1_bubble);
    cout << "冒泡排序后: ";
    printArray(arr1_bubble);

    // 测试选择排序
    selectionSort selection;
    vector<int> arr1_selection = arr1;
    selection.sort(arr1_selection);
    cout << "选择排序后: ";
    printArray(arr1_selection);

    cout << "\n测试用例2：已排序数组\n";
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "原始数组: ";
    printArray(arr2);

    // 测试堆排序
    vector<int> arr2_heap = arr2;
    heapSort.sort(arr2_heap);
    cout << "堆排序后: ";
    printArray(arr2_heap);

    // 测试冒泡排序
    vector<int> arr2_bubble = arr2;
    bubble.sort(arr2_bubble);
    cout << "冒泡排序后: ";
    printArray(arr2_bubble);

    // 测试选择排序
    vector<int> arr2_selection = arr2;
    selection.sort(arr2_selection);
    cout << "选择排序后: ";
    printArray(arr2_selection);

    cout << "\n测试用例3：逆序数组\n";
    vector<int> arr3 = {5, 4, 3, 2, 1};
    cout << "原始数组: ";
    printArray(arr3);

    // 测试堆排序
    vector<int> arr3_heap = arr3;
    heapSort.sort(arr3_heap);
    cout << "堆排序后: ";
    printArray(arr3_heap);

    // 测试冒泡排序
    vector<int> arr3_bubble = arr3;
    bubble.sort(arr3_bubble);
    cout << "冒泡排序后: ";
    printArray(arr3_bubble);

    // 测试选择排序
    vector<int> arr3_selection = arr3;
    selection.sort(arr3_selection);
    cout << "选择排序后: ";
    printArray(arr3_selection);

    return 0;
}