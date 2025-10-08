#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

Node* findIntersectionNode(Node *A, Node *B, int d) {
	while(d>0){
		A = A->next;
		d--;
	}
	while(A!=NULL && B!=NULL){
		if(A==B){
			return A;
		}
		A=A->next;
		B=B->next;
	}
	return NULL;
}
Node* getIntersectionNode(Node *A, Node *B) {
	Node* tempA = A;
	int al = 0;
	int bl = 0;
	Node* tempB = B;
	while(tempA!=NULL){
		al++;
		tempA = tempA->next;
	}
	while(tempB!=NULL){
		bl++;
		tempB = tempB->next;
	}
	if(al>bl){
		return  findIntersectionNode(A, B, al-bl);
	}
	else{
		return  findIntersectionNode(B, A, bl-al);
	}
}

int main(){
    int T,nCommon;
    cout << "Enter no of test cases\n";
    cin >> T;
    while(T){
    int n1;
    cout << "Enter number of nodes for Linked list 1: ";
    cin >> n1;
    int val,key,count=0;
    int n2;
    cout << "Enter number of nodes for Linked list 2: ";
    cin >> n2;
   cout << "Enter number of common (intersecting) nodes: ";
   cin >> nCommon;
    cout << "For Linked list 1 : \nEnter value for node 1: ";
    cin >> val;
    Node* head1 = new Node(val);
    Node* temp1 = head1;
       for(int i = 2; i <= n1; i++){
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        temp1->next = new Node(val);
        temp1 = temp1->next;
       }

       cout << "For Linked list 2 : \nEnter value for node 1: ";
       cin >> val;
       Node* head2 = new Node(val);
       Node* temp2 = head2;
       for(int i = 2; i <= n2; i++){
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        temp2->next = new Node(val);
        temp2 = temp2->next;
      }
         Node* tail1 = temp1; // last node of list 1
         Node* tail2 = temp2; // last node of list 2
         Node* commonHead = NULL;
         Node* commonTail = NULL;

         if (nCommon > 0) {
         cout << "Enter values for common (intersecting) nodes:\n";
         for (int i = 0; i < nCommon; i++) {
              int val;
              cout << "Enter value for common node " << i + 1 << ": ";
              cin >> val;
              Node* newNode = new Node(val);

            if (!commonHead)
                commonHead = commonTail = newNode;
            else {
            commonTail->next = newNode;
            commonTail = newNode;
            }
         }
         if (tail1) tail1->next = commonHead;
         if (tail2) tail2->next = commonHead;
   }

      Node* ans = getIntersectionNode(head1, head2);
      if (ans != NULL)
         cout << "Intersection : " << ans->data << endl;
       else
         cout << "No intersection found" << endl;
          T--;
    }
}