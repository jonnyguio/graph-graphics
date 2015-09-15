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
        int index,
            degree;
        bool destroyed;

    public:
        Face (int, Edge *, Edge *, Edge *);
        Face (int, Edge, Edge, Edge);
        Face ();
        ~Face();

        bool operator==(const Face&);

    public:
        void Index(int);

        int Index();

        int Degree();

        bool Destroyed();

        void Destroy();

        void SetDegree(int);

        int DegreePP();

        int DegreeMM();

        Edge* E1() const;

        Edge* E2() const;

        Edge* E3() const;

        bool formsTri(Edge *, Edge *, Edge *);

};
#endif
