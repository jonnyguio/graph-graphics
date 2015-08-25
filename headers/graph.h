#include "point.h"
#include "edge.h"
#include "face.h"
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

        vector<Face>
            *faces;

        bool
            hasConnected;

    public:
        Graph(int, vector<Point>, vector<Edge>);

        Graph(int, vector<Point>*, vector<Edge>*);

        Graph(int, vector<Point>*);

        // GETTERS AND SETTERS
        vector<Point>* getVertices(void);

        void setVertices(vector<Point>*);

        void addVertice(Point*);

        void setVertices(vector<Point>*);

        vector<Edge>* getEdges(void);

        void setEdges(vector<Edge>*);

        void addEdge(Edge*);

        void setEdges(vector<Edge>*);

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

<<<<<<< HEAD
        // TRIANGLES
        void setTriangles();

        bool formsTri(Edge *, Edge *, Edge *);

        bool findInt(vector<unsigned long>, unsigned long, int);
=======
        //Collapse
        void collapse(graph, int);
>>>>>>> origin/master
};
#endif
