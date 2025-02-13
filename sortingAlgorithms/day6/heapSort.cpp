#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int root)
{
    int largest = root;
    int left = largest * 2 + 1;
    int right = largest * 2 + 2;

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