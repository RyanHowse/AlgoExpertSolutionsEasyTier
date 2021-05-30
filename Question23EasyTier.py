#Ryan Howse
#5/29/2021
#Run-Length Encoding (lossless data compression)
#Example: AAAAAABBBBCCCCCCCCDD = 6A4B8C2D
#runs of 10 or more must be broken up into single digit runs
#due to the fact that numbers can also be withing the data string

def runLengthEncoding(string):
  	#Let's have a return variable
	returnString = ""
	#and a counter
	consecutiveCharacters = 1
	
	#for every character, check if the next one is the same character
	#if it is, increment the counter, and handle if we've reached 10 yet
	#if so, add "9" and the character to the string and reset the counter to keep going
	for i in range(len(string)-1):
		if string[i] == string[i+1]:
			consecutiveCharacters = consecutiveCharacters + 1
			if consecutiveCharacters == 10:
				returnString = returnString + str(consecutiveCharacters-1) +string[i]
				consecutiveCharacters = 1
		
		#if the next character is not the same, add the counter and the character to the string
		else:
			returnString = returnString + str(consecutiveCharacters) +string[i]
			consecutiveCharacters = 1
	
	#handle the last case since we can only do up to the second last in
	#python without going out of bounds
	returnString = returnString + str(consecutiveCharacters) +string[len(string)-1]
			
	return returnString
