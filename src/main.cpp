#include "../include/searchMachine.h"
#include "entities/searchMachine.cpp" // Inclua o arquivo de implementação aqui

int main() {
    SearchMachine search;
    search.readFile();

    std::string query;
    std::cout << "Digite a consulta: ";
    std::getline(std::cin, query);
    cout << endl;


    std::vector<pair<std::string, int>> relevantDocuments = search.search(query);

    if (relevantDocuments.empty()) {
    cout << "Nenhum documento relevante encontrado." << std::endl;
    } else {
    cout << "Documentos Relevantes:" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < relevantDocuments.size(); i++) {
    cout << i+1 << "º " << ": " <<relevantDocuments[i].first << ".txt" << endl;
    }
    cout << "--------------------------------------------------------" << endl;
    }

    return 0;
}