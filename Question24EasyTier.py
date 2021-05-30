#Ryan Howse
#5/29/2021
#Given a data string can you make a target anagram?

def generateDocument(characters, document):
  	#to do this, we're going to sort the characters of each string into 2 lists
	#then go through each character and see if the required characters for the
	#document are available in the data string
	characters = sorted(characters)
	document = sorted(document)
	
	#we also need a return variable
	isPossible = True
	#an exit for our loop
	keepLooping = True
	#and iterators for our two strings
	itCh = 0
	itDo = 0
	
	#don't bother if there's no target
	if len(document)==0:
		keepLooping = False
	
	while keepLooping:
		#iterate both indexes if we have a match
		if characters[itCh] == document[itDo]:
			itCh = itCh + 1
			itDo = itDo + 1
		#only iterate the character index if there's no match
		else:
			itCh = itCh + 1
		#if the document index is equal to the length of the document string
		#then we have accounted for all needed characters, and the document is possible
		if itDo == len(document):
			keepLooping = False

		#if we reach the end of the characters string first, that means that
		#the document cannot be made, as there are characters in the
		#document string unaccounted for
		elif itCh == len(characters):
			keepLooping = False
			isPossible = False
			
	return isPossible
