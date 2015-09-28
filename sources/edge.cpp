#include <iostream>
#include <cmath>
#include <vector>
#include "../headers/edge.h"

using namespace std;

Edge::Edge () {
    this->a = NULL;
    this->b = NULL;
    this->degree = 0;
    this->isCrit = false;
    this->destroyed = false;
    this->printed = false;
    this->drawn = false;
}

Edge::Edge (Point *a, Point *b) {
    this->a = a;
    this->b = b;
    this->degree = 0;
    this->isCrit = false;
    this->destroyed = false;
    this->printed = false;
    this->drawn = false;
}

Edge::Edge (Point a, Point b) {
    this->a = &a;
    this->b = &b;
    this->degree = 0;
    this->isCrit = false;
    this->destroyed = false;
    this->printed = false;
    this->drawn = false;
}

Edge::~Edge() {
    //cout << "Destroying edge: " << this->index << endl;
}

void Edge::Index(int index) {
    this->index = index;
}

int Edge::Index() {
    return this->index;
}

void Edge::Dist(float dist){
    this->dist = dist;
}

float Edge::Dist() const{
    return this->dist;
}

int Edge::Degree(){
    return this->degree;
}

bool Edge::IsCrit(){
    return this->isCrit;
}

void Edge::IsCrit(bool value){
    this->isCrit = value;
}

bool Edge::Destroyed(){
    return this->destroyed;
}

void Edge::Destroy(){
    this->destroyed = true;
}

void Edge::Revive(){
    this->destroyed = false;
}

void Edge::Degree(int value){
    this->degree = value;
}

int Edge::DegreePP(){
    return ++this->degree;
}

int Edge::DegreeMM(){
    return --this->degree;
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
    cout << "Index: " << this->index << "\t(" << this->a->Index() << ", " << this->b->Index() << ") - Distance: " << this->dist << " - Degree: " << this->degree << " - isCrit: " << this->isCrit << endl;
    //this->a->print();
    //this->b->print();
}

float Edge::distance() {
    float sum=0;
    vector<float>::iterator it, it2;
    for (
        it2 = this->a->Coordinates().begin(), it = this->b->Coordinates().begin(); it != this->a->Coordinates().end() || it2 != this->b->Coordinates().end(); ++it, ++it2
        )
        sum += pow(*it2 - *it, 2);
    return
        sqrt(sum);
}

template class std::vector<Edge>;
