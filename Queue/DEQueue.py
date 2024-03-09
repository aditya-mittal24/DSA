
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None
        
class Dequeue:
    def __init__(self):
        self.front = None
        self.rear = None
        
    def Display(self):
        ptr = self.front
        while ptr:
            print(ptr.data, end=" ")
            ptr = ptr.next
        print()
        
    def pushright(self, val):
        newNode = Node(val)
        if not newNode:
            print("Dequeue is full!")
        else:
            if not self.front:
                self.front=self.rear=newNode
            else:
                self.rear.next = newNode
                self.rear = newNode
    
    def pushleft(self, val):
        newNode = Node(val)
        if not newNode:
            print("Dequeue is full!")
        else:
            newNode.next = self.front
            self.front = newNode
            if not self.rear: self.rear = self.front
            
    def popright(self):
        x = -1
        if not self.front:
            print("Dequeue is empty!")
        else:
            x = self.rear.data
            if self.front==self.rear:
                self.front = self.rear = None
            else:
                ptr = self.front
                while ptr.next != self.rear:
                    ptr = ptr.next
                self.rear = ptr
                self.rear.next = None
        return x

    def popleft(self):
        x = -1
        if not self.front:
            print("Dequeue is empty!")
        else:
            x = self.front.data
            self.front = self.front.next
    
if __name__=="__main__":
    dq = Dequeue()
    dq.pushright(3)
    dq.pushright(4)
    dq.pushright(5)
    dq.pushleft(2)
    dq.pushleft(1)
    dq.pushleft(0)
    dq.popleft()
    dq.popright()
    dq.Display()
                