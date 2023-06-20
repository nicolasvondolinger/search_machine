#include "../../include/searchMachine.h"
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

SearchMachine::SearchMachine() {
    documentsPath_ = "./src/documentos";
}

string SearchMachine::normalizeWord(string word) {
    std::string normalized = "";

    for (char c : word) {
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
                        string newWord = normalizeWord(palavra);
                        invertedIndex_ = buildIndex(newWord, fileName);
                    }
                }
                arquivoEntrada.close();
            }
        }
    }
}

vector<pair<string, int>> SearchMachine::search(string input) {
    // Normaliza as palavras da consulta
    istringstream iss(input);
    vector<string> words;
    string word;
    while (iss >> word) {
        string normalizedWord = normalizeWord(word);
        words.push_back(normalizedWord);
    }

    // Mapa para armazenar o número de ocorrências de cada documento relevante
    map<string, int> documentOccurrences;
    map<string, int> wordOccurrences;
    // Percorre cada palavra da consulta
    for (auto it = words.begin(); it != words.end(); it++) {
        // Consulta o índice invertido para obter os documentos que contêm a palavra
        if (invertedIndex_.find(*it) != invertedIndex_.end()) {
            wordOccurrences = invertedIndex_[*it];
            // Atualiza o contador de ocorrências de cada documento
            for (auto entry = wordOccurrences.begin(); entry != wordOccurrences.end(); ++entry) {
                documentOccurrences[entry->first]++;
            }
        } else {
            // Se alguma palavra não for encontrada no índice, retorna um vetor vazio
            return vector<pair<string, int>>();
        }
    }

    vector<pair<string, int>> relevantDocuments;
    string key;
    for (auto entry = documentOccurrences.begin(); entry != documentOccurrences.end(); entry++) {
        if (entry->second == words.size()) {
            key = entry->first;
            auto valueIterator = wordOccurrences.find(key);
            if (valueIterator != wordOccurrences.end()) {
                int value = valueIterator->second;
                relevantDocuments.emplace_back(key, value);
            }
        }
    }

    // Ordenar o vetor com base nos valores em ordem decrescente
    sort(relevantDocuments.begin(), relevantDocuments.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             if(a.second != b.second){
                return a.second > b.second;
         }else{
                return a.first > b.first; 
         }
         });



    return relevantDocuments;
}
