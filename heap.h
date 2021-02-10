
#pragma once

#include "util.h"
#include <new>

using namespace std;

struct ELEMENT
{
    int v;
    int dis;
};

struct HEAP
{
    int capacity;
    int size;
    int *pos;
    struct ELEMENT** H;
};

ELEMENT* NewElement(int v, int dis);
void swap(ELEMENT** , ELEMENT** );
void minimumHeapify(HEAP* heap, int);

void print(HEAP*);
int isEmpty(struct HEAP*);
// to check if the heap is empty and whether it returns 0


ELEMENT* extractMin(HEAP*);
void buildMinHeap(HEAP*);
void decreaseKey(HEAP*, int, int);
void insert(HEAP*, int k);
