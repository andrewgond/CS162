int ways_to_top(int n) {
	// YOUR CODE GOES HERE
	//Base Cases:
	if (n == 0) return 1;
	else if (n == 1) return 1;
	else if (n == 2) return 2;

	//Recursive case:
	else return (ways_to_top(n-1) + ways_to_top(n-2) + ways_to_top(n-3));
	
}
