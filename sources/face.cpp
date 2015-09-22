#include <iostream>
#include <cmath>
#include <vector>
#include "../headers/face.h"

using namespace std;

Face::Face () {
    this->e1 = NULL;
    this->e2 = NULL;
    this->e3 = NULL;
    this->degree = 1;
    this->destroyed = false;
}

Face::Face (int index, Edge *e1, Edge *e2, Edge *e3) {
    this->e1 = e1;
    this->e2 = e2;
    this->e3 = e3;
    this->index = index;
    this->degree = 1;
    this->destroyed = false;
}

Face::Face (int index, Edge e1, Edge e2, Edge e3) { // eita
    this->e1 = &e1;
    this->e2 = &e2;
    this->e3 = &e3;
    this->index = index;
    this->degree = 1;
    this->destroyed = false;
}

Face::~Face() {
    //cout << "Destroying face: " << this->index << endl;
}

bool Face::operator==(const Face& f) {
    return (this->e1 == f.E1() && this->e2 == f.E2() && this->e3 == f.E3());
}

void Face::Index(int index) {
    this->index = index;
}

int Face::Degree(){
    return this->degree;
}

bool Face::Destroyed(){
    return this->destroyed;
}

void Face::Destroy(){
    this->destroyed = true;
}

void Face::Revive(){
    this->destroyed = false;
}

void Face::Degree(int value){
    this->degree = value;
}

int Face::DegreePP(){
    return ++this->degree;
}

int Face::DegreeMM(){
    return --this->degree;
}

Edge* Face::E1() const{
    return this->e1;
}

void Face::E1(Edge *e) {
    this->e1 = e;
}

Edge* Face::E2() const{
    return this->e2;
}

void Face::E2(Edge *e) {
    this->e2 = e;
}

Edge* Face::E3() const{
    return this->e3;
}

void Face::E3(Edge *e) {
    this->e3 = e;
}

int Face::Index() {
    return this->index;
}

template class std::vector<Face>;
