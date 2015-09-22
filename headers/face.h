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

        void print(void);

        int Degree();

        bool Destroyed();

        void Destroy();

        void Revive();

        void Degree(int);

        int DegreePP();

        int DegreeMM();

        Edge* E1() const;

        void E1(Edge*);

        Edge* E2() const;

        void E2(Edge*);

        Edge* E3() const;

        void E3(Edge*);

        bool formsTri(Edge *, Edge *, Edge *);

};
#endif
