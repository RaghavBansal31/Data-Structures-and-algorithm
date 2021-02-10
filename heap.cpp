
#include "heap.h"
#include "util.h"


ELEMENT* NewElement(int v, int dis)
{
    struct ELEMENT* ele = (struct ELEMENT*) malloc(sizeof(ELEMENT));
    ele->v = v;
    ele->dis = dis;
    return ele;
}


//This method swaps the two nodes in the heap
void swap(ELEMENT** ele1, ELEMENT** ele2)
{
    struct ELEMENT* tem = *ele1;
    *ele1 = *ele2;
    *ele2= tem;
}

//this method is used to minimum heapify the node wich is at j
void minimumHeapify(HEAP* heap, int j)
{
    int mini = j;
    int le = leftChild(j);
    int ri = rightChild(j);

    if (le < heap->size && heap->H[le]->dis < heap->H[mini]->dis)
        mini = le;
    if(ri < heap->size && heap->H[ri]->dis < heap->H[mini]->dis)
        mini = ri;

    if(mini!=j)
    {

        ELEMENT* smal = heap->H[mini];
        ELEMENT* ind = heap->H[j];

        heap->pos[smal->v] = j;
        heap->pos[ind->v]=mini;

        swap(&heap->H[mini], &heap->H[j]);
        minimumHeapify(heap, mini);
    }


}

int isEmpty(struct HEAP* heap)
{
    return heap->size == 0;
}

//this is used to fetch out the minimum value
ELEMENT* extractMin(HEAP* heap)
{
    if (isEmpty(heap))
        return NULL;

    ELEMENT* root = heap->H[0];

    ELEMENT* la = heap->H[heap->size - 1];
    heap->H[0] = la;


    heap->pos[root->v] = (heap->size)-1;
    heap->pos[la->v] = 0;
    heap->size=(heap->size)-1;
    minimumHeapify(heap, 0);
    // the above is used to change the positon
    return root;
}

void decreaseKey(HEAP* heap, int v, int dis)
{
    int j = heap->pos[v];
    heap->H[j]->dis = dis;

    // O(Logn) time
    while (j && heap->H[j]->dis < heap->H[(j - 1) / 2]->dis)
    {
        heap->pos[heap->H[j]->v] = (j-1)/2;
        heap->pos[heap->H[(j-1)/2]->v] = j;
        swap(&heap->H[j], &heap->H[(j - 1) / 2]);
        j = (j - 1) / 2;
    }
}
