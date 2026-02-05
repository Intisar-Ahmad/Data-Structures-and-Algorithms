#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>

using namespace std;

// my attempt
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         int i = 0,j = 0;
//         vector<int> max;
//         queue<int> q;
//         while(j < n){
//             while(j - i + 1 <= k && j < n){
//                 while(!q.empty() && nums[j] > nums[q.front()]){
//                     q.pop();
//                 }
//                 q.push(j);
//                 j++;
//             }
//             max.push_back(nums[q.front()]);
//             if(q.front() == i) q.pop();
//             while(!q.empty() && nums[q.back()] > nums[q.front()]){
//                 q.pop();
//             }
//             i++;
//         }
//         return max;
//     }
// };



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  deque<int> dq; 
    vector<int> result;

    for (int j = 0; j < nums.size(); j++) {
        if (!dq.empty() && dq.front() < j - k + 1) {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] < nums[j]) {
            dq.pop_back();
        }

        dq.push_back(j);

        if (j >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}
    
};
int main() {
 
    return 0;
}