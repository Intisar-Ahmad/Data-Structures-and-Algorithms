#include <iostream>
#include <vector>
using namespace std;

// the selection sort described in the book uses additional memory. So, it has a space complexity of O(n). We are going to do it in O(1) space.

void selectionSort(vector<int> &array)
{
    int size = array.size();
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < size; i++)
    {
        min = INT_MAX;
        for (int j = i; j < size; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                minIndex = j;
            }
        }
        array[minIndex] = array[i];
        array[i] = min;
    }
}

void displayArr(const vector<int> &array ){
    for (auto &&i : array)
    {
        cout << i << " ";
    }
    cout << endl;   
}

void revSelectionSort(vector<int> &array){
    int size = array.size();
    int max = INT_MIN;
    int maxIndex = -1;
    for (int i = 0; i < size; i++)
    {
        max = INT_MIN;
        for (int j = i; j < size; j++)
        {
            if (array[j] > max)
            {
                max = array[j];
                maxIndex = j;
            }
        }
        array[maxIndex] = array[i];
        array[i] = max;
    }
}
int main()
{
    vector<int> arr = {3, 1, 6, -4, 3, 10};

    selectionSort(arr);
    displayArr(arr);
    revSelectionSort(arr);
    displayArr(arr);
    return 0;
}