//Ryan Howse
//5/5/2021
//Take in an array of values and return an array 
//of equal length with the values squared in ascending order

#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  //first we need a return array
	vector<int> returnArray = {};
	//and an iterator to add things to it
	vector<int>::iterator it;
	//we need a current value to add to the array
	int currentValueToAdd;
	//minimum and maximum values that we've seen
	//having these will avoid unnecessary looping for negative numbers
	int minValue, maxValue;
	//counter and variable to handle negative values (see below)
	bool placeValue = false;
	int placeValueCounter = 1;
	
	//handle the first case to set initial values
	it = returnArray.begin();
	currentValueToAdd = array[0]*array[0];
	minValue = currentValueToAdd;
	maxValue = currentValueToAdd;
	returnArray.insert(it, currentValueToAdd);
	
	//next we loop through the data array
	for(int i = 1; i < array.size(); i++){
		it = returnArray.begin();
		//square each value and add it to the return vector
		currentValueToAdd = array[i]*array[i];
		if(currentValueToAdd <= minValue){ 
			it = returnArray.begin();
		}
		else if(currentValueToAdd >= maxValue){
			it = returnArray.end();
		}
		else{
			placeValue = true;
			//this value will be used during the loop to iterate through and determine where the value goes
			placeValueCounter = 0;
		}
		
		//this will most likely trigger when there are negative values in the data array, as squaring those values
		//will make them positive, but they are on the low end of the data array
		//having this while loop handles the negative values without having to sort the entire array afterwards which may
		//not be neccessary if there are no negative vales
		while(placeValue){
			if(currentValueToAdd >= returnArray[placeValueCounter]){
				placeValueCounter++;
			}
			else{
				it = returnArray.begin()+placeValueCounter;
				placeValue = false;
			}
		}
		
		
		//and then add the squared value of the next data value to the end of the array
		returnArray.insert(it, currentValueToAdd);
		minValue = returnArray[0];
		maxValue = returnArray[returnArray.size()-1];
	}
	
  return returnArray;
}
