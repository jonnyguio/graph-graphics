#include <iostream>
#include <cmath>
#include <vector>
#include "../headers/point.h"

using namespace std;

Point::Point (int index, vector<float> *input) {
    this->coordinates = input;
    this->index = index;
    this->degree = 0;
    this->destroyed = false;
}

Point::Point (int index, vector<float> input) {
    this->coordinates = &input;
    this->index = index;
    this->degree = 0;
    this->destroyed = false;
}

Point::Point () {
    this->coordinates = new vector<float>();
    this->degree = 0;
    this->destroyed = false;
}

void Point::Index(int index) {
    this->index = index;
}

int Point::Index() {
    return this->index;
}

int Point::Degree(){
    return this->degree;
}

bool Point::Destroyed(){
    return this->destroyed;
}

void Point::Destroy(){
    this->destroyed = true;
}

void Point::SetDegree(int value){
    this->degree = value;
}

int Point::DegreePP(){
    return ++this->degree;
}

vector<float>* Point::Coordinates() const {return this->coordinates;}

//void Point::Coordinates(int val, int index) {this->coordinates[index] = val;}

void Point::Coordinates(vector<float> *input) {this->coordinates = input;}

void Point::print() {
    /*cout << "(";
    for (vector<float>::iterator it = this->coordinates->begin(); it != this->coordinates->end(); ++it) {
        cout << (it==this->coordinates->begin())?"":", ";
    }
    cout << ")" << endl;//("(%d, %d)\n", this.x, this.y);*/
    cout << index << endl;
}

void Point::printCoordinates() {
    cout << "(";
    for (vector<float>::iterator it = this->coordinates->begin(); it != this->coordinates->end(); ++it) {
        cout << ((it==this->coordinates->begin())?"":", ");
    }
    cout << ")" << endl;
}

float Point::distance(Point *p2) {
    float sum=0;
    vector<float>::iterator it, it2;
    for (it2 = p2->Coordinates()->begin(), it = this->coordinates->begin(); it != this->coordinates->end(); ++it, ++it2)
        sum += pow(*it2 - *it, 2);
    return
        sqrt(sum);
}

bool Point::operator==(const Point& p) {
    return (this->coordinates == p.Coordinates());
}

template class vector<Point>;
