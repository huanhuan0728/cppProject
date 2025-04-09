#include "QuickSort.h"
#include <iostream>
#include <vector>
using namespace std;

void QuickSort::sort(std::vector<int> &arr)
{
    quickSort(arr, 0, arr.size() - 1);
}

void QuickSort::quickSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int QuickSort::partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int store_index = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            store_index++;
            swap(arr[store_index], arr[j]);
        }
    }

    swap(arr[store_index + 1], arr[right]);
    return store_index + 1;
}