#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL)
        return new TreeNode(val);

    if(val < root->val)
        root->left = insertIntoBST(root->left, val);

    if(val > root->val)
        root->right = insertIntoBST(root->right, val);

    return root;
}

void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root)
        return NULL;

    if(root->val > key) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if(root->val < key) {
        root->right = deleteNode(root->right, key);
        return root;
    }
    else {
        if(!root->left && !root->right) {
            delete root;
            return NULL;
        }
        else if(!root->left) {
            TreeNode* t = root->right;
            delete root;
            return t;
        }
        else if(!root->right) {
            TreeNode* t = root->left;
            delete root;
            return t;
        }
        else {
            TreeNode* child = root->left;
            TreeNode* parent = root;
            while(child->right) {
                parent = child;
                child = child->right;
            }
            if(root != parent) {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
}

int main() {
    TreeNode* root = NULL;
    int n, val, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        root = insertIntoBST(root, val);
    }
    cout << "\nBST (Inorder before insertion): ";
    inorder(root);
    cout << "\nEnter key to delete: ";
    cin >> key;
    root = deleteNode(root, key);
    cout << endl;
    cout << "BST (Inorder after insertion): ";
    inorder(root);
    cout << endl;
    return 0;
}
