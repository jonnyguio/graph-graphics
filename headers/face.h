#include <vector>
#include "edge.h"

#ifndef _FACE_H_
#define _FACE_H_
using namespace std;

class Face {
    private:
        Edge
            *e1,
            *e2,
            *e3;
        int index;
        int degree;

    public:
        Face (int, Edge *, Edge *, Edge *);
        Face (int, Edge, Edge, Edge);
        Face ();

    public:
        void Index(int);

        int Index();

        int Degree();

        void SetDegree(int);

        int DegreePP();

        bool formsTri(Edge *, Edge *, Edge *);

};
#endif
