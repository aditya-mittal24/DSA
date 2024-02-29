
def FindingDuplicates(s):
    hash = {}
    for i in range(len(s)):
        hash[s[i]] = 1 + hash.get(s[i], 0)
    for c in hash:
        if hash[c] > 1:
            print(f"{c} is repeating {hash[c]} times.")
            
def DuplicatesUsingBitwise(s):
    a,h = 0,0
    for i in range(len(s)):
        x = 1
        x = x<<ord(s[i])-97
        if x&h>0:
            print(f"{s[i]} is duplicate.")
        else:
            h = x|h


FindingDuplicates('finding')
DuplicatesUsingBitwise('finding')