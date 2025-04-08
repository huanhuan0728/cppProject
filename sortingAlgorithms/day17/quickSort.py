def partition(arr, left, right):
    pivot = arr[right]
    store_index = left -1
    for i in range(left, right):
        if arr[i] <= pivot:
            store_index += 1
            arr[store_index], arr[i] = arr[i], arr[store_index]
    
    store_index += 1
    arr[store_index], arr[right] = arr[right], arr[store_index]
    return store_index

def quickSoprt(arr, left, right):
    if left < right:
        pivot_index = partition(arr, left, right)
        quickSoprt(arr, left, pivot_index-1)
        quickSoprt(arr, pivot_index+1, right)