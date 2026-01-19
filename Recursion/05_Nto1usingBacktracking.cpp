#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int n,int i){
    if(n < 1) return;

    print(n-1,i+1);
    cout << i << endl;
}

int main() {
    print(5,1);
    return 0;
}