def ToggleCase(s):
    res = ""
    for i in range(len(s)):
        if s[i].isupper():
            res += s[i].lower()
        elif s[i].islower():
            res += s[i].upper()
        else:
            res += s[i]
    return res

print(ToggleCase("Hello HOw aRe YoU?"))