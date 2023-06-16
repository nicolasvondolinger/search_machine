#ifndef searchMachine
#define searchMachine

#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::string;
using std::map;
using std::vector;

class SearchMachine {
    public:
    // Construtor da Classe;
    SearchMachine();

    // Lê os arquivos
    void readFile();

    // Subsistema de indexação
    map<string, map<string, int>> buildIndex(string newWord, string arquivo);
    
    // Subsistema de recuperação
    vector<std::pair<string,int>> search(string words);

    private:
    // Normaliza as palavras (coloca por padrao todas minúsculas)
    string normalizeWord(string word);

    // Indice invertido
    map<string, map<string, int>> invertedIndex_;

    // caminho de /documentos
    string documentsPath_;
};

#endif