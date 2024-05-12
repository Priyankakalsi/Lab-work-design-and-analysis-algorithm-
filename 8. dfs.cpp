// Write a program to implement Depth-First-Search for graph

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform Depth-First Search
void DFS(vector<vector<int>> &graph, int startNode)
{
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false); // To keep track of visited nodes
    stack<int> nodeStack;

    nodeStack.push(startNode);
    visited[startNode] = true;

    cout << "Depth-First Traversal starting from node " << startNode << ": ";

    while (!nodeStack.empty())
    {
        int currentNode = nodeStack.top();
        nodeStack.pop();
        cout << currentNode << " ";

        // Traverse all adjacent nodes of currentNode
        for (int adjacentNode : graph[currentNode])
        {
            if (!visited[adjacentNode])
            {
                nodeStack.push(adjacentNode);
                visited[adjacentNode] = true;
            }
        }
    }

    cout << endl;
}

int main()
{
    int numNodes, numEdges;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < numEdges; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    DFS(graph, startNode);

    return 0;
}
