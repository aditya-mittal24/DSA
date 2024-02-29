class FindingDuplicates:
    def DuplicatesInSorted(self, arr):
        lastDuplicate = -1
        duplicates = []
        for i in range(len(arr)-1):
            if arr[i] == arr[i+1] and lastDuplicate != arr[i]:
                duplicates.append(arr[i])
                lastDuplicate = arr[i]
        return duplicates

    def CountingDuplicates(self, arr):
        i, j = 0, 0
        duplicates = 0
        while i < len(arr)-1:
            if arr[i] == arr[i+1]:
                j = i+1
                while arr[i] == arr[j]:
                    j += 1
                duplicates += j-i
                i = j-1
            i += 1
        return duplicates

    def DuplicatesUsingHash(self, arr):
        mx = max(arr)
        hash = [0] * (mx+1)
        for i in range(len(arr)):
            hash[arr[i]] += 1
        for i in range(mx):
            if hash[i] > 1:
                print(f"{i} is repeating {hash[i]} times")


arr = FindingDuplicates()
print(arr.CountingDuplicates([3, 6, 8, 8, 10, 12, 15, 15, 15, 20]))
arr.DuplicatesUsingHash([3, 6, 8, 8, 10, 12, 15, 15, 15, 20])
