#ifndef FILMES_H
#define FILMES_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>



using namespace std;

typedef struct filme {
  string tconst;
  string titleType;
  string primaryTitle;
  string originalTitle;
  int isAdult;
  int startYear;
  string endYear;
  int runtimeMinutes;
  string genres;
} Filme;

class Filmes {
public:
    vector<Filme> filmes;

  Filmes() { inserirFilmes("C:/Users/xtron/Desktop/projetoBusca/filmesCrop.txt"); }

  vector<Filme> getFilmeList(){return filmes;};
  

  void inserirFilmes(const string &arquivoNome) {
    string linha;
    ifstream arquivo(arquivoNome);
    string aux;
    if (!arquivo.is_open()) {
      cout << "ListaFilmes: Erro ao abrir o arquivo." << endl;
      return;
    }
    int cont = 0;
    int contEx = 0;
    getline(arquivo, linha);


    while (getline(arquivo, linha)) {
      stringstream ss(linha);
      Filme filme;

      // Lê os campos da linha e armazena na estrutura Filme
      getline(ss, filme.tconst, '\t');
      getline(ss, filme.titleType, '\t');
      getline(ss, filme.primaryTitle, '\t');
      getline(ss, filme.originalTitle, '\t');

      ss >> filme.isAdult;
      ss.ignore(); // Ignora o separador '\t'
      ss >> filme.startYear;
      ss.ignore();
      getline(ss, filme.endYear, '\t');
      ss >> filme.runtimeMinutes;
      ss.ignore();
      getline(ss, filme.genres);
      
      //filmes.push_back(filme);
      aux = filme.tconst;   

      if (aux.substr(0, 2) == "tt") {
        aux = aux.substr(2); // Remova os dois primeiros caracteres "tt"
        
      }

      bool hasDigit = false;
        for (char c : aux) {
            if (std::isdigit(c)) {
                hasDigit = true;
                break;
            }
        }

        if (!hasDigit) {
            continue;
        }

        long pos = stol(aux);


        pos = (pos-7917518) / 2; 

      Filme filmeVazio;
      filmeVazio.tconst = "null";
      
      if(cont == pos){
        filmes.push_back(filme);
        
      }else{
        contEx++;
        filmes.push_back(filmeVazio);
        filmes.push_back(filme);
        cont++;
      }

      cont++;

    }

    
  }




  Filme getInformation(const string &tconst) {
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
    pos = (pos-7917518) / 2; 


    Filme filmeEncontrado = filmes[pos];

    return filmeEncontrado;
  }


  void imprimeInformacoesDoFilme(const string &tconst) {
    // Use a função getInformation para obter as informações do filme com o
    // tconst especificado
    Filme filme = getInformation(tconst);

    // Verifique se o tconst foi encontrado ou se é "null"
    if (filme.tconst == "null") {
      cout << "Filme com tconst \"" << tconst << "\" nao encontrado." << endl;
    } else {
      cout << "Informacoes do Filme com tconst \"" << tconst << "\":" << endl;
      cout << "Titulo: " << filme.primaryTitle << endl;
      cout << "Tipo: " << filme.titleType << endl;
      cout << "Titulo Original: " << filme.originalTitle << endl;
      cout << "Ano de Inicio: " << filme.startYear << endl;
      cout << "Ano de Termino: " << filme.endYear << endl;
      cout << "Adulto: " << (filme.isAdult == 1 ? "Sim" : "Nao") << endl;
      cout << "Duracao: " << filme.runtimeMinutes << " minutos" << endl;
      cout << "Generos: " << filme.genres << endl << endl;
    }
  }
};

#endif