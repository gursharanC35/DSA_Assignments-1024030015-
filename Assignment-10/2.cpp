
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int n;
    vector<vector<int>> adj;

public:
    Graph(int v)
    {
        n = v;
        adj.resize(n);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start)
    {
        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int x : adj[node])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
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
    cout << "Enter edge pairs (u v):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    g.BFS(start);
    return 0;
}
