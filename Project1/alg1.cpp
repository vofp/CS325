/*
 * Enumeration 
 * Loop over each pair of indices i; j and compute the sum from k=i to j of a[k]. 
 * Keep the best sum you have found so far.
 */

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

int MaxSubarray(int a[], int n);

int main(int argc, char **argv){
	int input[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
	std::cout << MaxSubarray(input,10) << std::endl;
}

int MaxSubarray(int a[], int n){
	
	int i,j,k;
	int max = a[0];
	int sum;
	for(i = 0; i < n; ++i ){
		for (j = i; j < n; ++j){
			sum = 0;
			for (k = i; k <=j; ++k){
				sum += a[k];
			}
			if(max < sum){
				max = sum;
			}
		}
	}
	return max;
}
