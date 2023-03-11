#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int bSArr[8], mSArr[8], input;
	for (int loop = 0; loop < 8; loop++) {
		cin >> input;
		bSArr[loop] = input;
		mSArr[loop] = input;
	}
	cout << "Bubble Sort" << endl;
	for (int loopY = 0; loopY < 7; loopY++) {
		for (int loopX = 0; loopX < (7 - loopY); loopX++) {
			if (bSArr[loopX] > bSArr[loopX + 1]) {
				int temp = bSArr[loopX];
				bSArr[loopX] = bSArr[loopX + 1];
				bSArr[loopX + 1] = temp;
				for (int loop = 0; loop < 8; loop++) {
					if (loop != 7)
						cout << bSArr[loop] << " ";
					else
						cout << bSArr[loop];
				}
				cout << endl;
			}
		}
	}
	cout << "Answer" << endl;
	for (int loop = 0; loop < 8; loop++) {
		if (loop != 7)
			cout << bSArr[loop] << " ";
		else
			cout << bSArr[loop];
	}
	cout << endl;
	cout << "Merge Sort" << endl;
	int* a = mSArr;
	int* b = new int[8];
	for (int seg = 1; seg < 8; seg += seg) {
		for (int start = 0; start < 8; start += seg + seg) {
			int low = start, mid = min(start + seg, 8), high = min(start + seg + seg, 8);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		bool isSame = true;
		for (int loop = 0; loop < 8; loop++) {
			if (a[loop] != b[loop])
				isSame = false;
		}
		if (!isSame) {
			for (int loop = 0; loop < 8; loop++) {
				if (loop != 7)
					cout << b[loop] << " ";
				else
					cout << b[loop];
			}
			cout << endl;
		}
		int* temp = a;
		a = b;
		b = temp;
	}
	if (a != mSArr) {
		for (int i = 0; i < 8; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
	cout << "Answer" << endl;
	for (int loop = 0; loop < 8; loop++) {
		if (loop != 7)
			cout << mSArr[loop] << " ";
		else
			cout << mSArr[loop];
	}
	cout << endl;
	return 0;
}
