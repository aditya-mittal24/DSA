#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void Create()
    {
        int n, el;
        cout << "Enter no. of elements: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> el;
            Node *newNode, *ptr;
            newNode = new Node;
            newNode->data = el;
            newNode->next = NULL;
            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
            }
        }
    }

    void Display()
    {
        Node *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << ' ';
            ptr = ptr->next;
        }
    }

    void Append(int val)
    {
        Node *ptr, *newNode;
        newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }

    void ReverseDisplay(Node *ptr = NULL)
    {
        if (ptr != NULL)
        {
            ReverseDisplay(ptr->next);
            printf("%d ", ptr->data);
        }
    }

    int Length()
    {
        Node *ptr;
        ptr = head;
        int count = 0;
        while (ptr != NULL)
        {
            count += 1;
            ptr = ptr->next;
        }
        return count;
    }

    int Sum()
    {
        Node *ptr;
        ptr = head;
        int sum = 0;
        while (ptr != NULL)
        {
            sum += ptr->data;
            ptr = ptr->next;
        }
        return sum;
    }

    int Max()
    {
        Node *ptr;
        ptr = head;
        int max = INT_MIN;
        while (ptr)
        {
            max = max < ptr->data ? ptr->data : max;
            ptr = ptr->next;
        }
        return max;
    }

    int Search(int val)
    {
        Node *ptr;
        ptr = head;
        while (ptr)
        {
            if (ptr->data == val)
                return 1;
            ptr = ptr->next;
        }
        return 0;
    }

    int MoveToHeadSearch(int val)
    {
        Node *ptr, *prevPtr;
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == val)
            {
                prevPtr->next = ptr->next;
                ptr->next = head;
                head = ptr;
                return 1;
            }
            prevPtr = ptr;
            ptr = ptr->next;
        }
        return 0;
    }
    void Insert(int val, int pos)
    {
        Node *newNode;
        newNode = new Node();
        newNode->data = val;
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *ptr;
            ptr = head;
            for (int i = 0; i < pos - 1 && ptr; i++)
            {
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }

    void SortedInsert(int val)
    {
    }

    int Delete(int pos)
    {
        Node *ptr, *prevPtr;
        int data;
        ptr = head;
        if (pos == 0)
        {
            head = ptr->next;
            data = ptr->data;
            delete ptr;
            return data;
        }
        else
        {
            prevPtr = NULL;
            for (int i = 0; i < pos && ptr; i++)
            {
                prevPtr = ptr;
                ptr = ptr->next;
            }
            if (ptr)
            {
                prevPtr->next = ptr->next;
                data = ptr->data;
                delete ptr;
                return data;
            }
        }
        return -1;
    }

    bool isSorted()
    {
        Node *ptr;
        int x = INT_MIN;
        ptr = head;
        while (ptr)
        {
            if (x > ptr->data)
                return false;
            x = ptr->data;
            ptr = ptr->next;
        }
        return true;
    }

    void RemoveDuplicates()
    {
        Node *prevPtr, *ptr;
        prevPtr = head;
        ptr = head->next;
        while (ptr)
        {
            if (prevPtr->data == ptr->data)
            {
                prevPtr->next = ptr->next;
                delete ptr;
                ptr = prevPtr->next;
            }
            else
            {
                prevPtr = ptr;
                ptr = ptr->next;
            }
        }
    }
    void Reverse()
    {
    }

    void RReverse(Node *ptr1, Node *ptr2)
    {
    }

    void Concatenate(LinkedList ll2)
    {
    }

    void Merge(LinkedList ll2)
    {
    }
    int CheckLoop()
    {
    }
};

int main()
{
    // int val, pos;
    // cout << "Enter position: ";
    // cin >> pos;
    // val = Delete(pos);
    // cout << endl << val << endl;
    // if (isSorted())
    //     cout << "Sorted" << endl;
    // else
    //     cout << "Unsorted" << endl;
    LinkedList ll, ll2;
    int ch = 1, el, pos;
    while (ch > 0 && ch <= 20)
    {
        printf("\n-----MENU-----\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Append\n");
        printf("4. Insert\n");
        printf("5. Reverse Display\n");
        printf("6. Length\n");
        printf("7. Sum\n");
        printf("8. Max\n");
        printf("9. Search\n");
        printf("10. Move to head search\n");
        printf("11. Sorted Insert\n");
        printf("12. Delete\n");
        printf("13. Sorted or not\n");
        printf("14. Remove Duplicates\n");
        printf("15. Reverse\n");
        printf("16. Recursive Reverse\n");
        printf("17. Concatenate\n");
        printf("18. Merge\n");
        printf("19. Check Loop\n");
        printf("20. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            ll.Create();
            break;
        case 2:
            ll.Display();
            break;
        case 3:
            printf("Enter element to be appended: ");
            scanf("%d", &el);
            ll.Append(el);
            break;
        case 4:
            printf("Enter element to be inserted: ");
            scanf("%d", &el);
            printf("Enter position: ");
            scanf("%d", &pos);
            ll.Insert(el, pos);
            break;
        case 5:
            ll.ReverseDisplay();
            break;
        case 6:
            printf("Length of the linked list: %d", ll.Length());
            break;
        case 7:
            printf("Sum of the linked list: %d", ll.Sum());
            break;
        case 8:
            printf("Max element of the linked list: %d", ll.Max());
            break;
        case 9:
            printf("Enter element to be searched: ");
            scanf("%d", &el);
            int present = ll.Search(el);
            if (present)
                printf("Element is present!");
            else
                printf("Element not found!");
            break;
        case 10:
            printf("Enter element to be searched: ");
            scanf("%d", &el);
            int present = ll.MoveToHeadSearch(el);
            if (present)
            {
                printf("Element is present!");
            }
            else
                printf("Element not found!");
            break;
        case 11:
            printf("Enter element to be inserted: ");
            scanf("%d", &el);
            ll.SortedInsert(el);
            break;
        case 12:
            printf("Enter position: ");
            scanf("%d", &pos);
            ll.Delete(pos);
            printf("Element Deleted!");
            break;
        case 13:
            if (ll.isSorted() == 0)
                printf("Linked list is not sorted.");
            else
                printf("Linked list is sorted");
            break;
        case 14:
            ll.RemoveDuplicates();
            ll.Display();
            break;
        case 15:
            ll.Reverse();
            ll.Display();
            break;
        case 16:
            ll.RReverse(NULL, ll.head);
            ll.Display();
            break;
        case 17:
            ll2.Create();
            ll.Concatenate(ll2);
            ll2.head = NULL;
            break;
        case 18:
            ll2.Create();
            ll.Merge(ll2);
            ll2.head = NULL;
            break;
        case 19:
            if (ll.CheckLoop())
            {
                printf("Loop Detected!");
            }
            else
            {
                printf("No loop.");
            }
            break;
        default:
            return 0;
        }
    }
    return 0;
}