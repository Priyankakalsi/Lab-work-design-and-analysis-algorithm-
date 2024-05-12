#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph
{
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices) : V(vertices)
    {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void print()
    {
        cout << "Graph:" << endl;
        for (int i = 0; i < V; ++i)
        {
            cout << "Vertex " << i << " -> ";
            for (auto &neighbor : adj[i])
            {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    void dijkstra(int src)
    {
        vector<int> dist(V, numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto &neighbor : adj[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Vertex   Distance from Source" << endl;
        for (int i = 0; i < V; ++i)
            cout << i << "\t\t" << dist[i] << endl;
    }
};

int main()
{
    int size;
    cout << "Enter number of Edges: ";
    cin >> size;
    Graph g(size);

    char ch;
    int start, u, v, w;
    do
    {
        cout << "Options: ";
        cout << "\n\t1: Add an Edge";
        cout << "\n\t2: Dijkstra";
        cout << "\n\t3: Print Graph";
        cout << "\n\tQ: Quit";
        cout << "\nChoose: ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            cout << "Enter Vertex 1: ";
            cin >> u;
            cout << "Enter Vertex 2: ";
            cin >> v;
            cout << "Enter Edge Weight: ";
            cin >> w;
            g.addEdge(u, v, w);
            break;
        case '2':
            cout << "Enter Starting Edge: ";
            cin >> start;
            g.dijkstra(start);
            break;
        case '3':
            g.print();
            break;
        case 'Q':
        case 'q':
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid Option";
            break;
        }
        cout << "\n\n";
    } while (ch != 'Q' && ch != 'q');

    return 0;
}
