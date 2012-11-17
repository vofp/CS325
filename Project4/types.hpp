#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;

/* City holds data about each point on graph
 */
class City {
public:
	/* Starting values loaded from file */
	std::string id;
	int x;
	int y;

	int d;        /* distance from center */
	int pathAdd;  /* minimum units added to add this point to path */
	int idx;      /* index of where to add point in path */
	bool onPath;  /* quick way to find out if point is on path*/
	bool onCheck; /* quick way to find out of point is on checkList*/

	/* Functions */
	City(char *id_new, int x_new, int y_new); /* init */
	string *output(); /* string for grading */
	string *plot();   /* string for ploting */
};

/* Graph holds data on cities 
 */
class Graph {
public:
	std::vector<City> cities; /* holds all cities or points */
	unsigned int path_size;   /* holds current path size */
	int size;                 /* number of cities */
	vector<City *> *path;
	vector<int> *length;
	
	/* Functions */
	Graph(); /* init */
	void add(City c); /* adds a city */
};

