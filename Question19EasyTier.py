#Ryan Howse
#5/29/2021
#Insertion Sort

#this sort puts each element in the list in it's proper place as it goes
def insertionSort(array):
	for i in range(len(array)):
		#we start at the current index and work backwards to check if the value
		#at the current index is is the right place
		for j in range(i , 0, -1):
			if j > 0:
				if array[j] < array[j-1]:
					#do a simple flip
					temp = array[j]
					array[j] = array[j-1]
					array[j-1] = temp
	return array
