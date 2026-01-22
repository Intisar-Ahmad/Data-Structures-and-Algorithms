#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while(i >= 0 && (digits[i]+1)%10 == 0){
            digits[i]=(digits[i]+1)%10;
            i--;
        }
        if(i < 0) digits.insert(digits.begin(), 1);
        else digits[i]+=1;


        return digits; 
    }

int main() {
 
    return 0;
}