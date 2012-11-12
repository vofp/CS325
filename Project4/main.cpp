#include "main.hpp"
using namespace std;

int main(int argc, char **argv){
	Graph *g = new Graph();
	cout << "reading" <<endl;
	readInFile(argv[1], g);
	cout << "tsp" <<endl;
	tsp(g);
	cout << "printing" <<endl;
	//printPlotPath(argv[2],g);
}

