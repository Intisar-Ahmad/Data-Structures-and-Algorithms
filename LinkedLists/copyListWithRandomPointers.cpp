#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

   Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        unordered_map<Node*,Node*> m;


        Node* head2  = new Node(head->val);
        Node* tail2 = head2;
        Node* temp = head->next;
        m[head] = head2;
        while(temp){
            tail2->next = new Node(temp->val);
            tail2 = tail2->next;
            m[temp] = tail2;
            temp = temp->next;
        }

        temp = head;
        Node* temp2 = head2;
        while(temp){
            temp2->random = m[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }

        return head2;
    }

int main() {
 
    return 0;
}