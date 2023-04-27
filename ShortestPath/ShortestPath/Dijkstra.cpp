#include <iostream>
#include <string>
#include <queue>
#include <vector>

#define MAX 50
#define INF 987654321

using namespace std;
class Node {
public:
    int num;
    int weight;
    Node* next;

    Node(int temp,int w) {
        num = temp;
        weight = w;
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

    void Insert(int a, int b,int w) {
        if (a >= n || b >= n) return;
        if (nodeList[a] == NULL)  nodeList[a] = new Node(b,w);
        else {
            Node* temp = nodeList[a];
            while (true) {
                if (temp->next == NULL) break;
                temp = temp->next;
            }
            temp->next = new Node(b,w);
        }
        if (nodeList[b] == NULL)  nodeList[b] = new Node(a, w);
        else {
            Node* temp = nodeList[b];
            while (true) {
                if (temp->next == NULL) break;
                temp = temp->next;
            }
            temp->next = new Node(a, w);
        }

    }
};

void Dijkstra(Graph& g, int start, int end) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < g.n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[start] = 0;

    while (!visited[end]) {
        int minDist = INF;
        int curr = -1;

        for (int i = 0; i < g.n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                curr = i;
                minDist = dist[i];
            }
        }

        visited[curr] = true;

        for (Node* p = g.nodeList[curr]; p != NULL; p = p->next) {
            int next = p->num;
            int weight = p->weight;

            if (!visited[next] && dist[next] > dist[curr] + weight) {
                dist[next] = dist[curr] + weight;
            }
        }
    }

    cout << "최단 거리: " << dist[end] << endl;
}


int main()
{
    Graph g(5);

    g.Insert(0, 1, 1);
    g.Insert(0, 2, 5);
    g.Insert(0, 3, 3);
    g.Insert(1, 3, 2);
    g.Insert(2, 4, 2);
    g.Insert(3, 4, 3);

    Dijkstra(g, 0, 4);
}
