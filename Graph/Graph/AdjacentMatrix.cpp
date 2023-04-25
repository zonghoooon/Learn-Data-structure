#include <iostream>

#define MAX 50

using namespace std;

class Graph {
public:
    int n; // 정점 개수
    bool mat[MAX][MAX];

    Graph(int num) {
        n = num;
        fill(&mat[0][0], &mat[num-1][num], false);
    }

    void Insert(int a, int b) {
        if (a >= n || b >= n) return;
        mat[a][b] = true;
        mat[b][a] = true;
    }

    void Delete(int a, int b) {
        if (a >= n || b >= n) return;
        mat[a][b] = false;
        mat[b][a] = false;
    }

    bool Check(int a, int b) {
        if (a >= n || b >= n) return false;
        return mat[a][b];
    }
};

int main()
{
    Graph* graph = new Graph(4);

    graph->Insert(0, 1);
    graph->Insert(0, 2);
    graph->Insert(0, 3);
    graph->Insert(1, 3);
    graph->Insert(2, 3);

    for (int i = 0; i < 4;i++) {
        for (int j = 0; j < 4; j++) {
            cout << graph->Check(i, j) << " ";
        }
        cout << endl;
    }
}
