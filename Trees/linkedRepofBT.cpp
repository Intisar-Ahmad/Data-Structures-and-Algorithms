#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* leftChild;
    Node* rightChild;
    
    Node(int data):data(data){
        leftChild = rightChild = nullptr;
    }

};



int main() {
    Node* root = new Node(5); // pretty chill since there are essentially no rules on how to add nodes to the BT. so do whatever you please
    root->leftChild = new Node(1);
    root->rightChild = new Node(2);
    
    cout << root->data << endl;
    cout << "Left Child of root "<< root->leftChild->data << endl;
    cout << "Right Child of root "<< root->rightChild->data << endl;

    return 0;
}