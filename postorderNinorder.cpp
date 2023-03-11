/*
	give a level-order binary tree,output its inorder and postorder.
	input:AB0CD00E,string include 'A' to 'Z' and '0','0' means nullnode.
	output:ECBDA'\n'ECDBA
*/

#include <iostream>
#include <queue>
using namespace std;

//class of Node
class Node {
public:
	char element;
	Node* lChild;
	Node* rChild;
	Node(char element) {
		this->element = element;
		lChild = NULL;
		rChild = NULL;
	}
	~Node(){}
};

class Tree {
private:
	Node* root;
public:
	Tree() { 
	// new tree without value
		root = NULL;
	}
	
	//insert function
	void insert(char element) {
		if (root == NULL) {
			root = new Node(element);
			return;
		}
		
		//create a queue 'listNode' to push Node*
		queue<Node*> listNode;
		listNode.push(root);
		
		while (!listNode.empty()) {
			//take its front,then pop it up
			Node* temp = listNode.front();
			listNode.pop();

			if (temp->lChild == NULL) {
				//new node(element) while lchild is nullnode
				temp->lChild = new Node(element);
				return;
			}
			else if (temp->rChild == NULL) {
				//new node(element) while rchild is nullnode
				temp->rChild = new Node(element);
				return;
			}
			else {
				//push the lchild and rchild data while its not nullnode 
				listNode.push(temp->lChild);
				listNode.push(temp->rChild);
			}
		}
	}
	
	void inOrder() {
		inOrder(root);
	}
	
	void inOrder(Node* n) {
		//print by inorder
		Node* temp = n;
		if (temp != NULL) {
			inOrder(temp->lChild);
			if (temp->element != '0') { 
			//print out the element without '0'
				cout << temp->element;
			}
			inOrder(temp->rChild);
		}
	}
	
	void postOrder() {
		postOrder(root);
	}
	
	void postOrder(Node* n) {
		// print by postorder
		Node* temp = n;
		if (temp != NULL) {
			postOrder(temp->lChild);
			postOrder(temp->rChild);
			if (temp->element != '0') {
			//print out the element without '0'
				cout << temp->element;
			}
		}
	}
	
	void deleteNode(Node* n) { 
	//method used to delete
		Node* temp = n;
		if (temp != NULL) {
			deleteNode(temp->lChild);
			deleteNode(temp->rChild);
			delete temp;
		}
	}
	~Tree() { 
	//deleteNode after using bTree
		deleteNode(root);
	}
};

int main() {
	Tree* tree = new Tree();
	string input;
	cin >> input; //input:AB0CD00E
	
	for (int loop = 0; loop < input.length(); loop++) {
		tree->insert(input[loop]);
	}
	
	cout<<"inOrder: ";
	tree->inOrder();

	cout << endl;
	
	cout<<"postOrder: ";
	tree->postOrder();
	
	delete tree;
	return 0;
}
