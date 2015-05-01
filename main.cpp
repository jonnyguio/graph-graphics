#include <iostream>

using namespace std;

class Coordinate {
    private:
        int x, y;

    public:
        Coordinate (int x, int y) {
            this->x = x;
            this->y = y;
        }
        Coordinate () {
            this->x = 0;
            this->y = 0;
        }

    public:
        void print(void);
};

void Coordinate::print() {
    cout << "(" << this->x << ", " << this->y << ")" << endl;//("(%d, %d)\n", this.x, this.y);
}

class Graph {
    private:
        int index;
        Coordinate point;
        Graph *next;

    public:
        Graph(int index, Coordinate point) {
            this->point = point;
            this->index = index;
        }

        Graph * nextVertice() {
            return this->next;
        }

        void print() {
            cout << "Index:" << this->index << endl << "Coordinates:";
            point.print();
            cout << endl;
        }

};

int main () {
    Coordinate point1(1, 1);
    Graph graph(1, point1);
    Graph->next = new Graph(2, new Coordinate(2, 2));
    point1.print();
    graph.print();
}
