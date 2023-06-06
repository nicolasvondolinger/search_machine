#include <string>
#include <cctype>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

map<string, map<string, int>> buildIndex(string newWord, string arquivo, map<string, map<string, int>> invertedIndex_){
    invertedIndex_[newWord][arquivo]++;
    return invertedIndex_;
}


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

map<string, map<string, int>> readFile() {
    map<string, map<string, int>> invertedIndex_;
    for (const auto arquivo : filesystem::directory_iterator("./documentos/")) {
        if (arquivo.is_regular_file()) {
            ifstream arquivoEntrada(arquivo.path());
            if (arquivoEntrada) {
                string linha;
                while (getline(arquivoEntrada, linha)) {
                    istringstream iss(linha);
                    string palavra;
                    while (iss >> palavra) {
                        string fileName = arquivo.path().stem();
                        string newWord = normalizeWord(palavra);
                        invertedIndex_ = buildIndex(newWord, fileName, invertedIndex_);
                    }
                }
                arquivoEntrada.close();
            }
        }
    }
    return invertedIndex_;
}


string final (map<string, int> mapaInterno) {
    string final  = "(";
    for(auto it = mapaInterno.begin(); it != mapaInterno.end(); it++) {
        final += it -> first;
        int frequencia = it -> second;
        final += ", " + to_string(frequencia);
        if(it++ == mapaInterno.end()){
            final += ")";
            break;
        }
        final += "), (";
    }

    return final;
}


int main() {


    readFile();

    map<string, map<string, int>> invertedIndex_ = readFile();

    for(auto it = invertedIndex_.begin(); it != invertedIndex_.end(); it++) {
        string palavra = it -> first;
        map<string, int> mapaInterno = it->second;
        for(auto it2 = mapaInterno.begin(); it2 != mapaInterno.end(); it2++) {
            string arquivo = it2 -> first;
            int frequencia = it2 -> second;
            string valor = final(mapaInterno);
            cout << palavra << " " << valor << endl;
            break;
        }
    }


    return 0;
}