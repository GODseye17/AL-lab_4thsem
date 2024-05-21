#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_NODES = 100; // Maximum number of nodes in the graph

int graph[MAX_NODES][MAX_NODES];
int maxClique[MAX_NODES];
int maxCliqueSize = 0;

bool isClique(int clique[], int cliqueSize, int newNode) {
    for (int i = 0; i < cliqueSize; i++) {
        if (graph[clique[i]][newNode] == 0)
            return false;
    }
    return true;
}

void findMaxClique(int clique[], int cliqueSize, int remainingNodes, int node) {
    if (remainingNodes == 0) {
        if (cliqueSize > maxCliqueSize) {
            maxCliqueSize = cliqueSize;
            for (int i = 0; i < cliqueSize; i++) {
                maxClique[i] = clique[i];
            }
        }
        return;
    }

    if (cliqueSize + remainingNodes <= maxCliqueSize)
        return;

    for (int i = node; i < MAX_NODES; i++) {
        if (isClique(clique, cliqueSize, i)) {
            clique[cliqueSize] = i;
            findMaxClique(clique, cliqueSize + 1, remainingNodes - 1, i + 1);
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;

    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1][node2] = graph[node2][node1] = 1;
    }

    int clique[MAX_NODES];
    findMaxClique(clique, 0, numNodes, 0);

   cout << "Maximum Clique: ";
for (int i = 0; i < maxCliqueSize; i++) {
    maxClique[i]=clique[i];
    cout << maxClique[i] << " ";
}
cout << endl;

    cout << endl;

    return 0;
}
