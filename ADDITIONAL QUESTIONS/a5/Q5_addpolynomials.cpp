#include <iostream>
using namespace std;
class Node{
public:
    int co;
    int pow;
    Node* next;
    Node(int c, int p){
        co = c;
        pow = p;
        next = NULL;
    }
};

Node* addPolynomial(Node* head1, Node* head2){
    Node* dummy = new Node(0, 0);
    Node* prev = dummy;
    Node* cur1 = head1;
    Node* cur2 = head2;
    while(cur1 && cur2){
        if(cur1->pow < cur2->pow){
            prev->next = cur2;
            prev = cur2;
            cur2 = cur2->next;
        }
        else if(cur1->pow > cur2->pow){
            prev->next = cur1;
            prev = cur1;
            cur1 = cur1->next;
        }
        else{
            cur1->co = cur1->co + cur2->co;
            prev->next = cur1;
            prev = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    if(cur1)
        prev->next = cur1;
    if(cur2)
        prev->next = cur2;

    return dummy->next;
}

void printList(Node* head){
    cout << "[";
    while(head){
        cout << "[" << head->co << ", " << head->pow << "]";
        head = head->next;
        if(head) cout << ", ";
    }
    cout << "]";
}


int main(){
    int n1, n2, co, pow;
    cout << "Enter number of terms in 1st polynomial: ";
    cin >> n1;
    if(n1 == 0){
        cout << "Empty polynomial" << endl;
        return 0;
    }
    cout << "Enter coefficient and power for term 1: ";
    cin >> co >> pow;
    Node* head1 = new Node(co, pow);
    Node* temp = head1;
    for(int i=2; i<=n1; i++){
        cout << "Enter coefficient and power for term " << i << ": ";
        cin >> co >> pow;
        temp->next = new Node(co, pow);
        temp = temp->next;
    }

    cout << "Enter number of terms in 2nd polynomial: ";
    cin >> n2;
    if(n2 == 0){
        cout << "Empty polynomial!" << endl;
        return 0;
    }
    cout << "Enter coeff and power for term 1: ";
    cin >> co >> pow;
    Node* head2 = new Node(co, pow);
    temp = head2;
    for(int i=2; i<=n2; i++){
        cout << "Enter coeff and power for term " << i << ": ";
        cin >> co >> pow;
        temp->next = new Node(co, pow);
        temp = temp->next;
    }

    cout << "\n1st Polynomial: ";
    printList(head1);
    cout << "\n2nd Polynomial: ";
    printList(head2);
    Node* head = addPolynomial(head1, head2);
    cout << "\nPolynomial after addition:\n";
    printList(head);
    return 0;
}
