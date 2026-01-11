#include<iostream>

using namespace std;

int mostWater(int arr[],int size){
    int st = 0;
    int end = size - 1;
    int maxArea = -1000000; // imagine this as the lowest integer possible
    
    while(st < end){
        int width = end - st;
        int minHeight = min(arr[st],arr[end]);
        int area = width * minHeight;

        maxArea = max(area,maxArea);

        if(minHeight == arr[st]){
            st++;
        }
        else{
            end--;
        }

    }

    return maxArea;
}

int main(int argc,char **argv) {
    int arr[5] = {92, 85, 77, 88, 91};
    int temps[7] = {72, 68, 75, 70, 69, 74, 71};
    int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};


    int areaArr = mostWater(arr,5);
    int areaTemps = mostWater(temps,7);
    int areaPrimes = mostWater(primes,8);


    printf("%d is the area of arr, %d is the area of temps,%d is the area of primes\n",areaArr,areaTemps,areaPrimes);


    return 0;
}