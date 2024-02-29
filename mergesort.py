def merge_sort(arr):
    low = 0
    high = len(arr)-1
    if low==high:
        return
    else:
        mid = (low+high)//2
        left_arr = arr[low:mid+1]
        right_arr = arr[mid+1:high+1]
        merge_sort(left_arr)
        merge_sort(right_arr)
        merge(left_arr,right_arr,arr)

def merge(left,right,arr):
    i,j,k=0,0,0
    m = len(left)
    n = len(right)
    while i<m and j<n:
        if left[i] < right[j]:
            arr[k]= left[i]
            i+=1
        else:
            arr[k] = right[j]
            j+=1
        k+=1
    if i>=m:
        while j<n:
            arr[k] = right[j]
            j+=1
            k+=1
    elif j>=n:
        while i<m:
            arr[k] = left[i]
            i+=1
            k+=1

arr = list(map(int, input().split()))
merge_sort(arr)
print(arr)