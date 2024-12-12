#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define SIZE 5

int graph[SIZE][SIZE] = {
    {0, 2, 0, 1, 0},
    {2, 0, 3, 2, 5},
    {0, 3, 0, 0, 1},
    {1, 2, 0, 0, 4},
    {0, 5, 1, 4, 0}
};

int heuristics[SIZE] = {7, 6, 2, 1, 0};

typedef struct {
    int node;
    int heuristic;
} PriorityQueueNode;

PriorityQueueNode priorityQueue[SIZE];
int pqSize = 0;

void insert(int node) {
    int i = pqSize;
    priorityQueue[pqSize].node = node;
    priorityQueue[pqSize].heuristic = heuristics[node];
    pqSize++;

    while (i > 0 && priorityQueue[i].heuristic < priorityQueue[(i - 1) / 2].heuristic) {
        PriorityQueueNode temp = priorityQueue[i];
        priorityQueue[i] = priorityQueue[(i - 1) / 2];
        priorityQueue[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int removeMin() {
    if (pqSize == 0) return -1;

    int minNode = priorityQueue[0].node;
    priorityQueue[0] = priorityQueue[pqSize - 1];
    pqSize--;

    int i = 0;
    while (2 * i + 1 < pqSize) {
        int smallestChild = 2 * i + 1;
        if (2 * i + 2 < pqSize && priorityQueue[2 * i + 2].heuristic < priorityQueue[smallestChild].heuristic) {
            smallestChild = 2 * i + 2;
        }
        if (priorityQueue[i].heuristic < priorityQueue[smallestChild].heuristic) break;
        PriorityQueueNode temp = priorityQueue[i];
        priorityQueue[i] = priorityQueue[smallestChild];
        priorityQueue[smallestChild] = temp;
        i = smallestChild;
    }

    return minNode;
}


void bestFirstSearch(int start, int goal) {
    bool visited[SIZE] = {false}; 

    insert(start);

    while (pqSize > 0) {
        // Remove the node with the smallest heuristic value
        int current = removeMin();

        // Print the current node being visited
        printf("Visiting node: %d\n", current);

        // Check if the goal node is reached
        if (current == goal) {
            printf("Goal node %d reached!\n", goal);
            return;
        }

        // Mark the current node as visited
        visited[current] = true;

        // Explore the neighbors of the current node
        for (int i = 0; i < SIZE; i++) {
            // If there is a connection and the neighbor is not visited, insert it into the queue
            if (graph[current][i] != 0 && !visited[i]) {
                insert(i);
            }
        }
    }

    printf("Goal node not reachable.\n");
}

int main() {
    int start = 0;  // Define the start node
    int goal = 4;   // Define the goal node

    // Call the Best First Search function
    bestFirstSearch(start, goal);

    return 0;
}
