#include "../headers/point.h"

#ifndef _RADIUS_H_
#define _RADIUS_H_
class Radius {
    private:
        float radius;
        float rate;

    public:
        Radius();

        Radius(float, float);

        float getRadius();

        float increase();

        float Rate();

        void Rate(float);

        bool isTouching();

        float lerp(float, Point*, Point*);
};
#endif
