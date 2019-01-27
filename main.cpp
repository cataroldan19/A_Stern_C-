#include <iostream>
#include "Graph.h"
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main()
{


    int length = 5;
    int width = 5;
    int startP[] = {0,0};
    int endP[] = {4,4};

    Graph *field = new Graph(length, width, startP, endP);
    queue<Knoten*> notSearched;
    vector<Knoten*> searched;
    vector<Knoten*> path;
    vector<Knoten*> neighbors = field->getNeighbors(field->startPoint);
    bool alreadySearched;
    bool pathFound = false;
    string pathString;
    for(int i = 0; i < neighbors.size(); i++)
    {
        notSearched.push(neighbors[i]);
    }
    for(int i = 0; i < notSearched.size(); i++)
    {
        if(notSearched.front()->getX() == endP[0] && notSearched.front()->getY() == endP[1])
        {
            //endFound
            pathFound = true;
        }else
        {
            searched.push_back(notSearched.front());
            neighbors = field->getNeighbors(notSearched.front());
            for(int i = 0; i < neighbors.size(); i++)
            {
                alreadySearched = false;
                for(int j = 0; j < searched.size(); j++)
                {
                    if(searched[j] == neighbors[i])
                    {
                        alreadySearched = true;
                    }
                }
                if(!alreadySearched)
                {
                    notSearched.push(neighbors[i]);
                }
            }
        }
    }
    //path not found

    //delete *neighbors;
    //delete notSearched;
    //delete *searched;
    delete field;
    return 0;
}
