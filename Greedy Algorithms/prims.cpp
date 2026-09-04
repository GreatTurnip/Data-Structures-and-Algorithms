#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

using namespace std;

const int INF = INT_FAST64_MAX;

int main()
{
    int V, E;
    cin >> V >> E;
    using P = pair<int, int>;
    vector < vector <P> > adj(V);

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    int source; 
    cin >> source;

    vector <int> key(V, INF);
    vector <bool> visited(V, false);
    vector <int> parent(V, -1);

    priority_queue<P, vector <P>, greater<P>> pq;

    key[source] = 0;
    pq.push({0, source});
    while(!pq.empty())
    {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(visited[u])  continue;

        for(auto edge: adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if(!visited[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }

            visited[u] = true;
        }
    }
    int totalCost = 0;
    for(int i = 0; i < V; i++)
    {
        if(parent[i] != -1)
            totalCost += key[i];
    }
    cout << "Total MST Cost = " << totalCost << endl;
    return 0;
}