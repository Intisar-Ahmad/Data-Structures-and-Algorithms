#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<j+1;
        }
        cout<<endl;
    }
   

    //they did it with a nested loop but i did with a single one.
    for (int i = 1; i <= 9; i++)
    {
      cout<<i;
      if(i%3 == 0){
        cout<<endl;
      }
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<(i*3 + j + 1);
        }
        cout<<endl;
    }
    
    
    return 0;
}