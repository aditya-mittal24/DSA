from Stack import Stack


class QueueUsingStack:
    def __init__(self):
        self.stack1 = Stack()
        self.stack2 = Stack()

    def Display(self):
        self.stack2.Display()
        self.stack1.Display()
        print()

    def enqueue(self, val):
        self.stack1.Push(val)

    def dequeue(self):
        x = -1
        if self.stack2.isEmpty():
            if self.stack1.isEmpty():
                print("Queue is empty!")
                return x
            else:
                while not self.stack1.isEmpty():
                    self.stack2.Push(self.stack1.Pop())
        return self.stack2.Pop()


if __name__ == '__main__':
    q = QueueUsingStack()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    q.Display()
    q.dequeue()
    q.dequeue()
    q.Display()
    q.enqueue(5)
    q.enqueue(6)
    q.Display()
