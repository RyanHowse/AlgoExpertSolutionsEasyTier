//Ryan Howse
//5/29/2021
//Selection Sort

#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
	//this sort works by finding the lowest unsorted value
	//and moving it to the end of the sorted subset at the front of the array
	int lowestIndex = 0;
  for(int i = 0; i < array.size(); i++){
		//we set j to start equal to i, that way we aren't checking
		//already sorted values
		for(int j = i; j < array.size(); j++){
			//find the lowest unsorted value
			if(array[j] < array[lowestIndex]){
				lowestIndex = j;
			}
		}
		//we should have the index of the lowest unsorted number now
		//do a simple flip
		if(i != lowestIndex){
			int temp = array[i];
			array[i] = array[lowestIndex];
			array[lowestIndex] = temp;
		}
		//set the lowestIndex to our next starting point
		lowestIndex = i+1;
	}
  return array;
}
