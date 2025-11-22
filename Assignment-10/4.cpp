

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

class DSU
{
    vector<int> parent, rankv;

public:
    DSU(int n)
    {
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (rankv[x] < rankv[y])
            parent[x] = y;
        else if (rankv[x] > rankv[y])
            parent[y] = x;
        else
        {
            parent[y] = x;
            rankv[x]++;
        }
    }
};

int main()
{
    int n, e;
    cout << "Vertices: ";
    cin >> n;
    cout << "Edges: ";
    cin >> e;

    vector<Edge> edges(e);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         { return a.w < b.w; });

    DSU dsu(n);
    int totalCost = 0;

    cout << "Kruskal MST:\n";
    for (auto &ed : edges)
    {
        if (dsu.find(ed.u) != dsu.find(ed.v))
        {
            dsu.unite(ed.u, ed.v);
            cout << ed.u << " - " << ed.v << " (" << ed.w << ")\n";
            totalCost += ed.w;
        }
    }

    cout << "Total Weight = " << totalCost << endl;
}
