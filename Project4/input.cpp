#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "types.hpp"
using namespace std;

class City;

int readInFile(char filename[], Graph *graph){
	fstream inFile;


	inFile.open(filename, ios::in);

	if (!inFile) {
		cerr << "Can't open input file " << filename << endl;
		exit(1);
	}
	char id[100];
	int x;
	int y;
	while (!inFile.eof()) {
		inFile >> id >> x >> y;
		City city(id,x,y);
		graph->cities.push_back (city);
		//city.plot();
		//cout << *(graph->cities.back().output());

	}
}

