#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPOINT 10000

using namespace std;

class Point {
    private:
        int x, y;

    public:
        Point (int x, int y) {
            this->x = x;
            this->y = y;
        }
        Point () {
            this->x = 0;
            this->y = 0;
        }

    public:
        void print(void);
};

void Point::print() {
    cout << "(" << this->x << ", " << this->y << ")" << endl;//("(%d, %d)\n", this.x, this.y);
}

class Graph {
    private:
        int index;
        Point point;
        Graph *next;

    public:
        Graph(int index, Point point) {
            this->point = point;
            this->index = index;
        }

        Graph(int index, Point *point) {
            this->point = *point;
            this->index = index;
        }

        Graph * nextVertice() {
            return this->next;
        }

        void addVertice(Graph * newg) {
            this->next = newg;
        }

        void print() {
            cout << "Index:" << this->index << endl << "Points:";
            point.print();
            cout << endl;
        }

};

int main () {
    Point *point1;
    Graph *graph, *begin;
    /*graph->addVertice(new Graph(2, new Point(2, 2)));
    point1->print();
    graph->print();
    graph->nextVertice()->print();*/
    int n, x, y;
    string line;
    ifstream infile("teste.txt");

    n = 0;
    begin = NULL;
    while (infile >> x >> y) {
        if (begin) {
            graph->addVertice(new Graph(++n, new Point(x,y)));
            graph = graph->nextVertice();
            graph->print();
        }
        else {
            begin = new Graph(++n, new Point(x,y));
            begin->print();
            graph = begin;
        }
        //cout << x << "," << y << endl;
    }
    cout << "We have " << n << " points." << endl;
}
