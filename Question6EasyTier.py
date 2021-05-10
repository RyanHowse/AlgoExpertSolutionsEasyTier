#Ryan Howse
#5/9/2021
#Find the closest node value to a target value in a binary search tree

def findClosestValueInBst(tree, target):
  #we need a return variable
	closestValue = 0
	#we need a BST object that we'll initialize to the tree
	currentNode = tree
	#and we'll have an escape flag for our while loop
	keepLooking = True
	#our smallest difference
	smallestDif = 2147483647
	
	while keepLooking:
		if currentNode.value == target:
			#exact match
			closestValue = currentNode.value
			keepLooking = False
		elif currentNode.value > target:
			#we go left if we can
			if currentNode.left != None:
				#determine if the next node is further away than the current one is
				if abs(currentNode.value - target) < smallestDif:
					#assign new value if the difference is smaller and update the smallest difference
					smallestDif = abs(currentNode.value - target)
					closestValue = currentNode.value
				#go left
				currentNode = currentNode.left
			else:
        #this triggers if there's no left node
				#determine if the next node is further away than the current one is
				if abs(currentNode.value - target) < smallestDif:
					#assign new value if the difference is smaller and update the smallest difference
					smallestDif = abs(currentNode.value - target)
					closestValue = currentNode.value
				keepLooking = False
		elif currentNode.value < target:
			#we go right if we can
			if currentNode.right != None:
				#determine if the next node is further away than the current one is
				if abs(currentNode.value - target) < smallestDif:
					#assign new value if the difference is smaller and update the smallest difference
					smallestDif = abs(currentNode.value - target)
					closestValue = currentNode.value
				#go right
				currentNode = currentNode.right
			else:
				#determine if the next node is further away than the current one is
				if abs(currentNode.value - target) < smallestDif:
					#assign new value if the difference is smaller and update the smallest difference
					smallestDif = abs(currentNode.value - target)
					closestValue = currentNode.value
				keepLooking = False
	return closestValue


# This is the class of the input tree. Do not edit.
class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
