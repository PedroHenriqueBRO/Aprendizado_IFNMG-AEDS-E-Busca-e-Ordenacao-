#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "tries.h"
#include <chrono>
using namespace std;
void cipherceasar(int key, vector<string> &palavras)
{
  auto start = chrono::high_resolution_clock::now();

  auto start2 = chrono::high_resolution_clock::now();

  auto end2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);

  for (unsigned i = 0; i < palavras.size(); i++)
  {
    for (unsigned j = 0; j < palavras[i].length(); j++)
    {
      palavras[i][j] += key;
      if (palavras[i][j] > 90)
      {
        int dif = palavras[i][j] - 90;
        palavras[i][j] = 65 + dif - 1;
        continue;
      }
    }
  }
  cout << "Sua chave criptografada: ";
  for (unsigned i = 0; i < palavras.size(); i++)
  {
    cout << palavras[i] << " ";
  }
  cout << endl;
  auto end = chrono::high_resolution_clock::now();

  // Calcular a duração da execução
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

  // Imprimir o tempo de execução em milissegundos
  cout << "Tempo de execucao: " << duration.count() << " milissegundos" << endl;
}
void cipherbreak(vector<string> palavras, Trie arvore, int aux)
{
  auto start = chrono::high_resolution_clock::now();

  auto start2 = chrono::high_resolution_clock::now();

  auto end2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);

  int cont = 0;
  int best = cont;
  int indice = 0;
  vector<vector<string>> bruteforce;
  for (unsigned i = 1; i < 26; i++)
  {
    for (unsigned k = 0; k < palavras.size(); k++)
    {
      for (unsigned j = 0; j < palavras[k].length(); j++)
      {
        palavras[k][j] -= 1;
        if (palavras[k][j] < 65)
        {
          int dif = palavras[k][j] - 65;
          palavras[k][j] = 90 + dif + 1;
        }
      }
    }
    bruteforce.push_back(palavras);
  }

  for (unsigned i = 0; i < bruteforce.size(); i++)
  {
    for (int j = 0; j < aux; j++)
    {
      if (arvore.pesquisa(bruteforce[i][j]) == true)
      {
        cont++;
      }
      if (cont > best)
      {
        best = cont;
        indice = i;
      }
    }
    cont = 0;
  }
  cout << "A sua descriptografia e: ";
  for (int i = 0; i < aux; i++)
  {
    cout << bruteforce[indice][i] << " ";
  }
  cout << endl;
  cout << "Sua chave de criptografia foi: " << indice + 1 << endl;
  auto end = chrono::high_resolution_clock::now();

  // Calcular a duração da execução
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

  // Imprimir o tempo de execução em milissegundos
  cout << "Tempo de execucao: " << duration.count() << " milissegundos" << endl;
}
int main()
{
  auto start = chrono::high_resolution_clock::now();

  auto start2 = chrono::high_resolution_clock::now();

  auto end2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);

  Trie arvorepalavras;

  arvorepalavras.insereDoArquivo("C:/Users/xtron/Desktop/GithubProjects/projeto2/pt_BR.dic");

  int key;

  vector<string> palavras;

  cout << "Digite as palavras" << endl;

  string aux;

  getline(cin, aux);

  aux += ' ';

  string palavra;

  int cont = 0;

  for (char c : aux)
  {
    if (c == ' ')
    {
      palavras.push_back(palavra);
      palavra = "";
      cont++;
      continue;
    }
    palavra += toupper(c);
  }

  cout << "Digite a chave de criptografia" << endl;
  
  cin >> key;

  cipherceasar(key, palavras);

  cipherbreak(palavras, arvorepalavras, cont);

  auto end = chrono::high_resolution_clock::now();

  // Calcular a duração da execução
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

  // Imprimir o tempo de execução em milissegundos
  cout << "Tempo de execucao: " << duration.count() << " milissegundos" << endl;
  return 0;
}