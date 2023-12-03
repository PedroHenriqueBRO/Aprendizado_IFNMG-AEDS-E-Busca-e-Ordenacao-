
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits>
#include <climits>

#include <cctype>  // Para a função tolower

using namespace std;

const int ALFABETO_TAMANHO = 26;

class TrieNode {
public:
    TrieNode* filhos[ALFABETO_TAMANHO];
    bool fimDaPalavra;

    TrieNode() : fimDaPalavra(false) {
        for (int i = 0; i < ALFABETO_TAMANHO; ++i) {
            filhos[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* raiz;

public:
    Trie() : raiz(new TrieNode()) {}

    int indice(char ch) const {
        // Converte o caractere para minúscula antes de calcular o índice
        return tolower(ch) - 'a';
    }

    void insere(const string& palavra) {
        TrieNode* atual = raiz;

        for (char ch : palavra) {
            int index = indice(ch);
            if (index < 0 || index >= ALFABETO_TAMANHO) {
                // Caractere fora do intervalo
                cerr << "Erro: Caractere fora do intervalo." << endl;
                return;
            }
            if (!atual->filhos[index]) {
                atual->filhos[index] = new TrieNode();
            }
            atual = atual->filhos[index];
        }

        atual->fimDaPalavra = true;
    }

    bool pesquisa(const string& palavra) const {
        TrieNode* atual = raiz;

        for (char ch : palavra) {
            int index = indice(ch);
            if (index < 0 || index >= ALFABETO_TAMANHO) {
                // Caractere fora do intervalo
                cerr << "Erro: Caractere fora do intervalo." << endl;
                return false;
            }
            if (!atual->filhos[index]) {
                return false;
            }
            atual = atual->filhos[index];
        }

        return atual->fimDaPalavra;
    }

    void insereDoArquivo(const string& arquivo) {
        ifstream arquivoStream(arquivo);
        string palavra;

        if (arquivoStream.is_open()) {
            while (arquivoStream >> palavra) {
                insere(palavra);
            }
            arquivoStream.close();
            cout << "Palavras do arquivo inseridas com sucesso." << endl;
        } else {
            cerr << "Erro ao abrir o arquivo '" << arquivo << "'." << endl;
        }
    }
    };
    