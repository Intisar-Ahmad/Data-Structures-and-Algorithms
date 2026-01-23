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


 ListNode* func(ListNode* curr,ListNode* prev,ListNode* next){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(!curr) return prev;
        next = curr->next;
        return func(curr,prev,next);
    }

    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = curr->next;

        return func(curr,prev,next);

    }

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = curr->next;

        while(true){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(!curr){
                return prev;
            }
            next = curr->next;
        }

        return curr;

    }
};

int main() {
 
    return 0;
}