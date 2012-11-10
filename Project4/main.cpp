#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "types.hpp"
using namespace std;

int readInFile(char filename[], Graph *g);
int printOutput(char filename[], Graph *graph);
int printPlot(char filename[], Graph *graph);
int printPlotPath(char filename[], Graph *graph);


int tsp(Graph *graph);

int main(int argc, char **argv){
	Graph *g = new Graph();
	cout << "reading" <<endl;
	readInFile(argv[1], g);
	cout << "tsp" <<endl;
	tsp(g);
	cout << "printing" <<endl;
	//printPlotPath(argv[2],g);
}

