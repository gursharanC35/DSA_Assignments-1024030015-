
#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int n;
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    Graph(int v)
    {
        n = v;
        adj.resize(n);
        visited.assign(n, false);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSUtil(int node)
    {
        visited[node] = true;
        cout << node << " ";

        for (int x : adj[node])
        {
            if (!visited[x])
                DFSUtil(x);
        }
    }

    void DFS(int start)
    {
        cout << "DFS Traversal: ";
        DFSUtil(start);
        cout << endl;
    }
};

int main()
{
    int n, e;
    cout << "Enter vertices: ";
    cin >> n;

    Graph g(n);

    cout << "Enter edges: ";
    cin >> e;
    cout << "Enter (u v):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Start vertex: ";
    cin >> start;

    g.DFS(start);
}
