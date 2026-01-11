#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int st = 0;
    int end = numbers.size() - 1;

    while (st < end)
    {
        int sum = numbers[st] + numbers[end];

        if (sum < target)
        {
            st++;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
           break;
        }
    }
     return {st, end};
}

int main()
{
    vector<int> numbers = {2, 7, 11, 15};

    vector<int> numbers2 = {1, 3, 4, 6, 10};

    vector<int> ans1 = twoSum(numbers, 22);
    vector<int> ans2 = twoSum(numbers2, 10);

    for (auto &&i : ans1)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto &&i : ans2)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}