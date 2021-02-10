#pragma once
#include "nc.h"

using namespace std;

int nextCommand(int *s, int *t, int *f)
{
    char c;
    while(1){

        cin>>c;

        if (c == 'S' || c == 's')
        {
            break;
        }
        if (c == 'F' || c == 'f')
        {
            cin >> *s >> *t >> *f;
            break;
        }

        if(c == 'R' || c == 'r')
        {
            break;
        }

        if(c == 'W' || c == 'w')
        {
            break;
        }

        cout<<"Invalid Command\n";
    }
    return c;
}
