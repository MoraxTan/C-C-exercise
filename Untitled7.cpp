//queue exercise in DATA STRUCTURE course
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int n;
	char c;
	string code;
	Node(char c, int n) {
		this->c = c;
		this->n = n;
		code = "";
		prev = NULL;
		next = NULL;
		parent = NULL;
		lChild = NULL;
		rChild = NULL;
	}
	~Node() {}
	Node* prev;
	Node* next;
	Node* parent;
	Node* lChild;
	Node* rChild;
};

class List {
public:
	Node* head;
	Node* tail;
	int size;
	List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	
	~List() {
		while (size != 0) {
			Node* temp = tail;
			tail = tail->prev;
			delete temp;
			size -= 1;
		}
	}
	
	void push(Node* node) {
		if (size == 0) {
			head = node;
			tail = node;
			size += 1;
			return;
		}
		Node* temp = head;
		while (temp != NULL) {
			if (node->c == temp->c) {
				temp->n += 1;
				Node* delTemp = node;
				delete delTemp;
				node = NULL;
				break;
			}
			temp = temp->next;
		}
		if (node != NULL) {
			tail->next = node;
			node->prev = tail;
			tail = node;
			size += 1;
		}
	}
	
	void insert(Node* node) {
		if (size == 0) {
			head = node;
			tail = node;
			size += 1;
			return;
		}
		tail->next = node;
		node->prev = tail;
		tail = node;
		size += 1;
	}
	
	Node* getSmallest() {
		Node* smallest = head;
		Node* temp = head;
		do {
			temp = temp->next;
			if (temp != NULL) {
				if (smallest->n > temp->n) {
					smallest = temp;
				}
				else if ((smallest->n == temp->n) && (smallest->c > temp->c)) {
					smallest = temp;
				}
			}
			else
			{
				break;
			}
		} while (true);
		
		if ((smallest->prev != NULL) && (smallest->next != NULL)) {
			smallest->prev->next = smallest->next;
			smallest->next->prev = smallest->prev;
			smallest->prev = NULL;
			smallest->next = NULL;
		}
		else if ((smallest->prev != NULL) && (smallest->next == NULL)) {
			smallest->prev->next = NULL;
			tail = smallest->prev;
			smallest->prev = NULL;
		}
		else if ((smallest->prev == NULL) && (smallest->next != NULL)) {
			smallest->next->prev = NULL;
			head = smallest->next;
			smallest->next = NULL;
		}
		size -= 1;
		return smallest;
	}
	
	string getCode(char c) {
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->c == c) {
				return temp->code;
			}
			temp = temp->next;
		}
		return "";
	}
	
	char decode(string s) {
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->code == s) {
				return temp->c;
			}
			temp = temp->next;
		}
		return ' ';
	}
};

void postOrder(Node* node) {
	if (node->lChild != NULL) {
		if (node->lChild->c != '_') {
			cout << node->lChild->c;
		}
	}

	if (node->rChild != NULL) {
		if (node->rChild->c != '_') {
			cout << node->rChild->c;
		}
	}
	cout << node->c;
}

void tocode(Node* node) {
	Node* temp = node;
	Node* parent = node->parent;
	while (parent != NULL)
	{
		if (parent->lChild != NULL) {
			if ((temp->c == parent->lChild->c) && (temp->n == parent->lChild->n)) {
				node->code = "0" + node->code;
			}
		}
		if (parent->rChild != NULL) {
			if ((temp->c == parent->rChild->c) && (temp->n == parent->rChild->n)) {
				node->code = "1" + node->code;
			}
		}
		temp = parent;
		parent = parent->parent;
	}
}

int main() {
	List* list = new List();
	queue<Node*> allNode;
	string inputString;
	cin >> inputString;
	
	for (int loop = 0; loop < inputString.length(); loop++) {
		list->push(new Node(inputString[loop], 1));
	}
	
	if (list->size != 0) {
		while (list->size > 1)
		{
			Node* temp1 = list->getSmallest();
			Node* temp2 = list->getSmallest();
			Node* newNode = new Node('_', (temp1->n + temp2->n));
			newNode->lChild = temp1;
			newNode->rChild = temp2;
			temp1->parent = newNode;
			temp2->parent = newNode;
			list->insert(newNode);
			if (temp1->c != '_') {
				allNode.push(temp1);
			}
			if (temp2->c != '_') {
				allNode.push(temp2);
			}
		}
	}
	
	while (allNode.size() != 0)
	{
		Node* temp = allNode.front();
		tocode(temp);
		cout << temp->c << ": " << temp->code << endl;
		list->insert(temp);
		allNode.pop();
	}
	
	string compressString = "";
	for (int loop = 0; loop < inputString.length(); loop++) {
		compressString += list->getCode(inputString[loop]);
	}
	
	cout << compressString << endl;
	string decompressString = "";
	string insertString = "";
	char getChar = ' ';
	for (int loop = 0; loop < compressString.length(); loop++) {
		insertString += compressString[loop];
		getChar = list->decode(insertString);
		if (getChar != ' ') {
			decompressString += getChar;
			insertString = "";
		}
	}
	cout << decompressString << endl;
	delete list;
	return 0;
}

