#Ryan Howse
#5/24/2021
#Depth-first Search of a tree using arrays
#I originally was stumped by the array structure of the tree and had to look
#at their c++ solution for help, but I've learned how to do it a bit cleaner now because of it,
#and I was able to translate it over to Python myself

class Node:
    def __init__(self, name):
        self.children = []
        self.name = name

    def addChild(self, name):
        self.children.append(Node(name))
        return self

    def depthFirstSearch(self, array):
        array.insert(len(array), self.name)
	for c in self.children:
        	c.depthFirstSearch(array)
	return array
