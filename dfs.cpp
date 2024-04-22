#include<bits/stdc++.h>

using namespace std;

// Function to perform Depth First Search (DFS)
void dfs(int src, int a[][5], vector<int> &visited , int n)
{
    visited[src] = 1; // Mark the source node as visited
    cout << src << endl; // Print the visited node
    for( int i = 0; i < n; i++) // Loop through all nodes
    {
        // If there is an edge from the source to this node and it has not been visited yet
        if(a[src][i] == 1 && visited[i] != 1)
        {
            dfs(i, a, visited, n); // Recursively call DFS for this node
        }
    }

}

int main()
{
    // Adjacency matrix representation of the graph
    int a[][5] = {
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1},
        {0,0,1,0,0},
        {0,0,1,1,0}
    };

    int src = 0; // Starting node for DFS
    vector<int>visited(5,0); // Vector to keep track of visited nodes
    visited[src] = 1; // Mark the source node as visited
    int n = 5; // Number of nodes in the graph
    dfs(src, a, visited, n); // Call DFS function
}
