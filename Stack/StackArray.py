
class Stack:
    def __init__(self):
        self.size = 0
        self.top = -1
        self.s = []
        
    def Create(self):
        self.size = int(input("Enter size of the Stack: "))
        self.top = -1
        self.s = [0] * self.size
    
    def Display(self):
        for i in range(self.top,-1,-1):
            print(f"{self.s[i]}", end=" ")
    
    def isEmpty(self):
        return self.top==-1
    
    def isFull(self):
        return self.top+1==self.size
    
    def stackTop(self):
        if self.isEmpty(): return -1
        else: return self.s[self.top]
    
    def Push(self, val):
        if self.isFull():
            print("Stack Overflow!")
        else:
            self.top += 1
            self.s[self.top] = val
    
    def Pop(self):
        x = -1
        if self.isEmpty():
            print("Stack Underflow!")
        else:
            x = self.s[self.top]
            self.top -= 1
        return x
    
    def Peak(self, pos):
        x = -1
        if pos>self.top:
            print("Invalid positon")
        else:
            x = self.s[self.top-pos]
        return x
    
st = Stack()
st.Create()
print(st.isEmpty())
st.Push(1)
print(st.isEmpty())
st.Push(2)
print(st.Peak(0))
print(st.isFull())
st.Push(3)
print(st.Pop())
st.Push(4)
st.Push(5)
print(st.stackTop())
print(st.isFull())
st.Display()