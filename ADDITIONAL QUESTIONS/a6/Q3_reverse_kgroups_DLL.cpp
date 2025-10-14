#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node* createDLL(int n){
    if(n <= 0) 
    return nullptr;

    int val;
    cout << "Enter value for node 1: ";
    cin >> val;
    Node* head = new Node(val);
    Node* temp = head;

    for(int i = 2; i <= n; i++){
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        Node* newNode = new Node(val);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}

Node* reverseKGroup(Node* head, int k){
    if (!head) 
    return nullptr;

    Node* curr = head;
    Node* newHead = nullptr;
    Node* groupPrev = nullptr;
    while(curr){
        Node* groupHead = curr;
        Node* temp = nullptr;
        Node* groupEnd = curr;
        for (int i = 0; i < k - 1 && groupEnd->next; i++)
            groupEnd = groupEnd->next;

        Node* nextGroup = groupEnd->next;

        Node* prev = nextGroup;  
        Node* node = curr;
        while (node != nextGroup) {
            temp = node->next;
            node->next = prev;
            node->prev = temp;
            prev = node;
            node = temp;
        }

        if (!newHead) newHead = prev;
        if (groupPrev) groupPrev->next = prev;
        prev->prev = groupPrev;

        groupPrev = groupHead;
        curr = nextGroup;
    }
    return newHead;
}

void printList(Node* head){
    Node* temp = head;
    while (temp){
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

int main(){
    int n, k;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node* head = createDLL(n);
    cout << "Enter k : ";
    cin >> k;
    cout << "\nOriginal DLL:\n";
    printList(head);
    head = reverseKGroup(head, k);
    cout << "\nDLL after reversing in groups of " << k << ":\n";
    printList(head);
    return 0;
}
