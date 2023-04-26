#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int u;
    int v;
    int weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

//해당 노드의 부모 노드를 찾는 메소드
int find(vector<int>& parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

vector<Edge> kruskal(int n, vector<Edge>& edges) {
    vector<Edge> result;
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
        });
    for (Edge edge : edges) {
        int root1 = find(parent, edge.u);
        int root2 = find(parent, edge.v);
        if (root1 != root2) {
            result.push_back(edge);
            parent[root1] = root2;
        }
    }
    return result;
}


int main() {
    int n = 6;
    vector<Edge> edges = {
        Edge(0, 1, 1),
        Edge(0, 2, 4),
        Edge(0, 3, 3),
        Edge(1, 3, 2),
        Edge(2, 3, 5)
 
    };
    vector<Edge> result = kruskal(n, edges);
    int weight = 0;
    for (Edge edge : result) {
        weight += edge.weight;
        cout << edge.u << " - " << edge.v << endl;
    }
    cout << "total weight: " << weight << endl;
    return 0;
}
