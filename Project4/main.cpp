#include "main.hpp"
#include <pthread.h>
using namespace std;

#define THREADS 1

int number_of_threads = THREADS;
//pthread_mutex_t next_number_mutex;
//pthread_mutex_t graph_mutex;
Graph *g = new Graph();
int number;


int main(int argc, char **argv){
	
	number = -1;

	double elapTime;
	clock_t beginT, endT;

	beginT = clock();

	cout << "reading" <<endl;
	readInFile(argv[1], g);
	cout << "tsp" <<endl;
	tsp(g);
		
	cout << pathLength(g->path,g->length) << endl;

	cout << "optimizing" << endl;	
	/* Non-threaded */
	int i;
	for(i = 0; i < g->size; i++){
		optimize(g->path, g->length, i);
	}

	cout << pathLength(g->path,g->length) << endl;
	


	cout << "printing" <<endl;
	printOutput(argv[2],g);

	endT = clock();
	elapTime = ((double)(endT - beginT))/CLOCKS_PER_SEC/number_of_threads;
	cout << number_of_threads << ", " << elapTime << endl;
}


int next_number(){
	number++;
	return number;
}


