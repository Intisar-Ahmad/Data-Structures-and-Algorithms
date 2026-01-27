#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>

using namespace std;

class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int h = heights[s.top()];
        s.pop();
        int w = s.empty() ? n : n - s.top() - 1;
        maxArea = max(maxArea, h * w);
    }

    return maxArea;
   }
};

int main() {
 
    
    return 0;
}