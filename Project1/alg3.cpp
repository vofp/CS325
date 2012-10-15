/*
 * Divide and Conquer
 * If we split the array into two halves, we know that the maximum subarray will either be
 *      * contained entirely in the frst half,
 *      * contained entirely in the second half, or
 *      * made of a suffix of the frst half of maximum sum and a prefix of the second half of maximum sum
 * The frst two cases can be found recursively. The last case can be found in linear time.
 */

#define ALL     0
#define LEFT    1
#define RIGHT   2
#define OVERALL 3

using namespace std;

void MaxSubarray_h(int array[], int size, int sums[]){
	// Base case.
	if(size <= 1){
		sums[ALL]     = array[0];   // Sum of entire array
		sums[LEFT]    = array[0];   // Largest sum from left end of array
		sums[RIGHT]   = array[0];   // Largest sum from right end of array
		sums[OVERALL] = array[0];   // Largest sum found so far
		return;
	}
	int i = size/2;   // Index of middle element

	// Recurse.
	int *left  = new int[4];
	int *right = new int[4];
	MaxSubarray_h(array,i, left);
	MaxSubarray_h(array+i, size-i, right);

	// Calculate various possible maximum sums.
	int a = left[ALL]   + right[ALL];    // Sum of everything
	int l = left[ALL]   + right[LEFT];   // Possible max sum from the left
	int r = left[RIGHT] + right[ALL];    // Possible max sum from the right
	int m = left[RIGHT] + right[LEFT];   // Possible max sum straddling both branches

	// Check for and find new maximums.
	l = l > left[LEFT] ? l : left[LEFT];   // Is the new left sum larger?
	r = r > right[RIGHT] ? r : right[RIGHT];   // Is the new right sum larger?
	int overall = left[OVERALL] > right[OVERALL] ? left[OVERALL] : right[OVERALL];
	overall = overall > m ? overall : m;

	// Final answers!
	sums[0] = a;
	sums[1] = l;
	sums[2] = r;
	sums[3] = overall;
}


int MaxSubarray(int a[], int n){
	int *p = new int[4];
	MaxSubarray_h(a,n,p);
	int s1 = p[0] > p[1] ? p[0] : p[1];
	int s2 = p[2] > p[3] ? p[2] : p[3];
	s1 = s1 > s2 ? s1 : s2;
	return s1;
}
