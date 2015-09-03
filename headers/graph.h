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
            *points, *freePoints;

        vector<Edge>
            *edges, *freeEdges;

        vector<Face>
            *faces, *freeFaces;

        bool
            hasConnected;

    public:
        Graph(int, vector<Point>, vector<Edge>);

        Graph(int, vector<Point>*, vector<Edge>*);

        Graph(int, vector<Point>*);

        // GETTERS AND SETTERS
        vector<Point>* getVertices(void);

        vector<Point>* FreePoints(void);

        void addVertice(Point*);

        void setVertices(vector<Point>*);

        vector<Edge>* getEdges(void);

        vector<Edge>* FreeEdges(void);

        void setEdges(vector<Edge>*);

        void addEdge(Edge*);

        vector<Face>* Faces();

        vector<Face>* FreeFaces(void);

        void addFace(Face*);

        void setFaces(vector<Face>*);

        float Index(void);

        void Index(float);

        int CC();

        void CC(int);

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

        // TRIANGLES
        void setTriangles();

        bool formsTri(Edge, Edge, Edge);

        // Find Stuff

        bool findInt(vector<unsigned long>, unsigned long, int);

        bool findPoint(vector<Point>, unsigned long, Point);

        bool findEdge(vector<Edge>, unsigned long, Edge);


        //Collapse
        void collapse(Graph);

        void findFreeMembers(Graph*, int);

        bool freeMembersLeft(Graph*, int);

        void kill(int);

        //MISC
        Graph* copy(Graph);

        bool EdgeCompare(Edge e1, Edge e2);
};
#endif
