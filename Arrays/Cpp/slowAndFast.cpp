#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 int findDuplicate(vector<int>& nums) {
        int slow = 0;int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        slow = 0;
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

int main() {
 
    return 0;
}