/*
 * Better Enumeration 
 * Notice that in the previous algorithm, the same sum is computed many times.
 * In particular, notice that sum from k=i to j of a[k] can be computed from sum from k=i to j - 1 of a[k] in O(1) time, rather than starting from scratch.
 * Write a new version of the frst algorithm that takes advantage of this observation.
 */

using namespace std;


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