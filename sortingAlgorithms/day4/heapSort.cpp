#include <iostream>
#include <vector>

using namespace std;

// 调整最大堆，使得root为根的堆其满足最大堆特性
void heapify(vector<int> &arr, int n, int root)
{
    int largest = root;
    int left = largest * 2 + 1;
    int right = largest * 2 + 2;

    if (arr[left] > arr[largest] && left < n)
        largest = left;

    if (arr[right] > arr[largest] && right < n)
        largest = right;

    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();
    buildHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(vector<int> &arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// 测试主函数
int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "原始数组: ";
    printArray(arr);

    heapSort(arr);

    cout << "堆排序后: ";
    printArray(arr);
    return 0;
}
