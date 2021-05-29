//Ryan Howse
//5/29/2021
//Run-Length Encoding (lossless data compression)
//Example: AAAAAABBBBCCCCCCCCDD = 6A4B8C2D
//runs of 10 or more must be broken up into single digit runs
//due to the fact that numbers can also be withing the data string

using namespace std;

string runLengthEncoding(string str) {
  	//Let's have a return variable
	string returnString = "";
	//and a counter
	int consecutiveCharacters = 1;
	
	//for every character, check if the next one is the same character
	//if it is, increment the counter, and handle if we've reached 10 yet
	//if so, add "9" and the character to the string and reset the counter to keep going
	for(int i = 0; i < str.length(); i++){
		if(str[i]==str[i+1]){
			cout << str[i];
			cout << "";
			consecutiveCharacters++;
			if(consecutiveCharacters == 10){
				returnString += to_string(consecutiveCharacters-1)+str[i];
				consecutiveCharacters = 1;
			}
		}
		//if the next character is not the same, add the counter and the character to the string
		else{
			cout << str[i];
			cout << "";
			returnString += to_string(consecutiveCharacters)+str[i];
			consecutiveCharacters = 1;
		}
	}
  	return returnString;
}
