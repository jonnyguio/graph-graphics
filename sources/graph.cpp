#ifndef INCLUDE_GUARD_GRAPH
#define INCLUDE_GUARD_GRAPH

#include "../headers/graph.h"
#endif

#include <stdlib.h>
#include <iostream>

using namespace std;

Graph::Graph(int index, Point point) {
    this->point = &point;
    this->index = index;
    this->next = NULL;
}

Graph::Graph(int index, Point *point) {
    this->point = point;
    this->index = index;
    this->next = NULL;
}

Graph* Graph::nextVertice() {
    return this->next;
}

void Graph::addVertice(Graph * newg) {
    this->next = newg;
}

void Graph::print() {
    cout << "Index:" << this->index << endl << "Points:";
    point->print();
    cout << endl;
}

void Graph::printAll() {
    Graph *g;
    g = this;
    while (g) {
        g->print();
        g = g->next;
    }
}

void Graph::setPoint(Point *p) {
    this->point = p;
}

Point Graph::getPoint() {
    return *this->point;
}

void Graph::printDistances() {
    Graph *g;
    g = this->next;
    cout << "Index: " << this->index << endl;
    while (g) {
        cout << "\t" << "Distance to Index " << g->index << ": " << this->point->distance(g->point) << endl;
        g = g->next;
    }
}
