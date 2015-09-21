#include <GLUT/GLUT.h>

#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "../headers/graph.h"
#include "../headers/UIHandler.h"
#include "../headers/radius.h"

using namespace std;

bool UIHandler::drawFaces = false;
int UIHandler::step = 0;

int main(int argc, char** argv) {

    int maxSteps;

    Graph
        *graph;

    clock_t
        start, end;

    streambuf
        *backup, *out;

    start = clock();

    ofstream outfile("results.txt");

    backup = cout.rdbuf();
    out = outfile.rdbuf();

    graph = new Graph(1);
    maxSteps = graph->calc(backup, out);

    UIHandler::init(argc, argv, graph, maxSteps);
    UIHandler::setMainGraph(graph);
    glutMainLoop();

    end = clock();

    cout.rdbuf(backup);
    cout << "Time: " << (double) (end - start) / CLOCKS_PER_SEC << endl;

    delete graph;


    //cout << endl << "Radius: " << radius->getRadius() << endl;
    //begin->printAll();
    //begin->printDistances();
    //cout << "We have " << n << " points." << endl;
}
