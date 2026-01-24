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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while(list1 && list2){
            if(list1->val <= list2->val){
                if(!head){
                    head = tail = list1;
                }
                else{
                    tail->next = list1;
                    tail = list1;
                }
                    list1 = list1->next;
            }
            else{
                if(!head){
                    head = tail = list2;
                }
                else{
                    tail->next = list2;
                    tail = list2;
                }
                    list2 = list2->next;
            }
        }

        while(list1){
              if(!head){
                    head = tail = list1;
                }
                else{
                    tail->next = list1;
                    tail = list1;
                }
                    list1 = list1->next;
        }

        while(list2){
        if(!head){
            head = tail = list2;
            }
        else{
            tail->next = list2;
            tail = list2;
        }
            list2 = list2->next;
        }

        return head;
    }

int main() {
 
    return 0;
}