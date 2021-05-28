//Ryan Howse
//5/28/2021
//Finding the nth fibonacci number

using namespace std;

int getNthFib(int n) {
  	//let's give ourselves a return variable, which will
	//also be our running total
	int currentValue = 1;
	//the next value in the sequence
	int nextValue;
	//and a previous value
	int previousValue = 0;

	//takes care of the edge cases
	//for loop below can't account for the 0 because it'd be 0 + 0
	if(n==1) { currentValue = 0; }
	if(n==2) { currentValue = 1; }

	//adds the previous number to the current number to get the next number
	for(int i = 2; i < n; i++){
		nextValue = currentValue + previousValue;
		previousValue = currentValue;
		currentValue = nextValue;
	}
	
	return currentValue;
}
