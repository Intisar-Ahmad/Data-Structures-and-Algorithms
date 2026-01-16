#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int bestbuy = prices[0];
        int n = prices.size();
        for(int i =1; i < n;i++){
            if(prices[i] < bestbuy){
                bestbuy = prices[i];
                continue;
            }
            if((prices[i] - bestbuy) > maxprofit){
                maxprofit = (prices[i] - bestbuy);
            }

        }
        return maxprofit;
    }

int main() {
 
    return 0;
}