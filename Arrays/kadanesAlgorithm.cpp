#include <iostream>
#include <vector>
// Maximum subarray sum

using namespace std;

int BruteForce(const vector<int> &arr)
{
  // O(n^2) solution
    int size = arr.size();
    int maxSum = INT_MIN;


    for (int start = 0; start < size; start++)
    {
        int currentSum = 0;
        for (int end = start; end < size; end++)
        {
            currentSum += arr[end];
            if(currentSum > maxSum){
                maxSum = currentSum;
            }
        }
        
    }
    return maxSum;
}

int KadanesAlgo(const vector<int> &arr){
    int currSum = arr[0];
    int maxSum = currSum;

    for (int i = 1;i < arr.size();i++)
    {
       currSum = max(arr[i],currSum + arr[i]);
       maxSum = max(currSum,maxSum); 
    }

    return maxSum;
    

}

int main()
{
    vector<int> nums = {42, -7, 0, 19, -34, 8, -2, 15, -16, 3, 27, -9};
    cout << BruteForce(nums) << endl;
    cout << KadanesAlgo(nums) << endl;
    return 0;
}