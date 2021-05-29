#Ryan Howse
#5/28/2021
#Finding the index of a target number within a vector, using binary search
#I got close on this one but had to consult the help, comments for future understanding
#I think part of my problem was trying to do it with one return statement,
#because even their solution doesn't seem to work if I change it up to have one return 

def binarySearch(array, target):
    #the first thing we pass the recursive function is the whole array, the target value,
	#and for our initial range we just give it the whole scope of the array
	return binarySearchRecursive(array, target, 0, len(array)-1);

#declare our recursive function
#it takes the array, the target value we're looking for, and a right and left bounds
#that we'll use to calculate our new middle point in each recursion
def binarySearchRecursive(array, target, left, right):
	#if the value we've given as left exceeds the right value, then the
	#target value does not exist within the data array, so we return -1 which
	#is the expected value for that scenario
	if left > right:
		return -1
	
	#to find the middle point we just average the beginning and end that we've set
	middle = round((left + right)/2)
	#check to see if the target value is at the middle index we've found
	checkMatch = array[middle]
	#if the target is at the "middle" index, we've found the target, and
	#can return the "middle" index as the answer
	if checkMatch == target:
		return middle
	
	#if the target value is less than the middle index value,
	#we need to recurse using the current left value, and the middle
	#index -1
	#example: for the initial case the left value would be 0 and middle -1 would
	#be half the full array - 1
	elif target < checkMatch:
		return binarySearchRecursive(array, target, left, middle -1)
	
	#if the target value is greater than the middle index value,
	#we need to recurse using the middle index + 1 as our lower limit
	#this time, and the previous right value as our upper limit
	else:
		return binarySearchRecursive(array, target, middle + 1, right)
