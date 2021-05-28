//Ryan Howse
//5/28/2021
//finding the sum of an array, given that nested arrays are multiplied
//by thier depth
//ex: array = [5 ,2,[7, -1], 3, [6, [-13, 8], 4]]
//12, calculated as 5 + 2 + (2 * (7 - 1)) + 3 + (2*(6 + (3*(-13 + 8) + 4)))

#include <any>
#include <vector>

using namespace std;

//declare our recursive function
int productSumRecursive(vector<any> array, int depth);

int productSum(vector<any> array) {
	//we need a return total, and a way to mark what depth we're at
  int sumTotal = 0;
	int currentDepth = 1;
	for(int i = 0; i < array.size(); i++){
		//check to see if the current array index is an integer or a nested array
		if(array[i].type() == typeid(vector<any>)){
			//if it's an array, we send it off to the recursive function
			sumTotal += productSumRecursive(any_cast<vector<any>>(array[i]), currentDepth) * currentDepth;
		}
		else{
			//if it's an integer, we just add it to the total
			sumTotal += any_cast<int>(array[i]);
		}
	}
	//the program eventually ends here, after all the recursion has resolved
  return sumTotal;
}

int productSumRecursive(vector<any> array, int depth){
	//add 1 to the depth
	//we do it in the recursive function so that when one layer of recursion
	//completes, the previous layer still has it's correct depth
	depth++;
	int sumTotal = 0;
	for(int i = 0; i < array.size(); i++){
		if(array[i].type() == typeid(vector<any>)){
			//here we do the same, passing nested arrays to the function again, with a deeper depth
			//the sumTotal is accrued by the sum of the nested array, multiplied by the correct depth
			sumTotal += productSumRecursive(any_cast<vector<any>>(array[i]), depth) * depth;
		}
		else{
			sumTotal += (any_cast<int>(array[i])) * depth;
		}
	}
	return sumTotal;
}
