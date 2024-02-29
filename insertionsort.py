def insertion_sort(a,n):
    for k in range(1,n):
        temp = a[k]
        j = k-1
        while temp<=a[j] and j>=0:
            a[j+1] = a[j]
            j = j-1
        a[j+1] = temp
    
l = [34,21,89,4,76,24,18,3,99]
insertion_sort(l,len(l))
print(l)