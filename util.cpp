#pragma once
#include "util.h"
#include "heap.h"
#include "graph.h"
using namespace std;

int getParent(int j)
{
  return (j/2);
}

int leftChild(int j)
 {
   return j*2 +1;
 }
int rightChild(int j)
{
  return (2*j)+2;
}
// the above three return position to the paren accordingly

bool isLeaf(HEAP *heap, int j)
{
    if(j >= ((heap->size)/2) && j <= heap->size)
    {
        return true;
    }
    return false;
}

// this is a constructor
HEAP* initialize(int capacity)
{
    HEAP* heap = new HEAP;
    heap->pos = (int *)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    heap->H= (struct ELEMENT**) malloc(capacity * sizeof(struct ELEMENT*));
    return heap;
}

bool inHeap(struct HEAP *heap, int v)
{
    if (heap->pos[v] < heap->size)
       return true;
    else
        return false;
}

void printW(GRAPH* gra, int v1)
{
    int i = 0;
    for (int q = 0; q < v1 +1 ; q++)
    {
        cout << q;
        LISTNODE* upd = gra->A[q].head;
        while(upd != NULL)
        {
            if(i == 0)
            {
                cout << " : (" << upd->dest << "," << upd->weight << ")";
                i++;
            }

            cout << "; (" << upd->dest << "," << upd->weight << ")" ;
            upd = upd->next;
        }
        i = 0;
        cout << "\n";
    }

}
