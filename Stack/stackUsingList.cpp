#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{



public:
    Node *head;
    LinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertFirst(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertLast(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at a specific position (1-based index, after pos-1 nodes)
    void insertAtMiddle(int val, int pos)
    {
        if (pos <= 1)
        {
            insertFirst(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        int count = 1;
        while (temp && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        if (!temp)
        {
            insertLast(val);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Remove first node with given value
    void removeNode(int val)
    {
        if (!head)
            return;
        if (head->data == val)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != val)
        {
            temp = temp->next;
        }

        if (temp->next)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Update first node with oldVal to newVal
    void updateNode(int oldVal, int newVal)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == oldVal)
            {
                temp->data = newVal;
                return;
            }
            temp = temp->next;
        }
    }

    // Traverse and print the list
    void traversal() const
    {
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Destructor to free memory
    ~LinkedList()
    {
        Node *temp = head;
        while (temp)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};


class Stack{
    public:
    Node* top = list.head;
    LinkedList list;
    
    // push
    void push(int element){
        list.insertFirst(element);
        top = list.head;
    }

    // pop
    int pop(){
        int data = top->data;
        list.removeNode(top->data);
        top = list.head;
        return data;
    }

    //display
    void display(){
        list.traversal();
    }

    // isEmpty and isFull
    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        try {
            Node* test = new Node(0);
            delete test;
            return false;
        } catch (std::bad_alloc&) {
            return true;
        }
    }
    
};

int main() {
    Stack s1;
    s1.push(5);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    s1.push(7);

    s1.display();

    s1.pop();
    s1.pop();
    s1.pop();

    s1.display();
    return 0;
}