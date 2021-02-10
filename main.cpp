#pragma once
#include<stdio.h>
#include<cmath>
#include<iostream>
#include<fstream>
#include <climits>
#include<new>
#include"nc.h"
#include"heap.h"
#include"graph.h"
#include"util.h"
using namespace std;

int main()
{
    //initializing variables
    char c;
    int s, t;
    int f;
    bool fl = false;

   int v1, e1,u,v,w;
    ifstream myFile;
    myFile.open("Ginput.txt");
    if(!myFile){
        cout<<"Error: File not found error"<<endl;
        ::exit(0);
    }
    myFile >> v1 >> e1;

    GRAPH* gra = createGraph(v1);


    while(1)
    {
        c = nextCommand(&s, &t, &f);
        switch (c)
        {
        case 's':
        case 'S': printf("COMMAND: %c\n", c);
        myFile.close();
        delete gra;
        ::exit(0);


        case 'r':
        case 'R':
        {
            printf("COMMAND: %c\n", c);
            fl = true;

                while(myFile >> u >> v >> w)
                {
                    addEdge(gra, u, v, w);
                }
                break;
        }


        case 'f':
        case 'F':
        {   printf("COMMAND: %c\n", c);
            if(fl == true)
            {
                if( s == 0 || t == 0)
                {
                   cout<<"Error: There are invalid nodes, either one or more"<<endl;
                }
                if( f != 1 && f != 0)
                {
                    cout<<"Error: value of flag is invalid"<<endl;
                }
                else {
                int x = dijkstra(gra, s, t, f);
                cout << "Length: " << x << endl;
                }
            }
            else
            {
                cout << "Error: the graph is  not initialized" << endl;
            }

            break;
        }

        case 'w':
        case 'W':
        {
            printf("COMMAND: %c\n", c);
            if(fl == true)
            {
            cout << v1 << " " << e1 << endl;

            {
                int j = 0;
                for (int i = 1; i < v1 +1 ; i++)
                {
                    cout << i;
                    LISTNODE* upd = gra->A[i].head;
                    while(upd != NULL)
                    {
                        if(j == 0)
                        {
                            cout << " : (" << upd->dest << "," << upd->weight << ")";
                            j++;
                            upd = upd->next;
                        }
                        else{
                        cout << "; (" << upd->dest << "," << upd->weight << ")" ;
                          upd = upd->next;
                        }

                    }
                    j = 0;
                    cout << "\n";
                }

            }

            }
            else
            {
                cout << "Error: the graph is  not initialized" << endl;
            }

            break;
        }

        default: break;
        }
    }

}
