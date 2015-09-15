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

void Face::SetDegree(int value){
    this->degree = value;
}

int Face::DegreePP(){
    return ++this->degree;
}

int Face::DegreeMM(){
    return --this->degree;
}

Edge* Face::E1(){
    return this->e1;
}

Edge* Face::E2(){
    return this->e2;
}

Edge* Face::E3(){
    return this->e3;
}

int Face::Index() {
    return this->index;
}

template class std::vector<Face>;
