/*
 * Divide and Conquer
 * If we split the array into two halves, we know that the maximum subarray will either be
 *      * contained entirely in the frst half,
 *      * contained entirely in the second half, or
 *      * made of a suffix of the frst half of maximum sum and a prefix of the second half of maximum sum
 * The frst two cases can be found recursively. The last case can be found in linear time.
 */
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;

void MaxSubarray_h(int a[], int n, int b[]){
	if(n <= 1){
		b[0] = a[0];
		b[1] = a[0];
		b[2] = a[0];
		b[3] = a[0];
		return;
	}
	int i = n/2;
	int *left = new int[4];
	MaxSubarray_h(a,i,left);
	int *right = new int[4];
	MaxSubarray_h(a+i,n-i,right);

	int sum = left[0] + right[0];
	int l = left[0]+right[1];
	int r = left[2]+right[0];
	int mid = left[2]+right[1];

	l = l > left[1] ? l : left[1];
	r = r > right[2] ? r : right[2];
	int m = left[3] > right[3] ? left[3] : right[3];
	m = m > mid ? m : mid;

	b[0] = sum;
	b[1] = l;
	b[2] = r;
	b[3] = m;
}


int MaxSubarray(int a[], int n){
	int *p = new int[4];
	MaxSubarray_h(a,n,p);
	int s1 = p[0] > p[1] ? p[0] : p[1];
	int s2 = p[2] > p[3] ? p[2] : p[3];
	s1 = s1 > s2 ? s1 : s2;
	return s1;
}
