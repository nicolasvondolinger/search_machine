#include "../include/searchMachine.h"
#include "entities/searchMachine.cpp" // Inclua o arquivo de implementação aqui

int main() {
    SearchMachine search;
    search.readFile();

    std::string query;
    std::cout << "Digite a consulta: ";
    std::getline(std::cin, query);

    std::vector<std::pair<std::string, int>> relevantDocumentsPairs = search.search(query);
    std::vector<std::string> relevantDocuments;

    // Extrair apenas as strings relevantes do vetor de pares
    for (const auto& pair : relevantDocumentsPairs) {
        relevantDocuments.push_back(pair.first);
    }

    if (relevantDocuments.empty()) {
        std::cout << "Nenhum documento relevante encontrado." << std::endl;
    } else {
        std::cout << "Documentos relevantes:" << std::endl;
        int i=1;
        for (const std::string& document : relevantDocuments) {
            std::cout << i << "°: " << document << ".txt" << std::endl;
            i++;
        }
    }

    return 0;
}
