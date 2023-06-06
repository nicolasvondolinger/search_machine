#include "../../include/searchMachine.h"
#include <string>
#include <cctype>
#include <fstream>
#include <filesystem>
#include <sstream>


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
    for (const auto arquivo : filesystem::directory_iterator(documentsPath_)) {
        if (arquivo.is_regular_file()) {
            ifstream arquivoEntrada(arquivo.path());
            if (arquivoEntrada) {
                string linha;
                while (getline(arquivoEntrada, linha)) {
                    istringstream iss(linha);
                    string palavra;
                    while (iss >> palavra) {
                        string newWord = normalizeWord(palavra);
                    }
                }
                arquivoEntrada.close();
            }
        }
    }
}


void SearchMachine::buildIndex() {

}
