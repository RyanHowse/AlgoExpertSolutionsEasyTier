//Ryan Howse
//5/29/2021
//Checking to see if a given string is a palindrome

using namespace std;
#include <math.h>

bool isPalindrome(string str) {
	//lets have a return value
	bool isPalindrome = true;
	
	//create a character array and send the data string to it
  	char stringChars[str.length()+1];
	strcpy(stringChars, str.c_str());
	
	//checks if the first and last character is the same
	//every iteration the characters to check moves forward on
	//one end and backwards on the other
	//example: first check: index first and index last
	//				 second check: index first + 1 and index last -1
	//goes until the checks reach the middle
	for(int i = 0; i < strlen(stringChars)/2; i++){
		if(stringChars[i] != stringChars[strlen(stringChars)-1-i]){
			isPalindrome = false;
		}
	}
	
	return isPalindrome;
}
