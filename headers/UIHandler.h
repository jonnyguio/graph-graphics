#ifndef _UI_H_
#define _UI_H_
using namespace std;

class UIHandler {

    public:

        static void render(void);

        static void keyboard(unsigned char c, int x, int y);

        static void mouse(int button, int state, int x, int y);

        static int init(int argc, char** argv);

        static bool drawFaces;

        static int step;

        static void drawEdge(float width, float x1, float y1, float x2, float y2, int R, int G, int B);

        static void drawEdge(float width, Edge* e, int R, int G, int B);

        static void drawFace(float x1, float y1, float x2, float y2, float x3, float y3, int R, int G, int B);

        static void drawGraph();

};
#endif
