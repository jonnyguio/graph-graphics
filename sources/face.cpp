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
    this->isCrit = false;
    this->destroyed = false;
    this->enabled = false;
    this->rank = -1;
}

Face::Face (int index, Edge *e1, Edge *e2, Edge *e3) {
    this->e1 = e1;
    this->e2 = e2;
    this->e3 = e3;
    this->index = index;
    this->degree = 1;
    this->isCrit = false;
    this->destroyed = false;
    this->enabled = false;
    this->rank = -1;
}

Face::Face (int index, Edge e1, Edge e2, Edge e3) { // eita
    this->e1 = &e1;
    this->e2 = &e2;
    this->e3 = &e3;
    this->index = index;
    this->degree = 1;
    this->isCrit = false;
    this->destroyed = false;
    this->enabled = false;
    this->rank = -1;
}

Face::~Face() {
    //cout << "Destroying face: " << this->index << endl;
}

void Face::print() {
    cout << "Index: " << this->index << "\t(" << this->e1->Index() << ", " << this->e2->Index() << ", " << this->e3->Index() << ") - Degree: " << this->degree << " - IsCrit: " << this->isCrit << endl;
    //this->a->print();
    //this->b->print();
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

bool Face::IsCrit(){
    return this->isCrit;
}

void Face::IsCrit(bool value){
    this->isCrit = value;
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

void Face::Enable(){
    this->enabled = true;
}

void Face::Disable(){
    this->enabled = false;
}

bool Face::IsEnabled(){
    return this->enabled;
}

void Face::Rank(int value){
    this->rank = value;
}

int Face::Rank(){
    return this->rank;
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
