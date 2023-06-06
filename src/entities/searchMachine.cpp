#include "../../include/searchMachine.h"
#include <string>
#include <cctype>
#include <iostream>
#include <dirent.h>
#include <fstream>


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

void SearchMachine::readFile() {
    
}


void SearchMachine::buildIndex() {

}


int main(){
    return 0;
}