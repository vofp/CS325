#include "main.hpp"
#include <pthread.h>
using namespace std;


#define THREADS 1


int number_of_threads = THREADS;
//pthread_mutex_t next_number_mutex;
//pthread_mutex_t graph_mutex;
Graph *g = new Graph();
int number;
char *output;

int main(int argc, char **argv){
	output = argv[2];
	void (*prev_fn)(int);
	prev_fn = signal (SIGTERM,terminate);
    if (prev_fn==SIG_IGN) signal (SIGTERM,SIG_IGN);
	
	number = -1;

	double elapTime;
	clock_t beginT, endT;

	beginT = clock();

	cout << "reading" <<endl;
	readInFile(argv[1], g);
	cout << "tsp" <<endl;
	tsp(g);
		
	cout << pathLength(g->path,g->length) << endl;

	printPlot("outputPlot1.txt",g);
	cout << "optimizing" << endl;	
	/* Non-threaded */
	int i;
	for(i = 0; i < g->size; i++){
		optimize(g->path, g->length, i);
	}
	printPlot("outputPlot2.txt",g);
	bool done = false;
	int p = pathLength(g->path,g->length);
	while(!done){	
		for(i = 0; i < 15; i++){
			//cout << i << endl;
			//optimize(g->path, g->length, i);
			optimize2(g->path, g->length, i);
		}
		int p2 = pathLength(g->path,g->length);
		if(p == p2){
			done = true;
		}
		p = p2;
	}
	done = false;
	while(!done){	
		for(i = 0; i < g->size; i++){
			//cout << i << endl;
			//optimize(g->path, g->length, i);
			optimize2(g->path, g->length, i);
		}
		int p2 = pathLength(g->path,g->length);
		if(p == p2){
			done = true;
		}
		p = p2;
	}



	cout << pathLength(g->path,g->length) << endl;
	


	cout << "printing" <<endl;
	//printPlot(argv[2],g);
	printOutput(argv[2],g);

	endT = clock();
	elapTime = ((double)(endT - beginT))/CLOCKS_PER_SEC/number_of_threads;
	cout << number_of_threads << ", " << elapTime << endl;
	cout << "finished" << endl;
}


int next_number(){
	number++;
	return number;
}


void terminate (int param){
	printOutput(output,g);
	printPlot("outputPlot.txt",g);
	printf ("Terminating program...\n");
	exit(1);
}
