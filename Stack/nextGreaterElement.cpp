#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
#include<stack>


using namespace std;

   vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> s;


        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                next_greater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
      
        vector<int> result;
        for (int num : nums1) {
            if (next_greater.count(num)) {
                result.push_back(next_greater[num]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }

int main() {
 
    return 0;
}