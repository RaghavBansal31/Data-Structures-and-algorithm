#pragma once
#include "util.h"

struct GRAPH {
    int v; //vertex
    struct LIST* A;
};

struct LISTNODE {
    int dest;
    int weight;
    struct LISTNODE* next;
};

struct LIST
{
    struct LISTNODE *head;
};


LISTNODE* nLNode(int des, int weig);
GRAPH *createGraph(int v);
void addEdge(GRAPH* gra, int sour, int des, int weig);
int dijkstra(GRAPH* gra, int sour, int targ, int fl);
void printPath();
