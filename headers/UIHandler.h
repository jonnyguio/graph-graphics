#ifndef _UI_H_
#define _UI_H_
using namespace std;

class UIHandler {

    public:

        static void render(void);

        static void keyboard(unsigned char c, int x, int y);

        static void mouse(int button, int state, int x, int y);

        static void init(int argc, char** argv, Graph*, int);

        static Graph* mainGraph;

        static Graph* currentGraph;

        static bool drawFaces;

        static int step;

        static int maxStep;

        static void setMainGraph(Graph *g);

        static void setCurrentGraph(Graph *g);
        
        static void drawEdge(float width, float x1, float y1, float x2, float y2, int R, int G, int B);

        static void drawEdge(float width, Edge* e, int R, int G, int B);

        static void drawFace(float x1, float y1, float x2, float y2, float x3, float y3, int R, int G, int B);

        static void drawFace(Edge*, Edge*, Edge*, int, int, int);

        static void drawFace(Face*, int, int, int);

        static void drawGraph(Graph*);

};
#endif
