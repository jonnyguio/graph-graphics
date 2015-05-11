#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

#ifndef POINT_H
#define POINT_H
#include "../headers/point.h"
#endif

#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

using namespace std;

Point::Point (vector<int> *input) {
    this->coordinates = input;
}

Point::Point () {
    this->coordinates = new vector<int>();
}

vector<int>* Point::Coordinates() {return this->coordinates;}

//void Point::Coordinates(int val, int index) {this->coordinates[index] = val;}

void Point::Coordinates(vector<int> *input) {this->coordinates = input;}

void Point::print() {
    cout << "(";
    for (vector<int>::iterator it = this->coordinates->begin(); it != this->coordinates->end(); ++it) {
        cout << (it==this->coordinates->begin())?"":", ";
    }
    cout << ")" << endl;//("(%d, %d)\n", this.x, this.y);
}

float Point::distance(Point *p2) {
    float sum=0;
    vector<int>::iterator it, it2;
    for (it2 = p2->Coordinates()->begin(), it = this->coordinates->begin(); it != this->coordinates->end(); ++it, ++it2)
        sum += pow(*it2 - *it, 2);
    return
        sqrt(sum);
}
