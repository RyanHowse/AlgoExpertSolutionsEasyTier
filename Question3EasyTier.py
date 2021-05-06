#Ryan Howse
#5/6/2021
#Take in an array of values and return an array
#of equal length with the values squared, in ascending order

def sortedSquaredArray(array):
    #first we need a return array
	returnArray = []
	#and an array counter
	arrayCounter = 1
	
	#we need a current value to add to the array
	currentValueToAdd = 0
	
	#maximum and minimum values that we've seen
	#having these will avoid unnecessary looping for negative numbers
	minValue = 0
	maxValue = 0
	
	#counter and variable to handle negative values (see below)
	placeValue = False
	placeValueCounter = 0
	
	#handle the first case to set initial values
	currentValueToAdd = array[0]*array[0]
	minValue = currentValueToAdd
	maxValue = currentValueToAdd
	returnArray.insert(0, currentValueToAdd)
	
	#next we loop through the data array
	#note for me, 1: skips the first element since we did that already
	for i in array[1:]:
		currentValueToAdd = array[arrayCounter]*array[arrayCounter]
		arrayCounter = arrayCounter + 1
		if currentValueToAdd <= minValue:
			returnArray.insert(0, currentValueToAdd)
		elif currentValueToAdd >= maxValue:
			returnArray.insert(len(returnArray), currentValueToAdd)
		else:
			placeValue = True
			placeValueCounter = 0
			
		#this will most likely trigger when there are negative values in the data array, as squaring those values
		#will make them positive, but they are on the low end of the data array
		#having this while loop handles the negative values without having to sort the entire array afterwards which may
		#not be neccessary if there are no negative vales
		while placeValue:
			if currentValueToAdd >= returnArray[placeValueCounter]:
				placeValueCounter = placeValueCounter + 1
			else:
				placeValue = False
				returnArray.insert(placeValueCounter, currentValueToAdd)
		
		#update our min and max values
		minValue = returnArray[0]
		maxValue = returnArray[len(returnArray)-1]
		
  return returnArray
