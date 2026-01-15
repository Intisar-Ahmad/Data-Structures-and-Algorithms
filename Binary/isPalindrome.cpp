#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;
    bool isPalindrome(int x) {
        int revNum = 0;
        int copy = x;

        if(x < 0) return false;
        while(x!=0){
            int digit = x%10;

            if(revNum > INT_MAX/10 || revNum < INT_MIN/10) return 0;

            revNum = revNum * 10 + digit;
            x/=10;
        }

        return revNum==copy;

    }


int main() {
 
    return 0;
}