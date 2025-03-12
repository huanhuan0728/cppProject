def partition(arr, left, right):
    pivot = arr[right]
    store_index = left-1
    for i in (left, right):
        if arr[i] > pivot:
            store_index += 1
            arr[store_index], arr[i] = arr[i], arr[store_index]

    store_index += 1
    arr[store_index], arr[right] = arr[right], arr[store_index]  
    return  store_index

def quickSort(arr, left, right):
    if(left < right):
        pivot = partition(arr, left, right)
        quickSort(arr, left, pivot)
        quickSort(arr, pivot, right)

if __name__ == "__main__":
    arr = [3, 2, 1, 4, 5]
    quickSort(arr, 0, len(arr) - 1)

    print(arr)
