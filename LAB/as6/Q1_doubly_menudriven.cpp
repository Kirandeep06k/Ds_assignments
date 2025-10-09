#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        data = d; 
        prev = next = NULL;
    }
};

Node* insertAtBeginning(Node* head, int v) {
    Node* newnode = new Node(v);
    if(head) 
    head->prev = newnode;
    newnode->next = head;
    return newnode;
}

Node* insertAtEnd(Node* head, int v) {
    Node* newnode = new Node(v);
    if(!head) 
    return newnode;
    Node* temp = head;
    while(temp->next)
    temp = temp->next;
    
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

Node* insertAfter(Node* head, int x, int v){
    Node* temp = head;
    while(temp){
        if(temp->data == x){
            Node* newnode = new Node(v);
            newnode->next = temp->next;
            if(temp->next) 
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
            return head;
        }
        temp = temp->next;
    }
    cout << "Value not found!\n";
    return head;
}

Node* deleteNode(Node* head, int v){
    if(!head) return NULL;
    Node* temp = head;
    while(temp){
        if(temp->data == v){
            if(temp->prev) 
            temp->prev->next = temp->next;
            else 
            head = temp->next;
            if(temp->next) 
            temp->next->prev = temp->prev;
            delete temp;
            return head;
        }
        temp = temp->next;
    }
    cout << "Value not found!\n";
    return head;
}

void search(Node* head, int v){
    Node* temp = head;
    int pos = 1;
    while(temp) {
        if(temp->data == v){
            cout << v << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found\n";
}

void display(Node* head){
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    int ch, v, x;
    while(true){
        cout << "\nMenu:\n"
             << "1 Insert at beginning\n"
             << "2 Insert at end\n"
             << "3 Insert after a node\n"
             << "4 Delete a node\n"
             << "5 Search a node\n"
             << "6 Display\n"
             << "7 Exit\n"
             << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1:
            cout << "Enter value: "; 
            cin >> v; head = insertAtBeginning(head, v); 
            break;
            case 2: 
            cout << "Enter value: "; 
            cin >> v; 
            head = insertAtEnd(head, v);
            break;
            case 3:
            cout << "Enter value after which to insert and new value: ";
            cin >> x >> v; 
            head = insertAfter(head, x, v);
            break;
            case 4:
            cout << "Enter value to delete: "; 
            cin >> v;
            head = deleteNode(head, v);
            break;
            case 5: 
            cout << "Enter value to search: "; 
            cin >> v; 
            search(head, v); 
            break;
            case 6:
            display(head); 
            break;
            case 7: 
            cout << "Exiting...\n";
            return 0;
            default: 
            cout << "Invalid choice!\n";
        }
    }
}