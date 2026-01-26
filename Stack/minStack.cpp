#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    int min;

    Node(int data):data(data),min(data){
        next = nullptr;
    }
};

class MinStack {
public:
    Node* head = nullptr;
    MinStack() {
        
    }
    
    void push(int val) {
        if(!head){
            head = new Node(val);
            return;
        }
        Node* newNode = new Node(val);
        if(head->min < newNode->min){
            newNode->min = head->min;
        }
        newNode->next = head;
        head = newNode;
    }
    
    void pop() {
        if(!head) return;
        head = head->next;

    }
    
    int top() {
        if(!head) return -1;
        return head->data;
    }
    
    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
 
    return 0;
}