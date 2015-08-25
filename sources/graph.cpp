#include "../headers/graph.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

Graph::Graph(int index, vector<Point> *points) {
    this->points = points;
    this->edges = new vector<Edge>();
    this->index = index;
}

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

void Graph::setVertices(vector<Point>* points) {
    this->points = points;
}

void Graph::addVertice(Point *point) {
    this->points->push_back(*point);
}

vector<Edge>* Graph::getEdges() {
    return this->edges;
}

void Graph::setEdges(vector<Edge>* edges) {
    this->edges = edge;
}

void Graph::addEdge(Edge* edge) {
    this->edges->push_back(*edge);
}

void Graph::Index(float index) {
    this->index = index;
}

float Graph::Index() {
    return this->index;
}

void Graph::HasConnected(bool state) {
    this->hasConnected = state;
}

bool Graph::HasConnected() {
    return this->hasConnected;
}

void Graph::print() {

    cout << "Vertices:" << endl;

    for (vector<Point>::iterator it = this->points->begin(); it != this->points->end(); ++it)
    {
        cout << (*it).Index() << " ";
    }

    cout << endl << endl << "Edges:" << endl;

    for (vector<Edge>::iterator it = this->edges->begin(); it != this->edges->end(); ++it) {
        (*it).print();
    }
}

/*void Graph::printDetails() {
    for (vector<Edge>::iterator it = this->edges->begin(); it != this->edges->end(); ++it) {
        (*it).print();
    }
}*/

void Graph::printDistances() {
    for (vector<Edge>::iterator it = this->edges->begin(); it != this->edges->end(); ++it) {
        (*it).print();
        cout << "Distance:" << (*it).distance() << endl;
    }
}

void Graph::connect(Radius *r, Point *a, Point *b) {
    Edge e = Edge(a, b);
    vector<Edge>::iterator it;

    it = find (this->edges->begin(), this->edges->end(), e);

    if (a->distance(b) / 2 < r->getRadius() && it == this->edges->end()) {
        this->edges->push_back(*(new Edge(a, b)));
    }
    /*vector<int>::iterator it;
    it = find (this->connected->begin(), this->connected->end(), g->Index());
    if (it == this->connected->end()) {
        if (this->point->distance(g->getPoint()) / 2 < r->getRadius()) {
            this->connected->push_back(g->Index());
            //g->connect(this->index);
        }
    }*/
}

//Always uses with the begining of the graph
int Graph::components() {

    vector<int> vertices;
    vector<int>::iterator search, test;

    for (vector<Point>::iterator it = this->points->begin(); it != this->points->end(); ++it)
    {
        vertices.push_back((*it).Index());
    }

    for (vector<Edge>::iterator it = this->edges->begin(); it != this->edges->end(); ++it) {
        vertices.erase(remove(vertices.begin(), vertices.end(), (*it).B()->Index()), vertices.end());
    }

    return vertices.size();
}

graph* copy(graph* g1){
  graph* temp;
  temp = (graph*) malloc(sizeof(graph));
  temp->setVertices(g1->getVertices());
  temp->setEdges(g1->getEdges());
  temp->Index(g1->Index());
  return temp;
}

void Graph::collapse(graph g1, int dimension){
  graph* g2;
  g2 = copy(g1);
  F
  ace fTemp = new Face();
  if(dimension == 2){
    while(g2->getFaces().size() > 0){
      while(freeMember(g2, 2)){

      }
    }
  }
  while(){

  }

}
