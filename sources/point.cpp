#include <iostream>
#include <cmath>
#include <vector>
#include "../headers/point.h"

using namespace std;

Point::Point (int index, vector<float> input) {
    this->coordinates = input;
    this->index = index;
    this->degree = 0;
    this->isCrit = true;
    this->destroyed = false;
    this->enabled = false;
}

Point::Point () {
    this->degree = 0;
    this->isCrit = true;
    this->destroyed = false;
    this->enabled = false;
}

Point::~Point() {
    //cout << "Destroying point: " << this->index << endl;
    this->coordinates.clear();
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

bool Point::IsCrit(){
    return this->isCrit;
}

void Point::IsCrit(bool value){
    this->isCrit = value;
}

bool Point::Destroyed(){
    return this->destroyed;
}

void Point::Destroy(){
    this->destroyed = true;
}

void Point::Revive(){
    this->destroyed = false;
}

void Point::Enable(){
    this->enabled = true;
}

void Point::Disable(){
    this->enabled = false;
}

bool Point::IsEnabled(){
    return this->enabled;
}

void Point::Degree(int value){
    this->degree = value;
}

int Point::DegreePP(){
    return ++this->degree;
}

int Point::DegreeMM(){
    return --this->degree;
}

vector<float> Point::Coordinates() const {return this->coordinates;}

//void Point::Coordinates(int val, int index) {this->coordinates[index] = val;}

void Point::Coordinates(vector<float> input) {this->coordinates = input;}

void Point::print() {
    cout << "v" << index << ": ";
    cout << "(";
    for (vector<float>::iterator it = this->coordinates.begin(); it != this->coordinates.end(); ++it) {
        cout << *it;
        cout << ((it+1==this->coordinates.end())?"":", ");
    }
    cout << ")" << endl;//("(%d, %d)\n", this.x, this.y);*/
}

void Point::printCoordinates() {
    cout << "(";
    for (vector<float>::iterator it = this->coordinates.begin(); it != this->coordinates.end(); ++it) {
        cout << ((it==this->coordinates.begin())?"":", ");
    }
    cout << ")" << endl;
}

float Point::distance(Point *p2) {
    float sum=0;
    vector<float>::iterator it, it2;
    for (it2 = p2->Coordinates().begin(), it = this->coordinates.begin(); it != this->coordinates.end(); ++it, ++it2)
        sum += pow(*it2 - *it, 2);
    return
        sqrt(sum);
}

bool Point::operator==(const Point& p) {
    return (this->coordinates == p.Coordinates());
}

template class std::vector<Point>;
