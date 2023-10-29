#ifndef LISTAGENERO_H_INCLUDED
#define LISTAGENERO_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>

class NoGenero {
public:
  string genero;
  NoGenero *proximo;
  NoGenero *anterior;
};

class listaGenero {
private:
  NoGenero *primeiro;
  NoGenero *ultimo;
  int tamanhoDaLista = 0;

public:
  listaGenero() : primeiro(nullptr), ultimo(nullptr){};

  int getTamanhoDaLista() { return tamanhoDaLista; }

  bool insereGenero(string genero) {
    NoGenero *novoNo = new NoGenero();
    novoNo->genero = genero;
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

  bool removeGenero(string genero) {
    NoGenero *atual = primeiro;
    while (atual) {
      if (atual->genero ==
          genero) { // Encontrou o nó com o ID do filme a ser removido

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
    NoGenero *atual = primeiro;
    while (atual) {
      cout << atual->genero << (atual->proximo ? ", " : "");
      atual = atual->proximo;
    }
  }
};
#endif // LISTAGENERO_H_INCLUDED
