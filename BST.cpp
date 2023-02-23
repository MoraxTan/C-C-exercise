#include<iostream>
#include<cstring>
using namespace std;

class Tree {
public:
	int* arr;
	int size;
	
	Tree() {
		arr = new int[1023];
		memset(arr, 0, 1023*sizeof(int));
		size = 1023;
	}
	~Tree() {
		delete[] arr;
	}
	
	void insert(int element){
		if (arr[0] == 0) {
			arr[0] = element;
			return;
		}
		int curPos = 0; //Root position (current position)
		bool successInsert = false; //Determine if insert
		do {
			int curElement = arr[curPos]; //Current position element
			if (element < curElement) {
				if (arr[(2 * curPos) + 1] == 0) {
					arr[(2 * curPos) + 1] = element;
					successInsert = true;
				}
				else
				{
					curPos = (2 * curPos) + 1;
				}
			}
			else
			{
				if (arr[(2 * curPos) + 2] == 0) {
					arr[(2 * curPos) + 2] = element;
					successInsert = true;
				}
				else
				{
					curPos = (2 * curPos) + 2;
				}
			}
		} while (!successInsert);
	}
	
	void printLevelOrder() {
		int lastElementPos = findLastElementPos();
		for (int loop = 0; loop <= lastElementPos; loop++) {
			cout << arr[loop] << " ";
		}
	}
	
	int findLastElementPos() {
		int lastElementPos = 0;
		for (int loop = 1022; loop >= 0; loop--) {
			if (arr[loop] != 0) {
				lastElementPos = loop;
				break;
			}
		}
		return lastElementPos;
	}
	
	void removeElement(int element) {
		if (arr[0] == 0) {
			return;
		}
		int curPos = 0;
		int foundPos = 0;
		bool successFound = false;
		do {
			int curElement = arr[curPos];
			if (element == curElement) {
				foundPos = curPos;
				successFound = true;
				break;
			}
			if (element < curElement) {
				if (((2 * curPos) + 1) < 1023) {
					curPos = (2 * curPos) + 1;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (((2 * curPos) + 2) < 1023) {
					curPos = (2 * curPos) + 2;
				}
				else
				{
					break;
				}
			}
		} while (!successFound);
	
		if (successFound) {
			recursiveMove(foundPos);
		}
		else
		{
			return;
		}
	}
	
	void recursiveMove(int pos) {
		int leftChildPos = (2 * pos) + 1;
		int rightChildPos = (2 * pos) + 2;
		
		if (arr[leftChildPos] == 0 && arr[rightChildPos] == 0) {
			arr[pos] = 0;
			return;
		}
		
		if (this->arr[leftChildPos] != 0) {
			int pred_idx = leftChildPos;
			while (this->arr[pred_idx * 2 + 2] != 0) {
				pred_idx = pred_idx * 2 + 2;
			}
			this->arr[pos] = this->arr[pred_idx];
			this->recursiveMove(pred_idx);
		}
		
		else if (this->arr[rightChildPos] != 0) {
			int succ_idx = rightChildPos;
			while (this->arr[succ_idx * 2 + 1] != 0) {
				succ_idx = succ_idx * 2 + 1;
			}
			this->arr[pos] = this->arr[succ_idx];
			this->recursiveMove(succ_idx);
		}
	}
};

int main() {
	Tree* tree = new Tree();
	int input;
	bool endInsert = false;
	bool endRemove = false;
	
	do {
		cin >> input;
		if (endInsert && !endRemove && (input == -1)) {
			endRemove = true;
		}
		if ((input == -1) && !endInsert) {
			endInsert = true;
		}
		if (!endInsert && !endRemove) {
			tree->insert(input);
		}
		if (endInsert && !endRemove && (input != -1)) {
			tree->removeElement(input);
		}
	} while (!endRemove);
	
	tree->printLevelOrder();
	delete tree;
	
	return 0;
}
