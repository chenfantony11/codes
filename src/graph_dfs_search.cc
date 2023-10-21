#include <iostream>
#include "func.h"

/*
 * @brief   Deep first search algorithm for graph
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
    void dfs(int v) {
        /* current vertex */
        std::cout << v << " ";
        /* if all vertex have been visited, return */
        if (v == _v) {
            return;
        }

        /* if vertex have edge, visit it */
        for (int i = v + 1; i <= _v; i++) {
            if (_matrix[v][i] == true && _visited[i] == false) {
                _visited[i] = true;
                dfs(i);
            }
        }
        return;
    }
};

/*
 * .  (1) - (2) - (4)
 *     |  \
 *    (3) - (5)
 *
 */
int graph_dfs_test() {
    /* build graph */
    Graph g = Graph(5, 1);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(1, 5);

    /* start from 1 */
    g.enterVertex(1);

    std::cout << "graph dfs test:" << std::endl;
    /* dfs */
    g.dfs(1);
    std::cout << std::endl;
    return 0;
}