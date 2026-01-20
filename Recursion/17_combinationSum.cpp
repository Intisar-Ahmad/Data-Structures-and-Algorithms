#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combSum(int i, vector<int> &arr, int tar, vector<int> &ds)
{
    if (tar == 0)
    {
              for (auto &&j : ds)
            {
                cout << j << " ";
            }
            cout << endl;

        return;
    }
    if (i == arr.size())
    {
        if (tar == 0)
        {
            for (auto &&j : ds)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        return;
    }
    if (arr[i] > tar)
    {
        combSum(i + 1, arr, tar, ds);
    }
    else
    {
        ds.push_back(arr[i]);
        combSum(i, arr, tar - arr[i], ds);

        ds.pop_back();
        combSum(i + 1, arr, tar, ds);
    }
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<int> com;
    vector<vector<int>> ans;
    // combSum(0, arr, target, com, ans);

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ds;
    combSum(0, arr, 6, ds);
    return 0;
}