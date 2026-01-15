#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);
        int result = 0;
        for(int i = 2;i<n;i++){
            if(isPrime[i]){
                result++;
                for(int j = i * 2;j<n;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        return result;
    }

int main() {
 
    return 0;
}