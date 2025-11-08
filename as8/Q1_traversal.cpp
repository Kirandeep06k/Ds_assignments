#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
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

void preOrder(Node* root){
    if(root == nullptr)
    return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == nullptr)
    return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == nullptr)
    return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = nullptr;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter the numbers:\n";
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nPreorder traversal: ";
    preOrder(root);
    cout << "\nInorder traversal: ";
    inOrder(root);
    cout << "\nPostorder traversal: ";
    postOrder(root);
    cout << endl;
    return 0;
}
