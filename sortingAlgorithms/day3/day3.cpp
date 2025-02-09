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
        for (int i = gap; i < n; i += gap)
        {
            int temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > gap)
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }

            arr[j + gap] = temp;
        }
    }
}

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 1; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
            swapped = true;
        }

        if (!swapped)
        {
            /* code */
            break;
        }
    }
}