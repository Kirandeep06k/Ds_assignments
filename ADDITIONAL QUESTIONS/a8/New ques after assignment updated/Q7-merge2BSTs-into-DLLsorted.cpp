#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node() : data(0), left(nullptr), right(nullptr) {

    }
    Node(int data) : data(data), left(nullptr), right(nullptr) {

    }
    Node(int data, Node* left, Node* right) : data(data), left(left), right(right) {

    }
};

class mergetodll {
public:
    Node* mergeBSTs(Node* x, Node* y) {
        stack<Node*> s1, s2;
        Node* head = NULL;
        Node* prev = NULL;
        Node* cur;
        
        while(x || y || !s1.empty() || !s2.empty()) {
            cur = NULL;
            while(x) {
                s1.push(x);
                x = x->left;
            }

            while(y) {
                s2.push(y);
                y = y->left;
            }

            if(s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data)) {
                cur = s1.top();
                s1.pop();
                x = cur->right;
            }
            else {
                cur = s2.top();
                s2.pop();
                y = cur->right;
            }
            
            cur->left = prev;
            cur->right = NULL;
            
            if(prev) {
                prev->right = cur;
            }
            else {
                head = cur;
            }
            prev = cur;
        }
        return head;
    }
};

void printDLLForward(Node* head) {
    Node* curr = head;
    while(curr) {
        cout << curr->data;
        if(curr->right)
        cout << " <-> ";
        curr = curr->right;
    }
    cout << " <-> nullptr" << endl;
}

int main() {
    mergetodll m;
    Node* root1 = new Node(20);
    root1->left = new Node(10);
    root1->right = new Node(30);
    root1->right->left = new Node(25);
    root1->right->right = new Node(100);
    
    
    Node* root2 = new Node(50);
    root2->left = new Node(5);
    root2->right = new Node(70);
    
    Node* dllHead = m.mergeBSTs(root1, root2);
    
    cout << "DLL Forward: ";
    printDLLForward(dllHead);
    return 0;
}