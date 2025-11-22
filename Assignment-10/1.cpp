#include <iostream>
#include <vector>
using namespace std;

class GraphMatrix
{
    int n;
    vector<vector<int>> matrix;

public:
    GraphMatrix(int vertices)
    {
        n = vertices;
        matrix.assign(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v)
    {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void display()
    {
        cout << "\nAdjacency Matrix:\n";
        for (auto &row : matrix)
        {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }
    }

    int degree(int v)
    {
        int deg = 0;
        for (int i = 0; i < n; i++)
            deg += matrix[v][i];
        return deg;
    }

    void adjacentVertices(int v)
    {
        cout << "Adjacent vertices of " << v << ": ";
        for (int i = 0; i < n; i++)
            if (matrix[v][i] == 1)
                cout << i << " ";
        cout << endl;
    }

    int numberOfEdges()
    {
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (matrix[i][j] == 1)
                    count++;
        return count;
    }
};

int main()
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    GraphMatrix g(n);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.display();

    int v;
    cout << "Enter vertex to find degree: ";
    cin >> v;
    cout << "Degree: " << g.degree(v) << endl;

    cout << "Enter vertex to find adjacent vertices: ";
    cin >> v;
    g.adjacentVertices(v);

    cout << "Total number of edges: " << g.numberOfEdges() << endl;

    return 0;
}
