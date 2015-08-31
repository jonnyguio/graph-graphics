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
    this->edges = edges;
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

int Graph::CC(){
    return this->cc;
}

void Graph::CC(int cc){
    this->cc = cc;
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

bool Graph::findInt(vector<unsigned long> v, unsigned long size, int toFind) {
	unsigned long i;
	for(i = 0; i<size; i++) {
		if(v[i] == toFind) {
			return true;
		}
	}
	return false;
}

bool Graph::formsTri(Edge *e1, Edge *e2, Edge *e3) {
    vector<unsigned long> v, v2;
	int i;

	v.push_back(e1->A()->Index());
	v.push_back(e1->B()->Index());
	v.push_back(e2->A()->Index());
	v.push_back(e2->B()->Index());
	v.push_back(e3->A()->Index());
	v.push_back(e3->B()->Index());

	for(i = 0; i < 6; i++) {
		if (!findInt(v2, v2.size(), v[i])) {
			v2.push_back(v[i]);
		}
	}
	if (v2.size() == 3) {
		return true;
	}
	else {
		return false;
	}
}

void Graph::connect(Radius *r, Point *a, Point *b) {
    Edge e = Edge(a, b);
    vector<Edge>::iterator it;

    it = find (this->edges->begin(), this->edges->end(), e);

    if (a->distance(b) / 2 < r->getRadius() && it == this->edges->end()) {
        this->edges->push_back(*(new Edge(a, b)));
        this->edges[this->edges.size() - 1].a->DegreePP();
        this->edges[this->edges.size() - 1].b->DegreePP();
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

void Graph::setTriangles() {
    this->faces->clear();

    int i, j, k;

    vector<Edge> edgeTemp;
    edgeTemp = *(this->edges);

    reverse(edgeTemp.begin(), edgeTemp.end());

    int fSize = 1;

    for (i = 0; i < edgeTemp.size(); i++) {//Iterates through Last Edges
		for (j = i+1; j < edgeTemp.size(); j++) {//Iterates through Middle Edges
			for (k = j+1; k < edgeTemp.size(); k++) {//Iterates through First Edges
				if (formsTri(edgeTemp[i], edgeTemp[j], edgeTemp[k])) {
					this->faces->push_back(Face(fSize++, this->edges[i], this->edges[j], this->edges[k]));
					//faces[fSize].lastEdge = &edges[i];
					//faces[fSize].middleEdge = &edges[j];
					//faces[fSize].firstEdge = &edges[k];
					//faces[fSize].index = fSize;
					//fSize++;
				}
			}
		}
	}
}

graph* Graph::copy(Graph g1){
  Graph temp = new Graph(g1.Index(), g1.Points(), g1.Edges());
  temp.CC(g1.CC());
  temp.HasConnected(g1.HasConnected());
  return temp;
}

void Graph::findFreeMembers(Graph* g, dimension){
    int i = 0;
    switch(dimension){
        case 0:
            for(i = 0; i < faces.size(); i++){
                if(points[i].Degree() == 1 && point[i].Destroyed() == false){
                    freePoints.push_back(points[i]);
                }
            }
            break;
        case 1:
            for(i = 0; i < faces.size(); i++){
                if(edges[i].Degree() == 1){
                    freeEdges.push_back(edges[i]);
                }
            }
            break;
        case 2:
            for(i = 0; i < faces.size(); i++){
                if(faces[i].Degree() == 1){
                    freeFaces.push_back(faces[i]);
                }
            }
            break;
        default:
            break;
    }
}

void Graph::freeMembersLeft(Graph g, int dimension){
    switch(dimension){
        case 0:
            if(freePoints.size() > 0){
                return true;
            }
            else{
                return false;
            }
            break;
        case 1:
            if(freeEdges.size() > 0){
                return true;
            }
            else{
                return false;
            }
            break;
        case 2:
            if(freeFaces.size() > 0){
                return true;
            }
            else{
                return false;
            }
            break;
        default:
            printf("Wrong input! --> freeMembersLeft(graph g, int dimension);\n");
            return false;
            break;
    }
}

void Graph::kill(int dimension){
    iterator it;
    switch(dimension){
        case 0:
            if(freeEdges[0].a->degree == 1){
                freeEdges[0].a->Destroy();
                freePoints.erase(find (freePoints.begin(), freePoints.end(), freePoints[0].a));
                freeEdges.erase(freeEdges.begin());
            }
            else if(freeEdges[0].b->degree == 1){
                freeEdges[0].b->Destroy();
                freePoints.erase(find (freePoints.begin(), freePoints.end(), freeFaces[0].b));
                freeEdges.erase(freeEdges.begin());
            }
        case 1:
            if(freeFaces[0].e1->degree == 1){
                freeFaces[0].e1->Destroy();
                it = freeEdges.begin(), freeEdges.end(), freeFaces[0].e1);
                if(find ( == freeFaces[0].e1){
                    freeEdges.erase(it);
                    freeFaces.erase(freeFaces.begin());
                }
                
                
            }
            else if(freeFaces[0].e2->degree == 1){
                freeFaces[0].e2->Destroy();
                freeEdges.erase(find (freeEdges.begin(), freeEdges.end(), freeFaces[0].e2));
                freeFaces.erase(freeFaces.begin());
            }
            else if(freeFaces[0].e3->degree == 1){
                freeFaces[0].e3->Destroy();
                freeEdges.erase(find (freeEdges.begin(), freeEdges.end(), freeFaces[0].e3));
                freeFaces.erase(freeFaces.begin());
            }
            break;
        case 2:
            //Currently not our concern...
            break;
    }
}

void Graph::collapse(graph g1){
  graph* g2;
  g2 = copy(g1);
  findFreeMembers(g2, 2);
  while(g2->getFaces().size() > 0){
    while(freeMembersLeft(g2, 2)){
        kill(1);
    }
}

}
