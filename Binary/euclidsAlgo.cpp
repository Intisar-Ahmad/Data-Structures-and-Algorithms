#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a,int b){
   while(a > 0 && b > 0){
    if(a>b) a = a%b;
    else b = b%a;
   }
   if(a==0) return b;
   return a;
}

int lcm(int a,int b){
    int lcm = (a*b)/gcd(a,b);
    return lcm;
}

int main() {
    cout << gcd(25,35);
    return 0;
}