# Search Machine - Trabalho Prático 2023.1

## Projeto de Implementação de uma Máquina de Busca

Este projeto consiste na implementação de uma Máquina de Busca, que realiza a indexação e recuperação de documentos. A Máquina de Busca recebe uma expressão de busca como entrada e retorna os documentos mais relevantes para a consulta fornecida.

## Subsistemas

O projeto é dividido em três subsistemas: Coleta, Indexação e Recuperação. A fase de coleta já foi realizada, e todos os documentos de interesse estão armazenados na pasta `./documentos/`. Portanto, os alunos devem implementar apenas os subsistemas de Indexação e Recuperação.

### Indexação

A indexação consiste em processar os documentos coletados e construir um Índice Invertido. O Índice Invertido mapeia cada palavra às suas respectivas ocorrências nos documentos. A implementação do Índice Invertido pode ser feita utilizando a estrutura de dados `map<string, map<string, int>>` em C++. Cada palavra será normalizada antes de ser inserida no índice, removendo caracteres não alfabéticos e convertendo as letras para minúsculas.

Exemplo de Índice Invertido resultante:

Chave Valor
apartamento (d1.txt, 1), (d3.txt, 1)
casa (d1.txt, 2), (d2.txt, 1)
em (d2.txt, 1)
entrar (d2.txt, 1)
esta (d3.txt, 1)
ninguem (d1.txt, 1), (d2.txt, 1), (d3.txt, 1)
todos (d2.txt, 2), (d3.txt, 1)
no (d3.txt, 1)
porem (d1.txt, 1)
quem (d1.txt, 1), (d2.txt, 2), (d3.txt, 1)
quer (d1.txt, 2), (d2.txt, 1)
sairam (d2.txt, 1), (d3.txt, 1)
tambem (d1.txt, 2), (d2.txt, 1)


### Recuperação

O subsistema de recuperação é responsável por retornar os documentos mais relevantes para uma determinada consulta. A consulta consiste em um conjunto de palavras, e os documentos retornados devem conter todas as palavras da consulta. Os documentos são ordenados de acordo com a relevância, priorizando aqueles com um número maior de hits. Em caso de empate, a ordem é determinada pelo nome do arquivo em ordem lexicográfica.

## Instruções de Execução

Siga as instruções abaixo para executar o projeto em uma máquina Linux, de preferência Ubuntu:

1. Instalação do compilador:
   - Certifique-se de ter o compilador C++ instalado. Caso contrário, abra um terminal e execute o seguinte comando para instalar o compilador GCC:

     ```
     $ sudo apt update
     $ sudo apt install build-essential
     ```

2. Navegação até a pasta do projeto:
   - Abra um terminal.
   - Utilize o comando `cd` seguido do caminho para a pasta do projeto. Por exemplo:

     ```
     $ cd /caminho/para/o/projeto
     ```

3. Compilação do código:
   - No terminal, execute o seguinte comando para compilar o código-fonte do projeto:

     ```
     $ g++ main.cpp -o search_engine
     ```

4. Execução do projeto:
   - Após a compilação bem-sucedida, execute o projeto com o seguinte comando:

     ```
     $ ./search_engine
     ```

5. Consultas:
   - Após a execução do projeto, digite as consultas desejadas na linha de comando, separando as palavras por espaços.
   - Os documentos mais relevantes para a consulta serão exibidos na saída padrão, um por linha, em ordem de relevância.

Certifique-se de que a pasta `./documentos/` contém os documentos de interesse antes de executar o projeto.
