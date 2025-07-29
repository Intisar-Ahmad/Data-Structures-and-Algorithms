#include <iostream>

using namespace std;

int main() {

    int n =7;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i ; j--)
        {
            cout<<" ";
        }
        cout<<"*";
        for (int j = i*2-1; j > 0; j--)
        {
            cout<<" ";
        }
        if(i>0){
            cout<<"*";
        }
        cout<<endl;
        
    }
    

    for (int i = n-1; i > 0; i--)
    {
        for (int j = i; j <=n-1; j++)
        {
            cout<<" ";
        }
        cout<<"*";
        for (int j = i*2; j > 3 ; j--)
        {
         cout<<" ";
        }
        if(i > 1){
            cout<<"*";
        }
        cout<<endl;
        
    }
    
    return 0;
}