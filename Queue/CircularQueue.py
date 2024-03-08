
class CircularQueue:
    def __init__(self,size=10):
        self.size = size+1
        self.front = 0
        self.rear = 0
        self.Q = [0] * self.size
        
    def Display(self):
        ptr = self.front
        while(ptr!=self.rear):
            ptr = (ptr+1)%self.size
            print(self.Q[ptr],end=" ")
        print()
    
    def Enqueue(self, val):
        if (self.rear+1)%self.size==self.front:
            print("Queue is full!")
        else:
            self.rear = (self.rear+1)%self.size
            self.Q[self.rear] = val
    
    def Dequeue(self):
        x = -1
        if self.front==self.rear:
            print("Queue is empty!")
        else:
            self.front = (self.front+1)%self.size
            x = self.Q[self.front]
        return x
    
if __name__=="__main__":
    q = CircularQueue(5)
    q.Enqueue(1)
    q.Enqueue(2)
    q.Enqueue(3)
    q.Enqueue(4)
    q.Enqueue(5)
    q.Enqueue(6)
    q.Display()
    q.Dequeue()
    q.Dequeue()
    q.Display()
    q.Enqueue(6)
    q.Enqueue(7)
    q.Enqueue(8)
    q.Dequeue()
    q.Display()