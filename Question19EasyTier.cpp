//Ryan Howse
//5/29/2021
//Insertion Sort

#include <vector>
using namespace std;

//this sort puts each element in the array in it's proper place as it goes
vector<int> insertionSort(vector<int> array) {
	for(int i = 0; i < array.size(); i++){
		//we start at the current index and work backwards to check if the value
		//at the current index is is the right place
		for(int j = i; j >=0; j--){
			if(j > 0){
				if(array[j] < array[j-1]){
					//do a simple flip
					int temp = array[j];
					array[j] = array[j-1];
					array[j-1] = temp;
				}
			}
		}
	}
	return array;
}
