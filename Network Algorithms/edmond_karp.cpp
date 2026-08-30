#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>

using namespace std;

#define V 6  //this graph here only has 6 vertex

bool bfs(int residual_graph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited)); // set all the visited values to false

    queue <int> q;
    // push source into the queue
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v = 0; v < V; v++)
        {
            if(visited[v] == false && residual_graph[u][v] > 0)
            {
                // if the vertex we just just discovered is a sink then we found an augmented path
                if(v == t)
                {
                    // set parent (important)
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true; // set the visited to true so that the bfs doesnt repetedly encounter it
            }
        }
    }

    return false; // no sink is found
}

int edmond_karp(int graph[V][V], int s, int t)
{
    int u, v;

    int residual_graph[V][V];

    for(int u = 0; u < V; u++)
        for(int v =0; v < V; v++)
        {
            residual_graph[u][v] = graph[u][v];
        }
    
    int parent[V];
    int max_flow = 0; 
    while(bfs(residual_graph, s, t, parent))
    {
        // first find the bottleneck
        int path_flow = INT_MAX;

        for(v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, residual_graph[u][v]);
        }
        for(v = t; v != s; v = parent[v]) // go from the target to the source
        {
            //extract the parent
            u = parent[v];

            residual_graph[u][v] -= path_flow;
            residual_graph[u][v] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int graph[V][V]
        = { { 0, 16, 13, 0,  0, 0 }, 
            { 0, 0,  10, 12, 0, 0 },
            { 0, 4,   0, 0, 14, 0 },  
            { 0, 0,   9, 0,  0, 20},
            { 0, 0,   0, 7,  0, 4 }, 
            { 0, 0,   0, 0,  0, 0 } };

    cout << "The maximum possible flow is "
         << edmond_karp(graph, 0, 5);

    return 0;
}