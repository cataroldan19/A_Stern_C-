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
    vector<Knoten*> getNeighbors(Knoten*& k);
    int getLength();
    int getWidth();
    int length;
    int width;
    Knoten * startPoint;
    Knoten * endPoint;

    private:
    //array von alle Knoten
    vector<vector<Knoten*>> knoten;


    

    

};


Graph::Graph(int l, int w, int start[2], int endP[2])
{
    width = w;
    length = l;
    

    for(int i = 0; i < length; i++)
    {
        knoten.push_back(vector<Knoten*>());
        for(int j = 0; j < width; j++)
        {
            if(start[0] == j, start[1] == i)
            {
		startPoint = new Knoten(j, i, true, false);
                knoten[i].push_back(startPoint);
            }else if (endP[0] == j, endP[1] == i)
            {
		endPoint = new Knoten(j, i, false, true);
                knoten[i].push_back(endPoint);
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

vector<Knoten*> Graph::getNeighbors(Knoten*& k)
{

    int x = k->getX();
    int y = k->getY();
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


int Graph::getLength()
{
    return length;
}

int Graph::getWidth()
{
    return width;
}

//#endif
