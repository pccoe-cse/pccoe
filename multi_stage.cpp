// Include necessary libraries
#include<iostream>
#include<climits>
using namespace std;

int main(){
      // Ask user for the number of vertices
      cout<<"Enter the no. of vertices"<<endl;
      int ver ;
      cin>>ver;

      // Initialize adjacency matrix
      int adj_mat[ver][ver];

      cout<<"Give the weights of graph"<<endl;

      // Set all weights to 0 initially
      for(int i=0;i<ver;i++){
            for(int j=0;j<ver;j++){
                  adj_mat[i][j]=0;
            }
      }

      // Ask user to enter weights for each edge
      for(int i=0;i<ver;i++){
            for(int j=i+1;j<ver;j++){
                  cout<<"Enter for "<<i<<"-"<<j<<endl;
                  cin>>adj_mat[i][j];
            }
      }

      // Print the entered graph
      cout<<"Entered graph is"<<endl;
      for(int i=0;i<ver;i++){
            for(int j=0;j<ver;j++){
                  cout<<adj_mat[i][j]<<"\t";
            }
            cout<<endl;
      }
      
      int min;
      int cost[ver];
      int dist[ver];

      // Initialize cost and distance arrays
      for(int i=0;i<ver;i++){
            dist[i] = INT_MAX ;
            cost[i] = 0 ;
      }

      dist[ver-1] = -1;          //note...........

      // Calculate minimum cost and distance
      for(int i=ver-2;i>=0;i--){
            min = INT_MAX;
            for(int j=ver-1;j>i;j--){
                  if(adj_mat[i][j]>0 && ((adj_mat[i][j]  + cost[j]) < min)){
                        cost[i] = adj_mat[i][j]  + cost[j] ;
                        min = cost[i] ;
                        dist[i] = j ;
                  }
            }
      }

      // Print the minimum cost
      cout<<"The minimun cost of a path is --> "<<cost[0]<<endl;
      int i=0;

      // Print the shortest path
      cout<<"And the shortest path is --->"<<endl;
      cout<<"0-";
      while(dist[i]!=-1){
            cout<<dist[i]<<"-";
            i = dist[i] ;
      }
      return 0;
}

/*Enter the no. of vertices
7
Give the weights of graph
Enter for 0-1
1 2 7 0 0 0 0 0 3 6 0 0 4 10 0 0 3 10 0 8 2


Enter for 0-2
Enter for 0-3
Enter for 0-4
Enter for 0-5
Enter for 0-6
Enter for 1-2
Enter for 1-3
Enter for 1-4
Enter for 1-5
Enter for 1-6
Enter for 2-3
Enter for 2-4
Enter for 2-5
Enter for 2-6
Enter for 3-4
Enter for 3-5
Enter for 3-6
Enter for 4-5
Enter for 4-6
Enter for 5-6
Entered graph is
0	1	2	7	0	0	0	
0	0	0	0	3	6	0	
0	0	0	0	4	10	0	
0	0	0	0	0	3	10	
0	0	0	0	0	0	8	
0	0	0	0	0	0	2	
0	0	0	0	0	0	0	
The minimun cost of a path is --> 9
And the shortest path is --->
0-1-5-6-*/