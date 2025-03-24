#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int root)
{
    int largest = root;
    int left = root * 2 + 1;
    int right = root * 2 + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != root)
    {
        swap(arr[largest], arr[root]);
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<int> &arr, int n, int root)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();
    buildHeap(arr, n, 0);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6};
    cout << "原始数组： ";
    printArray(data);
    cout << endl;

    heapSort(data);

    cout << "排序后数组：";
    printArray(data);
    cout << endl;
}
