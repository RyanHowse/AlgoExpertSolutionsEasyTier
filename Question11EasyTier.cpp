//Ryan Howse
//5/26/2021
//Can a class take a photo if everyone wearing one coloured shirt is in the back,
//everyone wearing another is in the front, and everyone in the back must be
//taller than the person in front of them?

#include <vector>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  //First we need a return variable, in this case a boolean
	//to determine if a photo with the current class makeup is possible
	//under the given rules
	//it will become false if conditions are not met
	bool isPossible = true;
	//and a flag to check the alternate case if needed
	bool checkOtherCase = false;
	
	//first lets sort both vectors in ascending order
	//if the students of both rows in height order do not satisfy the
	//conditions, then theres is no arrangement of students that will work
	sort(redShirtHeights.begin(), redShirtHeights.end());
	sort(blueShirtHeights.begin(), blueShirtHeights.end());
	
	//now we'll iterate through each array and see if the person in
	//index i is taller than the person in index i of the other array
	//if one is false then we flip the arrays to see if it works to have the
	//people in the back row stand in the front row instead
	//if we get a false from both attempts then the class cannot take a photo
	//with the given rules, and the function will return isPossible = false;
	for(int i = 0; i < redShirtHeights.size(); i++){
		if(redShirtHeights[i] <= blueShirtHeights[i]){
			//someone in the back row is shorter or of equal height to the person in front of them, 
			//so try to flip the rows
			checkOtherCase = true;
			//set our iterator such so that it stops checking for efficiency sake
			i = redShirtHeights.size();
		}
	}
	
	//we only do this if there was a problem with the first case
	if(checkOtherCase){
		for(int i = 0; i < blueShirtHeights.size(); i++){
			if(blueShirtHeights[i] <= redShirtHeights[i]){
				//at this point both cases have failed, and the photo is not possible
				isPossible = false;
				//set our iterator such so that it stops checking for efficiency sake
				i = redShirtHeights.size();
			}
		}
	}
	
  return isPossible;
}
