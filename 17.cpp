#include <iostream>
using namespace std;

const int INF = 1e9;
int graph[100][100], parent[100], ranks[100], n, m;

struct Edge
{
    int u, v, weight;
};

int dist[100], visited[100];

void initialize()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int find(int u)
{
    if (u != parent[u])
    {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void union_sets(int u, int v)
{
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v)
    {
        if (ranks[root_u] > ranks[root_v])
        {
            parent[root_v] = root_u;
        }
        else if (ranks[root_u] < ranks[root_v])
        {
            parent[root_u] = root_v;
        }
        else
        {
            parent[root_v] = root_u;
            ranks[root_u]++;
        }
    }
}

void insertionSort(Edge edges[], int edgeCount)
{
    for (int i = 1; i < edgeCount; i++)
    {
        Edge key = edges[i];
        int j = i - 1;
        while (j >= 0 && edges[j].weight > key.weight)
        {
            edges[j + 1] = edges[j];
            j = j - 1;
        }
        edges[j + 1] = key;
    }
}

void dijkstra(int source)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != INF && !visited[v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from source node " << source << " are:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
        {
            cout << "Node " << i << ": INF" << endl;
        }
        else
        {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
}

void kruskal()
{
    Edge edges[100];
    int edgeCount = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] != INF)
            {
                edges[edgeCount++] = {i, j, graph[i][j]};
            }
        }
    }

    insertionSort(edges, edgeCount);

    int mstWeight = 0;
    int mstEdges = 0;
    initialize();

    cout << "Edges in the Minimum Spanning Tree (MST):" << endl;
    for (int i = 0; i < edgeCount && mstEdges < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v))
        {
            union_sets(u, v);
            cout << u << " - " << v << " with weight " << edges[i].weight << endl;
            mstWeight += edges[i].weight;
            mstEdges++;
        }
    }

    cout << "Total Weight of MST: " << mstWeight << endl;
}

int main()
{
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                graph[i][j] = INF;
            else
                graph[i][j] = 0;
        }
    }

    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int choice;

    while (true)
    {

        cout << "1. Run Dijkstra's Algorithm\n";
        cout << "2. Run Kruskal's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int source;
            cout << "Enter the source node for Dijkstra: ";
            cin >> source;
            dijkstra(source);
            break;
        }
        case 2:
        {
            kruskal();
            break;
        }
        case 3:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}