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

// searching in BST recursively
Node* search(Node* root, int data,int count){
    if(!root){
        cout << "Not found\n";
        return nullptr;
    }
    if(root->data == data){
        cout << "Found at "<< count << endl;
        return root;
    }
    else if(data < root->data && root->left){
        return search(root->left,data,count + 1);
    }
    else{
        return search(root->right,data, count + 1);
    }

}

// searching iteratively
void searchIteratively(Node* root, int data){
    Node* temp = root;
    int count = 1;
    while(temp){
        if(data == temp->data){
            cout << "Found at "<< count << endl;
            return;
        }
        else if(data < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
        count++;
    }
    cout << "Not found\n";
}

// Find minimum value node in a subtree
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// deleting from a BST
Node* deleteNode(Node* root, int key) {

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node found
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



int main() {
    Node* root = new Node(5); 
    insertNode(root,2);
    insertNode(root,3);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,6);
    insertNode(root,7);

    // cout << "in-order\n";
    // inOrder(root);// fun fact: if the in-order traversal of a BT is sorted in ascending order, it means that the BT is a BST
    // cout << endl;
    // cout << "pre-order\n";
    // preOrder(root);
    // cout << endl;
    // cout << "post-order\n";
    // postOrder(root);
    // cout << endl;

    // search(root,6,1);
    // search(root,10,1);

    // // searching iteratively
    // searchIteratively(root,6); 
    // searchIteratively(root,10); 

    inOrder(root);
    cout << endl;
    root = deleteNode(root,7);
    inOrder(root);
    cout << endl;
    return 0;
}
