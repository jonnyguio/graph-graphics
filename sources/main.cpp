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

    vector<Point*>
        *points;

    vector<float>
        *point;

    Point
        *point1;

    Graph
        *graph, *graph2, *begin;

    Radius
        *radius;

    int
        n, t, potency;

    float
        x, y,
        minx = 0, maxx = 0, miny = 0, maxy = 0,
        used;

    clock_t
        start, end;

    ifstream infile("teste.txt");
    ofstream outfile("results.txt");

    //cout.rdbuf(outfile.rdbuf());

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
                points = new vector<Point*>();
                points->push_back(new Point(++n, point));
                graph = new Graph(1, points);
                //begin->print();
            }
        }
    }

    graph->print();
/*
    used = (maxy - miny > maxx - minx) ? maxy - miny : maxx - minx;
    t = 0;
    potency = 0;
    start = clock();
    radius = new Radius(0, 0.2);

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
        /*++t;
        if (t % (int) pow(10,potency) == 0) {
            cout << t << endl;
            potency++;
        }
        cout << ++t << ",";
        begin->printComponents(n);
    }
*/
    end = clock();
    cout << endl << endl << endl << "Time: " << (double) (end - start) / CLOCKS_PER_SEC << endl;

    //cout << endl << "Radius: " << radius->getRadius() << endl;
    //begin->printAll();
    //begin->printDistances();
    //cout << "We have " << n << " points." << endl;
}
