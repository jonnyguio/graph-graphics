#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "../headers/graph.h"

#include "../headers/radius.h"

#include "../headers/main.h"

#define MAXPOINT 10000

using namespace std;

bool EdgeCompare(Edge e1, Edge e2) {
    return e1.Dist() > e2.Dist();
}

int Main::mainCalculations() {

    vector<Point>
        *points;

    vector<float>
        point;

    Graph
        *graph = NULL;

    Radius
        *radius;

    int
        n, i, j, k, fSize, eSize, vSize;

    float
        x, y,
        minx = 0, maxx = 0, miny = 0, maxy = 0;

    clock_t
        start, end;

    streambuf
        *backup, *out;

    ifstream infile("teste2");
    ofstream outfile("results.txt");

    backup = cout.rdbuf();
    out = outfile.rdbuf();
    //cout.rdbuf(out);

    start = clock();

    n = 0;
    //begin = NULL;
    while (infile >> x >> y) {
        if (x < MAXPOINT && y < MAXPOINT) {
            if (x < minx)
                minx = x;
            if (x > maxx)
                maxx = x;
            if (y < miny)
                miny = y;
            if (y > maxy)
                maxy = y;
            if (graph) {
                point.push_back(x);
                point.push_back(y);
                graph->addVertice(new Point(++n, point));
                point.clear();
                //graph->print();
            }
            else {
                point.push_back(x);
                point.push_back(y);
                points = new vector<Point>();
                points->push_back(*(new Point(++n, point)));
                graph = new Graph(1, points);
                point.clear();
                //begin->print();
            }
        }
    }

    //graph->print();

    radius = new Radius(-1, -1);

    i = 0;

    for (vector<Point>::iterator it = graph->getVertices()->begin(); it != graph->getVertices()->end(); ++it) {
        for (vector<Point>::iterator it2 = graph->getVertices()->begin() + ++i; it2 != graph->getVertices()->end(); ++it2) {
            graph->connect(radius, &(*it), &(*it2));
        }
    }

	sort(graph->getEdges()->begin(), graph->getEdges()->end(), EdgeCompare);

    graph->print();

    fSize = 0;
    //graph->setTriangles();

    i = 0;
    for (vector<Edge>::iterator it = graph->getEdges()->begin(); it != graph->getEdges()->end(); ++it) {
        j = i++ + 1;
        for (vector<Edge>::iterator it2 = graph->getEdges()->begin() + j; it2 != graph->getEdges()->end(); ++it2) {
            k = j++ + 1;
            for (vector<Edge>::iterator it3 = graph->getEdges()->begin() + k; it3 != graph->getEdges()->end(); ++it3) {
                if (graph->formsTri(*it, *it2, *it3)) {
                    //cout << (*it).Index() << " " << (*it2).Index() << " " << (*it3).Index() << endl;
					graph->Faces()->push_back(*(new Face(++fSize, &(*it), &(*it2), &(*it3))));
                    (*it).DegreePP();
                    (*it2).DegreePP();
                    (*it3).DegreePP();
                }

            }
        }
    }

    //reverse(graph->getEdges()->begin(), graph->getEdges()->end());
	reverse(graph->Faces()->begin(), graph->Faces()->end());

    for (vector<Point>::iterator it = graph->getVertices()->begin(); it != graph->getVertices()->end(); ++it)
    {
        (*it).print();
    }
    cout << endl;

    vSize = graph->getVertices()->size();
    eSize = graph->getEdges()->size();

    for(i = 0, j = 0; i < eSize || j < fSize;) {
        if (i < eSize && graph->getEdges()->at(eSize - i - 1).printed == false) {

            graph->getEdges()->at(eSize - i - 1).printed = true;
            printf("e%d: v%d -- v%d\n",
                graph->getEdges()->at(eSize - i - 1).Index(),
                graph->getEdges()->at(eSize - i - 1).A()->Index(),
                graph->getEdges()->at(eSize - i - 1).B()->Index());
            i++;
        }

        while (
        j < fSize
        && graph->Faces()->at(j).E1()->printed
        && graph->Faces()->at(j).E2()->printed
        && graph->Faces()->at(j).E3()->printed
        ) {
            graph->Faces()->at(j).Index(fSize - graph->Faces()->at(j).Index());
            printf("f%d: e%d -- e%d -- e%d\n",
                graph->Faces()->at(j).Index(),
                graph->Faces()->at(j).E1()->Index(),
                graph->Faces()->at(j).E2()->Index(),
                graph->Faces()->at(j).E3()->Index());
            j++;
        }
    }

    //graph->collapse();


    end = clock();
    cout.rdbuf(backup);
    cout << "Time: " << (double) (end - start) / CLOCKS_PER_SEC << endl;

    delete graph;
    delete radius;

    return 0;
    //cout << endl << "Radius: " << radius->getRadius() << endl;
    //begin->printAll();
    //begin->printDistances();
    //cout << "We have " << n << " points." << endl;
}
