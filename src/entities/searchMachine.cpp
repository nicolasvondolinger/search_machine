#include "../../include/searchMachine.h"
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

SearchMachine::SearchMachine() {
    documentsPath_ = "./documentos/";
}

string SearchMachine::normalizeWord(string word) {
    std::string normalized = "";

    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        if (isalpha(c)) {
            normalized += tolower(c);
        }
    }

    return normalized;
}

string normalizedWord(string word){
    std::string normalized = "";

    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        if (isalpha(c)) {
            normalized += tolower(c);
        }
    }

    return normalized;
}



int main(){
    return 0;
}