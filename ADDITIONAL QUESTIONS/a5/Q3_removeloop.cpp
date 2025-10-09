#include <iostream>
using namespace std;
class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

void removeLoop(ListNode* list){
    ListNode* sp = list;
    ListNode* fp = list;
    while(fp && fp->next){
        sp = sp->next;
        fp = fp->next->next;
        if(sp == fp)
            break;
    }
    if(fp == NULL || fp->next == NULL)
        return;

    sp = list;
    while(sp != fp){
        sp = sp->next;
        fp = fp->next;
    }

    while(sp->next != fp){
        sp = sp->next;
    }
    sp->next = NULL;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    int n, val, pos;
    cout << "Enter number of nodes: ";
    cin >> n;
    if(n == 0){
        cout << "Empty list" << endl;
        return 0;
    }
    cout << "Enter value for node 1: ";
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* temp = head;
    for (int i = 2; i <= n; i++) {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    cout << "Enter position to create loop : ";
    cin >> pos;
    if(pos > 0 && pos <= n){
        ListNode* loopNode = head;
        for (int i = 1; i < pos; i++)
            loopNode = loopNode->next;
        temp->next = loopNode;
    }
    removeLoop(head);
        cout << "Loop removed. Final list:\n";
        printList(head);
    return 0;
}
