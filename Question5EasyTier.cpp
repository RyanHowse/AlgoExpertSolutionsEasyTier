#include <vector>
#include <numeric>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
	//we need a return value
	int minimumChange;
	
	//we'll use a flag to determine if we need to do things the long way or if one of the short edge cases is true
	bool doTheMath = true;
	
  //first lets sort the coins vector
	sort(coins.begin(), coins.end());
	
	//let's handle some edge cases!
	//A couple of if's can save us some looping later; let's not do the math if we don't have to
	//if the lowest amount is also the highest amount, the lowest amount is the sum of all values + 1
	if(coins.size() > 1){
		if(coins[0] == coins[coins.size()-1]){
			doTheMath = false;
			minimumChange = accumulate(coins.begin(), coins.end(), 0) + 1;
		}
	}
	//if we have no coins OR 1 coin, the lowest will be 1
	if(coins.size() == 0){ minimumChange = 1, doTheMath=false; }
	if(coins.size() == 1){
		doTheMath = false;
		//unless we have 1 coin with value 1, which case 2 is the answer
		if(coins[0] > 1){ minimumChange = 1; }
		else{ minimumChange = 2; }
	}

	//if doTheMath is still true, lets do some math
	//i'm using a while loop, so i'll have a variable for iteration
	int currentIndex = 0;
	//and a running total
	int runningTotal = 0;
	//and a variable to check for a perfect sequence in order to handle our last edge case
	bool isSequence = true;
	
	while(doTheMath){
		//this keeps us from going out of bounds
		if(coins.size() >= currentIndex+1){
			//check if the current running total + the current index is greater than the next index
			//example: running total = 3, current index value is 4, next index value is 9
			//3 + 4 = 7, next value is 9, this means the minimum change we cannot make is 8
			if((runningTotal + coins[currentIndex] + 1) >= coins[currentIndex+1]){
				//update our running total
				runningTotal += coins[currentIndex];
				//check to see if we are on sequence
				if(currentIndex+1 != coins[currentIndex]){ isSequence = false; }
				//increment index and keep going
				currentIndex++;
			}
			else{
				//we have found the minimum! Only triggers if the minimum is between the values at coins[0] and coins[n]
				minimumChange = runningTotal + coins[currentIndex] + 1;
				doTheMath = false;
			}
		}
		else{
			//the final edge case is that if all the numbers are perfectly in sequence from 1 to n, the minimum will also be the sum + 1
			//to handle this, we use the isSequence variable
			if(isSequence == true){
				minimumChange = accumulate(coins.begin(), coins.end(), 0) + 1;
				doTheMath = false;
			}
			else{
				minimumChange = coins[coins.size()-1] + 1;
				doTheMath = false;
			}
		}
	}
	
  return minimumChange;
}
