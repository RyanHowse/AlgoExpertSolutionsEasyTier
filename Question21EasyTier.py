#Ryan Howse
#5/29/2021
#Checking to see if a given string is a palindrome

def isPalindrome(str):
	#lets have a return value
	isPalindrome = True
	
	#turn the data string into a list
	list(str)
	
	#checks if the first and last character is the same
	#every iteration the characters to check moves forward on
	#one end and backwards on the other
	#example: first check: index first and index last
	#				 second check: index first + 1 and index last -1
	#goes until the checks reach the middle
	for i in range(len(str)):
		if str[i] is not str[len(str)-1-i]:
			isPalindrome = False
			
	return isPalindrome
