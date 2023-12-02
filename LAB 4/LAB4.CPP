#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main() {
    // Open the source CPP file
    ifstream sourceFile("myFile.cpp");

    // Check if the file is open
    if (!sourceFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Read the contents of the file
    string content((istreambuf_iterator<char>(sourceFile)),
                   (istreambuf_iterator<char>()));

    // Close the source file
    sourceFile.close();

    // Define a regular expression to match function declarations
    regex functionRegex("\\b\\w+\\s+\\w+\\s*\\([^)]*\\)\\s*\\{");
    // Use regex iterator to find matches
    sregex_iterator next(content.begin(), content.end(), functionRegex);
    sregex_iterator end;

    // Counter for user-defined functions
    int functionCount = 0;

    // Print and count matched function declarations
    while (next != end) {
        smatch match = *next;
        if (match.str() != "int main(){") {
            cout << "Found function #" << ++functionCount << ": " << match.str() << endl;
        }        ++next;
    }

    cout << "Total user-defined functions found: " << functionCount << endl;

    return 0;
}
