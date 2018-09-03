
#include <iostream>
#include <stack>
#include <queue>
#include <vector>


//We will solve many graph traversal problems
//Function prototypes


//Traverse through the entire graph using DFS
void DFSTraversal(Node* current);

//Using DFS, we need to find the distance between node A to node B.
int getDistanceDFS(Node* start, Node* end);

//Using BFS, we need to find the distance between node A to node B.
//Note: BFS will give us the shortest path distance.
int shortestPathDistanceBFS(Node* start, Node* end);


//Do we have a valid Binary Search Tree?
bool validBST(Node* root);
void inOrder(std::vector<int> & myVect, Node* current);


//In a binary search tree, find the common ancestor of the given two nodes. 
Node* commonAncestor(Node* p, Node* q);
Node* goUpBy(Node* current, int n);
int getDepth(Node* current);



//Given a sorted vector, create a minimal balanced binary search tree
Node* minBST(std::vector<int>& myVect);
Node* minBST(std::vector<int>& myVect, int start, int end);


//Get the in-order succesor of the given node.
Node* getSuccessorOfBST(Node* current);
Node* getLeftMostNode(Node* current);




int main()
{
	//The solutions are correct, 
	//but we still have to display some test cases (Do this later).
    return 0;
}


//We will traverse the entire graph using recursion
void DFSTraversal(Node* current) {

	//Base case
	if(current == nullptr){
		return;
	}
	
	//We can visit the node and mark it that we have visited this node
	std::cout << current->data << "\n";
	current->isVisited = true;

	//For all its children
	for(int i : current->adjVect){
		Node* child = allNodesVect[i];

		if(child->isVisited == 0)
		{
			DFSTraversal(child);
		}

	}
}




//Get the distance from the start node to the end node, 
//using DFS which means that we will not get the shortest path
int getDistanceDFS(Node* start, Node* end) {
	//We will need a stack
	std::stack<Node*> myStack;

	start->dist = 0;
	start->isVisited = 1;

	//Pust the start node into the stack
	myStack.push(start);

	while (!myStack.empty()) {
		//Take out the top node and its length
		Node* current = myStack.top();

		int length = current->dist;
		myStack.pop();

		if(current == end){
			return length;
		}

		//For all the children node
		for (int i : current->adjVect) {
			Node* child = allNodesVect[i];

			if (child->isVisited == 0) {
				
				child->isVisited = 1;
				child->dist = length + 1;

				myStack.push(child);
			
			}
		}
	
	
	}
	return -1;

}




int shortestPathDistanceBFS(Node* start, Node* end) {

	if(start == nullptr || end == nullptr)
		return -1;    //Error	

	//We will use a queue structure
	std::queue<Node*> myQueue;

	start->dist = 0;
	start->isVisited = 1;

	myQueue.push(start);

	while(!myQueue.empty()){
		//Pop the front node and get the length
		Node* current = myQueue.front();

		int length = current->dist;
		myQueue.pop();


		if (current == end) 
			return length;
		

		for (int i : current->adjVect) {
			
			Node* child = allNodesVect[i];

			if (child->isVisited == 0) {
				child->isVisited = 1;
				child->dist = length + 1;

				myQueue.push(child);			
			}
		}
	}

	return -1;
}


//Determine if we have a valid BST
bool validBST(Node* root) {

	if (root == nullptr) {
		return 1;
	}

	std::vector<int> traversalVector;

	//We need to traverse the BST using inOrder traversal
	//As we traverse the BST we need to push the element into the vector

	inOrder(traversalVector, root);


	//We have populated the traversalVector, 
	//We will have a valid BST if the current element < next element
	for (int i = 0; i < traversalVector.size()-1; i++) {
		if (traversalVector[i] >= traversalVector[i + 1]) {
			return false;
		}
	}
	return true;
}

//This is my helper function. This will traverse the BST and update my vector
void inOrder(std::vector<int> & myVect, Node* current) {

	if (current != nullptr) {
		inOrder(myVect, current->left);
		myVect.push_back(current->data);
		inOrder(myVect, current->right);
	}

}



Node* commonAncestor(Node* p, Node* q) {

	//Call a node shallow and the other one deeper, determine using an turnary operator

	int delta = getDepth(p) - getDepth(q);

	Node* shallow = (delta > 0) ? q : p;
	Node* deeper = (delta > 0) ? p : q;

	//We need to move up the deeper node, so both nodes are in the same level 
	deeper = goUpBy(deeper, delta);


	//The two node pointer are now in the same level so we must check if equal, 
	//if not move both up

	while (shallow != nullptr && deeper != nullptr) {
		if(shallow == deeper){
			return deeper;
		}

		shallow = shallow->parent;
		deeper = deeper->parent;
	}

	//We were not able get a common Ancestor, therefore return nullptr.
	return nullptr;


}

//This is the helper function, it will make a node pointer move up n steps
Node* goUpBy(Node* current, int n) {

	for (int i = 0; i < n; i++) {
		current = current->parent;
	}

	return current;
}


//This is a helper function, it will give the depth of the given node
int getDepth(Node* current){

	int counter = 0;
	Node* tracker = current;

	while (tracker != nullptr){
		++counter;
		tracker = tracker->parent;
	}
	return counter;
}



//Given a sorted vector, create a min BST
Node* minBST(std::vector<int>& myVect) {
	return minBST(myVect, 0, myVect.size() - 1);
}

//This is the helper function
Node* minBST(std::vector<int>& myVect, int start, int end) {
	
	//Only vaalid when (left <= right), just like in the binary search.
	if (start > end) {
		return nullptr;
	}

	int mid = (start + end) / 2;

	Node* current = new Node(myVect[mid]);
	current->left = minBST(myVect, start, mid - 1);
	current->right = minBST(myVect, mid + 1, end);

	return current;

}



Node* getSuccessorOfBST(Node* current) {
	
	if(current == nullptr){
		return nullptr;
	}

	//Easy case
	if (current->right != nullptr) {
		return getLeftMostNode(current);
	}
	else{
		//We need two node pointers
		Node* tracker = current;
		Node* trackerParent = tracker->parent;

		while (trackerParent != nullptr && trackerParent->left != tracker) {
			tracker = trackerParent;
			trackerParent = trackerParent->parent;
		}
		return trackerParent;
	}

}

Node* getLeftMostNode(Node* current){


	if(current == nullptr){
		return nullptr;
	}

	while(current->left != nullptr){
		current = current->left;
	}

	return current;

}

