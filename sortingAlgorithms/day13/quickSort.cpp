#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int left, int right)
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

void quickSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, right, left);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
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

    quickSort(data, 0, data.size() - 1);

    cout << "排序后数组：";
    printArray(data);
    cout << endl;
}