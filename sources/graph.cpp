#include "../headers/graph.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

Graph::Graph(int index, vector<Point> points, vector<Edge> edges) {
    this->points = &points;
    this->edges = &edges;
    this->index = index;
}

Graph::Graph(int index, vector<Point> *points, vector<Edge> *edges) {
    this->points = points;
    this->edges = edges;
    this->index = index;
}

vector<Point>* Graph::getVertices() {
    return this->points;
}

void Graph::addVertice(Point *point) {
    this->points->push_back(point);
}

vector<Edge>* Graph::getEdges() {
    return this->edges;
}

void Graph::addEdge(Edge* edge) {
    this->edges->push_back(edge);
}

void Graph::Index(float index) {
    this->index = index;
}

float Graph::Index() {
    return this->index;
}

void HasConnected(bool state) {
    this->hasConnected = state;
}

bool HasConnected() {
    return this->hasConnected;
}

void Graph::printAll() {
    for (vector<Edge>::iterator it = this->edges->begin(); it != this->edges->end(); ++it) {
        (*it).print();
    }
}

void Graph::printDistances() {
    for (vector<Edge>::iterator it = this->edges->begin(); it !+ this->edges->end(); ++it) {
        (*it).print();
        cout << "Distance:" << (*it).distance() << endl;
    }
}
/*
void Graph::connect(Radius *r) {
    vector<int>::iterator it;
    it = find (this->connected->begin(), this->connected->end(), g->Index());
    if (it == this->connected->end()) {
        if (this->point->distance(g->getPoint()) / 2 < r->getRadius()) {
            this->connected->push_back(g->Index());
            //g->connect(this->index);
        }
    }
}

//Always uses with the begining of the graph
int Graph::components(int size) {
    int result = 1;
    vector<int> vertices;
    vector<int>::iterator search, test;
    Graph *g;
    for (int i = 0; i < size; i++)
        vertices.push_back(i+1);

    g = this;

    while (g) {
        for (vector<int>::iterator it = g->getConnected()->begin(); it != g->getConnected()->end(); ++it) {
            vertices.erase(remove(vertices.begin(), vertices.end(), *it), vertices.end());
        }
        g = g->nextVertice();
    }

    return vertices.size();
}*/
