#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        
    }
};

int sumOfLeftLeaves(TreeNode* root) {
    if (!root)
    return 0;
    int sum = 0;
    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->val;

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;
}

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Sum of Left Leaf Nodes: " << sumOfLeftLeaves(root);
    return 0;
}
