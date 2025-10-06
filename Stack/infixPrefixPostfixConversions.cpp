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
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }

    // isEmpty
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    // push
    void push(char element)
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
    char pop()
    {
        if (isEmpty())
        {
            cout << "Can't Pop. Stack is empty" << endl;
            return -1;
        }
        char pop = arr[top];
        top--;
        return pop;
    }

    // display

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        int temp = top;
        while (temp > -1)
        {
            cout << "|" << arr[temp] << "|" << endl;
            cout << "---" << endl;
            temp--;
        }
        cout << endl;
    }

    // peek
    char peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Can't peek" << endl;
            return '\0';
        }
        return arr[top];
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; // for non-operators
}

string InfixtoPostfix(string infix, bool reverse = false)
{
    string output = "";
    int size = infix.size();
    Stack st(size);
    for (int i = 0; i < size; i++)
    {
        if (infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '/')
        {
            if (reverse)
            {
                while (!st.isEmpty() && precedence(infix[i]) < precedence(st.peek()))
                {
                    char op = st.pop();
                    output.push_back(op);
                }
            }
            else
            {
                while (!st.isEmpty() && precedence(infix[i]) <= precedence(st.peek()))
                {
                    char op = st.pop();
                    output.push_back(op);
                }
            }
            st.push(infix[i]);
        }
        else if (infix[i] == '^')
        {
            if (reverse)
            {
                while (!st.isEmpty() && precedence(infix[i]) <= precedence(st.peek()))
                {
                    char op = st.pop();
                    output.push_back(op);
                }
            }
            else
            {
                while (!st.isEmpty() && precedence(infix[i]) < precedence(st.peek()))
                {
                    char op = st.pop();
                    output.push_back(op);
                }
            }

            st.push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
            {
                output.push_back(st.pop());
            }
            st.pop();
        }
        else
        {
            output.push_back(infix[i]);
        }
    }

    while (!st.isEmpty())
    {
        output.push_back(st.pop());
    }

    return output;
}

string reverse(string infix)
{
    int n = infix.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(infix[i], infix[n - i - 1]);
    }

    // Swap parentheses after reversal
    for (int i = 0; i < n; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    return infix;
}

string InfixtoPrefix(string str)
{
    str = reverse(str);

    str = InfixtoPostfix(str,true);

    str = reverse(str);

    return str;
}

int main()
{
    string infix = "A+B*(A/B)";
    string t1 = "A+B*C";               // tests precedence
    string t2 = "(A+B)*C";             // tests parentheses
    string t3 = "A^B^C";               // tests right-associativity
    string t4 = "A+(B*C-(D/E^F)*G)*H"; // nested and mixed operators
    string t5 = "A";                   // simplest valid case

    //    string output1 =  InfixtoPostfix(infix);
    //    string output2 =  InfixtoPostfix(t1);
    //    string output3 =  InfixtoPostfix(t2);
    //    string output4 =  InfixtoPostfix(t3);
    //    string output5 =  InfixtoPostfix(t4);
    //    string output6 =  InfixtoPostfix(t5);

    string output1 = InfixtoPrefix(infix);
    string output2 = InfixtoPrefix(t1);
    string output3 = InfixtoPrefix(t2);
    string output4 = InfixtoPrefix(t3);
    string output5 = InfixtoPrefix(t4);
    string output6 = InfixtoPrefix(t5);

    cout << output1 << endl;
    cout << output2 << endl;
    cout << output3 << endl;
    cout << output4 << endl;
    cout << output5 << endl;
    cout << output6 << endl;

    return 0;
}