#include <iostream>
#include <vector>
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

bool search_recur(Node* root, int key){
    if(root == nullptr)
    return false;
    if(root->data == key)
    return true;
    if(key < root->data)
        return search_recur(root->left, key);
    else
        return search_recur(root->right, key);
}

bool search_it(Node* root, int key){
    Node* curr = root;
    while(curr != nullptr){
        if(curr->data == key) return true;
        if(key < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    return false;
}

int findMax(Node *root){
        if(!root->right)
        return root->data;
        return findMax(root->right);
}

int findMin(Node *root){
        if(!root->left)
        return root->data;
        return findMin(root->left);
}

vector<Node*> findPreSuc(Node* root, int key) {
        Node* s = NULL;
        Node* p = NULL;
        Node* cur = root;
        while(cur){
            if(key >= cur->data){
                cur = cur->right;
            }
            else{
                s = cur;
                cur = cur->left;
            }
        }
        cur = root;
         while(cur){
            if(key <= cur->data){
                cur = cur->left;
            }
            else{
                p = cur;
                cur = cur->right;
            }
        }
        return {p,s};
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

    cout << "Enter a key to find predecessor and successor: ";
    int key;
    cin >> key;
    if(search_recur(root, val))
        cout << val << " found(rec)" << endl;
    else
        cout << val << " not found(rec)" << endl;

    if(search_it(root, val))
        cout << val << " found(iterative)" << endl;
    else
        cout << val << " not found(iterative)" << endl;
    
    cout << "Minimum value in BST: " << findMin(root) << endl;
    cout << "Maximum value in BST: " << findMax(root) << endl;
    vector<Node*> ans = findPreSuc(root, key);
    if (ans[0])
        cout << "Predecessor: " << ans[0]->data << endl;
    else
        cout << "Predecessor: None" << endl;

    if (ans[1])
        cout << "Successor: " << ans[1]->data << endl;
    else
        cout << "Successor: None" << endl;

    return 0;
}
