#include <iostream>
#include<vector>
using namespace std;

int secondLargestElement(vector<int> array){
    int max = INT_MIN;
    int secondMax = max;
    for (int i = 0; i < array.size(); i++)
    {
        if(array[i] > max){
            secondMax = max;
            max = array[i];
        }
        else if(array[i] > secondMax && array[i] < max){
            secondMax = array[i];
        }
    }
    return secondMax;
}

int main() {
    vector<int> arr = {2,3,5,1,6,3,7,2,-3};
    cout<<secondLargestElement(arr);
    return 0;
}