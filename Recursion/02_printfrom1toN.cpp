#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int n,int i){
    if(i <= n){
        cout << i << endl;
        print(n,i+1);
    }
}

int main() {
    print(5,1);
    return 0;
}