
class Stack:
    def __init__(self):
        self.top = -1
        self.size = 0
        self.s = []
    
    def push(self, val: str) -> None:
        self.top += 1
        self.s[self.top] = val
    
    def pop(self) -> str:
        self.top -= 1
        
    def isEmpty(self) -> bool:
        return self.top==-1
        
def isBalanced(s: str) -> bool:
    st = Stack()
    st.size = len(s)
    st.s = [''] * st.size
    for c in s:
        if c=='(':
            st.push('(')
        elif c==')':
            if st.isEmpty(): return False
            else: st.pop()
    return st.isEmpty()

s = "((a*b))*((c*d))"
print(isBalanced(s))

