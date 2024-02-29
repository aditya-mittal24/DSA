def bubble_sort(l,n):
    for i in range(n):
        for j in range(n-i-1):
            if l[j]>l[j+1]:
                temp = l[j]
                l[j] = l[j+1]
                l[j+1] = temp

l = [34,21,89,4,76,24,18,3,99]
bubble_sort(l,len(l))
print(l)