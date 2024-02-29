
class Node:
    def __init__(self,val):
        self.data = val
        self.next = None

class Stack:
    def __init__(self):
        self.top = None
        
    def Display(self):
        ptr = self.top
        while ptr:
            print(ptr.data, end=" ")
            ptr = ptr.next
    
    def Push(self, val: int) -> None:
        newNode = Node(val)
        if not newNode:
            print("Stack Overflow!")
        else:
            newNode.next = self.top
            self.top = newNode
            
    def Pop(self) -> int:
        x = -1
        if not self.top:
            print("Stack Underflow!")
        else:
            x = self.top.data
            self.top = self.top.next
        return x

    def Peek(self, pos: int) -> int:
        ptr = self.top
        x = -1
        while pos and ptr:
            ptr = ptr.next
            pos -= 1
        if ptr: x = ptr.data
        return x
    
    def isEmpty(self) -> bool:
        return self.top==None
    
    def isFull(self) -> bool:
        n = Node(0)
        return False if n else True
    
    def stackTop(self) -> int:
        if self.top:
            return self.top.data
        return -1
    
st = Stack()
st.Push(1)
st.Push(2)
print(st.Pop())
st.Push(3)
st.Push(4)
print(st.Peek(0))
print(st.Peek(1))
print(st.Peek(2))
st.Display()