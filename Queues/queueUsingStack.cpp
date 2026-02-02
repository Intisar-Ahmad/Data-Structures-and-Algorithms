#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>

using namespace std;

class MyQueue {


public:
    stack<int> s2; 
    stack<int> s1; 

    void transfer() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        transfer();
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        transfer();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
 
    return 0;
}