#Ryan Howse
#5/28/2021
#Remove duplicates from a linked list

# This is an input class. Do not edit.
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def removeDuplicatesFromLinkedList(linkedList):
  keepSearching = True
	#we need something pointing to the root of the list, because we're
	#going to be iterating through the list, which pushes the pointer forward
	root = linkedList
	
	while keepSearching:
		#only try to compare if there is a node to compare against
		if linkedList.next is not None:
			if linkedList.value == linkedList.next.value:
				#if there are at least 2 nodes ahead of the current one...
				if linkedList.next.next is not None:
					#...the next node becomes the node 2 nodes ahead, dropping the duplicate node
					linkedList.next = linkedList.next.next
				else:
					#if there's no extra node to replace the duplicate with, we just erase it
					linkedList.next = None
					keepSearching = False
			else:
				#this iterates through the list if there is no duplicate
				#at the next node
				linkedList = linkedList.next
		#if the next node is null then we are done!
		else:
			keepSearching = False
	#return the root of the list, which now has no duplicates
	return root
