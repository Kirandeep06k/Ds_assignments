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

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;       
        fast = fast->next->next;     
    }
    return slow;  
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
    cout << "Linked List: \n";
    temp = head;
    while(temp){
        cout << temp->data << "\t";
        temp = temp->next;
    }
    Node* mid = findMiddle(head);
    cout << "\nMiddle node : " << mid->data << endl;
    return 0;
}