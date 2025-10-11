#include <iostream>
using namespace std;
class Node{
    public:
    char data;
    Node* next;
    Node* back;
    Node(char data1){
        data = data1;
        next = nullptr;
        back = nullptr;
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
        cout << "Enter number of characters: ";
        cin >> n;
        if(n <= 0){
            cout << "List must have at least one node.";
            return;
        }
        Node* prev = nullptr;
        for(int i = 1; i <= n; i++){
            char val;
            cout << "Enter character for node " << i << ": ";
            cin >> val;
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
            }
            else{
                prev->next = newNode;
                newNode->back = prev;
            }
            prev = newNode;
        }
    }

    bool isPalindrome(){
        if(head == NULL || head->next == NULL)
        return true;
        Node* left = head;
        Node* right = head;
        while(right->next != NULL){
            right = right->next;
        }
        while(left != right && right->next != left){ //orleft->back!=right
            if(left->data != right->data){
                return false;
            }
            left = left->next;
            right = right->back;
        }
        return true;
    }
};

int main(){
    Linkedlist ob;
    ob.create();
    if(ob.isPalindrome())
        cout << "It is a Palindrome.\n";
    else
        cout << "It is not a Palindrome.\n";
    return 0;
}
