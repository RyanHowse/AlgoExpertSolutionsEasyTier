//Ryan Howse
//5/9/2021
//Find the closest node value to a target value in a binary search tree

#include <cmath>

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
	//for this let's just traverse through the given tree and compare the value of the current node
	//to the target value we're looking for
	
	//we need a return variable
	int closestValue = 0;
	//we need a BST object that we'll initialize to the tree
	BST *currentNode = tree;
	
	//and we'll have an escape flag for our while loop
	bool keepLooking = true;
	//our smallest difference
	int smallestDif = INT_MAX;
	
	while(keepLooking){
		if(currentNode->value == target){
			//exact match
			closestValue = currentNode->value;
			keepLooking = false;
		}
		else if(currentNode->value > target){
			//we go left if we can
			if(currentNode->left != NULL){
				//determine if the next node is further away than the current one is
				if(abs(currentNode->value - target) < smallestDif){
					//assign new value if the difference is smaller and update the smallest difference
          smallestDif = abs(currentNode->value - target);
					closestValue = currentNode->value;
				}
		    //go left
				currentNode = currentNode->left;
			}
			else{
        //this triggers if there's no left node
				//determine if the next node is further away than the current one is
				if(abs(currentNode->value - target) < smallestDif){
					//assign new value if the difference is smaller and update the smallest difference
          smallestDif = abs(currentNode->value - target);
					closestValue = currentNode->value;
				}
				keepLooking = false;
			}
		}
		else if(currentNode->value < target){
			//we go right if we can
			if(currentNode->right != NULL){
				//determine if the next node is further away than the current one is
				if(abs(currentNode->value - target) < smallestDif){
					//assign new value if the difference is smaller and update the smallest difference
          smallestDif = abs(currentNode->value - target);
					closestValue = currentNode->value;
				}
				//go right
				currentNode = currentNode->right;
			}
			else{
				//determine if the next node is further away than the current one is
				if(abs(currentNode->value - target) < smallestDif){
					//assign new value if the difference is smaller and update the smallest difference
          smallestDif = abs(currentNode->value - target);
					closestValue = currentNode->value;
				}
				keepLooking = false;
			}
		}
	}
	
  return closestValue;
}
