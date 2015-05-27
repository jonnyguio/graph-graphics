#include <iostream>
#include <cmath>
#include <vector>
#include "../headers/point.h"

using namespace std;

Point::Point (vector<float> *input) {
    this->coordinates = input;
}

Point::Point (vector<float> input) {
    this->coordinates = &input;
}

Point::Point () {
    this->coordinates = new vector<float>();
}

void Point::Index(int index) {
    this->index = index;
}

int Point::Index() {
    return this->index;
}

vector<float>* Point::Coordinates() {return this->coordinates;}

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
        cout << (it==this->coordinates->begin())?"":", ";
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
