//Ryan Howse
//5/28/2021
//find the 3 largest numbers in a given data array

#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  	//let's make an array to hold our highest values
	//the initial values are the lowest possible integer
	vector<int> highestValues = {INT_MIN, INT_MIN, INT_MIN};
	//for every value in the data array, we check against the 
	//three values currently stored
	//we float the lesser values foward, which keeps them in order as we go through
	//and helps us make sure we're keeping the right values. Simply replacing
	//lesser values with greater ones would lead to us dumping a value greater
	//than one of the lesser values within the return vector
	for(int i = 0; i < array.size(); i++){
		if(array[i]>=highestValues[0]){
			highestValues[2] = highestValues[1];
			highestValues[1] = highestValues[0];
			highestValues[0] = array[i];
		}
		else if(array[i]>=highestValues[1]){
			highestValues[2] = highestValues[1];
			highestValues[1] = array[i];
		}
		else if(array[i]>highestValues[2]){
			highestValues[2] = array[i];
		}
	}
	
	//sort to ascending for requirements purposes
	sort(highestValues.begin(), highestValues.end());
  	return highestValues;
}
