#Ryan Howse
#5/28/2021
#BubbleSort

def bubbleSort(array):
    	#lets do a bubble sort
	#the basic idea is that the bigger numbers
	#slowly float to the top
	#it does work
	#but its O(n^2)
	#so don't use it
	for i in range(len(array)-1):
		for j in range(len(array)-1):
			if array[j+1] < array[j]:
				temp = array[j]
				array[j] = array[j+1]
				array[j+1] = temp
	return array
