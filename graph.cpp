#pragma once
#include "graph.h"
#include "util.h"

LISTNODE* nLNode(int des, int weig)
{
    struct LISTNODE* node = (struct LISTNODE*) malloc(sizeof(struct LISTNODE));
    node->dest = des;
    node->weight = weig;
    node->next = NULL;
    return node;
}

GRAPH *createGraph(int v)
{
    GRAPH* gra = (struct GRAPH*) malloc(sizeof(GRAPH));
    gra->v = v;

    gra->A = (LIST*) malloc(v*sizeof(LIST));

    for (int j = 0; j <v; ++j)
    {
         gra->A[j].head = NULL;
    }
    return gra;

}

void addEdge (GRAPH* gra, int sour, int des, int weig)
{
    struct LISTNODE* node = nLNode(des, weig);
    node->next = gra->A[sour].head;
    gra->A[sour].head = node;
}

int dijkstra(GRAPH* gra, int sour, int targ, int fl)
{
    int v = gra->v;
    int dis[v];

    HEAP* minimumHeap = initialize(v);

    for(int j = 0; j < v; j++)
    {
        dis[j] = INT_MAX;
        minimumHeap->H[j] = NewElement(j, dis[j]);
        minimumHeap->pos[j] = j;
    }

    minimumHeap->H[sour] = NewElement(sour, dis[sour]);
    minimumHeap->pos[sour]= sour;
    dis[sour] = 0;
    decreaseKey(minimumHeap, sour, dis[sour]);

    minimumHeap->size = v;



    while (!isEmpty(minimumHeap))
    {

        ELEMENT* ele = extractMin(minimumHeap);
        int u = ele->v;


        LISTNODE* upd = gra->A[u].head;
        while (upd != NULL)
        {
            int b = upd->dest;


            if (inHeap(minimumHeap, b) && dis[u] != INT_MAX &&
                                          upd->weight + dis[u] < dis[b])
            {
                dis[b] = dis[u] + upd->weight;


                decreaseKey(minimumHeap, v, dis[v]);
            }
            upd = upd->next;
        }
    }

    if(fl == 1)
    {
        return dis[targ];
    }
    return 0;
}
