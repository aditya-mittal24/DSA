#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLL{
    private:
    Node *head;
    public:
    CircularLL(){
        head = NULL;
    }
    void Create(){
        int n, el;
        cout << "Enter no. of elements: ";
        cin >> n;
        for (int i = 0; i<n; i++){
            cout << "Enter element " << i+1 << ": ";
            cin >> el;
            Node *newNode;
            newNode = new Node();
            newNode->data = el;
            if (head==NULL){
                head = newNode;
                newNode->next = newNode;
            }
        }
    }

    void Display(){
        Node *ptr;
        ptr = head;
        do {
            cout << ptr->data << ' ';
            ptr = ptr->next;
        } while (ptr!=head);
    }
};

int main(){
    CircularLL ll;
    ll.Create();
    ll.Display();
    return 0;
}