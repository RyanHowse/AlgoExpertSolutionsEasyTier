//Ryan Howse
//5/24/2021
//Finding the sum of each branch depth of a binary tree

using namespace std;
//we need a return value
int depthSum = 0;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

//delcare our sum function
void DepthSum(BinaryTree *node, int runningTotal);

int nodeDepths(BinaryTree *root) {
	//because the sumList is global, it's important to reset it before each test case
	depthSum = 0;
	//we send the Depth function -1 because it's going to add 1
	//at the root, and this snowballs down the line into bigger and bigger miscalcs
	DepthSum(root, -1);
  return depthSum;
}

void DepthSum(BinaryTree *node, int runningTotal)
{
  //if the current node is null then we've gone outside of the tree
  //this means we exit so that the most recent node can check
  //to see if there is a right-hand node to travel to
  if (node == NULL){
    return;
  }

  //add to the running total
  //because of the recursion and the fact that no variables are overwritten, 
  //we can essenitally save instances of the branch sum at each node
  runningTotal += 1;

  //recur on left child
  DepthSum(node->left, runningTotal);

  //add the current node's depth to the global total
  depthSum += runningTotal;

  //recur on right child
  //this happens immediately after a left node returns due to NULL (see above)
  DepthSum(node->right, runningTotal);
}
