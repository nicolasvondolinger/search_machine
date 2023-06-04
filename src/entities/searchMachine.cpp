#include "searchMachine.h"
#include <string>
#include <cctype>

using namespace std;

SearchMachine::SearchMachine(string documentsPath) {
    documentsPath_ = documentsPath;
}

string SearchMachine::normalizeWord(string word) {
    std::string normalized = "";

    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        if (isalpha(c)) {
            normalized += c;
        }
    }

    for (int i = 0; i < normalized.length(); i++) {
        normalized[i] = tolower(normalized[i]);
    }

    return normalized;
}
