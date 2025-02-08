#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void shellSort(vector<int> &arr)
{
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        int i = gap;
        for (i; i < n; i +=  gap)
        {
            int temp = arr[i];
            int j = i - gap;
            while(j >=0 && arr[j] > temp)
            {
                arr[j+gap] = arr[j];
                j -= gap;
            }

            arr[j + gap] = temp;

        }
    }
}