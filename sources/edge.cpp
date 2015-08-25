#include <iostream>
#include <cmath>
#include <vector>
#include "../headers/edge.h"

using namespace std;

Edge::Edge () {
    this->a = NULL;
    this->b = NULL;
}

Edge::Edge (Point *a, Point *b) {
    this->a = a;
    this->b = b;
}

Edge::Edge (Point a, Point b) {
    this->a = &a;
    this->b = &b;
}

void Edge::Index(int index) {
    this->index = index;
}

int Edge::Index() {
    return this->index;
}

Point* Edge::A() const {
    return this->a;
}

void Edge::A(Point *a) {
    this->a = a;
}

Point* Edge::B() const {
    return this->b;
}

void Edge::B(Point *b) {
    this->b = b;
}

bool Edge::operator==(const Edge& e) {
    return (this->a == e.A() && this->b == e.B());
}

void Edge::print() {
    cout << "\t(" << this->a->Index() << ", " << this->b->Index() << ")" << endl;
    //this->a->print();
    //this->b->print();
}

float Edge::distance() {
    float sum=0;
    vector<float>::iterator it, it2;
    for (
        it2 = this->a->Coordinates()->begin(), it = this->b->Coordinates()->begin(); it != this->a->Coordinates()->end() || it2 != this->b->Coordinates()->end(); ++it, ++it2
        )
        sum += pow(*it2 - *it, 2);
    return
        sqrt(sum);
}

template class vector<Edge>;
