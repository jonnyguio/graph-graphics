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
    this->faces = new vector<Face>();
    this->freePoints = new vector<Point*>();
    this->freeEdges = new vector<Edge*>();
    this->freeFaces = new vector<Face*>();
}

Graph::Graph(int index, vector<Point> points, vector<Edge> edges) {
    this->points = &points;
    this->edges = &edges;
    this->index = index;
    this->faces = new vector<Face>();
    this->freePoints = new vector<Point*>();
    this->freeEdges = new vector<Edge*>();
    this->freeFaces = new vector<Face*>();
}

Graph::Graph(int index, vector<Point> *points, vector<Edge> *edges) {
    this->points = points;
    this->edges = edges;
    this->index = index;
    this->faces = new vector<Face>();
    this->freePoints = new vector<Point*>();
    this->freeEdges = new vector<Edge*>();
    this->freeFaces = new vector<Face*>();
}

Graph::Graph(int index, vector<Point> *points, vector<Edge> *edges, vector<Face> *faces) {
    this->points = points;
    this->edges = edges;
    this->index = index;
    this->faces = faces;
    this->freePoints = new vector<Point*>();
    this->freeEdges = new vector<Edge*>();
    this->freeFaces = new vector<Face*>();
}


Graph::~Graph() {
    //cout << "Deleting the graph: " << this->index << endl;
    delete this->faces;
    delete this->edges;
    delete this->points;
}

vector<Point>* Graph::getVertices() {
    return this->points;
}

vector<Point*>* Graph::FreePoints() {
    return this->freePoints;
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

vector<Edge*>* Graph::FreeEdges() {
    return this->freeEdges;
}

void Graph::setEdges(vector<Edge>* edges) {
    this->edges = edges;
}

void Graph::addEdge(Edge* edge) {
    this->edges->push_back(*edge);
}

vector<Face>* Graph::Faces() {
    return this->faces;
}

vector<Face*>* Graph::FreeFaces() {
    return this->freeFaces;
}

void Graph::setFaces(vector<Face>* faces) {
    this->faces = faces;
}

void Graph::addFace(Face* face) {
    this->faces->push_back(*face);
}

void Graph::Index(float index) {
    this->index = index;
}

float Graph::Index(){
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

bool Graph::findInt(vector<int> v, int size, int toFind) {
	int i;
	for(i = 0; i<size; i++) {
		if(v[i] == toFind) {
			return true;
		}
	}
	return false;
}

bool Graph::findPoint(vector<Point> v, int size, Point toFind) {
    int i;
    for(i = 0; i<size; i++) {
        if(&v.at(i) == &toFind) {
            return true;
        }
    }
    return false;
}

bool Graph::findEdge(vector<Edge> v, int size, Edge toFind) {
    int i;
    for(i = 0; i<size; i++) {
        if(&v.at(i) == &toFind) {
            return true;
        }
    }
    return false;
}

void Graph::connect(Radius *r, Point *a, Point *b) {
    //Edge e = Edge(a, b);
    vector<Edge>::iterator it;

    it = find (this->edges->begin(), this->edges->end(), Edge(a,b));

    if ((a->distance(b) / 2 < r->getRadius() && it == this->edges->end()) || r->getRadius() == -1) {
        this->edges->push_back(*(new Edge(a, b)));
        this->edges->at(this->edges->size() - 1).A()->DegreePP();
        this->edges->at(this->edges->size() - 1).B()->DegreePP();
        this->edges->at(this->edges->size() - 1).Dist(a->distance(b));
        this->edges->at(this->edges->size() - 1).Index(this->edges->size());
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

bool Graph::formsTri(Edge e1, Edge e2, Edge e3) {
    vector<int> v, v2;
	int i;

	v.push_back(e1.A()->Index());
	v.push_back(e1.B()->Index());
	v.push_back(e2.A()->Index());
	v.push_back(e2.B()->Index());
	v.push_back(e3.A()->Index());
	v.push_back(e3.B()->Index());

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

void Graph::setTriangles() {
/*    this->faces->clear();

    int i, j, k;

    vector<Edge> edgeTemp;
    edgeTemp = *(this->edges);

    reverse(edgeTemp.begin(), edgeTemp.end());

    int fSize = 1;

    for (i = 0; i < (int) edgeTemp.size(); i++) {//Iterates through Last Edges
		for (j = i+1; j < (int) edgeTemp.size(); j++) {//Iterates through Middle Edges
			for (k = j+1; k < (int) edgeTemp.size(); k++) {//Iterates through First Edges
				if (formsTri(edgeTemp[i], edgeTemp[j], edgeTemp[k])) {
					this->faces->push_back(Face(fSize++, this->edges->at(i), this->edges->at(j), this->edges->at(k)));
					//faces[fSize].lastEdge = &edges[i];
					//faces[fSize].middleEdge = &edges[j];
					//faces[fSize].firstEdge = &edges[k];
					//faces[fSize].index = fSize;
					//fSize++;
				}
			}
		}
	}*/
}

Graph* Graph::copy(Graph *g1){
  Graph* temp = new Graph(g1->Index(), g1->getVertices(), g1->getEdges(), g1->Faces());
  temp->CC(g1->CC());
  temp->HasConnected(g1->HasConnected());
  return temp;
}

void Graph::findFreeMembers(Graph *g, int dimension) {
    int i = 0;
    switch(dimension) {
        case 0:
            for (i = 0; i < (int) g->Faces()->size(); i++){
                if(g->getVertices()->at(i).Degree() == 1 && g->getVertices()->at(i).Destroyed() == false){
                    g->FreePoints()->push_back(&(g->getVertices()->at(i)));
                }
            }
            break;
        case 1:
            for(i = 0; i < (int) g->Faces()->size(); i++){
                if(g->getEdges()->at(i).Degree() == 1 && g->getEdges()->at(i).Destroyed() == false){
                    g->FreeEdges()->push_back(&(g->getEdges()->at(i)));
                }
            }
            break;
        case 2:
            cout << g->Faces()->size() << endl;
            for (i = 0; i < (int) g->Faces()->size(); i++) {
                if (g->Faces()->at(i).Degree() == 1 && g->Faces()->at(i).Destroyed() == false){
                    g->FreeFaces()->push_back(&(g->Faces()->at(i)));
                }
            }
            break;
        default:
            break;
    }
}

bool Graph::freeMembersLeft(Graph *g, int dimension){
    switch(dimension){
        case 0:
            if(g->FreePoints()->size() > 0){
                return true;
            }
            else{
                return false;
            }
            break;
        case 1:
            if(g->FreeEdges()->size() > 0){
                return true;
            }
            else{
                return false;
            }
            break;
        case 2:
            if(g->FreeFaces()->size() > 0){
                return true;
            }
            else{
                return false;
            }
            break;
        default:
            cout << "Wrong input! --> freeMembersLeft(graph g, int dimension);\n" ;
            return false;
            break;
    }
}

bool Graph::kill(Graph *g, int dimension) {
    //vector<Point>::iterator it;
    //vector<Edge>::iterator it2;
    switch(dimension) {
        case 0:
            if(g->FreeEdges()->at(0)->A()->Degree() == 1){
                g->FreeEdges()->at(0)->A()->Destroy();
                g->FreePoints()->erase(remove(g->FreePoints()->begin(), g->FreePoints()->end(), g->FreeEdges()->at(0)->A()), g->FreePoints()->end());
                g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeEdges()->at(0)), g->FreeEdges()->end());
                return true;
            }
            else if(g->FreeEdges()->at(0)->B()->Degree() == 1){

                g->FreeEdges()->at(0)->B()->Destroy();
                g->FreePoints()->erase(remove(g->FreePoints()->begin(), g->FreePoints()->end(), g->FreeEdges()->at(0)->B()), g->FreePoints()->end());
                g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeEdges()->at(0)), g->FreeEdges()->end());
                return true;
            }
        case 1:
            if(g->FreeFaces()->at(0)->E1()->Degree() == 1){
                g->FreeFaces()->at(0)->E1()->Destroy();
                g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeFaces()->at(0)->E1()), g->FreeEdges()->end());
                return true;
            }
            else {
                if(g->FreeFaces()->at(0)->E2()->Degree() == 1){
                    g->FreeFaces()->at(0)->E2()->Destroy();
                    g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeFaces()->at(0)->E2()), g->FreeEdges()->end());
                    return true;
                }
                else {
                    if(g->FreeFaces()->at(0)->E3()->Degree() == 1){
                        g->FreeFaces()->at(0)->E3()->Destroy();
                        g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeFaces()->at(0)->E3()), g->FreeEdges()->end());
                        return true;
                    }
                }
            }
            break;
        case 2:
            //Currently not our concern...
            break;
    }

    return false;
}

void Graph::killCrit(Graph *g, int dimension) {
    switch (dimension) {
        case 1:
            g->getEdges()->at(0).A()->DegreeMM();
            g->getEdges()->at(0).B()->DegreeMM();
            g->getEdges()->erase(remove(g->getEdges()->begin(), g->getEdges()->end(), g->getEdges()->at(0)), g->getEdges()->end());
            g->critEdges++;
        break;
        case 2:
            g->Faces()->at(0).E1()->DegreeMM();
            g->Faces()->at(0).E2()->DegreeMM();
            g->Faces()->at(0).E3()->DegreeMM();
            //g->Faces()->erase(remove(g->Faces()->begin(), g->Faces()->end(), g->Faces()->at(0)), g->Faces()->end());
            g->critFaces++;
        break;
    }
}

void Graph::collapse(){
    Graph* g2;
    int i = 0 ;
    int j = 0;
    g2 = copy(this);
    findFreeMembers(g2, 2);
    while(g2->Faces()->size() > 0 && j < 2 ) {
        j++;
        printf("Still has Members: %lu\n", g2->Faces()->size());
        i = 0;
        while(freeMembersLeft(g2, 2) && i < 3) {
            i++;
            printf(">>Still has free members\n");
            if (!kill(g2, 1)) {
                printf(">>>>I'm removing it\n");
                killCrit(g2, 2);
                findFreeMembers(g2, 2);
            }
            else{
                printf(">>>>SUCCESSFULLY KILLED\n");
            }
        }
    }
}
