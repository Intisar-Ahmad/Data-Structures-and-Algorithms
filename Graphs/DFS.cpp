#include <iostream>
#include <vector>
#include <string>


using namespace std;

vector<bool> visited(7,false);

void dfs(int startingNode,int numberOfNodes, vector<vector<int>> matrix,string names[]) {
  
    int j;
  cout << names[startingNode] << " ";
    visited[startingNode] = true;

  for (int j = 0; j < numberOfNodes; j++)
  {
    if(matrix[startingNode][j] && !visited[j]){
        dfs(j,numberOfNodes,matrix,names);
    }
  }
  
}

int main() {
    string cities[] = {"London", "Paris", "Berlin", "Rome"};
    int n = 4;

    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0}, // London
        {1, 0, 0, 1}, // Paris
        {1, 0, 0, 1}, // Berlin
        {0, 1, 1, 0}  // Rome
    };

    cout << "DFS Traversal starting from Berlin:" << endl;
    dfs(2,n,adjMatrix,cities);

    return 0;
}