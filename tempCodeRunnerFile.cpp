#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void Display(Node *head){
    Node *ptr;
    ptr = head;
    while (ptr!=NULL){
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
}

int main(){
    Node *head = NULL;
    int n,el;
    cout << "Enter no. of elements: ";
    cin >> n;
    for(int i = 0;i<n; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> el;
        Node *newNode, *ptr;
        newNode = new Node;
        newNode->data = el;
        newNode->next = NULL;
        if (head == NULL){
            head = newNode;
        }
        else{
            ptr = head;
            while (ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    Display(head);
}