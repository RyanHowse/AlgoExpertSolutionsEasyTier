#Ryan Howse
#5/5/2021
#Determine if two values within a given array equal a target sum

def twoNumberSum(array, targetSum):
  #we need a return array so we don't have 2 return statements
	returnArray = []
	
	#we'll have an escape variable so we can stop checking if we hit
	checkValues = True
	
	#indexes
	indexToCompareAgainst = 0
	iterateIndex = 1
	
	#can't compare to istelf, so any array of less than length 2 is auto DQ
	if len(array) > 1:
		while checkValues:
			#check if we have a hit within the bounds of the array
			if (indexToCompareAgainst + iterateIndex) < len(array):
				if array[indexToCompareAgainst] + array[indexToCompareAgainst + iterateIndex] == targetSum:
					returnArray.append(array[indexToCompareAgainst])
					returnArray.append(array[indexToCompareAgainst + iterateIndex])
					checkValues = False
				else:
					#only iterate the iteration value if there's still room in the array to move forward
					iterateIndex = iterateIndex + 1
			else:
				if indexToCompareAgainst < len(array)-1:
					#shift our compare value foward if we have reached the end, but there is room for another pass
					indexToCompareAgainst = indexToCompareAgainst + 1
					iterateIndex = 1
				else:
					#we have reached the end of the array with no hit, we will return the empty array
					checkValues = False
					
	return returnArray
