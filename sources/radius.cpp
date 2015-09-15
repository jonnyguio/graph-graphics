#include "../headers/radius.h"

Radius::Radius() {
    this->radius = 0;
    this->rate = 0;
}

Radius::Radius(float radius, float rate) {
    this->radius = radius;
    this->rate = rate;
}

float Radius::getRadius() {
    return this->radius;
}

void Radius::increase() {
    this->radius += this->rate;
}

float Radius::Rate() {
    return this->rate;
}

void Radius::Rate(float rate) {
    this->rate = rate;
}
