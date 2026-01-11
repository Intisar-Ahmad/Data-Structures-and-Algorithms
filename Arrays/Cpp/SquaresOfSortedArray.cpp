#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

   vector<int> sortedSquares(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;
        vector<int> res(end + 1,0);
        int temp = end;
        while(st <= end){
            if(nums[st] * nums[st] > nums[end] * nums[end]){
                res[temp--] = nums[st] * nums[st];
                st++;
            }
            else{
                res[temp--] = nums[end] * nums[end];
                end--;
            }
        } 

        return res;

    }

int main() {
    vector<int> nums = {-7, -3, 2, 3, 11};
    vector<int> res = sortedSquares(nums);

    for (int x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
