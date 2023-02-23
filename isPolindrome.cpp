#include <iostream>
using namespace std;

class singleton {
public:
	char c;
	singleton(char c){
		this->c = c;
		prev = NULL;
		next = NULL;
	}
	~singleton(){}
	singleton* prev;
	singleton* next;
};

class linkedlist {
public:
	singleton* head;
	singleton* tail;
	int size;
	linkedlist(){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	~linkedlist(){
		singleton* temp = tail;
		while (size > 0) {
			tail = temp->prev;
			delete tail;
		}
	}
	void push(string c) {
		string s = c;
		int len = s.length();
		for (int y = 0; y < len; y++) {
			if (size == 0) {
				singleton* k = new singleton(s[y]);
				head = k;
				tail = k;
				size++;
			}
			else
			{
				singleton* k = new singleton(s[y]);
				tail->next = k;
				k->prev = tail;
				tail = k;
				size++;
			}
		}
	}
	void check(string x) {
		singleton* temp = tail;
		string newX = "";
		while (temp != NULL) {
			newX += temp->c;
			temp = temp->prev;
		}
		if (newX == x) {
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
};

int main() {
	int x;
	string input;
	linkedlist* ll;
	cin >> x;
	while (x--)
	{
		ll = new linkedlist();
		cin >> input;
		ll->push(input);
		ll->check(input);
	}
	return 0;
}
