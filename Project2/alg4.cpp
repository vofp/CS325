/*
 * Enumeration 
 * Loop over each pair of indices i; j and compute the sum from k=i to j of a[k]. 
 * Keep the best sum you have found so far.
 */

using namespace std;


int MaxSubarray(int a[], int n){
	int current = 0;
	int max = 0;
	int i;
	for(i = 0;i < n; i++){
		current += a[i];
		if(current <= 0){
			current = 0;
		}else if(current > max){
			max = current;
		}
	}
	return max;
}
