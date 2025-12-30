#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void bfs(int startingNode,int numberOfNode,vector<vector<int>> matrix,string names[]){
    vector<bool> visited(numberOfNode,false);
    queue<int> q;
    
    visited[startingNode];
    q.push(startingNode);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        cout << names[curr] << " ";

        for (int i = 0; i < numberOfNode; i++)
        {
           if(matrix[curr][i] && !visited[i]){
            visited[i] = true;
            q.push(i);
           }
        }

    }


    cout << endl;
}

int main() {
   
    string cities[] = {"London", "Paris", "Berlin", "Rome"};
    int n = 4;



    // 2. Adjacency Matrix
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0}, // London
        {1, 0, 0, 1}, // Paris
        {1, 0, 0, 1}, // Berlin
        {0, 1, 1, 0}  // Rome
    };

    bfs(2, n, adjMatrix, cities);

    return 0;
}