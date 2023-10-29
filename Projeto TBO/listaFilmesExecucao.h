#ifndef FILMESEXIBICAO_H_INCLUDED
#define FILMESEXIBICAO_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>

class NoFilme {
public:
  string idFilme;
  NoFilme *proximo;
  NoFilme *anterior;
};

class listaFilmeExibicao {
private:
  NoFilme *primeiro;
  NoFilme *ultimo;
  int tamanhoDaLista = 0;

public:


  listaFilmeExibicao() : primeiro(nullptr), ultimo(nullptr){};

  int getTamanhoDaLista() { return tamanhoDaLista; }
  NoFilme* getPrimeiro() { return primeiro; };


  bool insereFilme(string idFilme) {
    NoFilme *novoNo = new NoFilme();
    novoNo->idFilme = idFilme;
    novoNo->proximo = nullptr;

    if (!primeiro) {
      novoNo->anterior = nullptr;
      primeiro = novoNo;
    } else {
      novoNo->anterior = ultimo;
      ultimo->proximo = novoNo;
    }

    ultimo = novoNo;
    tamanhoDaLista++;
    return true;
  }

  bool removeFilme(string idFilme) {
    NoFilme *atual = primeiro;
    while (atual) {
      if (atual->idFilme ==
          idFilme) { // Encontrou o nó com o ID do filme a ser removido

        if (atual ==
            primeiro) { // Caso o nó a ser removido seja o primeiro da lista

          primeiro = atual->proximo;
          if (primeiro) {
            primeiro->anterior = nullptr;
          } else { // Se a lista ficar vazia após a remoção
            ultimo = nullptr;
          }
        } else if (atual ==
                   ultimo) { // Caso o nó a ser removido seja o último da lista

          ultimo = atual->anterior;
          ultimo->proximo = nullptr;
        } else { // O nó a ser removido está no meio da lista

          atual->anterior->proximo = atual->proximo;
          atual->proximo->anterior = atual->anterior;
        }

        delete atual; // Libera a memória alocada para o nó
        tamanhoDaLista--;
        return true;
      }
      atual = atual->proximo;
    }

    // Se não encontrou o filme com o ID especificado
    return false;
  }
  void imprimeLista() {
    NoFilme *atual = primeiro;
    while (atual) {
      cout << atual->idFilme << (atual->proximo ? ", " : "");
      atual = atual->proximo;
    }
  }
};
#endif // FILMESEXIBICAO_H_INCLUDED
