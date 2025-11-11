#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class checkBST {
public:
    vector<int> inorder(Node* root) {
        vector<int> l, r, ans;
        if (!root)
        return {};
        l = inorder(root->left);
        r = inorder(root->right);
        ans.insert(ans.end(), l.begin(), l.end());
        ans.push_back(root->data);
        ans.insert(ans.end(), r.begin(), r.end());
        return ans;
    }

    bool isBST(Node* root) {
        vector<int> inor = inorder(root);
        for (int i = 0; i < inor.size() - 1; i++) {
            if (inor[i] > inor[i + 1])
            return false;
        }
        return true;
    }
};

int main() {
    Node* root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(6);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    root1->right->left = new Node(5);
    root1->right->right = new Node(7);

    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(8);

    checkBST s;
    cout << (s.isBST(root1) ? "Yes" : "No") << endl;
    cout << (s.isBST(root2) ? "Yes" : "No") << endl;

    return 0;
}
