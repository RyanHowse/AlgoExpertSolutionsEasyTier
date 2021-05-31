//Ryan Howse
//5/29/2021
//Finding the first non-repeating character
//Consulted the help for this question, and learned how to use
//hash tables because of it
//detailed comments for future understanding

#include <unordered_map>
using namespace std;

int firstNonRepeatingCharacter(string str) {
	//the hash table holding each character in the string,
	//and the number of times the character appears
	unordered_map<char, int> characterFrequencies;
	
	//goes through each character in the string
	for(auto character : str){
		//I believe this just initializes a count when it finds a new character
		//the program seems to work without it
		if(characterFrequencies.find(character) == characterFrequencies.end()){
			characterFrequencies[character] = 0;
		}
		//increments the count of the next character in the string
		characterFrequencies[character]++;
	}
  
	for(int idx = 0; idx < str.size(); idx++){
		char character = str[idx];
		//the first character entered into the list that
		//ended with a count of one is the first non-repeating character,
		//as the characters go into the table in order
		if(characterFrequencies[character] == 1){
			return idx;
		}
	}
	
	//if nothing is returned during the previous block
	//then there is no non-repeating character, in which
	//case the instructions are to return -1
	return -1;
}
