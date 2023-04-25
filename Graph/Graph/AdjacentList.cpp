#include <iostream>

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
        for (int i = 0; i < num;i++) {
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

    void Delete(int a, int b) {
        if (a >= n || b >= n) return;
        Node* temp = nodeList[a];
        Node* pre = NULL;
        while (true) {
            if (temp->num== b) break;
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;
        delete(temp);
    }

    void Check(int a) {
        if (a >= n) return;
        cout << a << ": ";
        Node* temp = nodeList[a];
        while (true) {
            if (temp == NULL) break;
            cout << temp->num << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
};

int main()
{
    Graph* graph = new Graph(4);

    graph->Insert(0, 1);
    graph->Insert(0, 2);
    graph->Insert(0, 3);
    graph->Insert(1, 0);
    graph->Insert(1, 3);
    graph->Insert(2, 0);
    graph->Insert(2, 3);
    graph->Insert(3, 0);
    graph->Insert(3, 1);
    graph->Insert(3, 2);

    graph->Check(0);
    graph->Check(1);
    graph->Check(2);
    graph->Check(3);
    
}
