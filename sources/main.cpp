#include <fstream>
#include <sstream>
#include <string>
#include <string.h>

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#ifndef GRAPH_H
#define GRAPH_H
#include "../headers/graph.h"
#endif

#ifndef RADIUS_H
#define RADIUS_H
#include "../headers/radius.h"
#endif

#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

#define MAXPOINT 10000

using namespace std;

int main () {
    Point
        *point1;
    Graph
        *graph, *graph2, *begin;
    Radius
        *radius;
    int
        n, t;
    float
        x, y,
        minx = 0, maxx = 0, miny = 0, maxy = 0,
        used;

    vector<float>* point;

    ifstream infile("teste.txt");
    ofstream outfile("results.txt");

    cout.rdbuf(outfile.rdbuf());

    radius = new Radius(0, 0.2);

    n = 0;
    begin = NULL;
    while (infile >> x >> y) {
        if (x < MAXPOINT && y < MAXPOINT) {
            if (x < minx)
                minx = x;
            if (x > maxx)
                maxx = x;
            if (y < miny)
                miny = y;
            if (y > maxy);
                maxy = y;
            if (begin) {
                point = new vector<float>();
                point->push_back(x);
                point->push_back(y);
                graph->addVertice(new Graph(++n, new Point(point)));
                graph = graph->nextVertice();
                //graph->print();
            }
            else {
                point = new vector<float>();
                point->push_back(x);
                point->push_back(y);
                begin = new Graph(++n, new Point(point));
                //begin->print();
                graph = begin;
            }
        }
    }

    used = (maxy - miny > maxx - minx) ? maxy - miny : maxx - minx;
    t = 0;
    while (radius->getRadius() <= used / 2) {
        radius->increase();
        graph = begin;

        while (graph) {
            graph2 = graph->nextVertice();
            while (graph2) {
                graph->connect(graph2, radius);
                graph2 = graph2->nextVertice();
            }
            //graph->printConnected();
            graph = graph->nextVertice();
        }
        cout << ++t << ",";
        begin->printComponents(n);
    }

    //cout << endl << "Radius: " << radius->getRadius() << endl;
    //begin->printAll();
    //begin->printDistances();
    //cout << "We have " << n << " points." << endl;
}
