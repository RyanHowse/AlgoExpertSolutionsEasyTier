//Ryan Howse
//5/5/2021
//Determine if a two numbers within a given array match a target sum

#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  //first we need a return array so we don't end up with 2 return statements
	vector<int> returnArray = {};
	vector<int>::iterator it = returnArray.begin();
	
	//we'll have an escape variable so we can stop checking if we hit
	bool checkValues = true;
	
	//we either need a variable to hold the value we're going to check,
	//or we need a variable to hold an index value. I think index value will
	//be cleaner in terms of computation
	int indexToCompareAgainst = 0;
	
	//we also need a way to iterate
	int iterateIndex = 1;
	
	if(array.size()>1){
		while(checkValues){
			//check if we have a hit, but only within the bounds of the array
			if(array[indexToCompareAgainst] + array[indexToCompareAgainst + iterateIndex] == targetSum && (indexToCompareAgainst + iterateIndex) < array.size()){
				returnArray.insert(it, array[indexToCompareAgainst]);
				it = returnArray.begin();
				returnArray.insert(it, array[indexToCompareAgainst + iterateIndex]);
				checkValues = false;
			}
			else{
				//check to see if we're at the end of the value array
				if(indexToCompareAgainst + iterateIndex == array.size()){
					if(indexToCompareAgainst < array.size()-1){
						//shift our compare value foward if we have reached the end, but there is room for another pass
						indexToCompareAgainst++;
						iterateIndex = 1;
					}
					else{
						//we have reached the end of the array with no hit, we will return the empty array
						checkValues = false;
					}
				}
				else{
					//only iterate the iteration value if there's still room in the array to move forward 
					iterateIndex++;
				}
			}
		}
	}
	
  return returnArray;
}
