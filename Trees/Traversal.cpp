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


int main() {
    Node* root = new Node(5); 
    insertNode(root,2);
    insertNode(root,3);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,6);
    insertNode(root,7);

    inOrder(root);

    return 0;
}