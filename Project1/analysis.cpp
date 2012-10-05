#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <time.h>
using namespace std;

int MaxSubarray(int a[], int n);
double diffclock(clock_t clock1,clock_t clock2);

int main(int argc, char **argv){
	
	srand ( time(NULL) );

	int input[] = new int[9000];
	int sizes[] = {100,200,300,400,500,600,700,800,900,1000,2000,3000,4000,5000,6000,7000,8000,900}
	int n = 0;
	int i;
	for(i = 0; i < n; ++i){
		for (; n < sizes[i]; ++n){
			input[n] = rand() % 198 - 99;
		}

	}
}

double diffclock(clock_t clock1,clock_t clock2){
	double diffticks=clock1-clock2;
	double diffms=(diffticks*10)/CLOCKS_PER_SEC;
	return diffms;
}