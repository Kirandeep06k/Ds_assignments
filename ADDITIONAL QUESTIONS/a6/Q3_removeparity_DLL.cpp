#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    DoublyLinkedList(){
        head = NULL;
    }

    void create(){
        int n;
        cout << "Enter number of nodes: ";
        cin >> n;
        if(n <= 0){
            cout << "List must have at least one node.\n";
            return;
        }
        Node* prevNode = nullptr;
        for(int i = 1; i <= n; i++){
            int val;
            cout << "Enter data for node " << i << ": ";
            cin >> val;
            Node* newNode = new Node(val);
            if(head == NULL)
                head = newNode;
            else{
                prevNode->next = newNode;
                newNode->prev = prevNode;
            }
            prevNode = newNode;
        }
    }

    bool checkEvenParity(int n){
        int count = 0;
        while(n){
            if(n & 1)
                count++;
            n >>= 1;
        }
        return (count % 2 == 0);
    }

    void deleteNode(Node* del){
        if(head == NULL || del == NULL)
            return;
        if(head == del)
            head = del->next;
        if(del->next != NULL)
            del->next->prev = del->prev;
        if(del->prev != NULL)
            del->prev->next = del->next;
        delete del;
    }

    void deleteEvenParityNodes(){
        Node* ptr = head;
        Node* nextNode;
        while(ptr != NULL){
            nextNode = ptr->next;
            if(checkEvenParity(ptr->data))
                deleteNode(ptr);
            ptr = nextNode;
        }
    }

    void display(){
        if(head == NULL){
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data;
            if(temp->next != NULL)
                cout << " <=> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    DoublyLinkedList ob;
    ob.create();
    cout << "\nOriginal Doubly Linked List:\n";
    ob.display();
    ob.deleteEvenParityNodes();
    cout << "\nList after deleting even parity nodes:\n";
    ob.display();
    return 0;
}
