#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m; // n is the number is vertices and m is the color we can use
vector <vector<int>> graph;
vector<int> soln;


bool isSafe(int vertex, int colour) // this checks if 'colour' can be used safely in 'vertex'
{
    for(int i = 1; i <= n; i++)
    {
        if (graph[vertex][i] == 1 && soln[i] == colour)
            return false;
    }   
    return true;
}

void mColoring(int vertex)
{
    // base case
    if(vertex > n)
    {
        static int solutionNo = 1;

        cout << "Solution : " << solutionNo++ << endl;
        for(int i = 1; i <= n; i++)
        {
            cout << soln[i] << endl;
        }
        cout << endl;
        return;
    }

    for(int colour = 1; colour <= m; colour ++)
    {
        if(isSafe(vertex, colour))
        {
            soln[vertex] = colour;
            mColoring(vertex + 1);
            // backtrack condition 0 is just a marker for empty
            soln[vertex] = 0;
        }
    }
}
int main()
{
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of colors : ";
    cin >> m;
    cout << "Enter adjacency matrix" << endl;
    graph.resize(n + 1, vector <int> (n + 1));
    soln.resize(n + 1, 0);

    cout << "Enter adjacency matrix" << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> graph[i][j];
    }

    mColoring(1);
    return 0;

}