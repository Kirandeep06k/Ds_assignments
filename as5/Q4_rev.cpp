#include <iostream>
#include <vector>
using namespace std;

class Node{
    public :
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* rev(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;  
}

void print(Node* head){
    Node *temp = head;
    while(temp){
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    if(n == 0){
        cout << "List is empty" << endl;
        return 0;
    }
    int val;
    cout << "Enter value for node 1: ";
    cin >> val;
    Node* head = new Node(val);
    Node* temp = head;
    for(int i = 2; i <= n; i++){
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        temp->next = new Node(val);
        temp = temp->next;
    }


    cout << "Original Linked List: \n";
    print(head);

    head = rev(head);
    cout << "Reversed Linked List: \n";
    print(head);
    return 0;
}