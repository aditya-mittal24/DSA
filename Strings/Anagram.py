def CheckAnagram(s1, s2):
    hash = {}
    for i in range(len(s1)):
        hash[s1[i]] = 1 + hash.get(s1[i], 0)
    for i in range(len(s2)):
        if s2[i] not in hash or hash[s2[i]]-1 < 0:
            return False
        else:
            hash[s2[i]] -= 1
    return True


print(CheckAnagram("observe", "verbose"))
