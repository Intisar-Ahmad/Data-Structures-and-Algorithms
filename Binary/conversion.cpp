#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int DtoB(int n)
{
    int accumulator = 0;
    int power = 0;
    if (n == 1 || n == 0)
    {
        return n;
    }
    while (n > 0)
    {
        if(n%2 == 1){
            accumulator+=pow(10,power);
        }
        power++;
        n /= 2;
    }
    return accumulator;
}

int BtoD(int n){
    int accumulator = 0;
    int power = 0;
    if(n == 1 || n == 0){
        return n;
    }

    while(n > 0){
        if(n%10== 1){
            accumulator+=pow(2,power);
        }
        power++;
        n/=10;
    }
    return accumulator;
}

int DtoBneg(int n){
    //assuming n is negative
    // to take the two's compliment I first have to convert the number into binary.



    n=-n;// to convert n into its positive form;
    //1. Converted check


    int binary = DtoB(n);
    // 2.Binary check



    // now that i have the binary value. I must prefix it with a 0,
    int power = 0;


    // now i need to replace the 0s and 1s;
    int onesCompliment = 0;
    while(binary>0){
        if(binary%10 == 0){
            onesCompliment+=pow(10,power);
        }
       power++;
        binary/=10;
    }
     onesCompliment+=pow(10,power);
     binary = onesCompliment;
    // final step, add a 1 but its binary addition.
    power = 0;
    for (int i = binary;i%10 != 0; i/=10)
    {
        power++;
    }

    binary += pow(10,power); 
    return binary;
    
}

int main()
{
    cout << DtoB(21) << endl;
     cout << BtoD(10110) << endl;
     cout << DtoBneg(-21) << endl;
    return 0;
}