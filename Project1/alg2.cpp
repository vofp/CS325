/*
 * Better Enumeration 
 * Notice that in the previous algorithm, the same sum is computed many times.
 * In particular, notice that sum from k=i to j of a[k] can be computed from sum from k=i to j - 1 of a[k] in O(1) time, rather than starting from scratch.
 * Write a new version of the frst algorithm that takes advantage of this observation.
 */

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;

int MaxSubarray(int a[], int n);
int runTestFile();

int main(int argc, char **argv){
	int input[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
	cout << MaxSubarray(input,10) << endl;
	runTestFile();
}

int runTestFile(){
	int *numbers = new int[100];
	int answer;
	int n = 0;
	ifstream file ("mstest.txt", ios::in);
	if (file.is_open()){
		char * c = new char;
		file.seekg (0, ios::beg);
		file.read (c, 1);
		while(*c=='['){
			char *s = new char[5];
			int i = 0;
			int answer;
			int n = 0;
			do{
				file.read (c, 1);
				if(*c == ','){
					//cout << atoi(s) << endl;
					numbers[n] = atoi(s);
					n++;
					i = 0;
					memset(s,0,5);
				}else{
					s[i] += c[0];
					i++;
				}
			}while(*c != ']');
			file.read (c, 1);
			i = 0;
			memset(s,0,5);
			do{
				file.read (c, 1);
				if(*c != '['){
					s[i] += c[0];
					i++;
				}
			}while(*c != '[' && file.good() );
			cout << MaxSubarray(numbers,n) << " " << atoi(s) << endl;
			answer = atoi(s);
			i = 0;
			memset(s,0,5);
		}

		file.close();
	}else{
		cout << "you suck" << endl;
	}
}

int MaxSubarray(int a[], int n){
	
	int i,j,k;
	int max = a[0];
	int sum;
	for(i = 0; i < n; ++i ){
		sum = 0;
		for (j = i; j < n; ++j){
			sum += a[j];
			if(max < sum){
				max = sum;
			}
		}
	}
	return max;
}