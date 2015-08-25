#include <vector>
#include "point.h"

#ifndef _EDGE_H_
#define _EDGE_H_
using namespace std;

class Edge {

    private:
        Point
            *a, *b;
        int
            index;

    public:
        Edge (Point *, Point *);
        Edge (Point, Point);
        Edge ();

        void Index(int);

        int Index(void);

        void print(void);

        float distance(void);

        Point* A() const;

        void A(Point*);

        Point* B() const;

        void B(Point*);

        bool operator==(const Edge&);
};
#endif
