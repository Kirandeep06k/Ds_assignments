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

ListNode* findkth(ListNode* temp, int k){
    while (temp != NULL && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp;
}

ListNode* rev(ListNode* head){
    ListNode* temp = head;
    ListNode* prev = NULL;
    while (temp != NULL){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode* reverseLinkedListKGroup(ListNode* head, int k){
    ListNode* kth;
    ListNode* nextNode;
    ListNode* prev = NULL;
    ListNode* temp = head;
    while (temp != NULL){
        kth = findkth(temp, k - 1);
        if (kth == NULL){
            if (prev) prev->next = temp;
            break;
        }
        nextNode = kth->next;
        kth->next = NULL;
        rev(temp); 

        if(temp == head)
            head = kth;
        else
            prev->next = kth;
        prev = temp;  
        temp = nextNode; 
    }
    return head;
}

void printList(ListNode* head){
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    int n, k, val;
    cout << "Enter number of nodes in linked list: ";
    cin >> n;
    if (n == 0){
        cout << "Empty list!" << endl;
        return 0;
    }
    cout << "Enter value for node 1: ";
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* temp = head;
    for(int i = 2; i <= n; i++){
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    cout << "Enter k (group size): ";
    cin >> k;
    cout << "\nOriginal Linked List:\n";
    printList(head);
    head = reverseLinkedListKGroup(head, k);
    cout << "\nLinked List after reversing : \n";
    printList(head);
    return 0;
}
