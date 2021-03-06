#pragma once
#include <vector>
#include <iostream>
#include <math.h>
#include <limits.h>
#include "types.hpp"
#include "optimize.hpp"
#include "common.hpp"

void tsp(Graph *graph);
int setupChecklist(vector<City *> *path, vector<int> *length, vector<City *> *checkList, int addedPath);
void hull(Graph *graph, vector<City *> *x, vector<City *> *y, vector<City *> *path);
void addAfter(City *c1, City *c2);
int greaterX(City *c1, City *c2);
int greaterY(City *c1, City *c2);
int greaterD(City *c1, City *c2);
void addToPath(Graph *graph, vector<City *> *path);
void sort(Graph *graph, vector<City *> *x, vector<City *> *y);
void sortD(Graph *graph, vector<City *> *x, vector<City *> *y, vector<City *> *checkList);
int shortestPath(vector<City *> *path, vector<int> *length, vector<City *> *checkList, int addedPath, int i);
