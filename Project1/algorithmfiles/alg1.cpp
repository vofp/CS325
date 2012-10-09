/*
 * Enumeration 
 * Loop over each pair of indices i; j and compute the sum from k=i to j of a[k]. 
 * Keep the best sum you have found so far.
 */

using namespace std;


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
