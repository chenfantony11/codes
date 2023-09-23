#include <stdio.h>
#include "func.h"

/*
 * @brief   breath first search algorithm for graph
 * graph: 5x5
 * Adjacency matrix
 */
class Graph {
private:
    int _v;
    bool _matrix[10][10];
    int _visited[10] = {0};
    int _count;

public:  
    Graph(int v, int from) {
        _v = v;
        _count = _v + from;
        for (int i=from; i < _count; ++i) {
            for (int j=from; j < _count; ++j) {
                _matrix[i][j] = false;
            }
        }
    }

    void enterVertex(int v) {
        _visited[v] = true;
    }

    void addEdge(int s, int t) {
      _matrix[s][t] = true;
      _matrix[t][s] = true;
    }

    /*
    * @brief   Deep first search algorithm
    * @param   from vertex
    * find the short path from the start node to the end node
    */ 
    void bfs(int v) {
        int queue[10000];
        int head = 0, tail = 0;
        queue[tail++] = v;
        /* current vertex */
        printf("%d ", v);
        while(head < tail) {
            int v = queue[head++];
            /* if all vertex have been visited, return */
            if (v == _v) {
                return;
            }

            /* if vertex have edge, visit it */
            for (int i = v + 1; i <= _v; i++) {
                if (_matrix[v][i] &&!_visited[i]) {
                    printf("%d ", i);
                    _visited[i] = true;
                    queue[tail++] = i;
                }
            }
        }
    }
};

/*
 * .  (1) - (2) - (4)
 *     |  \
 *    (3) - (5)
 *
 */
int graph_bfs_test() {
    /* build graph */
    Graph* g = new Graph(5, 1);
    g->addEdge(1, 3);
    g->addEdge(1, 2);
    g->addEdge(2, 4);
    g->addEdge(3, 5);
    g->addEdge(1, 5);

    /* start from 1 */
    g->enterVertex(1);

    printf("graph bfs test:\n");
    /* dfs */
    g->bfs(1);
    delete g;
    printf("\n");
    return 0;
}