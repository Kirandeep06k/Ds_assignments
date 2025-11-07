#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Tree {
public:
    void preOrder(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root) {
        if (root == nullptr) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void postOrder(Node* root) {
        if (root == nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Tree t;

    cout << "Preorder traversal: ";
    t.preOrder(root);
    cout << "\nInorder traversal: ";
    t.inOrder(root);
    cout << "\nPostorder traversal: ";
    t.postOrder(root);
    cout << endl;

    return 0;
}
