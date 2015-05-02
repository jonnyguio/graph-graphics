#ifndef INCLUDE_GUARD_POINT
#define INCLUDE_GUARD_POINT
#include "point.h"
#endif

class Graph {
    private:
        int index;
        Point *point;
        Graph *next;

    public:
        Graph(int, Point);

        Graph(int, Point*);

        Graph * nextVertice();

        void addVertice(Graph*);

        void print();

        void printAll();

        void setPoint(Point*) ;

        Point getPoint();

        void printDistances();

};
