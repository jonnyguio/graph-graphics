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
