#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool isPunctuation(char c) {
    string punctuationMarks = ".,:;!?";
    return punctuationMarks.find(c) != string::npos;
}

string replaceWord(const string& line, const string& wordToReplace, const string& replacement) {
    stringstream ss(line);
    string token;
    string modifiedLine;

    while (ss >> token) {
        string modifiedToken = token;

        if (modifiedToken.size() == wordToReplace.size() &&
            equal(wordToReplace.begin(), wordToReplace.end(), modifiedToken.begin(), [](char a, char b) {
                return tolower(a) == tolower(b);
                })) {
            if ((ss.eof() || ss.peek() == ' ' || isPunctuation(ss.peek())) &&
                (modifiedToken == token || isPunctuation(token.back()))) {
                modifiedToken = replacement;
            }
        }

        modifiedLine += modifiedToken + " ";
    }

    return modifiedLine;
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";
    string wordToReplace;
    string replacement;
    string inputText;

    cout << "Enter the text to process: ";
    getline(cin, inputText);

    cout << "Enter the word to replace: ";
    cin >> wordToReplace;
    cout << "Enter the replacement word: ";
    cin >> replacement;

    ofstream input(inputFile);
    if (!input) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    input << inputText;
    input.close();

    ofstream output(outputFile);
    if (!output) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    ifstream inputFileStream(inputFile);
    if (!inputFileStream) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFileStream, line)) {
        string modifiedLine = replaceWord(line, wordToReplace, replacement);
        output << modifiedLine << endl;
    }

    inputFileStream.close();
    output.close();

    cout << "Word replacement complete. Output written to " << outputFile << endl;

    return 0;
}
