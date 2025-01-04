// Implementation of Smart City Design Business Cases in C++
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// Issue: Intermittency (DFS)
void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

// Issue: High Costs (Dijkstra's Algorithm)
void Dijkstra(int src, vector<vector<pair<int, int>>> &graph, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &edge : graph[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << ": INF" << endl;
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
}

// Issue: Land Use (Prim's Algorithm)
void Prim(vector<vector<pair<int, int>>> &graph, int n) {
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;
    for (int count = 0; count < n - 1; ++count) {
        int u = -1;
        for (int i = 0; i < n; ++i) {
            if (!mstSet[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        mstSet[u] = true;

        for (auto &[v, weight] : graph[u]) {
            if (!mstSet[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    cout << "MST Edges:\n";
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

// Issue: Recycling (Quick Sort)
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Issue: Public Participation (BFS)
void BFS(int start, vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Issue: Transparency (Bellman-Ford Algorithm)
void BellmanFord(int src, vector<vector<pair<int, int>>> &graph, int n) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (auto &[v, weight] : graph[u]) {
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << ": INF" << endl;
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
}

// Issue: Efficiency (Floyd-Warshall Algorithm)
void FloydWarshall(vector<vector<int>> &dist, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of nodes:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    // Business Case 1: Renewable Energy
    cout << "Business Case 1: Renewable Energy\n";

    // Intermittency - DFS
    vector<vector<int>> adj1 = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    vector<bool> visited(4, false);
    cout << "DFS Traversal: ";
    DFS(0, adj1, visited);
    cout << endl;

    // High Costs - Dijkstra's Algorithm
    vector<vector<pair<int, int>>> graph1 = {{{1, 1}, {2, 4}}, {{0, 1}, {2, 2}, {3, 6}}, {{0, 4}, {1, 2}, {3, 3}}, {{1, 6}, {2, 3}}};
    Dijkstra(0, graph1, 4);

    // Land Use - Prim's Algorithm
    Prim(graph1, 4);

    // Recycling - Quick Sort
    vector<int> arr = {4, 2, 7, 3, 8, 1};
    quickSort(arr, 0, arr.size() - 1);
    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Business Case 2: Smart Governance Approaches
    cout << "\nBusiness Case 2: Smart Governance Approaches\n";

    // Public Participation - BFS
    vector<vector<int>> adj2 = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    cout << "BFS Traversal: ";
    BFS(0, adj2);
    cout << endl;

    // Transparency - Bellman-Ford Algorithm
    vector<vector<pair<int, int>>> graph2 = {{{1, 1}, {2, 4}}, {{2, 2}}, {{3, 3}}, {}};
    BellmanFord(0, graph2, 4);

    // Efficiency - Floyd-Warshall Algorithm
    vector<vector<int>> dist = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0}};
    FloydWarshall(dist, 4);

    return 0;
}
