#Ryan Howse
#5/26/2021
#Finding the minimum wait time for a set of queries, 
#if given a list of their execution times

def minimumWaitingTime(queries):
    #we need a return value
	minimumWaitTime = 0
	#and a value that we previously added
	previousValue = 0
	
    #first we need to sort the vector into ascending order
	#this makes it so that we are waiting the least amount of time.
	#if a large number is at the beginning of the vector, this large number
	#is going to be carried forward for the rest of the calculations,
	#so having smaller numbers appear first gives us the lowest calculations
	queries.sort()
	
	#then we simply iterate through the vector and add each number fibonacci
	#style to a running total, which will be our return variable
	#we do not have to do the last value in the vector because no query is waiting on it
	for i in queries[:-1]:
		#add the new value plus all previous values to the running count
		minimumWaitTime = minimumWaitTime + i + previousValue
		#then update the previous value to reflect what we just added
		previousValue = previousValue + i
	return minimumWaitTime
