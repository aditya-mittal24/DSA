class Array:
    def __init__(self, elements, size, length):
        self.a = []
        self.a.extend(elements)
        self.a.extend([0]*(size-len(elements)))
        self.size = size
        self.length = length

    def display(self):
        for i in range(self.length):
            print(self.a[i], end=" ")
        print()

    def append(self, x):
        if self.length == self.size:
            return -1
        self.a[self.length] = x
        self.length += 1

    def insert(self, index, x):
        if self.length == self.size:
            return -1
        for i in range(self.length, index, -1):
            self.a[i] = self.a[i-1]
        self.a[index] = x
        self.length += 1

    def delete(self, index):
        if index >= 0 and index < self.length:
            x = self.a[index]
            for i in range(index, self.length-1):
                self.a[i] = self.a[i+1]
            self.length -= 1
            return x
        return -1

    def LinearSearch(self, key):
        for i in range(self.length):
            if self.a[i] == key:
                return i
        return -1

    def BinarySearch(self, key):
        l = 0
        h = self.length-1

        while (l <= h):
            mid = int((l+h)/2)
            if self.a[mid] == key:
                return mid
            elif self.a[mid] < key:
                l = mid+1
            else:
                h = mid-1

        return -1

    def RBinarySearch(self, l, h, key):
        if l <= h:
            mid = int((l+h)/2)
            if self.a[mid] == key:
                return mid
            elif self.a[mid] > key:
                return self.RBinarySearch(l, mid-1, key)
            else:
                return self.RBinarySearch(mid+1, h, key)
        return -1

    def get(self, index):
        if index >= 0 and index < self.length:
            return self.a[index]
        return -1

    def set(self, index, x):
        if index >= 0 and index < self.length:
            self.a[index] = x

    def max(self):
        maxm = self.a[0]
        for i in range(1, self.length):
            if self.a[i] > maxm:
                maxm = self.a[i]
        return maxm

    def min(self):
        minm = self.a[0]
        for i in range(1, self.length):
            if self.a[i] < minm:
                minm = self.a[i]
        return minm

    def sum(self):
        total = 0
        for i in range(self.length):
            total += self.a[i]
        return total

    def avg(self):
        total = self.sum()
        return total/self.length

    def reverse(self):
        i, j = 0, self.length - 1
        while i < j:
            temp = self.a[i]
            self.a[i] = self.a[j]
            self.a[j] = temp
            i += 1
            j -= 1

    def InsertSort(self, x):
        i = self.length-1
        while self.a[i] > x:
            self.a[i+1] = self.a[i]
            i -= 1
        self.a[i+1] = x
        self.length += 1

    def isSorted(self):
        for i in range(self.length-1):
            if self.a[i] > self.a[i+1]:
                return False
        return True

    def Rearrange(self):
        i, j = 0, self.length - 1
        while i < j:
            while self.a[i] < 0 and i<j:
                i += 1
            while self.a[j] > 0 and j>i:
                j -= 1
            temp = self.a[i]
            self.a[i] = self.a[j]
            self.a[j] = temp

    def Merge(self, arr2):
        i, j, k = 0, 0, 0
        res = Array([], self.length + arr2.length, 0)
        while i < self.length and j < arr2.length:
            if self.a[i] < arr2.a[j]:
                res.a[k] = self.a[i]
                k += 1
                i += 1
            else:
                res.a[k] = arr2.a[j]
                k += 1
                j += 1
        while i < self.length:
            res.a[k] = self.a[i]
            k += 1
            i += 1
        while j < arr2.length:
            res.a[k] = arr2.a[j]
            k += 1
            j += 1
        res.length = self.length + arr2.length
        return res

    def Union(self, arr2):
        i, j, k = 0, 0, 0
        res = Array([], self.length + arr2.length, 0)
        while i < self.length and j < arr2.length:
            if self.a[i] < arr2.a[j]:
                res.a[k] = self.a[i]
                k += 1
                i += 1
            elif self.a[i] > arr2.a[j]:
                res.a[k] = arr2.a[j]
                k += 1
                j += 1
            else:
                res.a[k] = self.a[i]
                k += 1
                j += 1
                i += 1

        while i < self.length:
            res.a[k] = self.a[i]
            k += 1
            i += 1
        while j < arr2.length:
            res.a[k] = arr2.a[j]
            k += 1
            j += 1
        res.length = k
        return res

    def Intersection(self, arr2):
        i, j, k = 0, 0, 0
        res = Array([], self.length + arr2.length, 0)
        while i < self.length and j < arr2.length:
            if self.a[i] < arr2.a[j]:
                i += 1
            elif self.a[i] > arr2.a[j]:
                j += 1
            else:
                res.a[k] = self.a[i]
                k += 1
                j += 1
                i += 1

        res.length = k
        return res

    def Difference(self, arr2):
        i, j, k = 0, 0, 0
        res = Array([], self.length + arr2.length, 0)
        while i < self.length and j < arr2.length:
            if self.a[i] < arr2.a[j]:
                res.a[k] = self.a[i]
                k += 1
                i += 1
            elif self.a[i] > arr2.a[j]:
                j += 1
            else:
                j += 1
                i += 1

        while i < self.length:
            res.a[k] = self.a[i]
            k += 1
            i += 1

        res.length = k
        return res


arr = Array([12, 23, -1, 3, -8, -13, 23], 10, 7)
arr.Rearrange()
arr.display()
# arr2 = Array([3, 6, 7, 15, 20], 10, 5)
# arr.display()
# arr.append(7)
# arr.display()
# arr.insert(0, 1)
# arr.display()
# arr.delete(3)
# arr.display()
# print(arr.LinearSearch(5))
# print(arr.BinarySearch(10))
# print(arr.RBinarySearch(0, arr.length-1, 7))
# arr.get(4)
# arr.set(4,10)
# arr.display()
# print(arr.max())
# print(arr.min())
# print(arr.sum())
# print(arr.avg())
# arr.InsertSort(1)
# arr.display()
# arr2.display()
# res = arr.Difference(arr2)
# res.display()

