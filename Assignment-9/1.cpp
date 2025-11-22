#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

class Graph {
    int V;
    Node** adj;   

public:
    Graph(int V) {
        this->V = V;
        adj = new Node*[V];

        for (int i = 0; i < V; i++)
            adj[i] = NULL;
    }

    void addEdge(int u, int v) {
        Node* newNode = new Node();
        newNode->vertex = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = new Node();
        newNode->vertex = u;
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    void BFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            Node* temp = adj[curr];
            while (temp != NULL) {
                int neighbor = temp->vertex;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
                temp = temp->next;
            }
        }

        cout << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    g.BFS(start);

    return 0;
}
