def PermutationsBacktracking(s):
    res, a = [0] * len(s), [0] * len(s)

    def helper(k):
        if k == len(s):
            print(''.join(res))
        else:
            for i in range(len(s)):
                if a[i] == 1:
                    continue
                res[k] = s[i]
                a[i] = 1
                helper(k+1)
                a[i] = 0
    helper(0)


def Permutations(s):
    a = list(s)

    def helper(l):
        if l == len(a)-1:
            print(''.join(a))
        else:
            for i in range(l, len(a)):
                a[i], a[l] = a[l], a[i]
                helper(l+1)
                a[i], a[l] = a[l], a[i]

    helper(0)


Permutations("ABC")
