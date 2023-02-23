#include<iostream>
using namespace std;

class Person {
private:
	string name;
	int score;
public:
	Person(string name, int score) {
		this->name = name;
		this->score = score;
		prev = NULL;
		next = NULL;
	}
	~Person() {
	}
	Person* prev;
	Person* next;

	string getName() {
		return this->name;
	}
	int getScore() {
		return this->score;
	}
};

class PersonList {
private:
	Person* head;
	int size;
public:
	PersonList() {
		head = NULL;
		size = 0;
	}
	~PersonList() {
		Person* temp = head;
		while (size != 0) {
			temp = head;
			head = head->next;
			delete temp;
			size--;
		}
	}
	void addPerson(Person* p) {
		if (size == 0) {
			head = p;
			size++;
		}
		else {
			if (p->getScore() > head->getScore()) {
				head->prev = p;
				p->next = head;
				head = p;
				size++;
			}
			else {
				Person* temp = head;
				bool endLoop = false;
				while (!endLoop) {
					if (temp->next != NULL) {
						if (p->getScore() > temp->getScore()) {
							temp->prev->next = p;
							p->prev = temp->prev;
							temp->prev = p;
							p->next = temp;
							size++;
							endLoop = true;
						}
					}
					else {
						if (p->getScore() > temp->getScore()) {
							temp->prev->next = p;
							p->prev = temp->prev;
							temp->prev = p;
							p->next = temp;
							size++;
							endLoop = true;
						}
						else {
							temp->next = p;
							p->prev = temp;
							size++;
							endLoop = true;
						}
					}
					temp = temp->next;
				}
			}
		}
	}
	void deleteHead() {
		if(size != 0){
			Person* temp = head;
			head = head->next;
			delete temp;
			size--;
		}
		
	}
	void printList() {
		if(size>0){
			Person* temp = head;
			while (temp->next != NULL) 
			{
				cout << temp->getName() << endl;
				temp = temp->next;
			}
			cout << temp->getName() << endl;
		}
	}
};

int main() {
	int loopTime;
	string name;
	int score;
	PersonList* pList = new PersonList();
	cin >> loopTime;
	while (loopTime--)
	{
		cin >> name;
		if (name != "delete") {
			cin >> score;
			pList->addPerson(new Person(name, score));
		}
		else
		{
			pList->deleteHead();
		}
	}
	pList->printList();
	delete pList;
	return 0;
}

