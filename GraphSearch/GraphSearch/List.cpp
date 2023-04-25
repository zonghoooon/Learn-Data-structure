#include <iostream>
#include <string>
#include <queue>

#define MAX 50
using namespace std;
class Node {
public:
    int num;
    Node* next;

    Node(int temp) {
        num = temp;
        next = NULL;
    }
};
class Graph {
public:
    int n; // 정점 개수
    Node* nodeList[MAX];

    Graph(int num) {
        n = num;
        for (int i = 0; i < num; i++) {
            nodeList[i] = NULL;
        }
    }

    void Insert(int a, int b) {
        if (a >= n || b >= n) return;
        if (nodeList[a] == NULL)  nodeList[a] = new Node(b);
        else {
            Node* temp = nodeList[a];
            while (true) {
                if (temp->next == NULL) break;
                temp = temp->next;
            }
            temp->next = new Node(b);
        }

    }
};

void dfs(Graph* graph, int v, bool visited[], int target, string way) {
    if (target == v) {
        way += to_string(v);
        cout << way << endl;
        return;
    }
    visited[v] = true;
    Node* temp = graph->nodeList[v];
    while (temp != NULL) {
        string t = way + to_string(v) + "->";
        if (!visited[temp->num]) dfs(graph, temp->num, visited, target, t);
        temp = temp->next;

    }
}

void bfs(Graph* graph, int v, int target, bool visited[]) {
    queue<pair<int, string>> q;
    visited[v] = true;

    q.push({ v,to_string(v) + "->" });
    while (!q.empty()) {
        int temp = q.front().first;
        string way = q.front().second;
        q.pop();

        Node* node = graph->nodeList[temp];
        while (node != NULL) {
            if (!visited[node->num]) {
                if (node->num == target) {
                    cout << way + to_string(node->num) << endl;
                    return;
                }
                visited[node->num] = true;
                string t = way + to_string(node->num) + "->";
                q.push({ node->num,t });
            }
            node = node->next;
        }
    }
}

int main() {
    Graph* graph = new Graph(5);

    graph->Insert(0, 1);
    graph->Insert(0, 2);
    graph->Insert(0, 3);
    graph->Insert(1, 0);
    graph->Insert(1, 3);
    graph->Insert(2, 0);
    graph->Insert(2, 4);
    graph->Insert(3, 0);
    graph->Insert(3, 1);

    bool visited[5] = { false };
    string way = "";
    //dfs(graph, 0, visited, 4, way);
    bfs(graph, 0, 4, visited);

}
