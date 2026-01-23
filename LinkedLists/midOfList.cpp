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

  ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }

        temp = head;
        int mid = count/2 + 1;
        while(mid > 1){
            temp = temp->next;
            mid--;
        }

        return temp;
    }

int main() {
 
    return 0;
}