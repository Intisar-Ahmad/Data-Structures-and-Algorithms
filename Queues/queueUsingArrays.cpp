#include <iostream>

using namespace std;

class Queue{
    public:
    int *queue;
    int size;
    int frontEnd;
    int rearEnd;

    Queue(int size):size(size){
        frontEnd = -1;
        rearEnd = -1;
        queue = new int[size];
    }

    // enqueue
    void enqueue(int element){
        if(frontEnd == -1 && rearEnd == -1){
            cout << element << endl;
            queue[++frontEnd] = element;
            rearEnd++;
        }
        else if(rearEnd < size - 1){
            cout << element << endl;

            queue[++rearEnd] = element;
        }
        else{
            cout << "Overflow\n";
        }
    }

    //dequeue
    int dequeue(){
        if(frontEnd == -1 && rearEnd == -1){
            cout << "Underflow" << endl;
            return -100;
        }
        else if(frontEnd == rearEnd){
            
            int el = queue[frontEnd];
            frontEnd = rearEnd = -1;

            cout << el << endl;
            return el;
        }
        else{
            int el = queue[frontEnd];
            frontEnd++;

             cout << el << endl;
            return el;
        }
    }


    ~Queue(){
        delete []queue;
    }

};

int main() {
  Queue q1(5);
  
  q1.enqueue(5);
  q1.enqueue(3);
  q1.enqueue(2);
  q1.enqueue(1);
  q1.enqueue(4);
  q1.enqueue(7);

  q1.dequeue();
  q1.dequeue();
  q1.dequeue();
  q1.dequeue();
  q1.dequeue();

    return 0;
}