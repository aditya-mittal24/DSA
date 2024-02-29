def WordCount(s):
    words = 0
    for i in range(len(s)):
        if s[i]==' ' and s[i-1]!=' ':
            words += 1
    return words

print(WordCount("Hi how are you   bro"))