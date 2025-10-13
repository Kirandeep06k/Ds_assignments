#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList{
private:
    Node* head;
public:
    CircularLinkedList(){ 
        head = nullptr; 
    }
    void create(){
        int n;
        cout << "Enter number of nodes: ";
        cin >> n;
        if (n <= 0) {
            cout << "List must have at least one node.\n";
            return;
        }
        Node* last = nullptr;
        for(int i = 1; i <= n; i++){
            int val;
            cout << "Enter data for node " << i << ": ";
            cin >> val;
            Node* newNode = new Node(val);
            if(!head){
                head = newNode;
                head->next = head;
                last = head;
            }
            else{
                newNode->next = head;
                last->next = newNode;
                last = newNode;
            }
        }
    }

    bool isEvenParity(int num){
        int count = 0;
        while (num) {
            count += (num & 1);
            num >>= 1;
        }
        return (count % 2 == 0);
    }

    void deleteEvenParityNodes(){
        if(!head) 
        return;

        bool deleted;
        do{
            deleted = false;
            Node* current = head;
            Node* prev = nullptr;
            Node* tail = head;
            while(tail->next != head){
                tail = tail->next;
            }
            prev = tail;
            do {
                if (isEvenParity(current->data)){
                    if (current == head){
                        head = head->next;
                        prev->next = head;
                        delete current;
                        deleted = true;
                        break; 
                    }
                    else{
                        prev->next = current->next;
                        delete current;
                        deleted = true;
                        break;
                    }
                }
                prev = current;
                current = current->next;
            }while(current != head);
            
        } while(deleted && head);
    }

    void display(){
        if(!head){
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        do{
            cout << temp->data;
            temp = temp->next;
            if (temp != head) cout << " -> ";
        }while(temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList ob;
    ob.create();
    cout << "\nOriginal Circular Linked List:\n";
    ob.display();
    ob.deleteEvenParityNodes();
    cout << "\nList after deleting even parity nodes:\n";
    ob.display();
    return 0;
}