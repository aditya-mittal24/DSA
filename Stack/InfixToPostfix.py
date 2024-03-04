
class Stack:
    def __init__(self):
        self.top = -1
        self.s = []
    
    def push(self, c):
        self.top += 1
        self.s[self.top] = c
    
    def pop(self):
        x = self.s[self.top]
        self.top -= 1
        return x
        
    def isEmpty(self):
        return self.top==-1
    
    def stackTop(self):
        return self.s[self.top]
        
def InfixToPostfix(expr: str) -> str:
    st = Stack()
    st.s = [''] * len(expr)
    prec = {
        '+': 1,
        '-': 1,
        '*': 2,
        '/': 2,
    }
    res = ""
    for c in expr:
        if c in prec:
            while not st.isEmpty() and prec[st.stackTop()]>=prec[c]:
                res += st.pop()
            st.push(c)
        else:
            res += c
    while not st.isEmpty():
        res += st.pop()
    return res

print(InfixToPostfix('a+b*c-d/e'))