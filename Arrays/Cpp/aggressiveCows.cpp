#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(vector<int>& stalls, int cows, int dist)
{
   int countCows = cows - 1;
   int n = stalls.size();
    int lastCowPos = stalls[0];


    for (int i = 1; i < n; i++)
    {
        if(stalls[i] - lastCowPos >= dist){
            countCows--;
            lastCowPos = stalls[i];        
        }
    }

    return (countCows > 0)?false:true;
    
}

int aggressiveCows(vector<int>& stalls, int cows)
{
    sort(stalls.begin(), stalls.end());

    int st = 1;
    int end = stalls.back() - stalls.front();
    int ans = 0;

    while(st <= end)
    {
        int mid = st + (end - st)/2;
        if(isValid(stalls,cows,mid)){
            ans = mid;
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
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