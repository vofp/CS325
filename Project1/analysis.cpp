#define NUM_TRIAL 10

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;

int MaxSubarray(int a[], int n);
void algName(char s[]);

int main(int argc, char **argv){
	
	double elapTime;
	clock_t beginT, endT;
	srand ( time(NULL) );

	int *input = new int[9000];
	int sizes[] = {100,200,300,400,500,600,700,800,900,1000,2000,3000,4000,5000,6000,7000,8000,9000};
	double times[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
	int n = 0;
	int i;
	int t;
	ofstream myfile;
	for(t = 0; t < NUM_TRIAL; ++t){
		n = 0;
		for(i = 0; i < 18; ++i){
			for (; n < sizes[i]; ++n){
				input[n] = rand() % 198 - 99;
			}
			
			beginT = clock();
			MaxSubarray(input, n);
			endT = clock();
			elapTime = ((double) (endT-beginT))/CLOCKS_PER_SEC;
			cout << n << ": " << elapTime << endl;
			myfile.open("timing",fstream::app);
			myfile << n << ", " << elapTime << endl;
			myfile.close();
			//times[i] = times[i] + elapTime;
		}
	}
}

