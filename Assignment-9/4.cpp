#include <iostream>
#include <climits>
using namespace std;

int main() {
    int V, E;
    cin >> V;   
    cin >> E;   

    int graph[100][100];
    int INF = INT_MAX;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int src;
    cin >> src;   

    int dist[100];
    bool visited[100];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minDist = INF;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; 
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex\tDistance from source " << src << "\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << "\t" << "INF" << "\n";
        else
            cout << i << "\t" << dist[i] << "\n";
    }

    return 0;
}
