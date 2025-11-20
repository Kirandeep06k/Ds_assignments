#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class rview{
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            ans.push_back(q.front()->val);
            while (n--) {
                TreeNode* t = q.front();
                q.pop();
                if (t->right)
                q.push(t->right);
                if (t->left)
                q.push(t->left);
            }
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    rview s;
    vector<int> res = s.rightSideView(root);

    for (int x : res)
    cout << x << " ";
    return 0;
}
