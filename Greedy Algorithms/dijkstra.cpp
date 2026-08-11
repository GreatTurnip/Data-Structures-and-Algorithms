#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = INT32_MAX;

int main()
{
    int V, E;
    cin >> V >> E;
    using P = pair<int, int>;
    vector<vector<P>> adj(V); // one list for every vertices
    for(int i = 0; i < E; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    int source;
    cin >> source;

    vector<int> dist(V,INF);
    vector<bool> visited(V,false);
    vector<int> parent(V, -1);

    priority_queue<P,vector<P>,greater<P>> pq;
    dist[source] = 0;
    parent[source] = -1;
    pq.push({0,source});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) // if already processed no need for process again
            continue;
        for(auto edge : adj[u]) // loop through all the neighbours
        {
            int v = edge.first;
            int weight = edge.second;
            if(!visited[v] && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v],v});
            }
        }
        visited[u] = true;
    }

    cout << "Shortest Distances " << endl;
    for(int i = 0; i < V; i++)
        cout << i << " : " << dist[i] << endl;
    cout << "Parents : " << endl;
    for(int i = 0; i < V; i++)
        cout << i << " <- " << parent[i] << endl;
    
    return 0;
}