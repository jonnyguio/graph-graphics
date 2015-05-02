#include <fstream>
#include <sstream>
#include <string>
#include <string.h>

#ifndef INCLUDE_GUARD_MATH
#define INCLUDE_GUARD_MATH
#include <math.h>
#endif

#ifndef INCLUDE_GUARD_IOSTREAM
#define INCLUDE_GUARD_IOSTREAM
#include <iostream>
#endif

#ifndef INCLUDE_GUARD_GRAPH
#define INCLUDE_GUARD_GRAPH
#include "../headers/graph.h"
#endif

#ifndef INCLUDE_GUARD_RADIUS
#define INCLUDE_GUARD_RADIUS
#include "../headers/radius.h"
#endif

#define MAXPOINT 10000

using namespace std;

int main () {
    Point
      *point1;
    Graph
      *graph, *begin;
    /*graph->addVertice(new Graph(2, new Point(2, 2)));
    point1->print();
    graph->print();
    graph->nextVertice()->print();*/
    int
      n;
    float
      x, y;
    string line;
    ifstream infile("teste.txt");

    n = 0;
    begin = NULL;
    while (infile >> x >> y) {
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
    begin->printAll();
    begin->printDistances();
    cout << "We have " << n << " points." << endl;
}
