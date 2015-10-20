#include <vector>

#ifndef _POINT_H_
#define _POINT_H_
using namespace std;

class Point {
    private:
        vector<float> coordinates;
        int index,
            degree;
        bool destroyed,
            enabled,
            isCrit;

    public:
        Point (int, vector<float>);
        Point ();
        ~Point();

    public:
        void Index(int);

        int Index();

        int Degree();

        bool IsCrit();

        void IsCrit(bool);

        bool Destroyed();

        void Destroy();

        void Revive();

        void Enable();

        void Disable();

        bool IsEnabled();

        void Degree(int);

        int DegreePP();

        int DegreeMM();

        void print(void);

        void printCoordinates(void);

        float distance(Point*);

        vector<float> Coordinates() const;

        //void Coordinates(int, int);

        void Coordinates(vector<float>);

        bool operator==(const Point&);

};
#endif
