#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


 ListNode* swapPairs(ListNode* head) {
         ListNode* curr = head;
        for (int i = 0; i < 2; i++) {
            if (!curr) return head;
            curr = curr->next;
        }

      
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        curr = head;
        for (int i = 0; i < 2; i++) {
            nextNode = curr->next; 
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        if (nextNode) {
            head->next = swapPairs(nextNode );
        }
        return prev;
    }

int main() {
 
    return 0;
}