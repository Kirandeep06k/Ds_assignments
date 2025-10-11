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

    pair<Node *, Node *> splitList(){
        struct Node* t = head;
        int c = 1;
        while(t->next != head){
            c++;
            t = t->next;
        }
        struct Node* fp = head;
        struct Node* sp = head;
        while(fp->next != head && fp->next->next != head){
            sp = sp->next;
            fp = fp->next->next;
        }
        struct Node* head2 = sp->next;
        sp->next = head;
        t->next = head2;
        return {head,head2};
    }
};

void display(Node* head){
    Node* temp = head;
    do{
        cout << temp->data << "->";
        temp = temp->next;
    }while(temp!=head);
    cout << endl;
   }

int main(){
    Linkedlist ob;
    ob.create();
    pair<Node*, Node*> res = ob.splitList();
    cout << "First half: ";
    display(res.first);
    cout << "Second half: ";
    display(res.second);
    return 0;
}
