#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "types.hpp"
using namespace std;

class City;

int readInFile(char filename[]){
	fstream inFile;
	ofstream outFile;
	//char outputFilename[] = "out.list";


	inFile.open(filename, ios::in);

	if (!inFile) {
		cerr << "Can't open input file " << filename << endl;
		exit(1);
	}
/*
	outFile.open(outputFilename, ios::out);

	if (!outFile) {
		cerr << "Can't open output file " << outputFilename << endl;
		exit(1);
	}
*/
	char id[100];
	int x;
	int y;
	while (!inFile.eof()) {
		inFile >> id >> x >> y;
		City city(id,x,y);
		city.plot();
	}
}

