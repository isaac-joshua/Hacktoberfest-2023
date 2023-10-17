#include <bits/stdc++.h> 
using namespace std; 
#define V 4 

#define INF 99999 

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V]) 
{
    int dist[V][V];
    int i, j, k;

    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            dist[i][j] = graph[i][j]; 

    for (k = 0; k < V; k++) 
    { 
        for (i = 0; i < V; i++) 
        { 
            for (j = 0; j < V; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 

    printSolution(dist); 
}

/* A utility function to print solution */
void printSolution(int dist[][V]) 
{ 
    cout << "The following matrix shows the shortest distances"
            " between every pair of vertices \n"; 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            if (dist[i][j] == INF) 
                cout << "INF\t"; 
            else
                cout << dist[i][j] << "\t"; 
        } 
        cout << endl; 
    } 
}

// Driver code 
int main() 
{ 
    int graph[V][V] = { {0, 5, INF, 10}, 
                        {INF, 0, 3, INF}, 
                        {INF, INF, 0, 1}, 
                        {INF, INF, INF, 0} 
                    }; 

    // Print the solution 
    floydWarshall(graph); 
    return 0;
}
