#ifndef POINT_H
#define POINT_H
#include "point.h"
#endif

#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

#ifndef RADIUS_H
#define RADIUS_H
#include "../headers/radius.h"
#endif

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

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
