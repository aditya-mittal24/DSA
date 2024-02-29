class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        
class CircularLL:
    def __init__(self):
        self.head = None
        
    def Create(self):
        n = int(input("Enter no. of elements: "))
        for i in range(n):
            el = int(input(f"Enter element {i+1}: "))
            newNode = Node(el)
            if self.head==None:
                self.head = newNode
                newNode.next = newNode
                last = newNode
            else:
                last.next = newNode
                newNode.next = self.head
                last = newNode
    
    def Display(self):
        ptr = self.head
        while(ptr):
            print(ptr.data, end=" ")
            ptr = ptr.next
            if ptr==self.head: break
            
cll = CircularLL()
cll.Create()
cll.Display()