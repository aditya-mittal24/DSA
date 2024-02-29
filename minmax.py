def min_max(arr,low,high):
    if low==high:
        return arr[low],arr[low]
    else:
        mid = (low+high)//2
        left_min, left_max = min_max(arr,low,mid)
        right_min, right_max = min_max(arr,mid+1,high)
        return min(left_min,right_min),max(left_max,right_max)

arr = list(map(int, input().split()))
minimum, maximum = min_max(arr,0,len(arr)-1)
print(f"Minimum: {minimum}\nMaximum: {maximum}")
