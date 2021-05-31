#Ryan Howse
#5/29/2021
#Finding the first non-repeating character
#Consulted the help for this question, and learned how to use
#hash tables because of it
#detailed comments for future understanding

def firstNonRepeatingCharacter(str):
	#the hash table holding each character in the string,
	#and the number of times the character appears
	characterFrequencies = {}
	
	#goes through each character in the string
	for character in str:
		#increments the count of the next character in the string
		characterFrequencies[character] = characterFrequencies.get(character, 0) + 1
  		
	for idx in range(len(str)):
		character = str[idx]
		#the first character entered into the list that
		#ended with a count of one is the first non-repeating character,
		#as the characters go into the table in order
		if characterFrequencies[character] == 1:
			return idx
	
	#if nothing is returned during the previous block
	#then there is no non-repeating character, in which
	#case the instructions are to return -1
	return -1
