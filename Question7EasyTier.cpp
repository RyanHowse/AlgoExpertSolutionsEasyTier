//Ryan Howse
//5/22/2021
//Finding the sum of each branch of a binary tree

using namespace std;
//we need a return vector
vector<int> sumList = {};
vector<int>::iterator it;

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
void ArmSums(BinaryTree *node, int runningTotal);

vector<int> branchSums(BinaryTree *root) {
	//because the sumList is global, it's important to reset it before each test case
	sumList = {};
	ArmSums(root, 0);
  return sumList;
}

void ArmSums(BinaryTree *node, int runningTotal)
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
		runningTotal += node->value;
  
    //recur on left child
    ArmSums(node->left, runningTotal);
    
	  //if there is no node to the left or right then you have reached the end
		//of a branch, and should add the running total to the list
	  if(node->left == NULL && node->right == NULL){
			it = sumList.end();
			sumList.insert(it, runningTotal);
		}
  
    //recur on right child
		//this happens immediately after a left node returns due to NULL (see above)
    ArmSums(node->right, runningTotal);
}
