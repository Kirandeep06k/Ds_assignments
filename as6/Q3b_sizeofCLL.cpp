#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class Linkedlist{
    public:
    Node* head;
    Linkedlist(){
        head = NULL;
    }
    void create(){
        int n;
        cout << "Enter number of nodes: ";
        cin >> n;
        if(n <= 0){
            cout << "List must have at least one node.";
            return;
        }
        Node* prev = nullptr;
        for(int i = 1; i <= n; i++){
            int val;
            cout << "Enter data for node " << i << ": ";
            cin >> val;
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
            }else{
                prev->next = newNode;
            }
            prev = newNode;
        }
        prev->next = head;
    }

    int findSize(){
        if(head == NULL) return 0;
        int count = 0;
        Node* temp = head;
        do{
            count++;
            temp = temp->next;
        }while(temp != head);
        return count;
    }
};

int main(){
    Linkedlist ob;
    ob.create();
    cout << "Size of Circular Linked List is: " << ob.findSize() << endl;
    return 0;
}
