all:
	g++ sources/face.cpp sources/edge.cpp  sources/radius.cpp sources/point.cpp sources/graph.cpp sources/main.cpp -o bin/main -Wall -std=c++11
