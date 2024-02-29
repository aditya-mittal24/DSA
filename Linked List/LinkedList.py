
class Node:
    def __init__(self, item=None):
        self.data = item
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def Create(self):
        n = int(input("Enter no. of elements: "))
        for i in range(n):
            el = int(input(f"Enter element {i+1}: "))
            new_node = Node(el)
            if self.head == None:
                self.head = new_node
            else:
                ptr = self.head
                while ptr.next != None:
                    ptr = ptr.next
                ptr.next = new_node

    def Display(self):
        if self.head == None:
            print("Linked List empty!!")
        else:
            ptr = self.head
            while ptr != None:
                print(ptr.data)
                ptr = ptr.next

    def ReverseDisplay(self, node):
        if node != None:
            self.ReverseDisplay(node.next)
            print(node.data)

    def CountNodes(self):
        ptr = self.head
        cnt = 0
        while ptr != None:
            cnt += 1
            ptr = ptr.next
        return cnt

    def Sum(self):
        ptr = self.head
        sum = 0
        while ptr != None:
            sum += ptr.data
            ptr = ptr.next
        return sum
    
    def MoveToHeadSearch(self, val):
        ptr = self.head
        prevPtr = None
        while ptr!=None:
            if ptr.data == val:
                if ptr==self.head: return self.head
                prevPtr.next = ptr.next
                ptr.next = self.head
                self.head = ptr
                return ptr
            prevPtr = ptr
            ptr = ptr.next
        return False

    def Insert(self,val,pos):
        newNode = Node(val)
        if pos == 0:
            newNode.next = self.head
            self.head = newNode
        else:
            ptr = self.head
            for _ in range(pos-1):
                ptr = ptr.next
            newNode.next = ptr.next
            ptr.next = newNode
            
    def SortedInsert(self, val) -> None:
        ptr = self.head
        new_node = Node(val)
        prev = None
        while ptr.data<val:
            prev = ptr
            ptr = ptr.next
        if prev: prev.next = new_node
        new_node.next = ptr
    
    def Delete(self, pos):
        i = 0
        prev = None
        ptr = self.head
        while i<pos and ptr:
           prev = ptr
           ptr = ptr.next
           i += 1
        if prev: prev.next = ptr.next
        del ptr 
    
    def isSorted(self):
        ptr = self.head
        prev = float('-inf')
        while ptr:
            if ptr.data<prev:
                return False
            prev = ptr.data
            ptr = ptr.next
        return True
    
    def RemoveDuplicates(self):
        ptr1 = self.head.next
        ptr2 = self.head
        while ptr1:
            if ptr1.data == ptr2.data:
                ptr2.next = ptr1.next
                del ptr1
                ptr1 = ptr2.next
            else:
                ptr2 = ptr1
                ptr1 = ptr1.next
        
    
    def Reverse(self):
        prevPtr = None
        ptr = None
        nextPtr = self.head
        while nextPtr:
            prevPtr = ptr
            ptr = nextPtr
            nextPtr = nextPtr.next
            ptr.next = prevPtr
        self.head = ptr
    
    def RReverse(self, prevPtr, ptr):
        if ptr.next==None:
            ptr.next = prevPtr
            self.head = ptr
        else:
            self.RReverse(ptr, ptr.next)
            ptr.next = prevPtr
    
    def Concatenate(self, ll2):
        ptr = self.head
        while ptr.next:
            ptr = ptr.next
        ptr.next = ll2.head
    
    def Merge(self, ll2):
        first = self.head
        second = ll2.head
        third, last = None, None
        if first.data<second.data:
            third = first
            last = first
            first = first.next
        else:
            third = second
            second = last
            second = second.next
        while first and second:
            if first.data<second.data:
                last.next = first
                last = last.next
                first = first.next
                last.next = None
            else:
                last.next = second
                last = last.next
                second = second.next
                last.next = None
        while first:
            last.next = first
            last = last.next
            first = first.next
            last.next = None
        while second:
            last.next = second
            last = last.next
            second = second.next
            last.next = None
        self.head = third
        
    def CheckLoop(self):
        ptr1 = self.head
        ptr2 = self.head
        while ptr1 and ptr2:
            ptr1 = ptr1.next
            ptr2 = ptr2.next
            ptr2 = ptr2.next if ptr2 else None
            if ptr1==ptr2:
                return True
        return False

  
# 1  2  3  4  5 7
# ^        ^  ^
# t        l  f
# 6 8
# ^
# second

linked_list = LinkedList()
linked_list2 = LinkedList()

linked_list.Create()
linked_list2.Create()

# linked_list.Display()

# linked_list.ReverseDisplay(linked_list.head)

# print(linked_list.Sum())

# p = linked_list.MoveToHeadSearch(4)

# pos = int(input("Enter position to be deleted: "))

linked_list.Concatenate(linked_list2)

linked_list.Display()
