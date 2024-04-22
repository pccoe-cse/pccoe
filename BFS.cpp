// Include necessary libraries
#include<bits/stdc++.h>

// Use the standard namespace
using namespace std;

// Function to perform Breadth-First Search (BFS) on a graph
void bfs(int a[][5], int src, int n)
{
    // Create a queue to hold nodes to visit
    queue<int>q;
    // Create a vector to keep track of visited nodes
    vector<int>visited(n);

    // Add the source node to the queue
    q.push(src);
    // While there are nodes to visit
    while(!q.empty())
    {
        // Get the next node to visit
        int t = q.front();
        // Print the node
        cout << t << endl;
        // Remove the node from the queue
        q.pop();
        // For each node in the graph
        for(int i = 0; i < n; i++)
        {
            // If there is an edge from the current node to the node i and node i has not been visited
            if(a[t][i] == 1 && visited[i] != 1)
            {
                // Mark node i as visited
                visited[i] = 1;
                // Add node i to the queue
                q.push(i);
            }
        }

    }
}

// Main function
int main()
{
    // Define the adjacency matrix of the graph
    int a[][5] = {
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1},
        {0,0,1,0,0},
        {0,0,1,1,0}
    };

    // Define the source node
    int src = 0;
    // Define the number of nodes in the graph
    int n = 5;
    // Perform BFS on the graph
    bfs(a ,src, n);
}