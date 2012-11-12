#include <iostream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;

class City {
public:
	std::string id;
	int x;
	int y;
	int d;
	bool onPath;
	bool onCheck;
	City *next;
	City *prev;
	City(char *id_new, int x_new, int y_new);
	string *output();
	string *plot();
	int pathAdd;
	int idx;
};

class Graph {
public:
  std::vector<City> cities;
  unsigned int path_size;
	int size;
	Graph();
	void add(City c);
};

