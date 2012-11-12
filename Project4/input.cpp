#include "input.hpp"
using namespace std;

/* Loads in file, filename, and creates a city for each line.
 * Returns nothing, but changes Graph, graph.
 */
void readInFile(char filename[], Graph *graph){
	fstream inFile;
	char id[100];
	int x;
	int y;


	inFile.open(filename, ios::in);
	if (!inFile) {
		cerr << "Can't open input file " << filename << endl;
		exit(1);
	}

	while (!inFile.eof()) {
		inFile >> id >> x >> y;
		City city(id,x,y);
		graph->add(city);
		graph->size++;
	}

	/* Last city gets added twice for some reason, so removes it */
	graph->cities.pop_back();
	graph->size--;
}

