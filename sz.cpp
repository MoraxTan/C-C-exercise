#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class VaccineDetail
{
private:
	string name, code, country;
	double dosageRequired, populationCovered, quantity;

public:
	VaccineDetail(string name, string code, string country, double dosageRequired, double populationCovered, double quantity) {
		this->name = name;
		this->code = code;
		this->country = country;
		this->dosageRequired = dosageRequired;
		this->populationCovered = populationCovered;
		this->quantity = quantity;
	}
	~VaccineDetail() {}
	string getName() { return name; }
	string getCode() { return code; }
	string getCountry() { return country; }
	double getPosageRequired() { return dosageRequired; }
	double getPopulationCovered() { return populationCovered; }
	double getQuantity() { return quantity; }
	void setQuantity(double quantity) { this->quantity = quantity; }
};

void bubbleSort(string* arrS, double* arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] < arr[j + 1]) {
				double temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				string tempS = arrS[j];
				arrS[j] = arrS[j + 1];
				arrS[j + 1] = tempS;
			}
}

void readFile(vector<VaccineDetail>& vaccineDetailList) {
	ifstream readFile("vaccine.txt");
	if (!readFile.fail()) {
		if (!readFile.eof()) {
			string line1, line2, line3, line4, line5, line6;
			while (getline(readFile, line1))
			{
				getline(readFile, line2);
				getline(readFile, line3);
				getline(readFile, line4);
				getline(readFile, line5);
				getline(readFile, line6);
				VaccineDetail eachVaccine(line1, line2, line3, stod(line4), stod(line5), stod(line6));
				vaccineDetailList.push_back(eachVaccine);
			}
		}
	}
	readFile.close();
}

void writeFile(vector<VaccineDetail>& vaccineDetailList) {
	if (vaccineDetailList.size() != 0) {
		ofstream writeFile("vaccine.txt");
		for (VaccineDetail& vD : vaccineDetailList) {
			writeFile << vD.getName() << endl;
			writeFile << vD.getCode() << endl;
			writeFile << vD.getCountry() << endl;
			writeFile << vD.getPosageRequired() << endl;
			writeFile << vD.getPopulationCovered() << endl;
			writeFile << vD.getQuantity() << endl;
		}
		writeFile.close();
	}
}

template<typename T>
T getInput(string msg) {
	T userInput;
	cout << msg;
	cin >> userInput;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Input was not correct" << endl;
		cout << msg;
		cin >> userInput;
		
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return userInput;
}

string getInputLine(string msg) {
	string userInput;
	cout << msg;
	getline(cin, userInput);
	return userInput;
}

void inventoryCreation() {
	vector<VaccineDetail> vaccineDetailList;
	readFile(vaccineDetailList);
	string userInput = "yes";
	do {
		cout << "\nInventory Creation" << endl;
		if (vaccineDetailList.size() != 0) {
			cout << setw(10) << "Name" << setw(5) << "Code" << setw(10) << "Country" << setw(10) << "Required" << setw(10) << "Covered" << setw(10) << "Quantity" << endl;
			for (VaccineDetail& vD : vaccineDetailList) {
				cout << setw(10) << vD.getName() << setw(5) << vD.getCode() << setw(10) << vD.getCountry() << setw(10) << vD.getPosageRequired() << setw(10) << vD.getPopulationCovered() << setw(10) << vD.getQuantity() << endl;
			}
		}
		else {
			cout << "Inventory is empty" << endl;
		}
		string name, code, country;
		double dosageRequired, populationCovered, quantity;
		name = getInputLine("Enter the name of vaccine: ");
		code = getInputLine("Enter the code of vaccine: ");
		country = getInputLine("Enter the country of vaccine: ");
		do {
			dosageRequired = getInput<double>("Enter the dosageRequired of vaccine: ");
			if(dosageRequired < 0)
				cout << "Input was not correct" << endl;
		} while (dosageRequired < 0);
		do {
			populationCovered = getInput<double>("Enter the populationCovered of vaccine: ");
			if (populationCovered < 0)
				cout << "Input was not correct" << endl;
		} while (populationCovered < 0);
		do {
			quantity = getInput<double>("Enter the quantity of vaccine: ");
			if (quantity < 0)
				cout << "Input was not correct" << endl;
		} while (quantity < 0);
		VaccineDetail eachVaccine(name, code, country, dosageRequired, populationCovered, quantity);
		vaccineDetailList.push_back(eachVaccine);
		do {
			userInput = getInput<string>("Do you want to repeat? (yes / no): ");
			if ((userInput != "yes") && (userInput != "no"))
				cout << "Input was not correct" << endl;
		} while ((userInput != "yes") && (userInput != "no"));
	} while (userInput == "yes");
	writeFile(vaccineDetailList);
}
void updateVaccineQuantities() {
	vector<VaccineDetail> vaccineDetailList;
	readFile(vaccineDetailList);
	if (vaccineDetailList.size() != 0) {
		string userInput = "exit";
		do {
			cout << "\nUpdate vaccine quantities" << endl;
			cout << setw(5) << "Code" << setw(10) << "Name" << setw(10) << "Quantity" << endl;
			for (VaccineDetail& vD : vaccineDetailList) {
				cout << setw(5) << vD.getCode() << setw(10) << vD.getName() << setw(10) << vD.getQuantity() << endl;
			}
			userInput = getInputLine("Enter vaccine code to update vaccine quantities or enter 'exit' to exit update vaccine quantities: ");
			if (userInput != "exit") {
				bool findVaccine = false;
				for (VaccineDetail& vD : vaccineDetailList) {
					if (userInput == vD.getCode()) {
						findVaccine = true;
						cout << setw(5) << "Code" << setw(10) << "Name" << setw(10) << "Quantity" << endl;
						cout << setw(5) << vD.getCode() << setw(10) << vD.getName() << setw(10) << vD.getQuantity() << endl;
						string updateInput;
						double updateQuantity;
						do {
							updateInput = getInputLine("Enter 'received' to add quantity or\nEnter 'distributed' to subtract quantity: ");
							if ((updateInput != "received") && (updateInput != "distributed")) {
								cout << "Input was not correct" << endl;
							}
							else
							{
								do {
									updateQuantity = getInput<double>("Enter quantity you want to update: ");
									if (updateQuantity < 0)
										cout << "Input was not correct" << endl;
								} while (updateQuantity < 0);
								if (updateInput == "received") {
									vD.setQuantity(vD.getQuantity()+updateQuantity);
								}
								else
								{
									vD.setQuantity(vD.getQuantity()-updateQuantity);
									ofstream writeDistFile("dist.txt", ios::app);
									writeDistFile << vD.getCode() << endl;
									writeDistFile << updateQuantity << endl;
									writeDistFile.close();
								}
							}
						} while ((updateInput != "received") && (updateInput != "distributed"));
					}
				}
				if (!findVaccine) {
					cout << "Can't find vaccine, please enter correct vaccine code" << endl;
				}
			}
		} while (userInput != "exit");
		writeFile(vaccineDetailList);
	}
	else
	{
		cout << "\nUpdate vaccine quantities" << endl;
		cout << "Inventory is empty" << endl;
	}
}
void searchVaccine() {
	vector<VaccineDetail> vaccineDetailList;
	readFile(vaccineDetailList);
	if (vaccineDetailList.size() != 0) {
		string userInput = "exit";
		do {
			cout << "\nSearch vaccine and its available quantity by using vaccine code" << endl;
			cout << setw(5) << "Code" << setw(10) << "Name" << endl;
			for (VaccineDetail& vD : vaccineDetailList) {
				cout << setw(5) << vD.getCode() << setw(10) << vD.getName() << endl;
			}
			userInput = getInputLine("Enter vaccine code to get existing vaccine quantities or enter 'exit' to search vaccine: ");
			if (userInput != "exit") {
				bool findVaccine = false;
				for (VaccineDetail& vD : vaccineDetailList) {
					if (userInput == vD.getCode()) {
						findVaccine = true;
						cout << setw(5) << "Code" << setw(10) << "Name" << setw(10) << "Quantity" << endl;
						cout << setw(5) << vD.getCode() << setw(10) << vD.getName() << setw(10) << vD.getQuantity() << endl;
					}
				}
				if (!findVaccine) {
					cout << "Can't find vaccine, please enter correct vaccine code" << endl;
				}
			}
		} while (userInput != "exit");
	}
	else {
		cout << "\nSearch vaccine and its available quantity by using vaccine code" << endl;
		cout << "Inventory is empty" << endl;
	}
}
void produceList() {
	vector<string> codeList;
	vector<double> quantityList;
	cout << "\nProduce a list of all vaccines and their distributed quantities" << endl;
	ifstream openDistFile("dist.txt");
	if (!openDistFile.fail()) {
		string eachLine;
		while (getline(openDistFile, eachLine))
		{
			if (codeList.size() == 0) {
				codeList.push_back(eachLine);
				getline(openDistFile, eachLine);
				quantityList.push_back(stod(eachLine));
			}
			else
			{
				bool findCode = false;
				for (int loop = 0; loop < codeList.size(); loop++) {
					if (codeList.at(loop) == eachLine) {
						findCode = true;
						getline(openDistFile, eachLine);
						quantityList.at(loop) += stod(eachLine);
					}
				}
				if (!findCode) {
					codeList.push_back(eachLine);
					getline(openDistFile, eachLine);
					quantityList.push_back(stod(eachLine));
				}
			}
		}
		string* codeArray = new string[codeList.size()];
		double* quantityArray = new double[codeList.size()];
		for (int loop = 0; loop < codeList.size(); loop++) {
			codeArray[loop] = codeList.at(loop);
			quantityArray[loop] = quantityList.at(loop);
		}
		bubbleSort(codeArray, quantityArray, codeList.size());
		cout << setw(5) << "Code" << setw(25) << "Accumulated quantities" << endl;
		for (int loop = 0; loop < codeList.size(); loop++) {
			cout << setw(5) << codeArray[loop] << setw(25) << quantityArray[loop] << endl;
		}
	}
}

int main() {
	int userInput = 0;
	ifstream openDistFile("dist.txt");
	if (!openDistFile.fail()) {
		string eachLine;
		int lineCount = 0;
		while (getline(openDistFile, eachLine))
		{
			getline(openDistFile, eachLine);
			lineCount++;
		}
		if (lineCount < 10) {
			ofstream writeDistFile("dist.txt", ios::app);
			for (int loop = lineCount; loop < 10; loop++) {
				writeDistFile << "PF" << endl;
				writeDistFile << "0.01" << endl;
			}
			writeDistFile.close();
		}
	}
	else
	{
		ofstream writeDistFile("dist.txt", ios::app);
		for (int loop = 0; loop < 10; loop++) {
			writeDistFile << "PF" << endl;
			writeDistFile << "0.01" << endl;
		}
		writeDistFile.close();
	}
	openDistFile.close();
	do {
		cout << "\nVACCINE INVENTORY MANAGEMENT SYSTEM" << endl;
		cout << "1. Inventory Creation" << endl;
		cout << "2. Update vaccine quantities" << endl;
		cout << "3. Search vaccine and its available quantity by using vaccine code" << endl;
		cout << "4. Produce a list of all vaccines and their distributed quantities" << endl;
		cout << "0. Exit" << endl;
		do {
			userInput = getInput<int>("Enter the number of function you want to access: ");
			if (!((userInput >= 0) && (userInput <= 4)))
				cout << "Input was not correct" << endl;
		} while (!((userInput >= 0) && (userInput <= 4)));
		switch (userInput)
		{
		case 1:
			inventoryCreation();
			break;
		case 2:
			updateVaccineQuantities();
			break;
		case 3:
			searchVaccine();
			break;
		case 4:
			produceList();
			break;
		default:
			break;
		}
	} while (userInput != 0);
	return 0;
}