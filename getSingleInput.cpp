#include<iostream>
using namespace std;

int GetIntInput(const char* INPUT_PROMPT,const char* ERROR_STRING) {

	int MAX_LENGTH = 256;
	int input;

	bool failure;
	do {
		failure = false;
		cout << INPUT_PROMPT << endl;
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(MAX_LENGTH, '\n');
			cout << ERROR_STRING << endl;
			failure = true;
		}
	} while (failure);

	return input;
}

char GetCharInput(const char* INPUT_PROMPT, const char* ERROR_STRING) {

	int MAX_LENGTH = 256;
	char input;

	bool failure;
	do {
		failure = false;
		cout << INPUT_PROMPT << endl;
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(MAX_LENGTH, '\n');
			cout << ERROR_STRING << endl;
			failure = true;
		}
	} while (failure);

	return input;
}