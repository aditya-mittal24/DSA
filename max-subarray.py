import sys
def max_cross_subarray(arr,low,mid, high):
    left_sum = -sys.maxsize
    sum = 0
    max_left = mid
    max_right = mid
    for i in range(mid,low,-1):
        sum = sum+arr[i]
        if sum > left_sum:
            left_sum = sum
            max_left = i
    right_sum = -sys.maxsize
    sum = 0
    for i in range(mid+1, high):
        sum = sum+arr[i]
        if sum>right_sum:
            right_sum = sum
            max_right = i
    return max_left,max_right,left_sum+right_sum

def max_subarray(arr,low,high):
    if low==high:
        return low,high,arr[low]
    else:
        mid = int((low+high)/2)
        left_low, left_high, left_sum = max_subarray(arr,low,mid)
        right_low, right_high, right_sum = max_subarray(arr,mid+1,high)
        cross_low, cross_high, cross_sum = max_cross_subarray(arr,low,mid,high)
        if max(left_sum,right_sum,cross_sum) == left_sum:
            return left_low,left_high,left_sum
        elif max(left_sum,right_sum,cross_sum) == right_sum:
            return right_low,right_high,right_sum
        else:
            return cross_low,cross_high,cross_sum
arr = list(map(int, input().split()))
low,high,max_sum = max_subarray(arr,0,len(arr)-1)
print("Maximum Subarray: ", arr[low:high+1])
print("Maximum Sum: ", max_sum)