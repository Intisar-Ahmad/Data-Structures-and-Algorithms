#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlace(vector<int>& stalls, int cows, int dist)
{
    int count = 1;           // first cow placed
    int lastPos = stalls[0];

    for(int i = 1; i < stalls.size(); i++)
    {
        if(stalls[i] - lastPos >= dist)
        {
            count++;
            lastPos = stalls[i];
        }
    }
    return count >= cows;
}

int aggressiveCows(vector<int>& stalls, int cows)
{
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = 0;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(canPlace(stalls, cows, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    vector<vector<int>> testCases = {
        {1, 2, 4, 8, 9},
        {10, 1, 2, 7, 5},
        {5, 4, 3, 2, 1, 100},
        {1, 3, 5, 7, 9, 11}
    };

    vector<int> cows = {
        3,
        3,
        2,
        4
    };

    for(int i = 0; i < testCases.size(); i++)
    {
        cout << "Test case " << i + 1 << " -> ";
        cout << aggressiveCows(testCases[i], cows[i]) << endl;
    }

    return 0;
}