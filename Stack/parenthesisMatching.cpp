#include <iostream>

using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *arr; // array the stack is implement on

    Stack(int size) : size(size)
    {
        arr = new char[size];
        top = -1;
    }

    // isFull
    bool isFull()
    {
        if (top == size - 1){
            return true;
        }
        return false;
    }

    // isEmpty
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    // push
    void push(char element)
    {
        if (isFull())
        {
            return;
        }
        top++;
        arr[top] = element;
    }

    // pop
    char pop(){
        if(isEmpty()){
            return -1;
        }
        char pop = arr[top];
        top--;
        return pop;
    }


    // display

    void display(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }
        int temp = top;
        while(temp > -1){
            cout <<"|"<<arr[temp] <<"|"<<endl;
            cout<<"---"<<endl;
            temp--;
        }
        cout << endl;
    }

    //peek
    char peek(){
        if(isEmpty()){
             return -1;
        }
       
        return arr[top];
    }
    

    ~Stack(){
        delete[] arr;
    }
};


bool isValidParenthesis(string str){
    int size = str.size();
    Stack newStack(size);
    for (int i = 0; i < size; i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') newStack.push(str[i]);
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if(newStack.isEmpty()){
                return false;
            }
            if(str[i] == ')' && newStack.peek() == '(') {
                newStack.pop();
                continue;
            }
            else if(str[i] == '}' && newStack.peek() == '{') {
                newStack.pop();
                continue;
            }
            else if(str[i] == ']' && newStack.peek() == '[') {
                newStack.pop();
                continue;
            }
            else{
                return false;
            }
        }
    }
    return newStack.isEmpty();
}


int main() {
    string s1 = "({})))";
    string s2 = "({[]})";
    string s3 = "((({[]})))";
    string s4 = "({[})]";
    string s5 = "";

    cout << s1 << " : " << (isValidParenthesis(s1) ? "Valid" : "Invalid") << endl;
    cout << s2 << " : " << (isValidParenthesis(s2) ? "Valid" : "Invalid") << endl;
    cout << s3 << " : " << (isValidParenthesis(s3) ? "Valid" : "Invalid") << endl;
    cout << s4 << " : " << (isValidParenthesis(s4) ? "Valid" : "Invalid") << endl;
    cout << "Empty string : " << (isValidParenthesis(s5) ? "Valid" : "Invalid") << endl;
   
    return 0;
}