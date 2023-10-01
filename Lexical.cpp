// Lexical.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctype.h>

using namespace std;

int isKeyword(char buffer[]) {
	char keywords[51][51] = { "switch","typedef","union",
							"unsigned","void","register","short","signed",
							"sizeof","static","volatile","while""auto","break","case","char","const","continue","default",
							"do","double","enum","extern","return","struct","float","for","goto",
							"if","int","else","cin","cout","include","string","bool","asm","new","operator","private","template"
							"this","throw","public","catch","public","try","class","friend","inline","virtual","delete","long"};
	int i, inputCode_Flag = 0;

	for (i = 0; i < 51; ++i) {
		if (strcmp(keywords[i], buffer) == 0) {
			inputCode_Flag = 1;
			break;
		}
	}
	return inputCode_Flag;
}

int main() {
	char ch, buffer[15], operators[] = "+-*/%=";
	ifstream fin("Nicholas L5AC.cpp");
	int i, j = 0;
	int keywordCount = 0;
	int identifierCount = 0;
	int operatorsCount = 0;
	if (!fin.is_open()) {
		cout << "File open iz not work" << endl; 
		exit(0); 
	}
	
	while (!fin.eof()) {
		ch = fin.get();

		for (i = 0; i < 6; ++i) {
			if (ch == operators[i]) {
				++operatorsCount;
				cout << ch << " : operator" << endl;
			}
		}
		if (isalnum(ch)) {
			buffer[j++] = ch;
		}
		else if ((ch == ' ' || ch == '\n') && (j != 0)) {
			buffer[j] = '\0';
			j = 0;

			if (isKeyword(buffer) == 1) {
				++keywordCount;
				cout << buffer << ": is keyword" << endl;
			}
			else {
				++identifierCount;
				cout << buffer << ": is identifier" << endl;
			}
		}
	}
	cout << endl;
	cout << "number of keywords: " << keywordCount << endl;
	cout << "number of identifiers: " << identifierCount << endl;
	cout << "number of operators: " << operatorsCount << endl;
	fin.close();

	return 0;
}	