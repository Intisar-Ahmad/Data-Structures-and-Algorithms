#include <iostream>

using namespace std;

// Stack using array
class Stack
{
public:
    int size;
    int top;
    int *arr; // array the stack is implement on

    Stack(int size) : size(size)
    {
        arr = new int[size];
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
    void push(int element)
    {
        if (isFull())
        {
            cout << "Stack is full. Can't insert" << endl;
            return;
        }
        top++;
        arr[top] = element;
        cout << "Element inserted" << endl;
    }

    // pop
    int pop(){
        if(isEmpty()){
            cout << "Can't Pop. Stack is empty" << endl;
            return -1;
        }
        int pop = arr[top];
        top--;
        return pop;
    }

    // fill

    void fill(){
        for (int i = 0; i < size; i++)
        {
            this->push((i+1) * 2);
        }
        
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
    void peek(int i){
        if(isEmpty()){
             cout << "Stack is empty. Can't peek" << endl;
             return;
        }
        int index = top - (i - 1);
        if(index < 0 || index > (size - 1)){
            cout<< "Out of bounds access" << endl;
            return;
        }
        cout << arr[index] << endl; 
    }
    

    ~Stack(){
        delete[] arr;
    }
};

int main()
{
    Stack s1(5);
    s1.fill();
    // s1.push(10);
    // s1.fill();
    // s1.display();
    // s1.pop();
    // s1.pop();
    // cout <<s1.pop() << endl;

    // s1.display();
    s1.peek(-465);

    return 0;
}