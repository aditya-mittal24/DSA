def PairWithSumK(arr, k):
    hash = [0] * (max(arr)+1)
    pairs = []
    for i in range(len(arr)):
        c = k - arr[i]
        if c >= 0 and hash[c] != 0:
            pairs.append([arr[i], c])
        hash[arr[i]] += 1
    return pairs


def TwoSum(arr, k):
    hash = {}
    pairs = set()
    for i in range(len(arr)):
        c = k - arr[i]
        if c in hash:
            pairs.add((arr[i], c))
        hash[arr[i]] = i
    return list(pairs)


def PairsInSorted(arr, k):
    i, j = 0, len(arr)-1
    pairs = []
    while i < j:
        s = arr[i]+arr[j]
        if s == k:
            pairs.append([arr[i], arr[j]])
            i += 1
            j -= 1
        elif s > k:
            j -= 1
        else:
            i += 1
    return pairs


arr = [2, 3, 5, 6, 7, 8, 9, 10, 14, 16, 7]
arr1 = [1,3,4,5,6,8,9,10,12,14]
print(PairWithSumK(arr, 10))
print(TwoSum(arr, 10))
print(PairsInSorted(arr, 10))
print(PairsInSorted(arr1, 10))
