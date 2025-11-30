#include <iostream>
using namespace std;

class Queue {
public:
    int front;
    int rear;
    int *arr;
    int size;

    Queue(int size) : size(size) {
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // enqueue
    void enqueue(int el) {
        if ((rear + 1) % size == front) {
            cout << "Overflow\n";
            return;
        }

        if (front == -1) { 
            // first insertion
            front = 0;
        }

        rear = (rear + 1) % size;
        arr[rear] = el;
    }

    // dequeue
    int dequeue() {
        if (front == -1) {
            cout << "Underflow\n";
            return -1;
        }

        int temp = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return temp;
    }


    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Queue q1(5);

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);

    q1.display();

    return 0;
}
