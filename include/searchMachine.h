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
    void buildIndex();
    
    // Subsistema de recuperação
    vector<string> search(string);

    private:
    // Normaliza as palavras (coloca por padrao todas minúsculas)
    string normalizeWord(string word);

    // Indice invertido
    map<string, map<string, int>> invertedIndex_;

    // caminho de /documentos
    string documentsPath_;
};

#endif