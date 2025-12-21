#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index != 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteRoot() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap mh;
    mh.insert(10);
    mh.insert(40);
    mh.insert(30);
    mh.insert(5);

    cout << "Max-Heap after insertions: ";
    mh.display();

    mh.deleteRoot();
    cout << "After deleting root: ";
    mh.display();

    return 0;
}
