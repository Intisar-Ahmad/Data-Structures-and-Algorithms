#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

    void func(Node* head,Node* child){
        if(!child) return;
        Node* prev = nullptr;
        Node* temp = child;
        while(temp){
            if(temp->child){
                func(temp,temp->child);
            }
            prev = temp;
            temp = temp->next;
        }
        if(head){
        prev->next = head->next;
        if(head->next)
        head->next->prev = prev;
        head->next = child;
        child->prev = head;
        head->child = nullptr;
        }
        
    }

    Node* flatten(Node* head) {
        if(!head) return head;
        func(nullptr,head);

        return head;
    }

int main() {
 
    return 0;
}