//Ryan Howse
//5/24/2021
//Depth-frist Search of a tree using arrays
//I originally was stumped by the array structure of the tree and had to look
//at their solution for help, but I've learned how to do it a bit cleaner now because of it

#include <vector>
using namespace std;

class Node {
public:
	//we need a name for each node
	string name;
	//and a list within each node containing each node's children
  	vector<Node *> children;
	
	//Default constructor
  	Node(string str) { name = str; }

	//function for performing the search
	//gets passed an empty for us to build on
  	vector<string> depthFirstSearch(vector<string> *array) {
    	//store the name of the current node in the input array
		array->push_back(this->name);
		//for each of the current node's children, perform the same function recursively
		for(int i = 0; i < this->children.size(); i++){
			children[i]->depthFirstSearch(array);
		}
		//this code is only reachable once the entire tree has been traversed through
		//because of the recursion within the loop
		//and will return a list of every node's name
		return *array;
  }

	//a function to add children Nodes, calls the constructor but also
	//builds the children array of the node the child is added to
	Node *addChild(string name) {
  		Node *child = new Node(name);
    		children.push_back(child);
    		return this;
  }
};
