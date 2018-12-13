//#ifndef GRAPH_H
//#define GRAPH_H
#include "Knoten.h"
#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    public:

    Graph(int l, int w, int start[2], int endP[2]);
    ~Graph();

    private:

    vector<Knoten*> knoten;
    //Knoten* startPunkt;
    //Knoten* endPunkt;
    int length;
    int width;

    int * startPoint;
    int * endPoint;

};


Graph::Graph(int l, int w, int start[2], int endP[2])
{
    width = w;
    length = l;
    startPoint = start;
    endPoint = endP;

    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(startPoint[0] == j, startPoint[1] == i)
            {
                knoten.push_back(new Knoten(j, i, true, false));
            }else if (endPoint[0] == j, endPoint[1] == i)
            {
                knoten.push_back(new Knoten(j, i, false, true));
            }else
            {
                knoten.push_back(new Knoten(j, i, false, false));
            }
        }
    }
}

Graph::~Graph()
{
    //delete knoten;
    delete startPoint;
    delete endPoint;
}


//#endif
