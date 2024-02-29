#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Create(struct Node *start)
{
    struct Node *last, *newNode;
    int n, el;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &el);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = el;
        newNode->next = NULL;
        if (start == NULL)
        {
            start = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }
    return start;
}

void Append(struct Node *head, int val)
{
    struct Node *ptr, *newNode;
    ptr = head;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
    newNode->next = NULL;
}

void Display(struct Node *start)
{
    struct Node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void ReverseDisplay(struct Node *ptr)
{
    if (ptr != NULL)
    {
        ReverseDisplay(ptr->next);
        printf("%d ", ptr->data);
    }
}

int Length(struct Node *head)
{
    int count = 0;
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        count += 1;
        ptr = ptr->next;
    }
    return count;
}

int Sum(struct Node *head)
{
    int sum = 0;
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

int Max(struct Node *head)
{
    int max = INT_MIN;
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (max < ptr->data)
            max = ptr->data;
        ptr = ptr->next;
    }
    return max;
}

struct Node *Search(struct Node *head, int val)
{
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

struct Node *MoveToHeadSearch(struct Node *head, int val)
{
    struct Node *ptr, *prevPtr;
    ptr = head;
    prevPtr = NULL;
    while (ptr != NULL)
    {
        if (ptr->data == val && ptr != head)
        {
            prevPtr->next = ptr->next;
            ptr->next = head;
            return ptr;
        }
        else if (ptr->data == val && ptr == head)
            return head;
        prevPtr = ptr;
        ptr = ptr->next;
    }
    return NULL;
}

struct Node* Insert(struct Node *head, int val, int pos)
{
    if (pos == 0)
    {
        struct Node *newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Node *ptr, *newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        ptr = head;
        for (int i = 0; i < pos - 1 && ptr; i++)
        {
            ptr = ptr->next;
        }
        newNode->data = val;
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    return head;
}

struct Node* SortedInsert(struct Node *head, int val)
{
    struct Node *newNode, *ptr, *prevPtr;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    ptr = head;
    prevPtr = NULL;
    while (ptr && ptr->data < val)
    {
        prevPtr = ptr;
        ptr = ptr->next;
    }
    if (!prevPtr)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        prevPtr->next = newNode;
        newNode->next = ptr;
    }
    return head;
}

struct Node * Delete(struct Node *head, int pos)
{
    struct Node *ptr, *prevPtr;
    ptr = head;
    if (pos == 0)
    {
        head = ptr->next;
        free(ptr);
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
            free(ptr);
        }
    }
    return head;
}

int isSorted(struct Node *head)
{
    struct Node *ptr;
    int prevVal = INT_MIN;
    ptr = head;
    while (ptr)
    {
        if (prevVal > ptr->data)
            return 0;
        prevVal = ptr->data;
        ptr = ptr->next;
    }
    return 1;
}

void RemoveDuplicates(struct Node *head)
{
    struct Node *ptr, *prevPtr;
    prevPtr = head;
    ptr = prevPtr->next;
    while (ptr)
    {
        if (prevPtr->data == ptr->data)
        {
            prevPtr->next = ptr->next;
            free(ptr);
            ptr = prevPtr->next;
        }
        else
        {
            prevPtr = ptr;
            ptr = ptr->next;
        }
    }
}

struct Node* Reverse(struct Node *head)
{
    struct Node *prevPtr, *ptr, *nextPtr;
    prevPtr = NULL;
    ptr = NULL;
    nextPtr = head;
    while (nextPtr)
    {
        prevPtr = ptr;
        ptr = nextPtr;
        nextPtr = nextPtr->next;
        ptr->next = prevPtr;
    }
    head = ptr;
    return head;
}

struct Node* RReverse(struct Node *prevPtr, struct Node *ptr)
{
    if (ptr == NULL)
    {
        return prevPtr;
    }
    else
    {
        struct Node *start = RReverse(ptr, ptr->next);
        ptr->next = prevPtr;
        return start;
    }
}

void Concatenate(struct Node *head1, struct Node *head2)
{
    struct Node *ptr;
    ptr = head1;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = head2;
    head2 = NULL;
}

struct Node *Merge(struct Node *head1, struct Node *head2)
{
    struct Node *first, *second, *third, *last;
    first = head1;
    second = head2;
    third = NULL;
    last = NULL;
    if (first->data < second->data)
    {
        third = last = first;
        first = first->next;
        third->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        third->next = NULL;
    }
    while (first && last)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    while (first)
    {
        last->next = first;
        last = first;
        first = first->next;
        last->next = NULL;
    }
    while (second)
    {
        last->next = second;
        last = last->next;
        second = second->next;
        last->next = NULL;
    }
    return third;
}

int CheckLoop(struct Node *start)
{
    struct Node *ptr1, *ptr2;
    ptr1 = start;
    ptr2 = start;
    while (ptr1 && ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        ptr2 = ptr2 ? ptr2->next : ptr2;
        if (ptr1 == ptr2)
        {
            return 1;
        }
    }
    return 0;
}

struct Node* Destroy(struct Node* head){
    struct Node *ptr, *nextPtr;
    ptr = head;
    while (ptr){
        nextPtr = ptr->next;
        free(ptr);
        ptr = nextPtr;
    }
    return NULL;
}

int MiddleElement(struct Node *head){
    struct Node *ptr;
    ptr = head;
    int length=0;
    while (ptr){
        length += 1;
        ptr = ptr->next;
    }
    
}

int main()
{
    struct Node *head = NULL;
    struct Node *head2 = NULL;
    struct Node *ptr;
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
        switch (ch){
            case 1:
                head = Create(head);
                break;
            case 2:
                Display(head);
                break;
            case 3:
                printf("Enter element to be appended: ");
                scanf("%d", &el);
                Append(head, el);
                break;
            case 4:
                printf("Enter element to be inserted: ");
                scanf("%d", &el);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = Insert(head, el,pos);
                break;
            case 5:
                ReverseDisplay(head);
                break;
            case 6:
                printf("Length of the linked list: %d", Length(head));
                break;
            case 7:
                printf("Sum of the linked list: %d", Sum(head));
                break;
            case 8:
                printf("Max element of the linked list: %d", Max(head));
                break;
            case 9:
                printf("Enter element to be searched: ");
                scanf("%d", &el);
                ptr = Search(head, el);
                if (ptr) 
                    printf("Element is present!");
                else
                    printf("Element not found!");
                break;
            case 10:
                printf("Enter element to be searched: ");
                scanf("%d", &el);
                ptr = MoveToHeadSearch(head, el);
                if (ptr){
                    head = ptr;
                    printf("Element is present!");
                }
                else
                    printf("Element not found!");
                break;
            case 11:
                printf("Enter element to be inserted: ");
                scanf("%d", &el);
                head = SortedInsert(head, el);
                break;
            case 12:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = Delete(head, pos);
                printf("Element Deleted!");
                break;
            case 13:
                if (isSorted(head)==0)
                    printf("Linked list is not sorted.");
                else
                    printf("Linked list is sorted");
                break;
            case 14:
                RemoveDuplicates(head);
                Display(head);
                break;
            case 15:
                head = Reverse(head);
                Display(head);
                break;
            case 16:
                head = RReverse(NULL, head);
                Display(head);
                break;
            case 17:
                head2 = Create(head2);
                Concatenate(head, head2);
                head2 = NULL;
                break;
            case 18:
                head2 = Create(head2);
                Merge(head, head2);
                head2 = NULL;
                break;
            case 19:
                if (CheckLoop(head)) {
                    printf("Loop Detected!");
                } else{
                    printf("No loop.");
                }
                break;
            default:
                Destroy(head);
                Destroy(head2);
                return 0;
        }
    }
    return 0;
}