#include <iostream>
#include<vector>

using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

int BruteForce(vector<int> arr){
    int size = arr.size();
    int maxProfit = INT_MIN;
    for (int i = 0; i < size - 1; i++)
    {
        int currProfit = 0;
        for (int j = i + 1; j < size ; j++)
        {
            currProfit = arr[j] - arr[i];
            maxProfit = max(maxProfit,currProfit);
        }
        
    }
    if(maxProfit > 0) return maxProfit;
    else return 0;
}


int optimized(vector<int> arr){
    int size = arr.size();
    int buyingDay = INT_MAX;
    int sellingDay = INT_MIN;
    int maxProfit = INT_MIN;
    for (int i = 1; i < size; i++)
    {
       
       if(arr[i - 1] < buyingDay) buyingDay = arr[i - 1];
       sellingDay = arr[i];
       int currProfit = sellingDay - buyingDay;
       maxProfit = max(maxProfit,currProfit);
    }
    
    if(maxProfit > 0) return maxProfit;
    else return 0;

}

int main() {
    vector<int> arr = {7,1,5,3,6,2};
    cout<<BruteForce(arr) << endl;

    cout<<optimized(arr) << endl;
    return 0;
}