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
    //array von Nachbar, mit Parameter x und y in Graph
    vector<Knoten*> getNeighbors(int x, int y);

    private:
    //array von alle Knoten
    vector<vector<Knoten*>> knoten;


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
        knoten.push_back(vector<Knoten*>());
        for(int j = 0; j < width; j++)
        {
            if(startPoint[0] == j, startPoint[1] == i)
            {
                knoten[i].push_back(new Knoten(j, i, true, false));
            }else if (endPoint[0] == j, endPoint[1] == i)
            {
                knoten[i].push_back(new Knoten(j, i, false, true));
            }else
            {
                knoten[i].push_back(new Knoten(j, i, false, false));
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

vector<Knoten*> Graph::getNeighbors(int x, int y)
{
    vector<Knoten*> neighbors;
    if(x - 1 > 0)
    {
        neighbors.push_back(knoten[y].at(x - 1));
    }else if(x + 1 < width)
    {
        neighbors.push_back(knoten[y].at(x + 1));
    }else if(y - 1 > 0)
    {
        neighbors.push_back(knoten[y - 1].at(x));
    }else if(y + 1 < length)
    {
        neighbors.push_back(knoten[y + 1].at(x));
    }

    return neighbors;
}

//#endif
