all:
	g++ sources/face.cpp sources/point.cpp sources/edge.cpp sources/radius.cpp sources/graph.cpp sources/main.cpp -o bin/main -Wall
	g++ UI.cpp -o bin/UI -framework OpenGl -framework GLUT
