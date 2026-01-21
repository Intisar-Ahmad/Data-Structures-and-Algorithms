#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void func(vector<vector<int>> &mat, int r, int c, vector<string> &ans, string &s, vector<vector<bool>> &visited)
{
    if (r < 0 || c < 0 || r == mat.size() || c == mat.size() || mat[r][c] == 0 || visited[r][c])
    {
        // s.pop_back();
        return;
    }
    if (r == mat.size() - 1 && c == r)
    {
        ans.push_back(s);
        return;
    }
    visited[r][c] = true;
    // go up
    s.push_back('U');
    func(mat, r - 1, c, ans, s, visited);
    s.pop_back();
    // go down
    s.push_back('D');
    func(mat, r + 1, c, ans, s, visited);
    s.pop_back();
    // go left
    s.push_back('L');
    func(mat, r, c - 1, ans, s, visited);
    s.pop_back();
    // go right
    s.push_back('R');
    func(mat, r, c + 1, ans, s, visited);
    s.pop_back();
    visited[r][c] = false;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    vector<vector<bool>> visited(mat.size(), vector(mat.size(), false));
    string s = "";
    vector<string> ans;

    func(mat, 0, 0, ans, s, visited);

    for (auto &&i : ans)
    {
        cout << i << endl;
    }

    return 0;
}