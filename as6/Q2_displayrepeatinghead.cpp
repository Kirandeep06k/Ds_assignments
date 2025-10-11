#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
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
    if (n<=0){
        cout << "List must have at least one node.";
        return ;
    }
    Node* prev = nullptr;
    for (int i = 1; i <= n; i++){
        int val;
        cout << "Enter data for node " << i << ": ";
        cin >> val;
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
        else{
            prev->next = newNode;
        }
        prev = newNode; 
       }
       prev->next = head;
    }

    void display(){
    Node* temp = head;
    do{
        cout << temp->data << "\t";
        temp = temp->next;
    }while(temp!=head);
    cout << head->data;
    cout << endl;
   }

};

int main(){
    Linkedlist ob;
    ob.create();
    cout << "Displaying Linked list : \n";
    ob.display();
    return 0;
}