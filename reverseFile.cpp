#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void reverseFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile || !outFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    reverse(content.begin(), content.end());
    outFile << content;

    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "CSC450_CT5_mod5.txt";
    string outputFile = "CSC450_mod5_reverse.txt";
    string userInput;

    cout << "Enter text to append to the file: ";
    getline(cin, userInput);

    ofstream outFile(inputFile, ios::app); // append mode
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile << userInput << endl;
    outFile.close();

    reverseFile(inputFile, outputFile);

    cout << "Data appended and file reversed successfully." << endl;
    return 0;
}