#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Linkedlist {
public:
    Node* head;
    Linkedlist() {
        head = NULL;
    }

    void create() {
        int n;
        cout << "Enter number of nodes: ";
        cin >> n;
        if (n <= 0) {
            cout << "List must have at least one node.";
            return;
        }
        Node* prev = nullptr;
        for (int i = 1; i <= n; i++) {
            int val;
            cout << "Enter data for node " << i << ": ";
            cin >> val;
            Node* newNode = new Node(val);
            if (head == NULL)
                head = newNode;
            else
                prev->next = newNode;
            prev = newNode;
        }
        prev->next = head; // make circular
    }

    // Function to check even parity (even number of 1s)
    int check(int n) {
        int onecount = 0;
        while (n) {
            if ((n & 1) == 1)
                onecount++;
            n = n >> 1;
        }
        return (onecount % 2 == 0);
    }

    // Delete head node
    void delAtHead() {
        if (head == NULL)
            return;

        Node* tail = head;
        while (tail->next != head)
            tail = tail->next;

        Node* temp = head;
        if (head->next == head)
            head = NULL;
        else {
            head = head->next;
            tail->next = head;
        }
        delete temp;
    }

    // Delete node with given value
    void delThisVal(int v) {
        if (head == NULL)
            return;

        if (head->data == v) {
            delAtHead();
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            if (temp->next->data == v) {
                Node* todel = temp->next;
                temp->next = todel->next;
                delete todel;
                return;
            }
            temp = temp->next;
        }
    }

    void delEvenParity(){
        if(head == NULL)
            return;
        bool changed;
        do{
            changed = false;
            Node* temp = head;
            if (check(head->data)){
                delAtHead();
                changed = true;
                if (head == NULL) return;
            }
            else{
                temp = head;
                while (temp->next != head){
                    if (check(temp->next->data)){
                        Node* todel = temp->next;
                        temp->next = todel->next;
                        delete todel;
                        changed = true;
                    } else {
                        temp = temp->next;
                    }
                    if (head == NULL) break;
                }
            }
        } while(changed); 
    }

    void display(){
        if (head == NULL){
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do{
            cout << temp->data << "->";
            temp = temp->next;
        }while(temp != head);
        cout << endl;
    }
};

int main() {
    Linkedlist ob;
    ob.create();
    cout << "Original Circular linked list:\n";
    ob.display();
    ob.delEvenParity();
    cout << "New Circular linked list:\n";
    ob.display();
    return 0;
}
