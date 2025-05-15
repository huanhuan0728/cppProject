using System;
using System.Collections.Generic;

class Program
{
    static int partition(int[] arr, int left, int right)
    {
        int pivot = arr[right];
        int store_index = left - 1;

        for (int i = left; i < right; i++)
        {
            if (arr[i] < pivot)
            {
                store_index++;
                int temp = arr[store_index];
                arr[store_index] = arr[i];
                arr[i] = temp;
            }
        }
        store_index++;



    }
}