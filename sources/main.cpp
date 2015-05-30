#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iostream>

#include "../headers/graph.h"

#include "../headers/radius.h"

#define MAXPOINT 10000

using namespace std;

int main () {

    vector<Point>
        *points;

    vector<float>
        *point;

    Point
        *point1;

    Graph
        *graph = NULL, *graph2, *begin;

    Radius
        *radius;

    int
        n, t, i, j;

    float
        x, y,
        minx = 0, maxx = 0, miny = 0, maxy = 0,
        used;

    clock_t
        start, end;

    streambuf
        *backup, *out;

    ifstream infile("teste.txt");
    ofstream outfile("results.txt");

    backup = cout.rdbuf();
    out = outfile.rdbuf();
    cout.rdbuf(out);

    start = clock();

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
            if (graph) {
                point = new vector<float>();
                point->push_back(x);
                point->push_back(y);
                graph->addVertice(new Point(++n, point));
                //graph->print();
            }
            else {
                point = new vector<float>();
                point->push_back(x);
                point->push_back(y);
                points = new vector<Point>();
                points->push_back(*(new Point(++n, point)));
                graph = new Graph(1, points);
                //begin->print();
            }
        }
    }

    graph->print();

    used = (maxy - miny > maxx - minx) ? maxy - miny : maxx - minx;
    t = 0;
    start = clock();
    radius = new Radius(0, 0.2);

    while (radius->getRadius() <= used / 2) {
        radius->increase();

        i = 0;
        for (vector<Point>::iterator it = graph->getVertices()->begin(); it != graph->getVertices()->end(); ++it) {
            for (vector<Point>::iterator it2 = graph->getVertices()->begin() + ++i; it2 != graph->getVertices()->end(); ++it2) {
                graph->connect(radius, &(*it), &(*it2));
            }
        }
        cout << ++t << ": ";
        cout << graph->components();
        cout << endl;
        //graph->print();
    }

    end = clock();
    cout.rdbuf(backup);
    cout << "Time: " << (double) (end - start) / CLOCKS_PER_SEC << endl;

    //cout << endl << "Radius: " << radius->getRadius() << endl;
    //begin->printAll();
    //begin->printDistances();
    //cout << "We have " << n << " points." << endl;
}
