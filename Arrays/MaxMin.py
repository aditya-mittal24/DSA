def MaxMin(arr):
    mx,mn = arr[0],arr[0]
    for i in range(1,len(arr)):
        if arr[i]>mx:
            mx = arr[i]
        elif arr[i]<mn:
            mn = arr[i]
    return mx,mn
print(MaxMin([5,8,3,9,6,2,10,7,-1,4]))