all:
	g++ sources/face.cpp sources/edge.cpp  sources/radius.cpp sources/point.cpp sources/graph.cpp sources/main.cpp sources/UI.cpp -o bin/Homology -framework OpenGL -framework GLUT -Wall -std=c++11
	
