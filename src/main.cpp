#include "../include/searchMachine.h"
#include "entities/searchMachine.cpp" // Inclua o arquivo de implementação aqui

int main() {
    try {
    SearchMachine search;
    string wordsToSearch;

    search.readFile();

    cout << "Digite as palavras que deseja pesquisar: " << endl;
    cin >> wordsToSearch;


    for(auto i : search.search(wordsToSearch)){
        cout << i << ".txt" << endl;
    }
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}
