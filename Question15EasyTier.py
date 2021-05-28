#Ryan Howse
#5/28/2021
#finding the sum of an array, given that nested lists are multiplied
#by thier depth
#ex: list = [5 ,2,[7, -1], 3, [6, [-13, 8], 4]]
#12, calculated as 5 + 2 + (2 * (7 - 1)) + 3 + (2*(6 + (3*(-13 + 8) + 4)))

# Tip: You can use the type(element) function to check whether an item
# is a list or an integer.
def productSum(array):
    #we need a return total, and a way to mark what depth we're at
	sumTotal = 0
	currentDepth = 1
	for i in array:
		#check to see if the current list index is an integer or a nested list
		if type(i) == int:
			#if it's an integer, we just add it to the total
			sumTotal = sumTotal + i
		else:
			#if it's a list, we send it off to the recursive function
			sumTotal = sumTotal + productSumRecursive(i, currentDepth) * currentDepth
	#the program eventually ends here, after all the recursion has resolved
	return sumTotal

def productSumRecursive(array, depth):
	#add 1 to the depth
	#we do it in the recursive function so that when one layer of recursion
	#completes, the previous layer still has it's correct depth
	depth = depth + 1
	sumTotal = 0
	for i in array:
		if type(i) == int:
			#if it's an integer, we just add it to the total
			sumTotal = sumTotal + (i*depth)
		else:
			#here we do the same, passing nested arrays to the function again, with a deeper depth
			#the sumTotal is accrued by the sum of the nested array, multiplied by the correct depth
			sumTotal = sumTotal + productSumRecursive(i, depth) * depth
	return sumTotal
