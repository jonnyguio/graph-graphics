#include <vector>
#include "point.h"

#ifndef _EDGE_H_
#define _EDGE_H_
using namespace std;

class Edge {

    private:
        Point
            *a,
            *b;
        int index,
            degree;
        float
            dist;
        bool destroyed,
            isCrit;

    public:
        bool printed;
        bool drawn;
        Edge (Point *, Point *);
        Edge (Point, Point);
        Edge ();
        ~Edge();

        void Index(int);

        int Index(void);

        void Dist(float);

        float Dist(void) const;

        int Degree();

        bool IsCrit();

        void IsCrit(bool);

        bool Destroyed();

        void Destroy();

        void Revive();

        void Degree(int);

        int DegreePP();

        int DegreeMM();

        void print(void);

        float distance(void);

        Point* A() const;

        void A(Point*);

        Point* B() const;

        void B(Point*);

        bool operator==(const Edge&);
};
#endif
