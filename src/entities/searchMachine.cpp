#include "../../include/searchMachine.h"
#include <string>
#include <cctype>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <map>
#include <algorithm> 

using namespace std;

SearchMachine::SearchMachine() {
    documentsPath_ = "../documentos/";
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

map<string, map<string, int>> SearchMachine::buildIndex(string newWord, string arquivo){
    invertedIndex_[newWord][arquivo]++;
    return invertedIndex_;
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
                        string fileName = arquivo.path().stem();
                        fileName += ".txt";
                        string newWord = normalizeWord(palavra);
                        invertedIndex_ = buildIndex(newWord, fileName);
                    }
                }
                arquivoEntrada.close();
            }
        }
    }
}

void SearchMachine::search(vector<string> words) {
    // Normalizando as palavras recebidas
    for (int i = 0; i < words.size(); i++) {
       string newWord = normalizeWord(words[i]);
       words[i] = newWord;
    }
    
    // Comparando com as palavras do mapa e armazenando as correspondências
    map<string, int> searchMap;
    for (auto pair = invertedIndex_.begin(); pair != invertedIndex_.end(); pair++) {
        const std::map<std::string, int>& archives = pair->second; 
        bool allWordsPresent = true;
        
        for (const string& word : words) {
            if (archives.find(word) == archives.end()) {
                allWordsPresent = false;
                break;
            }
        }
        
        if (allWordsPresent) {
            for (const auto& inner_pair : archives) {
                searchMap[inner_pair.first] += inner_pair.second;
            }
        }
    }
    
    // Ordenando e imprimindo os arquivos pela frequência (maior para menor)
    vector<pair<string, int>> sortedFiles(searchMap.begin(), searchMap.end());
    sort(sortedFiles.begin(), sortedFiles.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    
    for (const auto& file : sortedFiles) {
        cout << "Arquivo: " << file.first << ", Frequência: " << file.second << endl;
    }
}


    
 
    