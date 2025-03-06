def partition(arr, left, right):
    pivot = arr[right]
    store_index = left - 1
    for j in range(left, right):
        if arr[j] < pivot:
            store_index += 1
            arr[store_index], arr[j] = arr[j], arr[store_index]
    
    arr[store_index+1], arr[right] = arr[right], arr[store_index+1]
    return store_index +1

def quick_sort(arr, left, right):
    if left < right:
        pivot = partition(arr, left, right)
        quick_sort(arr, left, pivot-1)
        quick_sort(arr, pivot+1, right)

if __name__ == "__main__":
    arr = [3, 2, 1, 4, 5]
    quick_sort(arr, 0, len(arr)-1)
    print(arr)


