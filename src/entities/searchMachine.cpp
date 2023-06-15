#include "../../contract/searchMachine.h"
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
    documentsPath_ = "./documentos";
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

vector<string> SearchMachine::search(string input) {
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
    // Percorre cada palavra da consulta
    for (auto it = words.begin(); it != words.end(); it++) {
        // Consulta o índice invertido para obter os documentos que contêm a palavra
        if (invertedIndex_.find(*it) != invertedIndex_.end()) {
            map<string, int> wordOccurrences = invertedIndex_[*it];
            // Atualiza o contador de ocorrências de cada documento
            for (auto entry = wordOccurrences.begin(); entry != wordOccurrences.end(); ++entry) {
                documentOccurrences[entry->first]++;
            }
        } else {
            // Se alguma palavra não for encontrada no índice, retorna uma lista vazia
            return vector<string>();
        }
    }

    vector<string> relevantDocuments;
    for (auto entry = documentOccurrences.begin(); entry != documentOccurrences.end(); entry++) {
        if (entry->second == words.size()) {
            relevantDocuments.push_back(entry->first);
        }
    }

    return relevantDocuments;
}


int main() {
    SearchMachine search;
    search.readFile();

    std::string query;
    std::cout << "Digite a consulta: ";
    std::getline(std::cin, query);

    std::vector<std::string> relevantDocuments = search.search(query);

    if (relevantDocuments.empty()) {
        std::cout << "Nenhum documento relevante encontrado." << std::endl;
    } else {
        std::cout << "Documentos relevantes:" << std::endl;
        for (const std::string& document : relevantDocuments) {
            std::cout << document << std::endl;
        }
    }

    return 0;
}
