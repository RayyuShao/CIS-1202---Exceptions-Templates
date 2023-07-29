// Raymond Shao
// CIS 1202 800
// July 28, 2023

#include <iostream>
using namespace std;

// custom exception structs
struct InvalidCharacterException : public exception {
    const char* what() const noexcept override {
        return "Invalid character. Only A-Z and a-z are allowed.";
    }
};

struct InvalidRangeException : public exception {
    const char* what() const noexcept override {
        return "Invalid offset. Only positive and negative offsets within the range of A-Z and a-z are allowed.";
    }
};

// function to calculate character offsets
char character(char start, int offset) {
    // check if the start character is a letter (A-Z or a-z)
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {
        throw InvalidCharacterException();
    }

    // check if the offset is within the range of A-Z and a-z
    if ((start + offset < 'A' || start + offset > 'Z') && (start + offset < 'a' || start + offset > 'z')) {
        throw InvalidRangeException();
    }

    // calculate and return the character after applying the offset
    return start + offset;
}

int main() {
    try {
        cout << "character('a', 1) returns: " << character('a', 1) << endl;
        cout << "character('a', -1) should throw an InvalidRangeException." /* << character('a', -1)*/ << endl; //uncomment to see error
        cout << "character('Z', -1) returns: " << character('Z', -1) << endl;
        cout << "character('?', 5) should throw an InvalidCharacterException." /* << character('?', 5) */ << endl; //uncomment to see error
        cout << "character('A', 32) should throw an exception." /*<< character('A', 32)*/ << endl; //uncomment to see error
    }
    catch (const InvalidCharacterException& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }
    catch (const InvalidRangeException& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Unknown exception caught." << endl;
    }

    return 0;
}