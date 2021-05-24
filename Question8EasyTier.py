#Ryan Howse
#5/24/2021
#Finding the sum of each node depth in a BST

#we need a global total that can be accessed by all functions
depthSum = 0

# This is the class of the input root. Do not edit it.
class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def nodeDepths(root):
    #because the sumList is global, it's important to reset it before each test case
    global depthSum
    depthSum = 0
    #we pass the function -1 because it's going to add 1 at the root
    #which will snowball down the line
    DepthSum(root, -1)
    return depthSum

def DepthSum(node, runningTotal):
    global depthSum
    #if the current node is null then we've gone outside of the tree
    #this means we exit so that the most recent node can check
    #to see if there is a right-hand node to travel to
    if node == None:
        return

    #add to the running total
    #because of the recursion and the fact that no variables are overwritten, 
    #we can essenitally save instances of the branch sum at each node
    runningTotal = runningTotal + 1

    #recur on left child
    DepthSum(node.left, runningTotal)

    #add the current node's depth to the global total
    depthSum = depthSum + runningTotal

    #recur on right child
    #this happens immediately after a left node returns due to None (see above)
    DepthSum(node.right, runningTotal)
