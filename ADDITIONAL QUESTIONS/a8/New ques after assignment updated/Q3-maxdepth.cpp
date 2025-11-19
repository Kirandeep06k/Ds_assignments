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

int maxDepth(TreeNode* root) {
        if(!root)
        return 0;

        return 1 + max (maxDepth(root->left), maxDepth(root->right));
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
    cout << endl;
    cout << "Max Depth of BST: " << maxDepth(root) << endl;
    return 0;
}
