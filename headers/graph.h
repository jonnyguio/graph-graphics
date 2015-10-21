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

        vector<Point*>
            *freePoints;

        vector<Point*>
            *critPoints;

        vector<Edge>
            *edges;

        vector<Edge*>
            *freeEdges;

        vector<Edge*>
            *critEdges;

        vector<Face>
            *faces;

        vector<Face*>
            *freeFaces;

        vector<Face*>
            *critFaces;

        bool
            hasConnected;

    public:
        int ncritVertices = 0, ncritEdges = 0, ncritFaces = 0;
        Graph(int, vector<Point>, vector<Edge>);

        Graph(int, vector<Point>*, vector<Edge>*);

        Graph(int, vector<Point>*, vector<Edge>*, vector<Face>*);

        Graph(int, vector<Point>*);

        Graph(int);

        ~Graph();

        // GETTERS AND SETTERS
        vector<Point>* Points(void);

        vector<Point*>* FreePoints(void);

        vector<Point*>* CritPoints(void);

        void addPoint(Point*);

        void setPoints(vector<Point>*);

        vector<Edge>* Edges(void);

        vector<Edge*>* FreeEdges(void);

        vector<Edge*>* CritEdges(void);

        void addEdge(Edge*);

        void setEdges(vector<Edge>*);

        vector<Face>* Faces();

        vector<Face*>* FreeFaces(void);

        vector<Face*>* CritFaces(void);

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

        bool findInt(vector<int>, int, int);

        static bool findPoint(vector<Point*>, int, Point*);

        int findEqualPoint(vector<Point>*, Point*);

        int findEqualEdge(vector<Edge>*, Edge*);

        bool findEdge(vector<Edge>, int, Edge);

        static vector<Point*> verticesFromFace(Edge* e1, Edge* e2, Edge* e3);

        //Collapse
        Graph* collapse(int);

        void livingMembers(Graph*, int);

        bool freeMembersLeft(Graph*, int);

        bool kill(Graph*, int);

        void killCrit(Graph*, int);

        //New Collapse Functions

        void dynamicCollapse(Graph*);

        void resetGraph(int);

        //MISC
        Graph* copy(Graph*);

        Graph* copy(Graph*, int);

        int calc(streambuf *, streambuf *);

};
#endif
