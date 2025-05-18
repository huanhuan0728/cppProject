#include <iostream>
#include <vector>
using namespace std;
/*
在 heapSort 中，首先需要 O(n) 的时间来构建堆，然后每次从堆中移除最大元素，
并且每次都要调用 heapify 来恢复堆的性质。移除每个元素的时间复杂度为 O(log n)，
共需要执行 n 次移除操作，因此 heapSort 的时间复杂度为 O(n log n)。
*/

void heapify(vector<int> &arr, int n, int root)
{
    int largest = root;
    int left = largest * 2 + 1;
    int right = largest * 2 + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (root != largest)
    {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest); // 递归遍历子树，确保修改后都符合大根堆的性质
    }

    return;
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

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]); // 将堆顶元素（最大值）放到数组末尾
        heapify(arr, i, 0);
    }
}
