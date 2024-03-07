
class Queue:
    def __init__(self,size=10):
        self.size = size
        self.front = -1
        self.rear = -1
        self.Q = [0] * size
        
    def Display(self):
        for i in range(self.front+1, self.rear+1):
            print(self.Q[i], end=" ")
    
    def enqueue(self, val):
        if self.rear==self.size-1:
            print("Queue is full!")
        else:
            self.rear += 1
            self.Q[self.rear] = val
    
    def dequeue(self):
        x = -1
        if self.rear==self.front:
            print("Queue is empty!")
        else:
            self.front += 1
            x = self.Q[self.front]
        return x
    
if __name__=="__main__":
    q = Queue(5)
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    q.enqueue(5)
    q.dequeue()
    q.dequeue()
    q.Display()