#include <iostream>

using namespace std;

//pow(x,n) meaning x^n

int Power(int x,int n){

    if(n == 0 || x == 1) return 1;
    else if(n == 1) return x;

    int binary = n;
    int ans = 1;
    int currX = x;

    if(binary < 0){
        x = 1/x;
        binary = -binary;
    }

    while(binary > 0){
        if(binary%2 == 1){
            ans *= currX;
        }
        currX *= currX;
        binary/=2;
    }

    return ans;
}

int main() {
   cout<< Power(3,5);
    return 0;
}