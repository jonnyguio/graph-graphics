#include <vector>

#ifndef _POINT_H_
#define _POINT_H_
using namespace std;

class Point {
    private:
        vector<float> *coordinates;
        int index,
            degree;
        bool destroyed;

    public:
        Point (int, vector<float>*);
        Point (int, vector<float>);
        Point ();

    public:
        void Index(int);

        int Index();

        int Degree();

        bool Destroyed();

        void Destroy();

        void SetDegree(int);

        int DegreePP();

        void print(void);

        void printCoordinates(void);

        float distance(Point*);

        vector<float>* Coordinates() const;

        //void Coordinates(int, int);

        void Coordinates(vector<float>*);

        bool operator==(const Point&);

};
#endif
