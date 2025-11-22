#include <iostream>
#include <climits>
using namespace std;

int main() {
    int V;
    cin >> V;

    int graph[100][100];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    int E;
    cin >> E;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    bool visited[100];
    int key[100];
    int parent[100];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, minKey = INT_MAX;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int mst_weight = 0;

    cout << "Edges in Prim MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i 
             << " (w=" << graph[i][parent[i]] << ")\n";
        mst_weight += graph[i][parent[i]];
    }

    cout << "Total weight: " << mst_weight << endl;
    return 0;
}
