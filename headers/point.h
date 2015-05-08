#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

using namespace std;

class Point {
    private:
        vector<int> *coordinates;

    public:
        Point (vector<int>*);
        Point ();

    public:
        void print(void);

        float distance(Point*);

        vector<int>* Coordinates();

        //void Coordinates(int, int);

        void Coordinates(vector<int>*);

};
