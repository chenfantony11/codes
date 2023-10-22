#include <iostream>
#include "func.h"

#define MAX_INT 1000000
/**
 * @brief   floyd warshall algorithm
 * multiple source shortest path
 * 
*/
class Graph {
private:
    int _v;
    int** _matrix;
    int _count;

public:
    Graph(int v) {
        _v = v;
        _matrix = new int*[v];
        for (int i=0; i < v; ++i) {
            _matrix[i] = new int[v];
            for (int j=0; j < v; ++j) {
                _matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int s, int t, int w1, int w2) {
      _matrix[s][t] = w1;
      _matrix[t][s] = w2;
    }

    int** getMetrix() {
        return _matrix;
    }
};

/**
 *    (1)  -- 4 -->  (4)
 *     |  <-- 5 --   |  ^
 *     2  \  +       12 |
 *     |    \6 \7    |  1
 *     v      +  \   v  |
 *    (2) -- 3 -->  (3)
*/

int floyd_warshall_test() {
    Graph g = Graph(5);
    g.addEdge(1, 2, 2, MAX_INT);
    g.addEdge(1, 3, 6, 7);
    g.addEdge(1, 4, 4, 5);
    g.addEdge(2, 3, 3, MAX_INT);
    g.addEdge(3, 4, 1, 12);
    g.addEdge(2, 4, MAX_INT, MAX_INT);

    int** e = g.getMetrix();
    
    std::cout << "floyd warshall test:" << std::endl;
    for (int i=1; i < 5; i++) {
        for (int j=1; j < 5; j++) {
            if(e[i][j] == MAX_INT) {
                std::cout << "  ";
            } else {
                std::cout << e[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }

    /**
     * make a new vertex from number 1 as the mid point,
     * check the a -> 1 ->b if short than a -> b, if shorter,
     * then update a->b as the shorter value.
    */
    for (int i=1; i < 5; i++) {
        for (int j=1; j < 5; j++) {
            for (int k=1; k < 5; k++) {
                if (e[j][k] > e[j][i] + e[i][k]) {
                    e[j][k] = e[j][i] + e[i][k];
                }
            }
        }
    }

    std::cout << "after sort:" << std::endl;
    for (int i=1; i < 5; i++) {
        for (int j=1; j < 5; j++) {
            std::cout << e[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}