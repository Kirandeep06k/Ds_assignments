#include <iostream>
using namespace std;
class Node{
	public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right = nullptr;
    }
};

void convert(Node* root){
	if(!root || !root->left || !root->right)
	return;
	
	if(root->left){
		convert(root->left);
		Node* tempright = root->right;
		root->right = root->left;
		root->left = NULL;
		
		Node* t = root->right;
		while(t->right){
			t = t->right;
		}
		t->right = tempright;
	}
	
	convert(root->right);
}

void inorder(Node* root){
	if(!root)
	return;
	inorder(root->left);
	cout << root->data << "->";
	inorder(root->right);
}
Node* buildtree(){
    int x;
    cin >> x;
    if(x==-1)
    return NULL;
    Node* t = new Node(x);
    cout << "Enter left of " << x << endl;
    t->left = buildtree();
    cout << "Enter right of " << x << endl;
    t->right = buildtree();
    return t;
}

int main(){
    cout << "Enter root\n";
    Node* root;
    root = buildtree();
    convert(root);
    cout << "Inorder traversal after conversion\n";
    inorder(root);
    return 0;
}