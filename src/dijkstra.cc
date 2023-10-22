#include <iostream>
#include "func.h"

#define MAX_INT 1000000
/**
 * @brief   dijkstra algorithm
 * get the shortest path from A to B with weight
 * 
*/
class Graph {
private:
    int _v;
    int** _matrix;
    int* _dis;
    int* _book;

public:
    Graph(int v) {
        _v = v;
        _matrix = new int*[v];
        _dis = new int[v];
        _book = new int[v];
        for (int i=0; i < v; ++i) {
            _matrix[i] = new int[v];
            _dis[i] = 0;
            _book[i] = 0;
            for (int j=0; j < v; ++j) {
                _matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int s, int t, int w1, int w2) {
      _matrix[s][t] = w1;
      _matrix[t][s] = w2;
    }

    void initDis() {
        for (int i=1; i < _v; ++i) {
            _dis[i] = _matrix[1][i];
        }
    }

    void initBook() {
        _book[1] = 1;
    }

    int** getMetrix() {
        return _matrix;
    }

    int* getDis() {
        return _dis;
    }

    int* getBook() {
        return _book;
    }
};

/* Adjacency table */
class Graph2 {
private:
    int _v;
    int* _s_p;
    int* _e_p;
    int* _w;
    int* first;
    int* next;
    int edge_num = 0;

public:
    Graph2(int v) {
        _v = v;
        /*source point*/
        _s_p = new int[v];
        /*end point*/
        _e_p = new int[v];
        /*weight*/
        _w = new int[v];

        first = new int[v];
        next = new int[v];
    }

    void addEdge(int s, int t, int w) {
        _s_p[edge_num++] = s;
        _e_p[edge_num++] = t;
        _w[edge_num++] = w;
        if (first[s] != MAX_INT) {
            /* store the next edge number of point s */
            next[edge_num - 1] = first[s];
            first[s] = edge_num - 1;
        } else {
            /* store the edge number of point s */
            first[s] = edge_num - 1;
        }
    }
};

/**
* (1) - 1 -> (2) - 3 -> (4) - 15 -> (6)
*  |      /        /    |         /.
*  12    9      4       13       4
*  v  ./   ./          .|.    /
* (3) ----   5     ----> (5)
*/

int dijkstra_test() {
    Graph g = Graph(7);
    g.addEdge(1, 2, 1, MAX_INT);
    g.addEdge(1, 3, 12, MAX_INT);
    g.addEdge(1, 4, MAX_INT, MAX_INT);
    g.addEdge(1, 5, MAX_INT, MAX_INT);
    g.addEdge(1, 6, MAX_INT, MAX_INT);
    g.addEdge(2, 3, 9, MAX_INT);
    g.addEdge(2, 4, 3, MAX_INT);
    g.addEdge(2, 5, MAX_INT, MAX_INT);
    g.addEdge(2, 6, MAX_INT, MAX_INT);
    g.addEdge(3, 4, MAX_INT, 4);
    g.addEdge(3, 5, 5, MAX_INT);
    g.addEdge(3, 6, MAX_INT, MAX_INT);
    g.addEdge(4, 5, 13, MAX_INT);
    g.addEdge(4, 6, 15, MAX_INT);
    g.addEdge(5, 6, 4, MAX_INT);

    g.initDis();
    g.initBook();

    std::cout << "dijkstra test:" << std::endl;
    int u = 1;
    for (int i=1; i < 7; i++) {
        int min = MAX_INT;
        /*
         * get the shortest point u relative to 1 from unvisited
         * point.
         * book is used to record the point has been visited.
         */
        for (int j=1; j < 7; j++) {
            if (g.getBook()[j] == 0 && g.getDis()[j] < min) {
                min = g.getDis()[j];
                u = j;
            }
        }
        g.getBook()[u] = 1;
        /* update the shortest path relative to u */
        for (int v=1; v < 7; v++) {
            if (g.getMetrix()[u][v] < MAX_INT) {
                if (g.getDis()[v] > g.getDis()[u] + g.getMetrix()[u][v]) {
                    g.getDis()[v] = g.getDis()[u] + g.getMetrix()[u][v];
                    std::cout << "u: " << u << ", v: " << v << ", dis: " 
                              << g.getDis()[v] << std::endl;
                }
            }
        }
    }
    
    for (int j=1; j < 7; j++) {
        std::cout << g.getDis()[j] << " ";
    }
    std::cout << std::endl;
    return 0;
}