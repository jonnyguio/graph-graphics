#ifndef GRAPH_H
#define GRAPH_H
#include "../headers/graph.h"
#endif

#include <stdlib.h>

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#include <algorithm>

using namespace std;

Graph::Graph(int index, Point point) {
    this->point = &point;
    this->index = index;
    this->next = NULL;
    this->connected = new vector<int>();
}

Graph::Graph(int index, Point *point) {
    this->point = point;
    this->index = index;
    this->next = NULL;
    this->connected = new vector<int>();
}

Graph* Graph::nextVertice() {
    return this->next;
}

void Graph::addVertice(Graph * newg) {
    this->next = newg;
}

void Graph::Index(float index) {
    this->index = index;
}

float Graph::Index() {
    return this->index;
}

void Graph::setPoint(Point *p) {
    this->point = p;
}

Point* Graph::getPoint() {
    return this->point;
}

vector<int>* Graph::getConnected() {
    return this->connected;
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

void Graph::printDistances() {
    Graph *g;
    g = this->next;
    cout << "Index: " << this->index << endl;
    while (g) {
        cout << "\t" << "Distance to Index " << g->index << ": " << this->point->distance(g->point) << endl;
        g = g->next;
    }
}

void Graph::printConnected() {
    cout << "[" << this->index << "] Indexes connected:";
    for (vector<int>::iterator it = this->connected->begin(); it != this->connected->end(); ++it) {
        cout << " " << *it ;
    }
    cout << endl;
}

bool Graph::isConnected(int index) {
    for (vector<int>::iterator it = this->connected->begin(); it != this->connected->end(); ++it) {
        if (*it == index)
            return true;
    }
    return false;
}

void Graph::connect(int index) {
    this->connected->push_back(index);
}

void Graph::connect(Graph *g, Radius *r) {
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
            //search = find (g->getConnected()->begin(), g->getConnected()->end(), *it);
            //if (search != g->getConnected()->end())
                //test = search;
                //vertices.erase(search - 1);
                //cout << "\t" << "find:" << *search << endl;
        }
        g = g->nextVertice();
    }

    return vertices.size();
}
