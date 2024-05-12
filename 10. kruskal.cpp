
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

vector<Edge> kruskalMST(vector<Edge>& edges, int numNodes) {
    vector<Edge> MST;
    vector<Subset> subsets(numNodes);
    for (int i = 0; i < numNodes; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    sort(edges.begin(), edges.end(), compareEdges);
    int edgeCount = 0, i = 0;
    while (edgeCount < numNodes - 1 && i < edges.size()) {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            MST.push_back(nextEdge);
            unionSets(subsets, x, y);
            edgeCount++;
        }
    }
    return MST;
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<Edge> edges(numEdges);
    for (int i = 0; i < numEdges; ++i)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    vector<Edge> MST = kruskalMST(edges, numNodes);
    for (const Edge& edge : MST)
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    return 0;
}
