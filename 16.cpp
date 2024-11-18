#include <iostream>
using namespace std;

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

void insert_edge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
    cout << "Edge inserted between " << u << " and " << v << "." << endl;
}

void display_graph(int n)
{
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(int start, int n)
{
    int queue[MAX_NODES], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = true;

    cout << "BFS traversal: ";
    while (front < rear)
    {
        int node = queue[front++];
        cout << node << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

void dfs(int node, int n)
{
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs(i, n);
        }
    }
}

int main()
{
    int n, choice;

    cout << "Enter number of nodes in the graph: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    while (true)
    {

        cout << "1. Insert Edge" << endl;
        cout << "2. Display Graph" << endl;
        cout << "3. BFS Traversal" << endl;
        cout << "4. DFS Traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int u, v;
            cout << "Enter nodes to connect (u v): ";
            cin >> u >> v;
            if (u >= 0 && u < n && v >= 0 && v < n)
            {
                insert_edge(u, v);
            }
            else
            {
                cout << "Invalid nodes!" << endl;
            }
            break;
        }
        case 2:
            display_graph(n);
            break;
        case 3:
        {
            int start;
            cout << "Enter starting node for BFS: ";
            cin >> start;
            if (start >= 0 && start < n)
            {
                for (int i = 0; i < n; i++)
                    visited[i] = false;
                bfs(start, n);
            }
            else
            {
                cout << "Invalid starting node!" << endl;
            }
            break;
        }
        case 4:
        {
            int start;
            cout << "Enter starting node for DFS: ";
            cin >> start;
            if (start >= 0 && start < n)
            {
                for (int i = 0; i < n; i++)
                    visited[i] = false;
                cout << "DFS traversal: ";
                dfs(start, n);
                cout << endl;
            }
            else
            {
                cout << "Invalid starting node!" << endl;
            }
            break;
        }
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}