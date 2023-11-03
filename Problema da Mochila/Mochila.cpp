#include <iostream>
#include <unistd.h>
#include <vector>
#include <chrono>
using namespace std;
void bestResult(int contteste, int maxpeso, vector<vector<int>> binarios, int matrizteste[][2])
{
    auto start = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);

    int best = 0;
    int matriz[binarios.size()][2];
    for (unsigned i = 0; i < binarios.size(); i++)
    {
        int somapeso = 0;
        int somavalor = 0;
        for (int j = 0; j < contteste; j++)
        {

            if (binarios[i][j] == 1)
            {
                somapeso = somapeso + matrizteste[j][0];
                somavalor = somavalor + matrizteste[j][1];
            }
        }
        matriz[i][0] = somapeso;
        matriz[i][1] = somavalor;
    }
    int cont;
    for (unsigned i = 0; i < binarios.size(); i++)
    {
        if (matriz[i][0] <= maxpeso && matriz[i][1] > best)
        {
            cont = i;
            best = matriz[i][1];
        }
    }
    cout << "--------" << endl;
    cout << "Maior valor:" << best << endl;
    cout << "Peso:" << matriz[cont][0] << endl;
    cout << "--------" << endl;
    auto end = chrono::high_resolution_clock::now();

    // Calcular a duração da execução
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Imprimir o tempo de execução em milissegundos
    cout << "Tempo de execucao: " << duration.count() << " milissegundos" << endl;
}

void geraBinarios(int conttestes, int maxpeso, int matrizteste[][2])
{
    auto start = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);

    vector<vector<int>> binarios;
    int soma;
    for (int i = 0; i < (1 << conttestes); i++)
    {
        soma = 0;
        vector<int> digitsbin;
        for (int j = 0; j < conttestes; j++)
        {
            if (soma > maxpeso)
            {
                break;
            }
            uint32_t aux = i;
            int digit = (aux >> j) & 0x1;
            if (digit == 1)
            {
                soma = soma + matrizteste[j][0];
            }
            digitsbin.push_back(digit);
        }
        if (soma <= maxpeso && soma >= 0)
        {
            binarios.push_back(digitsbin);
        }
    }
    //  for(unsigned i=0;i<binarios.size();i++){
    //     cout<<"--------"<<endl;
    //     cout<<"Number : "<<i<<" : ";
    //      for(int j=0;j<conttestes;j++){
    //         cout<<binarios[i][j];
    //      }
    //      cout<<endl;
    //      cout<<"--------"<<endl;
    //  }
    auto end = chrono::high_resolution_clock::now();

    // Calcular a duração da execução
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Imprimir o tempo de execução em milissegundos
    cout << "Tempo de execucao: " << duration.count() << " milissegundos" << endl;
    bestResult(conttestes, maxpeso, binarios, matrizteste);
}
int main()
{
    // Código para resolver o problema da mochila com solução ineficiente mas usando uma lógica muito bacana, usando um gerador de binarios em base a
    // quantidade de casos de teste para achar a melhor solução usando zeros e uns , ineficiente pois resolve casos de até aproximadamente N=17.
    int quanttestes;
    int maxpeso;
    cin >> quanttestes;
    cin >> maxpeso;
    int matriztestes[quanttestes][2];

    for (int i = 0; i < quanttestes; i++)
    {
        cin >> matriztestes[i][0];
        cin >> matriztestes[i][1];
    }
    geraBinarios(quanttestes, maxpeso, matriztestes);
}