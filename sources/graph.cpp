#include "../headers/graph.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <typeinfo>

#define MAXPOINT 10000

using namespace std;

struct EdgeCompare {
  bool operator()(const Edge& e1, const Edge& e2) const {
    return e1.Dist() > e2.Dist();
  }
} compare;

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

Graph::Graph(int index) {
    this->points = new vector<Point>();
    this->edges = new vector<Edge>();
    this->index = index;
    this->faces = new vector<Face>();
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

vector<Point>* Graph::Points() {
    return this->points;
}

vector<Point*>* Graph::FreePoints() {
    return this->freePoints;
}

void Graph::setPoints(vector<Point>* points) {
    this->points = points;
}

void Graph::addPoint(Point *point) {
    this->points->push_back(*point);
}

vector<Edge>* Graph::Edges() {
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

    if ((a->distance(b) / 2 <= r->getRadius() && it == this->edges->end()) || r->getRadius() == -1) {
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

Graph* Graph::copy(Graph *g1){
  Graph* temp = new Graph(g1->Index(), g1->Points(), g1->Edges(), g1->Faces());
  temp->CC(g1->CC());
  temp->HasConnected(g1->HasConnected());
  return temp;
}

void Graph::livingMembers(Graph *g, int dimension) {
    int i = 0;
    switch(dimension) {
        case 0:
            g->FreePoints()->clear();
            for (i = 0; i < (int) g->Points()->size(); i++){
                if (g->Points()->at(i).Destroyed() == false){
                    g->FreePoints()->push_back(&(g->Points()->at(i)));
                }
            }
            break;
        case 1:
            g->FreeEdges()->clear();
            for(i = 0; i < (int) g->Edges()->size(); i++){
                if (g->Edges()->at(i).Destroyed() == false){
                    g->FreeEdges()->push_back(&(g->Edges()->at(i)));
                }
            }
            break;
        case 2:
            g->FreeFaces()->clear();
            for (i = 0; i < (int) g->Faces()->size(); i++) {
                if (g->Faces()->at(i).Destroyed() == false){
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
            for (int i = 0; i < g->FreeEdges()->size(); i++) {
                if(g->FreeEdges()->at(i)->A()->Degree() == 1 && !g->FreeEdges()->at(i)->A()->Destroyed()) {
                    g->FreeEdges()->at(i)->A()->DegreeMM();
                    g->FreeEdges()->at(i)->B()->DegreeMM();
                    g->FreeEdges()->at(i)->A()->Destroy();
                    g->FreePoints()->erase(remove(g->FreePoints()->begin(), g->FreePoints()->end(), g->FreeEdges()->at(i)->A()), g->FreePoints()->end());
                    g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeEdges()->at(i)), g->FreeEdges()->end());
                    return true;
                }
                else if(g->FreeEdges()->at(i)->B()->Degree() == 1 && !g->FreeEdges()->at(i)->B()->Destroyed()) {
                    g->FreeEdges()->at(i)->A()->DegreeMM();
                    g->FreeEdges()->at(i)->B()->DegreeMM();
                    g->FreeEdges()->at(i)->B()->Destroy();
                    g->FreePoints()->erase(remove(g->FreePoints()->begin(), g->FreePoints()->end(), g->FreeEdges()->at(i)->B()), g->FreePoints()->end());
                    g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeEdges()->at(i)), g->FreeEdges()->end());
                    return true;
                }
            }
            break;
        case 1:
            for (int i = 0; i < g->FreeEdges()->size(); i++) {
                if(g->FreeFaces()->at(0)->E1()->Degree() == 1 && !g->FreeFaces()->at(0)->E1()->Destroyed()){
                    //cout << ">>> teste1" << endl;
                    g->FreeFaces()->at(0)->E1()->DegreeMM();
                    g->FreeFaces()->at(0)->E2()->DegreeMM();
                    g->FreeFaces()->at(0)->E3()->DegreeMM();
                    g->FreeFaces()->at(0)->E1()->Destroy();
                    g->FreeFaces()->at(0)->E1()->A()->DegreeMM();
                    g->FreeFaces()->at(0)->E1()->B()->DegreeMM();
                    g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeFaces()->at(0)->E1()), g->FreeEdges()->end());
                    g->FreeFaces()->erase(remove(g->FreeFaces()->begin(), g->FreeFaces()->end(), g->FreeFaces()->at(0)), g->FreeFaces()->end());
                    return true;
                }
                else {
                    if(g->FreeFaces()->at(0)->E2()->Degree() == 1 && !g->FreeFaces()->at(0)->E2()->Destroyed()){
                        //cout << ">>> teste2" << endl;
                        g->FreeFaces()->at(0)->E1()->DegreeMM();
                        g->FreeFaces()->at(0)->E2()->DegreeMM();
                        g->FreeFaces()->at(0)->E3()->DegreeMM();
                        g->FreeFaces()->at(0)->E2()->Destroy();
                        g->FreeFaces()->at(0)->E2()->A()->DegreeMM();
                        g->FreeFaces()->at(0)->E2()->B()->DegreeMM();
                        g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeFaces()->at(0)->E2()), g->FreeEdges()->end());
                        g->FreeFaces()->erase(remove(g->FreeFaces()->begin(), g->FreeFaces()->end(), g->FreeFaces()->at(0)), g->FreeFaces()->end());
                        return true;
                    }
                    else {
                        if(g->FreeFaces()->at(0)->E3()->Degree() == 1 && !g->FreeFaces()->at(0)->E3()->Destroyed()){
                            //cout << ">>> teste3 " << g->FreeEdges()->size() << endl;
                            g->FreeFaces()->at(0)->E1()->DegreeMM();
                            g->FreeFaces()->at(0)->E2()->DegreeMM();
                            g->FreeFaces()->at(0)->E3()->DegreeMM();
                            g->FreeFaces()->at(0)->E3()->Destroy();
                            g->FreeFaces()->at(0)->E3()->A()->DegreeMM();
                            g->FreeFaces()->at(0)->E3()->B()->DegreeMM();
                            g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeFaces()->at(0)->E3()), g->FreeEdges()->end());
                            g->FreeFaces()->erase(remove(g->FreeFaces()->begin(), g->FreeFaces()->end(), g->FreeFaces()->at(0)), g->FreeFaces()->end());
                            return true;
                        }
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
            g->FreeEdges()->at(0)->A()->DegreeMM();
            g->FreeEdges()->at(0)->B()->DegreeMM();
            g->FreeEdges()->erase(remove(g->FreeEdges()->begin(), g->FreeEdges()->end(), g->FreeEdges()->at(0)), g->FreeEdges()->end());
            g->critEdges++;
        break;
        case 2:
            g->FreeFaces()->at(0)->E1()->DegreeMM();
            g->FreeFaces()->at(0)->E2()->DegreeMM();
            g->FreeFaces()->at(0)->E3()->DegreeMM();
            //cout << typeid(g->Faces()->at(0)).name() << endl;
            //g->FreeFaces()->at(0)->E1()->print();
            //g->FreeFaces()->at(0)->E2()->print();
            //g->FreeFaces()->at(0)->E3()->print();
            g->FreeFaces()->erase(remove(g->FreeFaces()->begin(), g->FreeFaces()->end(), g->FreeFaces()->at(0)), g->FreeFaces()->end());
            g->critFaces++;
        break;
    }
}

void Graph::collapse(){
    Graph* g2;
    int i = 0 ;
    int j = 0;
    g2 = copy(this);
    livingMembers(g2, 2);
    while(g2->FreeFaces()->size() > 0) {
        j++;
        printf("Still has Members: %lu\n", g2->FreeFaces()->size());
        i = 0;
        while(freeMembersLeft(g2, 2)) {
            i++;
            printf(">>Still has faces\n");
            if (!kill(g2, 1)) {
                printf(">>>>I'm removing it\n");
                killCrit(g2, 2);
                livingMembers(g2, 1);
            }
            else{
                printf(">>>>SUCCESSFULLY KILLED\n");
            }
        }
    }
    livingMembers(g2, 1);
    while(g2->FreeEdges()->size() > 0) {
        j++;
        printf("Still has Members: %lu\n", g2->FreeEdges()->size());
        i = 0;
        while(freeMembersLeft(g2, 1)) {
            i++;
            printf(">>Still has edges\n");
            if (!kill(g2, 0)) {
                printf(">>>>I'm removing it\n");
                killCrit(g2, 1);
                livingMembers(g2, 0);
            }
            else{
                printf(">>>>SUCCESSFULLY KILLED\n");
            }
        }
    }
    cout << "Arestas críticas: " << g2->critEdges << "\t Faces críticas: " << g2->critFaces << "\t Vértices críticos: " << g2->FreePoints()->size() << endl;
}

void Graph::calc(streambuf *backup, streambuf *out) {

    vector<float>
        point;

    Radius
        *radius;

    int
        n, i, j, k, fSize, eSize, vSize;

    float
        x, y,
        minx = 0, maxx = 0, miny = 0, maxy = 0;

    ifstream infile("teste2");

    //cout.rdbuf(out);

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
            //if (this) {
            point.push_back(x);
            point.push_back(y);
            this->addPoint(new Point(++n, point));
            point.clear();
                //this->print();
            //}
            /*else {
                point.push_back(x);
                point.push_back(y);
                points = new vector<Point>();
                points->push_back(*(new Point(++n, point)));
                this->points = points;
                this->index = 1;
                point.clear();
                //begin->print();
            }*/
        }
    }

    radius = new Radius(0, 0.5);

    vector<Point>::iterator it, it2;
    while (radius->getRadius() <= 1) {
        i = 0;
        for (it = this->Points()->begin(); it != this->Points()->end(); ++it) {
            for (it2 = this->Points()->begin() + ++i; it2 != this->Points()->end(); ++it2) {
                this->connect(radius, &(*it), &(*it2));
            }
        }
        radius->increase();
    }

    sort(this->Edges()->begin(), this->Edges()->end(), compare);

    this->print();

    fSize = 0;
    //this->setTriangles();

    i = 0;
    for (vector<Edge>::iterator it = this->Edges()->begin(); it != this->Edges()->end(); ++it) {
        j = i++ + 1;
        for (vector<Edge>::iterator it2 = this->Edges()->begin() + j; it2 != this->Edges()->end(); ++it2) {
            k = j++ + 1;
            for (vector<Edge>::iterator it3 = this->Edges()->begin() + k; it3 != this->Edges()->end(); ++it3) {
                if (this->formsTri(*it, *it2, *it3)) {
                    //cout << (*it).Index() << " " << (*it2).Index() << " " << (*it3).Index() << endl;
                    this->Faces()->push_back(*(new Face(++fSize, &(*it), &(*it2), &(*it3))));
                    (*it).DegreePP();
                    (*it2).DegreePP();
                    (*it3).DegreePP();
                }

            }
        }
    }

    //reverse(this->Edges()->begin(), this->Edges()->end());
    reverse(this->Faces()->begin(), this->Faces()->end());

    for (vector<Point>::iterator it = this->Points()->begin(); it != this->Points()->end(); ++it)
    {
        (*it).print();
    }
    cout << endl;

    vSize = this->Points()->size();
    eSize = this->Edges()->size();

    for(i = 0, j = 0; i < eSize || j < fSize;) {
        if (i < eSize && this->Edges()->at(eSize - i - 1).printed == false) {

            this->Edges()->at(eSize - i - 1).printed = true;
            printf("e%d: v%d -- v%d\n",
                this->Edges()->at(eSize - i - 1).Index(),
                this->Edges()->at(eSize - i - 1).A()->Index(),
                this->Edges()->at(eSize - i - 1).B()->Index());
            i++;
        }
        while (
        j < fSize
        && this->Faces()->at(j).E1()->printed
        && this->Faces()->at(j).E2()->printed
        && this->Faces()->at(j).E3()->printed
        ) {
            this->Faces()->at(j).Index(fSize - this->Faces()->at(j).Index());

            printf("f%d: e%d -- e%d -- e%d\n",
                this->Faces()->at(j).Index(),
                this->Faces()->at(j).E1()->Index(),
                this->Faces()->at(j).E2()->Index(),
                this->Faces()->at(j).E3()->Index());
            j++;
        }
    }

    this->collapse();

    delete radius;

}
