#include <stdio.h>
#include "func.h"

#define MAX_INT 1000000
/* Adjacency table */
class Graph2 {
private:
    int _v;
    int *_dis;
    int* _s_p;
    int* _e_p;
    int* _w;
    int* first;
    int* next;
    int edge_num;

public:
    Graph2(int v, int edge) {
        _v = v;
        /*source point of edge*/
        _s_p = new int[edge];
        /*end point of edge*/
        _e_p = new int[edge];
        /*weight*/
        _w = new int[edge];

        first = new int[v];
        next = new int[v];
        _dis = new int[v];
        edge_num = 0;
    }

    void addEdge(int s, int t, int w) {
        _s_p[edge_num] = s;
        _e_p[edge_num] = t;
        _w[edge_num] = w;
        if (first[s] != MAX_INT) {
            /* store the next edge number of point s */
            next[edge_num - 1] = first[s];
            first[s] = edge_num - 1;
        } else {
            /* store the edge number of point s */
            first[s] = edge_num - 1;
        }
        edge_num++;
    }

    void initDis() {
        for (int i=0; i < _v; ++i) {
            _dis[i] = MAX_INT;
        }
        _dis[1] = 0;
    }

    int getEdgeNum() {
        return edge_num;
    }

    int getDis(int i) {
        return _dis[i];
    }

    /** check the distance if get shorter when
     * bring in the edge number i
     * 
     */
    bool updateDis(int i) {
        if (_dis[_e_p[i]] > _dis[_s_p[i]] + _w[i]) {
            _dis[_e_p[i]] = _dis[_s_p[i]] + _w[i];
            return true;
        }
        return false;
    }

    bool checkDisCircle(int i) {
        if (_dis[_e_p[i]] > _dis[_s_p[i]] + _w[i]) {
            return true;
        }
        return false;
    }
};

/**
* (1) - -3 -> (2) - 2 -> (3)
*  |                     |
*  5                     3      
*  v                     \/
* (5) <----   2    ---- (4)
*/

int bellman_ford_test() {
    Graph2* g = new Graph2(6, 10);
    g->addEdge(1, 2, -3);
    g->addEdge(1, 5, 5);
    g->addEdge(2, 3, 2);
    g->addEdge(3, 4, 3);
    g->addEdge(4, 5, 2);

    g->initDis();

    printf("bellman-ford test:\n");
    /** for each vertex */
    for (int i=1; i < 6; i++) {
        bool update = false;
        for (int j=0; j < g->getEdgeNum(); j++) {
            update = g->updateDis(j);
        }
        if (!update) {
            break;
        }
    }
    
    int have_circle = false;
    for (int i=0; i < g->getEdgeNum(); i++) {
        if (g->checkDisCircle(i)) {
            have_circle = true;
            break;
        }
    }
    if (have_circle) {
        printf("have circle\n");
    } else {
        for (int i=1; i < 6; i++) {
            printf("%d ", g->getDis(i));
        }
    }
    printf("\n");

    delete g;
    return 0;
}