#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

typedef struct _vertex
{
	float x;
	float y;
	int index;
} vertex;

typedef struct _edge
{
	vertex* v1;
	vertex* v2;
	float dist;
	bool printed;
	int index;
} edge;

typedef struct _face
{
	edge* firstEdge;
	edge* middleEdge;
	edge* lastEdge;
	int index;
} face;

float distance(edge* e){//Returns simple euclidian distance
	return sqrt((e->v1->x - e->v2->x)*(e->v1->x - e->v2->x) + (e->v1->y - e->v2->y)*(e->v1->y - e->v2->y));
}

bool compare(edge e1, edge e2){
	return e1.dist > e2.dist;
}

bool findInt(vector<int> v, int size, int toFind){
	int i;
	for(i = 0; i<size; i++){
		if(v[i] == toFind){
			return true;
		}
	}
	return false;
}

bool formsTri(edge e1, edge e2, edge e3){
	vector<int> v, v2;
	int i;
	v.push_back(e1.v1->index);
	v.push_back(e1.v2->index);
	v.push_back(e2.v1->index);
	v.push_back(e2.v2->index);
	v.push_back(e3.v1->index);
	v.push_back(e3.v2->index);
	for(i = 0; i < 6; i++){
		if (!findInt(v2, v2.size(), v[i])){
			v2.push_back(v[i]);
		}
	}
	if (v2.size() == 3){
		return true;
	}
	else{
		return false;
	}
}

int main(){

	size_t vSize = 0;//Number of vertices
	size_t eSize = 0;//Number of edges
	size_t fSize = 0;//Number of faces

	int i = 0;//Iteration counters
	int j = 0;//Iteration counters
	int k = 0;//Iteration counters

	//Vectors
	vector<vertex> vertices;
	vector<edge> edges;
	vector<face> faces;

	//Temporary variables
	float xTemp, yTemp;//Current input coordinates

	while(scanf("%f %f", &xTemp, &yTemp) != EOF){
		vertices.push_back(vertex());
		vertices[vSize].x = xTemp;
		vertices[vSize].y = yTemp;
		vertices[vSize].index = vSize;
		vSize++;
	}

	for(i = 0; i < vSize; i++){
		for(j = i+1; j < vSize; j++){
				edges.push_back(edge());
				edges[eSize].v1 = &vertices[i];
				edges[eSize].v2 = &vertices[j];
				edges[eSize].dist = distance(&edges[eSize]);
				edges[eSize].printed = false;
				edges[eSize].index = eSize;
				eSize++;
		}
	}

	//Sort edges according to size in descending order
	sort(edges.begin(), edges.end(), compare);

	for(i = 0; i < eSize; i++){//Iterates through Last Edges
		for(j = i+1; j < eSize; j++){//Iterates through Middle Edges
			for(k = j+1; k < eSize; k++){//Iterates through First Edges
				if(formsTri(edges[i], edges[j], edges[k])){
					faces.push_back(face());
					faces[fSize].lastEdge = &edges[i];
					faces[fSize].middleEdge = &edges[j];
					faces[fSize].firstEdge = &edges[k];
					faces[fSize].index = fSize;
					fSize++;
				}
			}
		}
	}
	reverse(edges.begin(), edges.end());
	reverse(faces.begin(), faces.end());

	for(i = 0; i < vSize; i++){
		printf("v%lu (%f, %f)\n", vertices[i].index, vertices[i].x, vertices[i].y);
	}
	printf("\n");

	for(i = 0, j = 0; i < eSize || j < fSize;){
		if(i < eSize && edges[eSize - i - 1].printed == false){

			edges[eSize - i -1].printed = true;
			printf("e%lu: v%lu -- v%lu\n", edges[eSize - i-1].index, edges[eSize - i - 1].v1->index, edges[eSize - i -1].v2->index);
			i++;
		}
		while(j < fSize && faces[j].firstEdge->printed && faces[j].middleEdge->printed && faces[j].lastEdge->printed){
			faces[j].index = fSize - faces[j].index - 1;
			printf("f%lu: e%lu -- e%lu -- e%lu\n", faces[j].index, faces[j].firstEdge->index, faces[j].middleEdge->index, faces[j].lastEdge->index);
			j++;
		}
	}
	return 0;
}
