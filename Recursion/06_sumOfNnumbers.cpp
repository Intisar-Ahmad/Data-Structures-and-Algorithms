#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void add(int n,int &sum){
    if(n < 1) return;
    add(n-1,sum);
    sum+=n;
}

void add2(int n,int sum){
    if(n < 1){
        cout << sum << endl;
        return;
    }
    sum+=n;
    add2(n-1,sum);
}

int add3(int n){
    if(n <= 1) return n;
    return n + add3(n-1);
}

int main() {
    int sum = 0;
    add(5,sum);
    add2(5,0);
    cout << add3(5) << endl;

    cout << sum << endl;
    return 0;
}