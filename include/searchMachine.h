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
    // Retorna um vetor de strings com os nomes dos arquivos que contém todas as palavras em ordem decrescente de frequência
    vector<string> search(string words);

    private:
    // Normaliza as palavras (coloca por padrao todas minúsculas)
    string normalizeWord(string word);

    // Separa as palavras de uma string em um vetor de strings
    void split(string str);

    // Indice invertido
    map<string, map<string, int>> invertedIndex_;

    // caminho de /documentos
    string documentsPath_;

    // vetor de palavras para pesquisa
    vector<string> words_;
};

#endif