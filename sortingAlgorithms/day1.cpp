#include <iostream>
#include <vector>

using namespace std;

// 插入排序
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] >= arr[i])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// 希尔排序（Shell Sort）
void shellSort(vector<int> &arr)
{
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    { // 初始步长 n/2，每次减半
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}