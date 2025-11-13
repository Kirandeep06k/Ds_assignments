#include <bits/stdc++.h>
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

Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

class Merge {
public:
    void inorder(Node* root, vector<Node*>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
    }

    vector<Node*> mergeVectors(vector<Node*>& a, vector<Node*>& b) {
        vector<Node*> merged;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i]->data < b[j]->data)
                merged.push_back(a[i++]);
            else
                merged.push_back(b[j++]);
        }
        while (i < a.size()) merged.push_back(a[i++]);
        while (j < b.size()) merged.push_back(b[j++]);
        return merged;
    }

    Node* linkDLL(vector<Node*>& arr) {
        if (arr.empty()) return nullptr;
        Node* head = arr[0];
        Node* curr = head;
        curr->left = nullptr;

        for (int i = 1; i < arr.size(); i++) {
            curr->right = arr[i];
            arr[i]->left = curr;
            curr = arr[i];
        }
        curr->right = nullptr;
        return head;
    }

    Node* mergeBSTs(Node* root1, Node* root2) {
        vector<Node*> a, b;
        inorder(root1, a);
        inorder(root2, b);
        vector<Node*> merged = mergeVectors(a, b);
        return linkDLL(merged);
    }
};

void printDLL(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->right) cout << " <--> ";
        curr = curr->right;
    }
    cout << " <--> null\n";
}

int main() {
    Merge s;
    Node* root1 = nullptr;
    Node* root2 = nullptr;

    int n1, n2, val;

    cout << "Enter number of nodes for BST1: ";
    cin >> n1;
    cout << "Enter elements of BST1: ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        root1 = insertBST(root1, val);
    }

    cout << "Enter number of nodes for BST2: ";
    cin >> n2;
    cout << "Enter elements of BST2: ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        root2 = insertBST(root2, val);
    }

    Node* head = s.mergeBSTs(root1, root2);

    cout << "\nMerged Doubly Linked List:\n";
    printDLL(head);

    return 0;
}
