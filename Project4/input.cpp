#include "input.hpp"
using namespace std;

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
		graph->add(city);
		graph->size++;
		//graph->cities.back().next = &(graph->cities.back());
		//graph->cities.back().prev = &(graph->cities.back());
		//graph->cities.push_back (city);
		//city.plot();
		//cout << *(graph->cities.back().output());

	}
	graph->cities.pop_back();
	graph->size--;
}

