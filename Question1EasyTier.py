#Ryan Howse
#5/5/2021
#Determine if a sequence exists within a givin array

def isValidSubsequence(array, sequence):
	#we need a placeholder index in the sequence array
	nextSequenceIndex = 0
	#we need a variable to hold the value we are looking for next 
  nextNumberToFind = sequence[nextSequenceIndex]
	#we need a result variable, starts as false and will be true if tests pass
	sequenceIsValid = False
	
	#check every number in the data array
	for i in array:
		if nextNumberToFind == i:
			#this triggers if there is another number left to be looked for
			if nextSequenceIndex < len(sequence)-1 :
				nextSequenceIndex = nextSequenceIndex + 1
				nextNumberToFind = sequence[nextSequenceIndex]
			else :
				#this triggers if all values in the sequence array have appeared
				#in the data array, in order
				sequenceIsValid = True
				
  return sequenceIsValid
