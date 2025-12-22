#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data):data(data){
        left = right = nullptr;
    }

};

// implementing BST style insert
void insertNode(Node* &root,int data){
    if(!root){
        root = new Node(data);
        return;
    }
    if(data<root->data){
        insertNode(root->left,data);
    }else{
        insertNode(root->right,data);
    }
}

// in-order traversal
void inOrder(Node* root){
    if(!root){
        return;
    }
     inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// pre-order traversal
void preOrder(Node* root){
    if(!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// post order traversal
void postOrder(Node* root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}


int main() {
    Node* root = new Node(5); 
    insertNode(root,2);
    insertNode(root,3);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,6);
    insertNode(root,7);

    cout << "in-order\n";
    inOrder(root);
    cout << endl;
    cout << "pre-order\n";
    preOrder(root);
    cout << endl;
    cout << "post-order\n";
    postOrder(root);
    cout << endl;

    return 0;
}