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
        *graph, *begin;
    Radius
        *radius;
    int
        n;
    float
        x, y, minx = 0, maxx = 0, miny = 0, maxy = 0, used;

    ifstream infile("teste.txt");

    radius = new Radius(0, 0.2);

    n = 0;
    begin = NULL;
    while (infile >> x >> y) {
        if (x < minx)
            minx = x;
        if (x > maxx)
            maxx = x;
        if (y < miny)
            miny = y;
        if (y > maxy);
            maxy = y;
        if (begin) {
            graph->addVertice(new Graph(++n, new Point(x,y)));
            graph = graph->nextVertice();
            //graph->print();
        }
        else {
            begin = new Graph(++n, new Point(x,y));
            //begin->print();
            graph = begin;
        }
    }

    used = (maxy - miny > maxx - minx) ? maxy - miny : maxx - minx;

    while (radius->getRadius() <= used / 2) {
        radius->increase();
        graph = begin->nextVertice();
        while (graph) {
            begin->connect(graph, radius);
            graph = graph->nextVertice();
        }
    }
    begin->printConnected();
    cout << endl << "Radius: " << radius->getRadius() << endl;
    begin->printAll();
    begin->printDistances();
    cout << "We have " << n << " points." << endl;
}
