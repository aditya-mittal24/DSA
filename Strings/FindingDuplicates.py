
def FindingDuplicates(s):
    hash = {}
    for i in range(len(s)):
        hash[s[i]] = 1 + hash.get(s[i], 0)
    for c in hash:
        if hash[c] > 1:
            print(f"{c} is repeating {hash[c]} times.")


def DuplicatesUsingBitwise(s):
    a, h = 0, 0
    for i in range(len(s)):
        x = 1
        x = x << ord(s[i])-97
        if x & h > 0:
            print(f"{s[i]} is duplicate.")
        else:
            h = x | h


FindingDuplicates('finding')
DuplicatesUsingBitwise('finding')

# h = 0000
# x = 0001
# h = 0001
# x = 0100
# h = 0101
# x = 1000
# h = 1101
# x = 0010
# h = 1111
# x = 0010
# x & h = 0010

