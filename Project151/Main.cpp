#include <iostream>
#include <fstream>
#include "ExpressionsValidity.h"

using namespace std;

const int MAX_EXPRESSIONS = 100; 

int main() {
    ifstream file("Expressions.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "\n**************" << endl;
    cout << "        EXPRESSIONS IN THE TEXT FILE      " << endl;
    cout << "**************" << endl;

    string expressions[MAX_EXPRESSIONS];  
    string expression;
    int lineNumber = 0;

    // Read expressions from the file
    while (getline(file, expression) && lineNumber < MAX_EXPRESSIONS) {
        cout << lineNumber + 1 << ": " << expression << endl;
        expressions[lineNumber] = expression; 
        lineNumber++;
    }
    file.close();

    cout << "\n========================================" << endl;
    cout << "         EXPRESSIONS VALIDITY CHECK      " << endl;
    cout << "========================================" << endl;

    while (true) {
        string input;
        cout << "\nEnter the line number to check (or 'q' to quit): ";
        cin >> input;

        if (input == "q" || input == "Q") {
            cout << "\n========================================" << endl;
            cout << "       PROGRAM HAS ENDED. GOODBYE!       " << endl;
            cout << "\n========================================" << endl;
            break;
        }

        try {
            int selectedLine = stoi(input);

            if (selectedLine < 1 || selectedLine > lineNumber) {
                cerr << "Invalid line number!" << endl;
                continue;
            }

            cout << "\n========================================" << endl;
            cout << "     RESULT FOR SELECTED EXPRESSION     " << endl;
            cout << "========================================" << endl;

            if (isValidExpression(expressions[selectedLine - 1])) {
                cout << "   The expression is VALID." << endl;
            }
            else {
                cout << "   The expression is INVALID." << endl;
            }

        }
        catch (invalid_argument&) {
            cout << "Invalid input! Please enter a valid line number or 'q' to quit." << endl;
        }
    }

    return 0;
}
