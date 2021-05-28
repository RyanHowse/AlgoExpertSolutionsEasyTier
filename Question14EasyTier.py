#Ryan Howse
#5/28/2021
#Finding the nth fibonacci number

def getNthFib(n):
  	#let's give ourselves a return variable, which will
	#also be our running total
	currentValue = 1
	#the next value in the sequence
	nextValue = 0
	#and a previous value
	previousValue = 0
	
	#takes care of the edge cases
	#for loop below can't account for the 0 because it'd be 0 + 0
	if n==1: currentValue = 0
	if n==2: currentValue = 1
	
	#adds the previous number to the current number to get the next number
	for i in range(n-2):
		nextValue = currentValue + previousValue
		previousValue = currentValue
		currentValue = nextValue
	
	return currentValue;
