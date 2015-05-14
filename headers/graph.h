#include "point.h"
#include <vector>
#include <iostream>
#include "radius.h"

#ifndef _GRAPH_H_
#define _GRAPH_H_
using namespace std;

class Graph {
    private:
        int index;
        Point *point;
        Graph *next;
        std::vector<int> *connected;

    public:
        Graph(int, Point);

        Graph(int, Point*);

        // GETTERS AND SETTERS
        Graph* nextVertice();

        void addVertice(Graph*);

        void setPoint(Point*);

        Point* getPoint();

        float Index();

        void Index(float);

        vector<int>* getConnected();

        // PRINT
        void print();

        void printAll();

        void printDistances();

        void printConnected();

        void printComponents(int);

        //CONNECTION
        void connect(Graph*, Radius*);

        void connect(int);

        bool isConnected(int);

        int components (int);
};
#endif
