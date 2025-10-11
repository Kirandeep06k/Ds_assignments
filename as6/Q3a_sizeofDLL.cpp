#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};

class Linkedlist{
    public:
    Node* head;
    Linkedlist(){
        head=NULL;
    }

    void create(){
        int n;
        cout<<"Enter number of nodes: ";
        cin>>n;
        if(n<=0){
            cout<<"List must have at least one node.";
            return;
        }
        Node* prevNode = nullptr;
        for(int i=1; i<=n; i++){
            int val;
            cout<<"Enter data for node "<<i<<": ";
            cin>>val;
            Node* newNode = new Node(val);
            if(head==NULL){
                head=newNode;
            }
            else{
                prevNode->next = newNode;
                newNode->prev = prevNode;
            }
            prevNode = newNode;
        }
    }

    int findSize(){
        int count=0;
        Node* temp=head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main(){
    Linkedlist ob;
    ob.create();
    cout<<"Size of Doubly Linked List is: "<< ob.findSize() <<endl;
    return 0;
}
