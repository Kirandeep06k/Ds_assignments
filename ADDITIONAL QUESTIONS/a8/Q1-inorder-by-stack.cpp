#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* insertIntoBST(Node* root, int val) {
    if(root == NULL)
        return new Node(val);

    if(val < root->val)
        root->left = insertIntoBST(root->left, val);

    if(val > root->val)
        root->right = insertIntoBST(root->right, val);

    return root;
}

vector<int> inOrder(Node* root) {
        vector<int>res;
        Node* c = root;
        stack<Node*>s;
        while(c || !s.empty()){
            while(c){
                s.push(c);
                c = c->left;
            }
            c = s.top();
            s.pop();
            res.push_back(c->val);
            c = c->right;
        }
        return res;
}

int main() {
    Node* root = NULL;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        root = insertIntoBST(root, val);
    }
    cout << "\nBST Inorder: ";
    vector<int> ans = inOrder(root);
    for(int v : ans) {
        cout << v << " ";
    }
    return 0;
}
