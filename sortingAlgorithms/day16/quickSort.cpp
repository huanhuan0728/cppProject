#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int store_index = left - 1;
    for (int i = left; i < right; i++)
    {
        if (arr[i] < arr[pivot])
        {
            store_index++;
            swap(arr[store_index], arr[i]);
        }
    }

    store_index++;
    swap(arr[store_index], arr[right]);

    return store_index;
}

void quickSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}