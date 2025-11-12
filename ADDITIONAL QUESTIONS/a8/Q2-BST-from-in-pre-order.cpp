#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class ConstructTree {
public:
    int find(int target, vector<int>& inorder, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int start, int end, int& index) {
        if (start > end)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index]);
        index++;

        int pos = find(root->val, inorder, start, end);

        root->left = tree(preorder, inorder, start, pos - 1, index);
        root->right = tree(preorder, inorder, pos + 1, end, index);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        return tree(preorder, inorder, 0, n - 1, index);
    }

    void printInorder(TreeNode* root) {
        if (!root) return;
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
};

int main() {
    ConstructTree ct;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n), inorder(n);

    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    TreeNode* root = ct.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    ct.printInorder(root);
    cout << endl;

    return 0;
}
