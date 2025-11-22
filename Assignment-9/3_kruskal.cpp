#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    int parent[100], rankArr[100];

    void init(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rankArr[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (rankArr[a] < rankArr[b])
            swap(a, b);

        parent[b] = a;
        if (rankArr[a] == rankArr[b])
            rankArr[a]++;
        return true;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    Edge edges[100];

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges, edges + E, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DSU dsu;
    dsu.init(V);

    int mst_weight = 0;

    cout << "Edges in Kruskal MST:\n";

    for (int i = 0; i < E; i++) {
        if (dsu.unite(edges[i].u, edges[i].v)) {
            cout << edges[i].u << " - " << edges[i].v 
                 << " (w=" << edges[i].w << ")\n";
            mst_weight += edges[i].w;
        }
    }

    cout << "Total weight: " << mst_weight << endl;
    return 0;
}
