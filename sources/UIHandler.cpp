#include <GLUT/GLUT.h>
#include <iostream>
#include "../headers/Graph.h"
#include "../headers/UIHandler.h"

using namespace std;

void UIHandler::init(int argc, char** argv){
	//UIHandler::drawFaces = false;
	printf("Press ESC or Right Click to quit.\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Persistent Homology");

	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

}

void UIHandler::keyboard(unsigned char c, int x, int y){
	cout << (int)c << endl;
	if(c == 27 /*ESC*/){
		exit(0);
	}
	if(c == 46 /* > */){
		//drawFaces = !drawFaces;
		step++;
		glutPostRedisplay();
	}

	if(c == 45 /* < */){
		//drawFaces = !drawFaces;
		if(step > 0){
			step--;
		}
		glutPostRedisplay();
	}

}

void UIHandler::mouse(int button, int state, int x, int y){
	if(button == GLUT_RIGHT_BUTTON){
		exit(0);
	}
}

void UIHandler::setMainGraph(Graph g){
	UIHandler::mainGraph = g;
}

void UIHandler::drawEdge(float width, float x1, float y1, float x2, float y2, int R, int G, int B){
	glLineWidth(width);
    glColor3ub( R, G, B );
    glBegin(GL_LINE_STRIP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void UIHandler::drawEdge(float width, Edge* e, int R, int G, int B){
	vector<float> v1 = e->A()->Coordinates();
	vector<float> v2 = e->B()->Coordinates();
	drawEdge(width, v1[0], v1[1], v2[0], v2[1], R, G, B);
}

void UIHandler::drawFace(float x1, float y1, float x2, float y2, float x3, float y3, int R, int G, int B){
	glLineWidth(1);
	glColor3ub( R, G, B );
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void UIHandler::drawFace(Edge* e1, Edge* e2, Edge* e3, int R, int G, int B){
	vector<Point*> vertices = Graph::verticesFromFace(e1, e2, e3);
	vector<float> v1 = vertices[0]->Coordinates();
	vector<float> v2 = vertices[1]->Coordinates();
	vector<float> v3 = vertices[2]->Coordinates();
	drawFace(v1[0], v1[1], v2[0], v2[1], v3[0], v3[1], R, G, B);
}

void UIHandler::drawFace(Face *f, int R, int G, int B){
	drawFace(f->E1(), f->E2(), f->E3(), R, G, B);
}

void UIHandler::drawGraph(Graph* g){
	int i = 0;
	int j = 0;
	int vSize = g->getVertices()->size();
    int eSize = g->getEdges()->size();
    int fSize = g->Faces()->size();

    for(i = 0, j = 0, step = 0; (i < eSize || j < fSize) && (i+j) < step;) {
        if (i < eSize && g->getEdges()->at(eSize - i - 1).printed == false) {

            g->getEdges()->at(eSize - i - 1).printed = true;
            drawEdge(2, &(g->getEdges()->at(eSize - i - 1)), 255, 255, 255);
            i++;
        }
        while (
        (i+j) < step
        && j < fSize
        && g->Faces()->at(j).E1()->printed
        && g->Faces()->at(j).E2()->printed
        && g->Faces()->at(j).E3()->printed
        ) {
            g->Faces()->at(j).Index(fSize - g->Faces()->at(j).Index());
        	drawFace(&(g->Faces()->at(j)), 100, 150, 150);
            j++;
        }
    }
}

void UIHandler::render(void){
	glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -13, 13, -13, 13, -1, 1);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Draws the axes
    //glEnable(GL_LINE_SMOOTH);
    drawEdge(1, 0.0, 12.0, 0.0, -12.0, 255, 255, 255);
    drawEdge(1, -12.0, 0.0, 12.0, 0.0, 255, 255, 255);

    //Sample graph
    //0 0
	//2 2
	//3 4
	//12 5
	//e0: v0 -- v1
	//e3: v1 -- v2
	//e1: v0 -- v2
	//f0: e0 -- e3 -- e1
	//e5: v2 -- v3
	//e4: v1 -- v3
	//f1: e3 -- e5 -- e4
	//e2: v0 -- v3
	//f2: e1 -- e5 -- e2
	//f3: e0 -- e4 -- e2
/*
	drawEdge(2, 0.0, 0.0, 2.0, 2.0, 210, 0, 0);//e0: v0 -- v1
	drawEdge(2, 2.0, 2.0, 3.0, 4.0, 168, 0, 42);//e3: v1 -- v2
	drawEdge(2, 0.0, 0.0, 3.0, 4.0, 126, 0, 84);//e1: v0 -- v2

	drawEdge(2, 3.0, 4.0, 12.0, 5.0, 84, 0, 126);//e5: v2 -- v3
	drawEdge(2, 2.0, 2.0, 12.0, 5.0, 42, 0, 168);//e4: v1 -- v3

	drawEdge(2, 0.0, 0.0, 12.0, 5.0, 0, 0, 210);//e2: v0 -- v3

	//Change next to true in order to see the faces

	if(drawFaces){
		drawFace(2.0, 2.0, 3.0, 4.0, 12.0, 5.0, 42, 0, 147);//f1: e3 -- e5 -- e4
		drawFace(0.0, 0.0, 3.0, 4.0, 12.0, 5.0, 24, 0, 189);//f2: e1 -- e5 -- e2
		drawFace(0.0, 0.0, 2.0, 2.0, 12.0, 5.0, 0, 0, 255);//f3: e0 -- e4 -- e2
		drawFace(2.0, 2.0, 3.0, 4.0, 12.0, 5.0, 42, 0, 147);//f1: e3 -- e5 -- e4
		drawFace(2.0, 2.0, 3.0, 4.0, 12.0, 5.0, 42, 0, 147);//f1: e3 -- e5 -- e4
		drawFace(0.0, 0.0, 2.0, 2.0, 3.0, 4.0, 168, 0, 42);//f0: e0 -- e3 -- e1
	}
*/

    glutSwapBuffers();
}
