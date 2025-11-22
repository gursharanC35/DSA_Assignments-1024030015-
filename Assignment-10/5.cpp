
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> mst(n, false);

    key[0] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!mst[i] && (u == -1 || key[i] < key[u]))
                u = i;

        mst[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (g[u][v] && !mst[v] && g[u][v] < key[v])
            {
                key[v] = g[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim MST:\n";
    int total = 0;
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i << " (" << g[i][parent[i]] << ")\n";
        total += g[i][parent[i]];
    }
    cout << "Total Weight = " << total << endl;

    return 0;
}
