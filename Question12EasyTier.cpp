//Ryan Howse
//5/26/2021
//Pairing riders on a tandem bicycle to produce the fastest
//or slowest total speed, determined by the given boolean

#include <vector>
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {
	//first we need a running total for the return variable
	int totalSpeed = 0;
	
  //in order to do this, we have to sort the first vector in ascending order
	//whether we sort the second in ascending or descending depends
	//on whether we want the fastest or slowest possible speed total
	//basically to get the fastest speed possible, we want to pair the fastest people
	//with the slowest people
	sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
	if(fastest){
		sort(blueShirtSpeeds.rbegin(), blueShirtSpeeds.rend());
	}
	else{
		sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
	}
	
	//now we simply need to compare them and take the fastest of each pair
	//to calculate the total speed
	for(int i = 0; i < redShirtSpeeds.size(); i++){
		if(redShirtSpeeds[i] >= blueShirtSpeeds[i]){
			totalSpeed += redShirtSpeeds[i];
		}
		else{
			totalSpeed += blueShirtSpeeds[i];
		}
	}
	
  return totalSpeed;
}
