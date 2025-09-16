#include <iostream>
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

    Node(int data1, Node* next1){  // extra constructor if doing this: Node* temp = new Node(v,head);
        data = data1;
        next = next1;
    }
};

Node* insertatBeginning(Node* head, int v){
    Node* temp = new Node(v,head);
    return temp;
}

Node* insertatEnd(Node* head, int v){
    if(head==NULL){
        return new Node(v);
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newnode = new Node(v); // this means the last. newly added points to null
    temp->next = newnode; 
    return head;
}

Node* insertinBetween(Node* head, int v, int x){
    if(head==NULL){
        return NULL; 
    }

    if(head->data==x){
        return new Node(v, head); 
    }

    Node* temp = head; 
    while(temp->next!=NULL){
        if(temp->next->data==x){
            Node* z = new Node(v);
            z->next = temp->next;
            temp->next = z;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* deletefromBeginning(Node* head){
    if(head==NULL){
        cout << "List is empty. Nothing to delete.\n";
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deletefromEnd(Node* head){
    if(head==NULL || head->next == NULL){
        cout << "List is empty. Nothing to delete.\n";
        return NULL;
    }

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deletethisValue(Node* head, int v){
    if(head==NULL){
        cout << "List is empty. Nothing to delete.\n";
        return head;
    }
    if(head->data==v){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp!=NULL){
        if(temp->data==v){
            prev->next =  prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int search(Node* head, int v){
    Node* temp = head;
    int pos = 1;
    while(temp){
        if(temp->data==v){
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

void display(Node* head){
    cout << "Displaying Linked list : \n";
    Node* temp = head;
    while(temp){
        cout << temp->data << "\t";
        temp = temp->next;
    }
}

int main(){
    int c,v,x,s,pos;
    Node* head = NULL;
    while(true){
    cout << "\nEnter choice\n";
    cout << "Menu\n"
    << "1 Insertion at the beginning\n"
    << "2 Insertion at the end\n"
    << "3 Insertion in between(before)\n"
    << "4 Deletion from the beginning\n"
    << "5 Deletion from the end\n"
    << "6 Deletion of a specific node\n"
    << "7 Search for a node and display its position from head\n"
    << "8 Display all the node values\n"
    << "9 Exit\n" << endl;
    cin >> c;
    switch(c){
        case 1:
        cout << "Enter value to be inserted\n";
        cin >> v;
        head = insertatBeginning(head, v);
        break;

        case 2:
        cout << "Enter value to be inserted\n";
        cin >> v;
        head = insertatEnd(head, v);
        break;

        case 3:
        cout << "Enter value to be inserted and the element before it has to been inserted\n";
        cin >> v >> x;
        head = insertinBetween(head, v, x);
        break;

        case 4:
        head = deletefromBeginning(head);
        break;

        case 5:
        head = deletefromEnd(head);
        break;

        case 6:
        cout << "Enter value to be deleted\n";
        cin >> v;
        head = deletethisValue(head, v);
        break;

        case 7:
        cout << "Enter value to be serached\n";
        cin >> s;
        pos = search(head,s);
        if(pos != -1){
            cout << s << " found at " << pos << endl;
        }
        else{
            cout << "Not found\n";
        }
        break;

        case 8:
        display(head);
        break;

        case 9:
        cout << "---------Exiting------------" << endl;
        return 0;

        default :
        cout << "Invalid choice" << endl;
      }
    }
    return 0;
}