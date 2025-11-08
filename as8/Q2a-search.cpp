#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val){
    if(root == nullptr)
    return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

bool search(Node* root, int key){
    if(root == nullptr)
    return false;
    if(root->data == key)
    return true;
    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main(){
    int n, val;
    Node* root = nullptr;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter the numbers:\n";
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
    }
    cout << "Enter a value to search: ";
    cin >> val;
    if(search(root, val))
        cout << val << " found" << endl;
    else
        cout << val << " not found" << endl;
    return 0;
}
