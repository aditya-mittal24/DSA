class FindMissingElement:
    def SingleMissingInFirstN(self, arr):
        sm = 0
        n = arr[-1]
        for i in range(len(arr)):
            sm += arr[i]
        s = (n*(n+1))/2
        return int(s-sm)
    
    def SingleMissingInSorted(self, arr):
        diff = arr[0]
        for i in range(1,len(arr)):
            if arr[i]-i!=diff:
                return i+diff
    
    def MultipleMissingInSorted(self,arr):
        missing = []
        diff = arr[0]
        i = 1
        while i<len(arr):
            if arr[i]-i!=diff:
                missing.append(i+diff)
                diff+=1
            else:
                i+=1
        return missing
    
    def MissingInUnsorted(self,arr):
        missing = []
        hash = [0] * (max(arr)+1)
        print(hash)
        for i in range(len(arr)):
            hash[arr[i]] = 1
        for i in range(min(arr),len(hash)):
            if hash[i]==0:
                missing.append(i)
        return missing
    

find = FindMissingElement()
print(find.SingleMissingInFirstN([1,2,3,4,5,7,8]))
print(find.SingleMissingInSorted([6,7,8,9,10,11,13,14,15,16]))
print(find.MultipleMissingInSorted([6,7,8,9,11,12,15,16,17,18,19]))
print(find.MissingInUnsorted([3,7,4,9,12,6,1,11,2,10]))


