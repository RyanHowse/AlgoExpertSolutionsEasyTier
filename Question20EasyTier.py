#Ryan Howse
#5/29/2021
#Selection Sort

def selectionSort(array):
	#this sort works by finding the lowest unsorted value
	#and moving it to the end of the sorted subset at the front of the array
	lowestIndex = 0
	for i in range(len(array)):
		#we set j to start equal to i, that way we aren't checking
		#already sorted values
		for j in range(i, len(array)):
			#find the lowest unsorted value
			if array[j] < array[lowestIndex]:
				lowestIndex = j
				
		#we should have the index of the lowest unsorted number now
		#do a simple flip
		if i is not lowestIndex:
			temp = array[i]
			array[i] = array[lowestIndex]
			array[lowestIndex] = temp
			
		#set the lowestIndex to our next starting point
		lowestIndex = i+1
		
	return array
