#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        int key = arr[i];
        while (j > 0 && arr[j] > key)
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

    for (int gap = n / 2; gap >= 0; gap /= 2)
    {
        for (int i = gap; i < n; i += gap)
        {
            int j = i - 1;
            int temp = arr[j];
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = arr[j];
        }
    }
}

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = i - 1; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    cout << " " << endl;
}