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

ListNode* rotate(ListNode* head, int k){
    //edge cases:
    if(head == NULL || head->next == NULL)
    return head;

    int c = 0;
    ListNode* temp = head;
    while(temp){
        c++;
        temp = temp->next;
    }

    //edge cases:
    k = k%c;
    if(k==0)
    return head;

    ListNode* oldhead = head;
    c = k;
    ListNode* cur = head;
    ListNode* prev = NULL;
    while(c--){
        prev = cur;
        cur = cur->next;
    }

    prev->next = NULL;
    ListNode* tail = cur;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = oldhead; 
    head = cur;
    return head;
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
    int n, val, k;
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
    cout << "Enter k : ";
    cin >> k;
    cout << "Before rotation:\n";
    printList(head);
    head = rotate(head, k);
    cout << "After rotation:\n";
    printList(head);
    return 0;
}
