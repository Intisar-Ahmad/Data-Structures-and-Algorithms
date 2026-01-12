#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumArray(vector<int> arr)
{
    int n = arr.size();

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool isValid(vector<int> arr,int M,int mid){
    int maxTime = 0;
    int painters = 1;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if(arr[i] > mid) return false;

        if(maxTime + arr[i] <= mid){
            maxTime+=arr[i];
        }
        else{
            maxTime = arr[i];
            painters++;
        }
    }


    if(painters > M){
        return false;
    }
    return true;
    
}

int func(vector<int> arr,int M){
    int st = 0;
    int end = sumArray(arr);
    int minTime = -1;

    if(arr.size() < M) return -1;

    while(st <= end){
        int mid = st + (end - st)/2;

        if(isValid(arr,M,mid)){
            minTime = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }

    }

    return minTime;

}

int main() {
     vector<vector<int>> testCases = {
        {10, 20, 30, 40},
        {5, 5, 5, 5},
        {1, 2, 3, 4, 5},
        {100},
        {1, 1, 1, 1, 100},
        {7, 2, 5, 10, 8},
        {15, 30, 10, 20, 25},
        {100, 200, 300, 400, 500},
        {3, 6, 2, 8, 4, 7},
        {1000000, 1000000, 1000000}
    };

    vector<int> painters = {
        2,  // for {10,20,30,40}
        2,  // for {5,5,5,5}
        3,  // for {1,2,3,4,5}
        1,  // for {100}
        2,  // for {1,1,1,1,100}
        2,  // for {7,2,5,10,8}
        3,  // for {15,30,10,20,25}
        3,  // for {100,200,300,400,500}
        3,  // for {3,6,2,8,4,7}
        2   // for {1000000,1000000,1000000}
    };

    for(int i = 0; i < testCases.size(); i++)
    {
        cout << "Test case " << i + 1 << ": ";
        cout << func(testCases[i], painters[i]) << endl;
    }

    return 0;
    return 0;
}