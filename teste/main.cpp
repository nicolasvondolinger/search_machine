#include <string>
#include <cctype>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iostream>

using namespace std;


string normalizeWord(string word) {
    std::string normalized = "";

    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        if (isalpha(c)) {
            normalized += tolower(c);
        }
    }

    return normalized;
}

void readFile() {
    for (const auto arquivo : filesystem::directory_iterator("./documentos/")) {
        if (arquivo.is_regular_file()) {
            ifstream arquivoEntrada(arquivo.path());
            if (arquivoEntrada) {
                string linha;
                while (getline(arquivoEntrada, linha)) {
                    istringstream iss(linha);
                    string palavra;
                    while (iss >> palavra) {
                        string newWord = normalizeWord(palavra);
                        cout << newWord << endl;
                    }
                }
                arquivoEntrada.close();
            }
        }
    }
}


int main() {


    readFile();

    return 0;
}