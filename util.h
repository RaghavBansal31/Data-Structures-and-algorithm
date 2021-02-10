
#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <climits>
#include <cmath>
#include <string>
#include <stdlib.h>
#include "heap.h"
#include "graph.h"

using namespace std;


int getParent(int);
int leftChild(int j);
int rightChild(int j);
bool isLeaf(int j);
bool inHeap(struct HEAP *heap, int v);

// all neccessary functions for the project to change positions and move value accordingly


HEAP* initialize(int c);
