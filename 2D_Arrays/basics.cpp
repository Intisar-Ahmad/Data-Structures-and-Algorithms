#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSumInRow(vector<vector<int>> arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int m = arr[i].size();
        int currSum = 0;
        for (int j = 0; j < m; j++)
        {
            currSum += arr[i][j];
        }
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

int maxSumInCol(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int maxSum = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        int currSum = 0;
        for (int j = 0; j < n; j++)
        {
            currSum += arr[j][i];
        }
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

int diagonalSum(vector<vector<int>> arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i][i];
    }

    return sum;
}

int SecondaryDiagonalSum(vector<vector<int>> arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i][n-i-1];
    }

    return sum;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3},
        {2, 6, 2},
        {5, -1, 9}};

    cout << SecondaryDiagonalSum(arr) << endl;
    return 0;
}