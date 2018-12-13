//#ifndef KNOTEN_H
//#define KNOTEN_H
#include <vector>
#include <iostream>

using namespace std;

class Knoten
{
    public:

        Knoten(int x, int y, bool startP, bool endP);
        int getX();
        int getY();
        char getSymbol();

    private:

        int x;
        int y;
        char symbol;
        bool endPoint;
        bool startPoint;

        int gewicht;
        //vector<Knoten> Nachbarn;

};

Knoten::Knoten(int xVal, int yVal, bool startP, bool endP)
{
    x = xVal;
    y = yVal;
    startPoint = startP;
    endPoint = endP;
    if(startPoint)
    {
        symbol = '#';
    }
    else if(endPoint)
    {
        symbol = '*';
    }else
    {
        symbol = '=';
    }
}



int Knoten::getX()
{
    return x;
}

int Knoten::getY()
{
    return y;
}

char Knoten::getSymbol()
{
    return symbol;
}

//#endif
