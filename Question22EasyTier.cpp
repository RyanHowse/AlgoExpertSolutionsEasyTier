//Ryan Howse
//5/29/2021
//Making a Caesar cipher
//all letters of the string are shifted by the key passed

using namespace std;

string caesarCypherEncryptor(string str, int key) {
  //create a character array and send the data string to it
  char stringChars[str.length()+1];
	strcpy(stringChars, str.c_str());
	
	//now we just take each character and shift it over to the
	//correct character using the ascii codes
	for(int i = 0; i < str.length(); i++){
		//checks if the characters need to wrap around
		//if they do we need the modulus of the key, minus the number
		//of characters it took to reach the wrap around point,
		//and 26, the number of letters in the alphabet
		if((stringChars[i] + key) > 122){
			//example: if the character was an x, the difference is 2
			//because it's 2 letters from the end
			int diff = 122 - stringChars[i];
			//example: character is x, key is 30
			//difference is 2, so we need (30-2) % 26
			//this gives us 28 % 26, which is 2
			//we add 2 to 96, which is the code before a, and we get c
			// x shifted 30 is c
			stringChars[i] = 96 + ((key-diff)%26);
		}
		else{
			stringChars[i] += key;
		}
		cout << stringChars[i];
	}
	
  return stringChars;
}
