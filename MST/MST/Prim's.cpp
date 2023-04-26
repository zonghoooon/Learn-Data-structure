#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

vector<Edge> prim(int n, vector<vector<pair<int, int>>>& adj) {
    vector<Edge> result;
    vector<bool> visited(n, false);
    priority_queue<tuple<int, int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    visited[0] = true;
    for (auto& edge : adj[0]) {
        pq.push(make_tuple(edge.second, edge.first ,0));
    }
    while (!pq.empty()) {
        int weight = get<0>(pq.top());
        int u = get<1>(pq.top());
        int pre = get<2>(pq.top());
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        result.push_back({ pre, u, weight });
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!visited[v]) {
                pq.push(make_tuple(w, v, u));
            }
        }
        pre = u;
    }
    return result;
}

int main() {
    int n = 6;
    vector<vector<pair<int, int>>> adj(n);
    adj[0].push_back({ 1, 1 });
    adj[0].push_back({ 2, 4 });
    adj[0].push_back({ 3, 3 });
    adj[1].push_back({ 0, 1 });
    adj[1].push_back({ 3, 2 });
    adj[2].push_back({ 0, 4 });
    adj[2].push_back({ 3, 5 });
    adj[3].push_back({ 0, 3 });
    adj[3].push_back({ 1, 2 });
    adj[3].push_back({ 2, 5 });

    vector<Edge> result = prim(n, adj);

    int weight = 0;

    for (Edge edge : result) {
        weight += edge.weight;
        cout << edge.u << " - " << edge.v <<  endl;
    }
    cout << weight << endl;
    return 0;
}