#Ryan Howse
#5/24/2021
#Finding the sum of each branch in a BST

#we need a global list that can be accessed by all functions
sumList = []

# This is the class of the input root. Do not edit it.
class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def branchSums(root):
  #because the sumList is global, it's important to reset it before each test case
	global sumList
	sumList = []
	ArmSums(root, 0)
	return sumList

def ArmSums(node, runningTotal):
	#if the current node is null then we've gone outside of the tree
	#this means we exit so that the most recent node can check
	#to see if there is a right-hand node to travel to
    if node == None:
		return
    
	#add to the running total
	#because of the recursion and the fact that no variables are overwritten, 
	#we can essenitally save instances of the branch sum at each node
	runningTotal = runningTotal + node.value
	
	#recur on left child
  ArmSums(node.left, runningTotal)
    
	#if there is no node to the left or right then you have reached the end
	#of a branch, and should add the running total to the list
	if node.left == None and node.right == None:
		sumList.insert(len(sumList), runningTotal)
		
  #recur on right child
	#this happens immediately after a left node returns due to NULL (see above)
  ArmSums(node.right, runningTotal)
