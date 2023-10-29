#ifndef LISTACINEMA_H_INCLUDED
#define LISTACINEMA_H_INCLUDED

#include "listaFilmes.h"
#include "listaFilmesExecucao.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct cinema {
  string cinema_id, nome_do_cinema;
  double coordenada_x, coordenada_y;
  float preco_ingresso;
  listaFilmeExibicao filmes_exibicao;
} Cinema;

typedef struct coordenada {
  double x, y;
} Coordenada;

class listaCinema {
private:
  vector<Cinema> cinemas; 

public:
  /* Métodos primários */
  int getTamanhoDaLista() { return cinemas.size(); }

  vector<Cinema> getListaCinemas(){ return cinemas;}
  
  void insereCinema(Cinema cine) {
    cinemas.push_back(cine);
  }
  
  void lerArquivo(string nome_arquivo) {
    ifstream arquivo(nome_arquivo);

    if (!arquivo.is_open()) {
      cout << "ListaCinema: Não foi possível abrir o arquivo" << endl;
      return;
    }

    string linha;
    getline(arquivo, linha);

    while (getline(arquivo, linha)) {
      Cinema cine;
      listaFilmeExibicao filmesExibicao;

      size_t pos = 0;
      string token;
      int coluna = 0;
      while ((pos = linha.find(',')) != string::npos) {
        token = linha.substr(0, pos);
        linha.erase(0, pos + 1);

        switch (coluna) {
        case 0:
          cine.cinema_id = token;
          break;
        case 1:
          cine.nome_do_cinema = token;
          break;
        case 2:
          cine.coordenada_x = stod(token);
          break;
        case 3:
          cine.coordenada_y = stod(token);
          break;
        case 4:
          cine.preco_ingresso = stof(token);
          break;
        default:
          filmesExibicao.insereFilme(token);
          break;
        }

        coluna++;
      }

      // Trate o último valor da linha
      switch (coluna) {
      case 0:
        cine.cinema_id = linha;
        break;
      case 1:
        cine.nome_do_cinema = linha;
        break;
      case 2:
        cine.coordenada_x = stod(linha);
        break;
      case 3:
        cine.coordenada_y = stod(linha);
        break;
      case 4:
        cine.preco_ingresso = stof(linha);
        break;
      default:
        filmesExibicao.insereFilme(linha);
        break;
      }

      cine.filmes_exibicao = filmesExibicao;
      insereCinema(cine);
    }

    arquivo.close();
  }

  /* Demais métodos */

  
  void imprimeDistancia(Coordenada posAtual, double distanciaMax) {
    vector<Cinema> cinemasFiltrados;
    for (const Cinema& cine : cinemas) {
      double distancia = distanciaPontos(posAtual, {cine.coordenada_x, cine.coordenada_y});
      if (distancia <= distanciaMax) {
        cinemasFiltrados.push_back(cine);
      }
    }

    for (const Cinema& cine : cinemasFiltrados) {
      
      cout << "Cinema ID: " << cine.cinema_id << endl;
      cout << "Nome do Cinema:" << cine.nome_do_cinema << endl;
      cout << "Coordenada X: " << cine.coordenada_x << endl;
      cout << "Coordenada Y: " << cine.coordenada_y << endl;
      cout << "Preco do Ingresso: " << cine.preco_ingresso << endl;

      cout << "Distancia da Posicao Atual: " << distanciaPontos(posAtual, {cine.coordenada_x, cine.coordenada_y}) << endl;

      cout << "Filmes em Exibicao:";
      listaFilmeExibicao filmeList = cine.filmes_exibicao;
      filmeList.imprimeLista();

      cout << endl;
      cout << endl;
    }
  }

  int imprimeCinemaPorAno(int anoInicial, int anoFinal) {
    int contador = 1;
    int qntdFilmesEncontrados = 0;
    Filmes listaFilmesGeral;
    

    if (anoInicial > anoFinal) {
      int aux = anoInicial;
      anoInicial = anoFinal;
      anoFinal = aux;
    }

    for (const Cinema& cine : cinemas) {
      listaFilmeExibicao listaFilmesExib = cine.filmes_exibicao;
      bool filmeAprovado = false;

      for (NoFilme* atualFilme = listaFilmesExib.getPrimeiro(); atualFilme; atualFilme = atualFilme->proximo) {
        Filme structFilme = listaFilmesGeral.getInformation(atualFilme->idFilme);
       
        if (structFilme.tconst != "null" &&
            structFilme.startYear >= anoInicial &&
            structFilme.startYear <= anoFinal) {
          filmeAprovado = true;
          
          break;
        }
      }

      if (filmeAprovado) {
        qntdFilmesEncontrados++;
        cout << "Cinema Numero: [ " << contador << " ] " << endl;
        cout << "Cinema ID: " << cine.cinema_id << endl;
        cout << "Nome do Cinema:" << cine.nome_do_cinema << endl;
        cout << "Coordenada X: " << cine.coordenada_x << endl;
        cout << "Coordenada Y: " << cine.coordenada_y << endl;
        cout << "Preco do Ingresso: " << cine.preco_ingresso << endl;

        cout << "Filmes em Exibicao:";
        listaFilmesExib.imprimeLista();

        cout << endl;
        cout << endl;
        
        
      }

      contador++;
    }
    

    return qntdFilmesEncontrados;
  }

void imprimeCinemas(const vector<Cinema>& cinemas) {
    for (const Cinema& cine : cinemas) {
      cout << "Cinema ID: " << cine.cinema_id << endl;
      cout << "Nome do Cinema: " << cine.nome_do_cinema << endl;
      cout << "Coordenada X: " << cine.coordenada_x << endl;
      cout << "Coordenada Y: " << cine.coordenada_y << endl;
      cout << "Preço do Ingresso: " << cine.preco_ingresso << endl;

      cout << "Filmes em Exibicao:";
      listaFilmeExibicao filmeList = cine.filmes_exibicao;
      filmeList.imprimeLista();

      cout << endl;
      cout << endl;
    }
  }

  
  double distanciaPontos(Coordenada pos1, Coordenada pos2) {
    return sqrt((pos2.x - pos1.x) * (pos2.x - pos1.x) + (pos2.y - pos1.y) * (pos2.y - pos1.y));
  }
};

#endif // LISTACINEMA_H_INCLUDED