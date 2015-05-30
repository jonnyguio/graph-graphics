#include "point.h"
#include "edge.h"
#include <vector>
#include <iostream>
#include "radius.h"

#ifndef _GRAPH_H_
#define _GRAPH_H_
using namespace std;

class Graph {
    private:
        int
            cc, index;

        vector<Point>
            *points;

        vector<Edge>
            *edges;

        bool
            hasConnected;

    public:
        Graph(int, vector<Point>, vector<Edge>);

        Graph(int, vector<Point>*, vector<Edge>*);

        Graph(int, vector<Point>*);

        // GETTERS AND SETTERS
        vector<Point>* getVertices(void);

        void addVertice(Point*);

        vector<Edge>* getEdges(void);

        void addEdge(Edge*);

        float Index(void);

        void Index(float);

        bool HasConnected(void);

        void HasConnected(bool);

        // PRINT

        void print();

        void printDistances();

        void printConnected();

        void printComponents(int);

        //CONNECTION
        void connect(Radius*, Point*, Point*);

        int components ();
};
#endif
