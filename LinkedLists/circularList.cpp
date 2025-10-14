#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next = nullptr;
};

class CircularList
{
public:
    Node *head;
    Node *end;

    CircularList() : head(nullptr), end(nullptr) {}

    // insertion in circular linked list

    // insertion at last
    void insertAtLast(int element)
    {
        Node *newNode = new Node();
        newNode->data = element;

        if (!head) 
        {
            head = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
        end->next = head;
    }

    // insertion at first
     void insertAtFirst(int element)
    {
        Node *newNode = new Node();
        newNode->data = element;

        if (!head)
        {
            head = newNode;
            end = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        end->next = head;
    }

    // display
    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }


    // deletion
    void removeNode(int pos){
        Node *temp = head;
        Node *prev = nullptr;
        if(!head){
            return;
        }
        if(pos == 0){
            if(head == end){
                head = nullptr;
                end = nullptr;
                delete temp;
                cout << "Deleted successfully at position:" << pos << endl;
                return;
            }
            end->next = temp->next;
            head = temp->next;
            delete temp;
            cout << "Deleted successfully at position:" << pos << endl;
            return;
        }
        int count = 0;
        while(count < pos){
            prev = temp;
            temp = temp->next;
            count++;

            if(temp == head){
                cout << "Position out of bounds" << endl;
                return;
            }
        }
        if(temp == end){
            prev->next = temp->next;
            end = prev;
            delete temp;
            cout << "Deleted successfully at position:" << pos << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;       
        cout << "Deleted successfully at position:" << pos << endl;
    }


    ~CircularList()
    {
        if (head)
        {
            Node *temp = head;
            do{
                Node* next = temp->next;
                delete temp;
                temp = next;
            }while(temp!=head);
            cout<< "The linked list has been deleted" << endl;
        }
    }
};

int main()
{
    CircularList list1;
    list1.insertAtLast(5);
    list1.insertAtLast(8);
    list1.insertAtLast(5);
    list1.insertAtLast(8);

    list1.display();

    list1.insertAtFirst(87);
    list1.insertAtFirst(7);

    list1.display();

    list1.removeNode(2);
    list1.removeNode(1);
    list1.removeNode(10);


    list1.display();

    return 0;
}