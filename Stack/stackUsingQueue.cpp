#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

class MyStack {

public:
    queue<int> q;
    MyStack() {

    }
    

    void push(int x) {
        int size = q.size();
        q.push(x);
        
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
   
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
 
    return 0;
}