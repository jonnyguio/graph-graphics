#include <vector>

#ifndef _POINT_H_
#define _POINT_H_
using namespace std;

class Point {
    private:
        vector<float> *coordinates;
        int index;

    public:
        Point (int, vector<float>*);
        Point (int, vector<float>);
        Point ();

    public:
        void Index(int);

        int Index();

        void print(void);

        void printCoordinates(void);

        float distance(Point*);

        vector<float>* Coordinates();

        //void Coordinates(int, int);

        void Coordinates(vector<float>*);

};
#endif
