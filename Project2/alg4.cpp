/*
 * Enumeration 
 * Loop over each pair of indices i; j and compute the sum from k=i to j of a[k]. 
 * Keep the best sum you have found so far.
 */

int MaxSubarray(int array[], int size){
	int current = 0;
	int max = 0;
	int i;

	for (i=0; i<size; i++) {
		current += array[i];
		if (current <= 0) {
			current = 0;
		} else if (current > max) {
			max = current;
		}
	}

	return max;
}

