#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void rotateLeft(Node*& x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node*& y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr) x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr) root = x;
        else if (y == y->parent->left) y->parent->left = x;
        else y->parent->right = x;
        x->right = y;
        y->parent = x;
    }

    void fixViolation(Node*& ptr) {
        Node* parent_ptr = nullptr;
        Node* grand_parent_ptr = nullptr;

        while ((ptr != root) && (ptr->color != BLACK) && (ptr->parent->color == RED)) {
            parent_ptr = ptr->parent;
            grand_parent_ptr = ptr->parent->parent;

            //  Parent is Left Child of Grandparent
            if (parent_ptr == grand_parent_ptr->left) {
                Node* uncle_ptr = grand_parent_ptr->right;

                //  Uncle is Red (Recolor only)
                if (uncle_ptr != nullptr && uncle_ptr->color == RED) {
                    grand_parent_ptr->color = RED;
                    parent_ptr->color = BLACK;
                    uncle_ptr->color = BLACK;
                    ptr = grand_parent_ptr;
                } else {
                    //  ptr is Right Child (Left Rotation)
                    if (ptr == parent_ptr->right) {
                        rotateLeft(parent_ptr);
                        ptr = parent_ptr;
                        parent_ptr = ptr->parent;
                    }
                    //  ptr is Left Child (Right Rotation)
                    rotateRight(grand_parent_ptr);
                    std::swap(parent_ptr->color, grand_parent_ptr->color);
                    ptr = parent_ptr;
                }
            } 
            //  Parent is Right Child of Grandparent (Mirror of Case A)
            else {
                Node* uncle_ptr = grand_parent_ptr->left;
                if (uncle_ptr != nullptr && uncle_ptr->color == RED) {
                    grand_parent_ptr->color = RED;
                    parent_ptr->color = BLACK;
                    uncle_ptr->color = BLACK;
                    ptr = grand_parent_ptr;
                } else {
                    if (ptr == parent_ptr->left) {
                        rotateRight(parent_ptr);
                        ptr = parent_ptr;
                        parent_ptr = ptr->parent;
                    }
                    rotateLeft(grand_parent_ptr);
                    std::swap(parent_ptr->color, grand_parent_ptr->color);
                    ptr = parent_ptr;
                }
            }
        }
        root->color = BLACK;
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(const int& data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            newNode->color = BLACK;
            root = newNode;
        } else {
            // Standard BST Insert
            Node* temp = root;
            Node* parent = nullptr;
            while (temp != nullptr) {
                parent = temp;
                if (data < temp->data) temp = temp->left;
                else temp = temp->right;
            }
            newNode->parent = parent;
            if (data < parent->data) parent->left = newNode;
            else parent->right = newNode;

            // Fix Red-Black Tree properties
            fixViolation(newNode);
        }
    }
};



int main(){}