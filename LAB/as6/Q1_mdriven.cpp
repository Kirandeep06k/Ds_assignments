#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = nullptr;
    }
};

Node* insertatstart(Node* tail, int v){
    Node* newNode = new Node(v);
    if(!tail){
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return tail;
}

Node* insertatend(Node* tail, int v){
    Node* newNode = new Node(v);
    if(!tail){
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return newNode;
}

Node* insertafter(Node* tail, int x, int v){
    if(!tail){
        return NULL;
    }
    Node* temp = tail->next;
    do{
        if(temp->data == x){
            Node* newNode = new Node(v);
            newNode->next = temp->next;
            temp->next = newNode;
            if(temp == tail){
                tail = newNode;
            }
            return tail;
        }
        temp = temp->next;
    }while(temp!=tail->next);
    cout<<"Value not found\n";
    return tail;
}

Node* del(Node* tail, int v){
    if(!tail){
        return NULL;
    }
    Node* cur = tail->next;
    Node* prev = tail;
    do{
        if(cur->data == v){
            if(cur == prev){
                delete cur;
                return NULL;
            }
            prev->next = cur->next;
            if(cur == tail){
                tail = prev;
            }
            delete cur;
            return tail;
        }
        prev = cur;
        cur = cur->next;
    }while(cur!=tail->next);
    cout<<"Value not found\n";
    return tail;
}

void search(Node* tail, int v){
     if(!tail){
        cout<<"List is empty\n";
        return;
    }
    Node* temp = tail->next;
    int p = 1;
    do{
        if(temp->data == v){
            cout<<"Found at position : " <<p<<endl;
            return;
        }
        temp = temp->next;
        p++;
    }while(temp!=tail->next);
    cout<<"Not found\n";
}

void print(Node* tail){
    if(!tail){
        cout<<"List is empty\n";
        return;
    }
    Node* temp = tail->next;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=tail->next);
    cout<<endl;
}

int main(){
    Node* tail = NULL;
    int c,v,x;
    while(true){
        cout<<"Menu :\n";
        cout<<"1. Insert at start\n" <<"2. Insert at end\n" << "3. Insert after a node\n" << "4. Delete a node\n" << "5. Search\n" << "6. Display\n" << "7. Exit\n" << "Enter choice\n";
        cin>>c;
        switch(c){
        case 1:
        cout<<"Enter value\n";
        cin>>v;
        tail = insertatstart(tail,v);
        break;

        case 2:
        cout<<"Enter value\n";
        cin>>v;
        tail = insertatend(tail,v);
        break;

        case 3:
        cout<<"Enter value after which to insert and new value\n";
        cin>>x>>v;
        tail = insertafter(tail, x, v);
        break;

        case 4:
        cout<<"Enter node to be deleted\n";
        cin>>v;
        tail = del(tail, v);
        break;

        case 5:
        cout<<"Enter value to be serached\n";
        cin>>v;
        search(tail, v);
        break;

        case 6:
        print(tail);
        break;

        case 7:
        cout<<"Exited\n";
        return 0;
        break;

        default:
        cout<<"Invalid choice\n";
      }
   }
}



