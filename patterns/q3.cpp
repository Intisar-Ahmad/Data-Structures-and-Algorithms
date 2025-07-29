#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i <= 4; i++)
    {

        for (int j = 1; j < i; j++)
        {
          cout<<" ";
        }
        

        for (int j = 4; j >= i; j--)
        {
            cout<<i;
        }
        cout<<endl;
    }
    
    return 0;
}