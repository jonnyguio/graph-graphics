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


using namespace std;

Point::Point (float x, float y) {
    this->x = x;
    this->y = y;
}

Point::Point () {
    this->x = 0;
    this->y = 0;
}

float Point::X() {return this->x;}

float Point::Y() {return this->y;}

void Point::X(float x) {this->x = x;}

void Point::Y(float y) {this->y = y;}

void Point::print() {
    cout << "(" << this->x << ", " << this->y << ")" << endl;//("(%d, %d)\n", this.x, this.y);
}

float Point::distance(Point *p2) {
    return
        sqrt(
            pow(p2->X() - this->X(), 2) + pow(p2->Y() - this->Y(), 2)
        );
}
