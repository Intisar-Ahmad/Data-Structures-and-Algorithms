#include <iostream>
#include <vector>
using namespace std;

// For adjacent pairs

void BruteForce(vector<int> arr, int target)
{
    int size = arr.size();
    if (arr[0] + arr[1] == target)
    {
        cout << "The pair sum is " << 0 << " and " << 1 << endl;
        return;
    }
    if (arr[size - 1] + arr[size - 2] == target)
    {
        cout << "The pair sum is " << size - 1 << " and " << size - 2 << endl;
        return;
    }

    for (int i = 1; i < size - 1; i++)
    {
        if (arr[i] + arr[i + 1] == target)
        {
            cout << "The pair sum is " << i << " and " << i + 1 << endl;
            return;
        }
        else if (arr[i] + arr[i - 1] == target)
        {
            cout << "The pair sum is " << i << " and " << i - 1 << endl;
            return;
        }

            
       
    }
    cout << "Pair sum doesn't exist" << endl;
}

vector<int> optimized(vector<int> arr,int target)
{
    int size = arr.size();
    int low = 1;
    int high = size - 2;
    vector<int> ans;
    if(arr[0] + arr[1] == target) {
        ans.push_back(0);
        ans.push_back(1);
    }
    else if(arr[size - 1] + arr[size - 2] == target){
        ans.push_back(size - 1);
        ans.push_back(size - 2);
    }
    else {
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] > target/2.0){
                if(arr[mid] + arr[mid - 1] == target){
                    ans.push_back(mid);
                    ans.push_back(mid - 1);
                    break;
                }
                else{
                    high = mid - 1;
                }
            }
           else if(arr[mid] < target/2.0){
                if(arr[mid] + arr[mid + 1] == target){
                    ans.push_back(mid);
                    ans.push_back(mid + 1);
                    break;
                }
                else{
                    low = mid + 1;
                }
            }
           else {
                if(arr[mid] + arr[mid + 1] == target){
                    ans.push_back(mid);
                    ans.push_back(mid + 1);
                    break;
                }
                else if(arr[mid] + arr[mid - 1] == target){
                    ans.push_back(mid);
                    ans.push_back(mid - 1);
                    break;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        
    }
    return ans;
}

void displayArr(const vector<int> &array ){
    for (auto &&i : array)
    {
        cout << i << " ";
    }
    cout << endl;   
}


//For random pairs

vector<int> BruteRandomForce(vector<int> arr,int target){
    vector<int> ans;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(arr[i] + arr[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
        
    }
    return ans;
}

vector<int> TwoSum(vector<int> arr,int target){
    vector<int> ans;
    int size = arr.size();
    int start = 0;
    int end = size - 1;

    while(start<=end){
        int add = arr[start] + arr[end];
        if(add > target){
            end--;
        }
        else if(add < target){
            start++;
        }
        else{
            ans.push_back(start);
            ans.push_back(end);
            break;
        }
    }

    return ans;
}

// For non-sorted array



int main()
{

    // For adjacent pairs
    vector<int> vec1 = {1,3,5,6,7,7,8};
    BruteForce(vec1,8);
    BruteForce(vec1,13);

    vector<int> ans1 = optimized(vec1,8);
    vector<int> ans2 = optimized(vec1,13);

    displayArr(ans1);
    displayArr(ans2);



    //For random ones
    vector<int> vec2 = {2,3,6,7,12,14,21,22};



    vector<int> ans4 = BruteRandomForce(vec2,21);
    vector<int> ans5 = TwoSum(vec2,21);
    // displayArr(ans4);
    displayArr(ans5);

    return 0;
}