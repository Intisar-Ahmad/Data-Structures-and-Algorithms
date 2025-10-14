#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
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

// Example usage

int main()
{
    LinkedList list;
    list.insertFirst(10);
    list.insertLast(20);
    list.insertAtMiddle(15, 2);
    list.traversal(); // 10 -> 15 -> 20 -> NULL
    list.updateNode(15, 17);
    list.traversal(); // 10 -> 17 -> 20 -> NULL
    list.removeNode(17);
    list.traversal(); // 10 -> 20 -> NULL
    return 0;
}
