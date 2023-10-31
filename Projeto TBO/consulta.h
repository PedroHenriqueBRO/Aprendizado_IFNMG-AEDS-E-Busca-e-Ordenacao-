#include "listaCinema.h"
#include "listaFilmes.h"
#include "listaFilmesExecucao.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <algorithm>

using namespace std;

class consulta {
public:
static vector<Filme>aux;
static void setVector(vector<Filme>a){
  aux=a;
}
vector<Filme> getVector(){
  return aux;
}
  static vector<Filme> verificaFilmesAnoEspec(int ano, vector<Filme> filmes) {
    vector<Filme> listafiltrada;

    for (const Filme &filme : filmes) {
      if (filme.startYear == ano) {
        listafiltrada.push_back(filme);
      }
    }
    return listafiltrada;
  }
  static vector<Filme> verificaFilmesAnoEspec(int anostart, int anoend,
                                              vector<Filme> filmes) {
    vector<Filme> listafiltrada;
    if (anoend < anostart) {
      int aux;
      aux = anostart;
      anostart = anoend;
      anoend = aux;
    }
    for (const Filme &filme : filmes) {
      if (filme.startYear >= anostart && filme.startYear <= anoend) {
        listafiltrada.push_back(filme);
      }
    }
    return listafiltrada;
  }

  static vector<Filme> verificaduracao(int minMinutes, int maxMinutes,
                                       vector<Filme> filmes) {
    vector<Filme> listafiltrada;

    for (const Filme &filme : filmes) {

      if (filme.runtimeMinutes != 0 && (filme.runtimeMinutes >= minMinutes &&
                                        filme.runtimeMinutes <= maxMinutes)) {
        listafiltrada.push_back(filme);
      }
    }
    return listafiltrada;
  }

   static bool buscaSubstring(const string &str, const string &substr) {
    size_t found = str.find(substr); // Procura a substring dentro da string

    if (found != string::npos) {
      return true; // Se encontrou a substring, retorna verdadeiro
    } else {
      return false; // Se não encontrou a substring, retorna falso
    }
  }

  static vector<Filme> verificaGenero(string genero, vector<Filme> filmes) {
    

    vector<Filme> listafiltrada;

    for (const Filme &filme : filmes) {
      size_t pos = 0;
      string token;
      string linha = genero;
      while ((pos = linha.find(';')) != string::npos) {
        token = linha.substr(0, pos);
        linha.erase(0, pos + 1);
        if (buscaSubstring(filme.genres, token) == true) {
          listafiltrada.push_back(filme);
        }
      }
    }
    return listafiltrada;
  }

  static vector<Filme> verificaTipo(string tipo, vector<Filme> filmes) {
    vector<Filme> listafiltrada; 
    for (const Filme &filme : filmes) {
      if (buscaSubstring(tipo, filme.titleType) == true) {
        listafiltrada.push_back(filme);
      }
    }
    return listafiltrada;
  }

  static vector<Cinema> filtraPrecoMax(float precoMax, vector<Cinema> cinemas) {
    vector<Cinema> cinemasFiltrados;

    for (const Cinema &cine : cinemas) {
      if (cine.preco_ingresso <= precoMax) {
        cinemasFiltrados.push_back(cine);
      }
    }
    return cinemasFiltrados;
  }

  static vector<Cinema> filtraPorAno(int ano, const vector<Cinema> &cinemas, const vector<Filme> &filmes) {
    vector<Cinema> cinemasFiltrados;

    for (const Cinema &cine : cinemas) {
        listaFilmeExibicao listaFilmesExib = cine.filmes_exibicao;
        bool filmeEncontrado = false;

        for (NoFilme *atualFilme = listaFilmesExib.getPrimeiro(); atualFilme;
             atualFilme = atualFilme->proximo) {
            const Filme &filme = getInformation(atualFilme->idFilme, filmes);

            if (filme.tconst != "null" && filme.startYear == ano) {
                filmeEncontrado = true;
                break;
            }
        }

        if (filmeEncontrado) {
            cinemasFiltrados.push_back(cine);
        }
    }

    return cinemasFiltrados;
}
  
  static vector<Cinema> filtraPorAno(int anoInicial, int anoFinal, const vector<Cinema> &cinemas, const vector<Filme> &filmes) {
    vector<Cinema> cinemasFiltrados;

    for (const Cinema &cine : cinemas) {
        listaFilmeExibicao listaFilmesExib = cine.filmes_exibicao;
        bool filmeEncontrado = false;

        for (NoFilme *atualFilme = listaFilmesExib.getPrimeiro(); atualFilme;
             atualFilme = atualFilme->proximo) {
            const Filme &filme = getInformation(atualFilme->idFilme, filmes);

            if (filme.tconst != "null" && filme.startYear >= anoInicial && filme.startYear <= anoFinal) {
                filmeEncontrado = true;
                break;
            }
        }

        if (filmeEncontrado) {
            cinemasFiltrados.push_back(cine);
        }
    }

    return cinemasFiltrados;
}

  static vector<Cinema>
  filtraCinemasPorDistancia(const Coordenada &coord, double distanciaMax,
                            const vector<Cinema> &cinemas) {
    vector<Cinema> cinemasFiltrados;

    for (const Cinema &cine : cinemas) {
      double distanciaA =
          distanciaPontos(coord, {cine.coordenada_x, cine.coordenada_y});

      if (distanciaA <= distanciaMax) {
        cinemasFiltrados.push_back(cine);
      }
    }

    return cinemasFiltrados;
  }

  static vector<Cinema> filtraGenero(string genero, const vector<Cinema> &cinemas, const vector<Filme> &filmes) {
    vector<Cinema> cinemasFiltrados;
  int cont;
    for (const Cinema &cine : cinemas) {
       
       cout<<"------"<<endl;
      listaFilmeExibicao listaFilmesExib = cine.filmes_exibicao;
      bool filmeEncontrado = false;
      for (NoFilme *atualFilme = listaFilmesExib.getPrimeiro(); atualFilme;
           atualFilme = atualFilme->proximo) {
        const Filme &filme = getInformation(atualFilme->idFilme, filmes);
        

        if (filme.tconst!="null"&&buscaSubstring(filme.genres,genero)==true) {
          filmeEncontrado = true;
          cout<<filme.genres<<endl;
          cont++;
          break;
        }
        
        
      }
      if (filmeEncontrado) {
        cinemasFiltrados.push_back(cine);
       
      }
      cout<<"-------"<<endl;
    }
    cout<<cont<<endl;
    return cinemasFiltrados;
  }

  static vector<Cinema> filtraPorDuracao(int minutosMin, int minutosMax, const vector<Cinema> &cinemas, const vector<Filme> &filmes) {
    vector<Cinema> cinemasFiltrados;
    

    for (const Cinema &cine : cinemas) {
      listaFilmeExibicao listaFilmesExib = cine.filmes_exibicao;
      bool filmeEncontrado = false;

      for (NoFilme *atualFilme = listaFilmesExib.getPrimeiro(); atualFilme;
           atualFilme = atualFilme->proximo) {
        const Filme &filme = getInformation(atualFilme->idFilme, filmes);

        if (filme.tconst != "null" && (filme.runtimeMinutes <= minutosMax &&
                                       filme.runtimeMinutes >= minutosMin)) {
          filmeEncontrado = true;
          break;
        }
      }

      if (filmeEncontrado) {
        cinemasFiltrados.push_back(cine);
      }
    }

    return cinemasFiltrados;
  }

  static vector<Cinema> filtraTipo(string tipo, const vector<Cinema> &cinemas, const vector<Filme> &filmes) {
    vector<Cinema> cinemasFiltrados;
    
    for (const Cinema &cine : cinemas) {
      listaFilmeExibicao listaFilmesExib = cine.filmes_exibicao;
      bool filmeEncontrado = false;

      for (NoFilme *atualFilme = listaFilmesExib.getPrimeiro(); atualFilme; atualFilme = atualFilme->proximo) {
        const Filme &filme = getInformation(atualFilme->idFilme, filmes);

        if (filme.tconst != "null" && buscaSubstring(tipo, filme.titleType)) {
          filmeEncontrado = true;
          break;
        }
      }

      if (filmeEncontrado) {
        cinemasFiltrados.push_back(cine);
      }
    }

    return cinemasFiltrados;
  }

static int imprimeCinemas(const vector<Cinema> &cinemas) {
  int cont = 0; 
  for (const Cinema &cine : cinemas) {
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
    cont++;
  }
  return cont;
}

  static int imprimeFilmes(vector<Filme> listafiltrada) {
    int contador = 1;
    for (const Filme &filme : listafiltrada) {
      cout << "[  " << contador << "  ]" << endl;
      cout << "Titulo: " << filme.primaryTitle << endl;
      cout << "Tipo: " << filme.titleType << endl;
      cout << "Titulo Original: " << filme.originalTitle << endl;
      cout << "Ano de Inicio: " << filme.startYear << endl;
      cout << "Ano de Termino: " << filme.endYear << endl;
      cout << "Adulto: " << (filme.isAdult == 1 ? "Sim" : "Nao") << endl;
      cout << "Duracao: " << filme.runtimeMinutes << " minutos" << endl;
      cout << "Generos: " << filme.genres << endl;
      cout << "--------------------------------------" << endl;
      contador++;
    }
    return contador;
  }

  static Filme getInformation(const string &tconst, const vector<Filme> &filmes) {
    // Encontre a primeira posição não nula na string tconst
    size_t firstNonSpace = tconst.find_first_not_of(' ');

    // Se não houver caracteres não nulos na string, retorne um filme vazio
    if (firstNonSpace == string::npos) {
      Filme filmeVazio;
      filmeVazio.tconst = "null";
      return filmeVazio;
    }

    // Crie uma substring a partir do primeiro caractere não nulo
    string tconstTrimmed = tconst.substr(firstNonSpace);
    
    string aux = tconstTrimmed;  

    if (aux.substr(0, 2) == "tt") {
      aux = aux.substr(2); // Remova os dois primeiros caracteres "tt"
        
    }else{
      cout << "Erro//GetInformation: " <<  aux <<endl;
    }
    

    long pos = stol(aux);
    pos = (pos - 7917518) / 2;

    if (pos >= 0 && pos < filmes.size()) {
        const Filme &filmeEncontrado = filmes[pos];
        return filmeEncontrado;
    } else {
        Filme filmeVazio;
        filmeVazio.tconst = "null";
        return filmeVazio;
    }
}

private:
  static double distanciaPontos(Coordenada pos1, Coordenada pos2) {
    return sqrt((pos2.x - pos1.x) * (pos2.x - pos1.x) +
                (pos2.y - pos1.y) * (pos2.y - pos1.y));
  }


};