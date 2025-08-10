#include <iostream>
#include <vector>

using namespace std;

// find the majority element

int BruteForce(vector<int> nums)
{
    int size = nums.size();
    int majorityElement = 0;
    int maxCount = 0;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (nums[j] == nums[i])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            if (maxCount > size / 2)
            {
                majorityElement = nums[i];
            }
        }
    }
    return majorityElement;
}

int optimized(vector<int> nums)
{
    // Assuming there is always a majority element.

    int size = nums.size();
    int majorityElement = nums[0];
    int freq = 0;
    for (int i = 0; i < size; i++)
    {
        if (freq == 0)
        {
            majorityElement = nums[i];
            freq = 1;
        }
        else if (nums[i] == majorityElement)
        {
            freq++;
        }
        else if (nums[i] != majorityElement)
        {
            freq--;
        }
    }

    return majorityElement;
}

int main()
{
    vector<int> arr = {2, 5, 1, 6, 2, 2, 2};

    cout << BruteForce(arr) << endl;
    cout << optimized(arr) << endl;

    return 0;
}