#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isArmstrong(int n){
    int ans = 0;
    int number = n;
    while(number!=0){
        int digit = number%10;
        ans += digit * digit * digit;
        number/=10; 
    }

    if(ans == n){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    cout << isArmstrong(153);
    return 0;
}