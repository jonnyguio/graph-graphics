#include <vector>

#ifndef _EDGE_H_
#define _EDGE_H_
using namespace std;

class Edge {
    private:
        Point *a, *b;

    public:
        Edge (Point *, Point *);
        Edge (Point, Point);
        Edge ();

    public:
        void print(void);

        int distance(void);

};
#endif
