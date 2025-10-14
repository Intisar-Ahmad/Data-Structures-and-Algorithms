#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr),prev(nullptr) {}
};

class DoublyList{
    public:
    Node *head;

    DoublyList() : head(nullptr) {}

    // insertion (at last should be enough)
    void insertAtLast(int value){
        Node *newNode = new Node(value);
        if(!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }
    // traversal(forward and backward)
    void displayInReverse(){
        if(!head){
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp->next){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl;
        
        // Now in reverse
        cout << "Reversed List:"<<endl;
        while(temp){
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
    // deletion
    void removeNode(int val){
        if (!head) return; // Empty list check
        Node* temp = head;
        // If head needs to be removed
        if (head->data == val) {
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }
        while (temp) {
            if (temp->data == val) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    ~DoublyList()
    {
        if (head)
        {
            Node *temp = head;
           
             while(temp){
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
            cout<< "The linked list has been deleted" << endl;
        }
    }

};

int main() {
    DoublyList list1;
    list1.insertAtLast(5);
    list1.insertAtLast(6);
    list1.insertAtLast(7);
    list1.insertAtLast(8);

    list1.displayInReverse();

    list1.removeNode(6);

    list1.removeNode(5);

    list1.displayInReverse();
    
    return 0;
}