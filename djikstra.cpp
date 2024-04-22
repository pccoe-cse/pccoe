#include<bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

// Define a 2D array to represent the graph. 999 represents infinity or no edge.
int graph[5][5] = { { 999, 6, 10, 999, 999 },   // 0
            { 999, 999, 2, 8, 14 },   // 1
            { 999, 2, 999, 3, 3 },   // 2
            { 999, 999, 999, 999, 2 },   // 3
            { 999, 999, 999, 6, 999 } };
/**
 * Represents a graph and calculates the shortest distances from a source node to all other nodes using Dijkstra's algorithm.
 */

void Graph()
{
  // Initialize visited array to keep track of visited nodes
  int visited[] = {0, 0, 0, 0, 0};
  
  // Initialize distance array with infinity (999) except for the source node (0)
  int distance[] = {0, 999, 999, 999 ,999};

  int k = 0, u;
  while(k < 5) // Loop until all nodes are visited
  {
  int max = 999;
  for(int i = 0; i < 5; i++) // Find the node with the smallest distance that hasn't been visited
  {
    if(distance[i] < max && visited[i] != 1)
    {
    max = distance[i];
    u = i;
    }
  }
  visited[u] = 1; // Mark the node as visited
  for(int i = 0; i < 5; i++) // Update the distances of the neighboring nodes
  {
    if(graph[u][i] != 999) // If there is an edge
    {
    if(graph[u][i] + distance[u] < distance[i]) // If the new distance is smaller
    {
      distance[i] = graph[u][i] + distance[u]; // Update the distance
    }
    }
  }
  k++;
  }
  for(int i = 0; i < 5; i++) // Print the shortest distances from the source node to all other nodes
  {
  cout << distance[i] << endl;
  }
}

int main()
{
  Graph(); // Call the function to execute Dijkstra's algorithm
}