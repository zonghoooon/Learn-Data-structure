#include <iostream>
#include <string>
#include <queue>
#define MAX 50
using namespace std;

class Graph {
public:
    int n; // 정점 개수
    bool mat[MAX][MAX];

    Graph(int num) {
        n = num;
        fill(&mat[0][0], &mat[num - 1][num], false);
    }

    void Insert(int a, int b) {
        if (a >= n || b >= n) return;
        mat[a][b] = true;
        mat[b][a] = true;
    }

    bool Check(int a, int b) {
        if (a >= n || b >= n) return false;
        return mat[a][b];
    }
};

void dfs(Graph* graph, int v, bool visited[],int target, string way) {
    if (target == v) {
        way += to_string(v);
        cout << way << endl;
        return;
    }
    visited[v] = true;
    for (int i = 0; i < graph->n; i++) {
        if (graph->mat[v][i] && !visited[i]) {
            string temp = way + to_string(v)+"->";
            dfs(graph, i, visited, target, temp);
        }
    }
}

void bfs(Graph* graph, int v, int target, bool visited[]) {
    queue<pair<int,string>> q;
    visited[v] = true;

    q.push({ v,to_string(v)+"->"});
    while (!q.empty()) {
        int temp = q.front().first;
        string way = q.front().second;
        q.pop();
        for (int i = 0; i < graph->n; i++) {
            if (graph->mat[temp][i] && !visited[i]) {
                if (i == target) {
                    cout << way + to_string(i) << endl;
                    return;
                }
                visited[i] = true;
                string t = way + to_string(i) + "->";
                q.push({ i,t });
            }
        }
    }
}

int main()
{
    Graph* graph = new Graph(5);

    graph->Insert(0, 1);
    graph->Insert(0, 2);
    graph->Insert(0, 3);
    graph->Insert(1, 3);
    graph->Insert(2, 4);

    bool visited[5] = { false };
    string way = "";
    //dfs(graph, 0, visited, 4, way);
    bfs(graph, 0, 4, visited);

}

