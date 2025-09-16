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

Node* occurence(Node* head, int k, int &c){ // or int& c
    Node *cur = head;
    Node* prev = nullptr;
    while(cur!=nullptr){

        if(cur->data==k){
            c++;
            if(prev == nullptr) {
                head = cur->next;
            } 
          
            else{
                prev->next = cur->next;
            }
            cur = cur->next;
        }

        else{
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
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
    int val,key,count=0;

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

    cout << "Enter key" << endl;
    cin >> key;
    cout << "Linked List: \n";
    print(head);
    head = occurence(head, key, count);
    cout << "New Linked List: \n";
    print(head);
    cout << "Count : " << count << endl;
    return 0;
}