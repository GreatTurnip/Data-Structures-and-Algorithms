#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

const int INF = INT16_MAX;

int main()
{
    int V,E;
    cin >> V >> E;

    vector <vector<pair<int,int>>> adj(V);

    for(int i = 0; i < E; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

    }
    int source;
    cin >> source;

    vector <int> key(V, INF);
    vector <bool> visited(V,false);
    vector <int> parent(V, -1);

    priority_queue<pair<int,int>,
        vector <pair <int,int>>,
        greater<pair<int,int>>> pq;
    

}