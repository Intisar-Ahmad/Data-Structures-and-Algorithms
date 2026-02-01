#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>


using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node *next, *prev;
        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int cap;
    int size = 0;

    LRUCache(int capacity) : cap(capacity) {
        head->next = tail;
        tail->prev = head;
    }

    
    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        mp.erase(node->key);
        delete node;
        size--;
    }

    
    void addNode(int key, int value) {
        Node* newNode = new Node(key, value);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        mp[key] = newNode;
        size++;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            int val = mp[key]->val;
            deleteNode(mp[key]);
            addNode(key, val);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            deleteNode(mp[key]);
        } else if (size == cap) {
            deleteNode(tail->prev); 
        }
        addNode(key, value);
    }
};

int main() {
 
    return 0;
}