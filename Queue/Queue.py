
class Node:
    def __init__(self,val):
        self.data = val
        self.next = None
        
class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        
    def Display(self):
        ptr = self.front
        while ptr:
            print(ptr.data, end=" ")
            ptr = ptr.next
        print()
        
    def enqueue(self, val):
        newNode = Node(val)
        if not newNode:
            print("Queue is full!")
        else:
            newNode.next = None
            if self.front==None:
                self.front = self.rear = newNode
            else:
                self.rear.next = newNode
                self.rear = newNode
    
    def dequeue(self):
        x = -1
        if self.front==None:
            print("Queue is empty!")
        else:
            x = self.front.data
            self.front = self.front.next
        return x
    
if __name__=='__main__':
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    q.enqueue(5)
    q.dequeue()
    q.dequeue()
    q.Display()