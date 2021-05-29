#Ryan Howse
#5/28/2021
#find the 3 largest numbers in a given data array

def findThreeLargestNumbers(array):
    #let's make an array to hold our highest values
	#the initial values are very low numbers since
	#python is too cool for things like integer limits apparently
	highestValues = [-999999999999, -999999999999, -999999999999]
	#for every value in the data array, we check against the 
	#three values currently stored
	#we float the lesser values foward, which keeps them in order as we go through
	#and helps us make sure we're keeping the right values. Simply replacing
	#lesser values with greater ones would lead to us dumping a value greater
	#than one of the lesser values within the return vector
	for i in array:
		if i >= highestValues[0]:
			highestValues[2] = highestValues[1]
			highestValues[1] = highestValues[0]
			highestValues[0] = i
		elif i >= highestValues[1]:
			highestValues[2] = highestValues[1]
			highestValues[1] = i
		elif i > highestValues[2]:
			highestValues[2] = i
	
	#sort to ascending for requirements purposes
	highestValues.sort()
	return highestValues
