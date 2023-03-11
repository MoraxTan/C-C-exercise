#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int n;
	char c;
	Node(char c, int n) {
		this->c = c;
		this->n = n;
		prev = NULL;
		next = NULL;
		lChild = NULL;
		rChild = NULL;
	}
	~Node(){}
	Node* prev;
	Node* next;
	Node* lChild;
	Node* rChild;
};

class List {
public:
	Node* head;
	Node* tail;
	int size;
	List(){
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
				if (smallest->n >= temp->n) {
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
		else if((smallest->prev != NULL) && (smallest->next == NULL)) {
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
};

void postOrder(Node* node) {
	if(node->lChild != NULL){
		if (node->lChild->c != '_') {
			cout << node->lChild->c;
		}
	}
		
	if(node->rChild != NULL){
		if (node->rChild->c != '_') {
			cout << node->rChild->c;
		}
	}
	cout << node->c;
}
	
int main() {
	List* list = new List();
	queue<Node*> printList;
	int inputLength, inputInt;
	char inputChar;
	cin >> inputLength;
	for (int loop = 0; loop < inputLength; loop++) {
		cin >> inputChar;
		cin >> inputInt;
		list->insert(new Node(inputChar, inputInt));
	}
	if (list->size != 0) {
		while (list->size > 1)
		{
			Node* temp1 = list->getSmallest();
			Node* temp2 = list->getSmallest();
			Node* newNode = new Node('_', (temp1->n + temp2->n));
			newNode->lChild = temp1;
			newNode->rChild = temp2;
			list->insert(newNode);
			printList.push(newNode);
		}
		if(inputLength > 1){
			list->getSmallest();
		}
		
		if(list->size == 1){
			printList.push(list->getSmallest());
		}
		while (printList.size() != 0)
		{
			Node* temp = printList.front();
			printList.pop();
			postOrder(temp);
		}
	}
	delete list;
	return 0;
}
