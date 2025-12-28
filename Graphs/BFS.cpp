#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void bfs(int startNode, int numberofNodes, const vector<vector<int>>& matrix, const string names[]) {
    vector<bool> visited(numberofNodes, false);
    queue<int> q;

    // start with the initial node
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // Use the 'names' array to see "what" this element is
        cout << names[curr] << " ";

        // Check all potential neighbors in the matrix row
        for (int neighbor = 0; neighbor < numberofNodes; neighbor++) {
            // If there is a connection (1) and it's not visited
            if (matrix[curr][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
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

    bfs(0, n, adjMatrix, cities);

    return 0;
}