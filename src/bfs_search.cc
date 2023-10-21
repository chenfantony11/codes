#include <iostream>
#include <memory>
#include "func.h"

// map
static int Array[5][4] = {
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 1},
};

static int Book[5][4] = {};
static int startx = 0, starty = 0, endx = 3, endy = 2;
static int min = 10000;

struct queue_node {
    int x;
    int y;
    int s;
};

class queue {
private:
    struct queue_node que[10000];
    int head;
    int tail;
public:

    explicit queue() : head(0), tail(0) {}
    void addElement(queue_node &node) {
        que[tail] = node;
        tail = (tail + 1) % 10000;
    }

    void removeElement() {
        head++;
    }

    int getHeadIndex() {
        return head;
    }

    int getTailIndex() {
        return tail;
    }

    queue_node getHead() {
        return que[head];
    }
};

void enqueue(queue &queue, queue_node element) {
    queue.addElement(element);
}

void dequeue(queue &queue) {
    queue.removeElement();
}

/*
 * @brief   breadth first search algorithm
 * @param   step: step number
 * find the short path from the start node to the end node
 */ 
void bfs(int x, int y, int step) {
    /* next step, right, down, left, up */
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int found = 0;
    queue que;
    queue_node node = {
        .x = x,
        .y = y,
        .s = step,
    };
    enqueue(que, node);
    Book[x][y] = 1;

    while (que.getHeadIndex() < que.getTailIndex()) {
        for (int i = 0; i < 4; i++) {
            int newx = que.getHead().x + next[i][0];
            int newy = que.getHead().y + next[i][1];

            if (newx < 0 || newy < 0 || newx >= 5 || newy >= 4) {
                continue;
            }
            if (Array[newx][newy] == 0 && Book[newx][newy] == 0) {
                // add new node to queue
                queue_node newNode = {
                    .x = newx,
                    .y = newy,
                    .s = que.getHead().s + 1,
                };
                enqueue(que, newNode);
                Book[newx][newy] = 1;
            }
            if (newx == endx && newy == endy) {
                if (que.getHead().s + 1 < min) {
                    min = que.getHead().s + 1;
                }
                found = 1;
                break;
            }
        }
        if (found == 1) {
            break;
        }
        dequeue(que);
    }
}

int bfs_test() {
    int step = 0;
    bfs(startx, starty, 0);
    std::cout << "bfs test: " << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << Book[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "min: " << min << std::endl;
    return 0;
}