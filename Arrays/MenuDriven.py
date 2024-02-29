from Array import Array

size = int(input('Enter size of the array: '))
arr = Array([],size,0)
ch = 1
while ch<13:
    print("Menu")
    print("1. Append")
    print("2. Insert")
    print("3. Delete")
    print("4. Search")
    print("5. Sum")
    print("6. Max")
    print("7. Min")
    print("8. Average")
    print("9. Rearrange")
    print("10. Reverse")
    print("11. Insert Sort")
    print("12. Display")
    print("13. Exit")

    ch = int(input("Enter your choice: "))
    
    if ch==1:
        x = int(input("Enter the element: "))
        arr.append(x)
    elif ch==2:
        x = int(input("Enter the element: "))
        index = int(input("Enter the index: "))
        arr.insert(index, x)
    elif ch==3:
        index = int(input("Enter index to be deleted: "))
        arr.delete(index)
    elif ch==4:
        element = int(input("Enter element to be searched: "))
        index = arr.BinarySearch(element)
        if index==-1:
            print("Element not found")
        else:
            print(f"Element found at {index}")
    elif ch==5:
        s = arr.sum()
        print(f"Sum of the array: {s}")
    elif ch==6:
        print(f"Max element in the array: {arr.max()}")
    elif ch==7:
        print(f"Min element in the array: {arr.min()}")
    elif ch==8:
        print(f"Average of the array: {arr.avg()}")
    elif ch==9:
        arr.Rearrange()
        arr.display()
    elif ch==10:
        arr.reverse()
        arr.display()
    elif ch==11:
        x = int(input("Enter the element: "))
        arr.InsertSort(x)
    elif ch==12:
        arr.display()