#include <iostream>
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

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;          
        cout << v << " ";           

        Node* temp = adj[v];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited); 
            }
            temp = temp->next;
        }
    }

    void DFS(int start) {
        bool* visited = new bool[V];

        for (int i = 0; i < V; i++)
            visited[i] = false;

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
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

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cin >> start;

    g.DFS(start);
    return 0;
}
