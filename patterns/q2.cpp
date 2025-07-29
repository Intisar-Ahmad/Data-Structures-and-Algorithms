#include <iostream>

using namespace std;

int main() {

    for (int i = 0; i < 5; i++)
    {
     for (int j = 0; j <= i; j++)
     {
       cout<<j;
     }
     cout<<endl;
    }


    for (int i = 1; i <= 4; i++)
    {
        for (int j = i; j > 0; j--)
        {
         cout<<j;
        }
        cout<<endl;
        
    }
    
    int num = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
          cout<<num;
          num++;
        }
        cout<<endl;
    }
    
    
    return 0;
}