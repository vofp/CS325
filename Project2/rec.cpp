struct maxS {
	int current;   // Current sum
	int max;       // Overall max
}

struct maxS MaxSubarray(int array[], int size) {
	struct maxS ms;

	if (size == 1) {   // Base case
		ms.current = 0;
		ms.max = array[0];
	} else {   // Recurse on array excluding last element.
		ms = MaxSubarray(array, size-1);
	}

	// Find maximum.
	ms.current += array[size-1];
	ms.current = (ms.current > 0) ? ms.current : 0;
	ms.max = (ms.current > ms.max) ? ms.current : ms.max;

	return ms;
}

