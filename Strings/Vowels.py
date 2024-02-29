def CountVowelConsonant(s):
    vowels, consonants = 0,0
    for i in range(len(s)):
        if s[i] in "AEIOUaeiou":
            vowels += 1
        elif s[i].isalpha():
            consonants+=1
    return vowels,consonants

print(CountVowelConsonant("Hello"))