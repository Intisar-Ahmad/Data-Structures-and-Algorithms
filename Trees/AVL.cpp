#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    int height;

    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* n) {
        return n ? n->height : 0;
    }

    int getBalance(Node* n) {
        return n ? getHeight(n->left) - getHeight(n->right) : 0;
    }

    // --- THE ROTATIONS ---

    // Right Rotate (used for Left-Heavy situations)
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x; // New root
    }

    // Left Rotate (used for Right-Heavy situations)
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y; // New root
    }

    Node* insert(Node* node, int data) {
        // 1. Standard BST insertion
        if (!node) return new Node(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node; // Duplicate values not allowed

        // 2. Update height of ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // 3. Get Balance Factor
        int balance = getBalance(node);

        // 4. Rebalance if needed (The 4 Cases)

        // Case 1: Left-Left (LL)
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        // Case 2: Right-Right (RR)
        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        // Case 3: Left-Right (LR)
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Case 4: Right-Left (RL)
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inOrder(Node* root) {
        if (root) {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    void display() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // Triggers RR rotation
    tree.insert(40);
    tree.insert(50);
    tree.insert(25); // Triggers a complex rotation

    cout << "In-order traversal of balanced AVL tree: ";
    tree.display();

    return 0;
}