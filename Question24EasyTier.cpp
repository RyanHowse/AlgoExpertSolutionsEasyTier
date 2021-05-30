//Ryan Howse
//5/29/2021
//Given a data string can you make a target anagram?

using namespace std;

bool generateDocument(string characters, string document) {
  	//to do this, we're going to sort the characters of each string into 2 lists
	//then go through each character and see if the required characters for the
	//document are available in the data string
	sort(characters.begin(), characters.end());
	sort(document.begin(), document.end());
	
	//we also need a return variable
	bool isPossible = true;
	//an exit for our loop
	bool keepLooping = true;
	//and iterators for our two strings
	int itCh = 0;
	int itDo = 0;
	
	while(keepLooping){
		//iterate both indexes if we have a match
		if(characters[itCh] == document[itDo]){
			itCh++;
			itDo++;
		}
		//only iterate the character index if there's no match
		else{
			itCh++;
		}
		//if the document index is equal to the length of the document string
		//then we have accounted for all needed characters, and the document is possible
		if(itDo == document.length()){
			keepLooping = false;
		}
		//if we reach the end of the characters string first, that means that
		//the document cannot be made, as there are characters in the
		//document string unaccounted for
		else if(itCh == characters.length()){
			keepLooping = false;
			isPossible = false;
		}
	}
	
  	return isPossible;
}
