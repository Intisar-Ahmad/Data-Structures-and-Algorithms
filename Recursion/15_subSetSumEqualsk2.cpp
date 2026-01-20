#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



bool func(vector<int> arr, int i, int k, int sum, vector<int> subset)
{

    if (i >= arr.size())
    {
        if (sum == k)
        {
            for (auto &&j : subset)
            {
                cout << j << " ";
            }
            cout << endl;
            return true;
        }

        return false;
    };

    // inclusion
    subset.push_back(arr[i]);
    if(func(arr, i + 1, k, sum + arr[i], subset)) return true;

    // exclusion
    subset.pop_back();
    int idx = i + 1;
    while (idx < arr.size() && arr[idx] == arr[i])
        idx++;
    if(func(arr, idx, k, sum, subset)) return true;
    return false;
}

int main()
{
    vector<int> arr = {1, 1, 2}; // must be sorted
    vector<int> sub;
    func(arr, 0, 2, 0, sub);
    return 0;
}