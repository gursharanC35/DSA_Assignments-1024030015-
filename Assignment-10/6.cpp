

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout << "Enter vertices: ";
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));
    cout << "Enter weighted adjacency matrix (0=no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    vector<int> dist(n, INT_MAX);
    vector<bool> used(n, false);

    dist[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        used[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (g[u][v] && dist[u] + g[u][v] < dist[v])
            {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }

    cout << "Dijkstra shortest distances:\n";
    for (int i = 0; i < n; i++)
        cout << "To " << i << " = " << dist[i] << endl;
}
