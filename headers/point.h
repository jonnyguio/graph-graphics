#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

using namespace std;

class Point {
    private:
        vector<float> *coordinates;

    public:
        Point (vector<float>*);
        Point (vector<float>);
        Point ();

    public:
        void print(void);

        float distance(Point*);

        vector<float>* Coordinates();

        //void Coordinates(int, int);

        void Coordinates(vector<float>*);

};
