#include <iostream>
#include <unistd.h>
#include <vector>
#include <chrono>
using namespace std;
void BestResult(vector<vector<int>> binarios, int maxpizza, int matrizpizzatempo[][2], int contpizza)
{
    auto start = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);

    int best = 0;
    int matriz[(1 << contpizza)][2];
    for (int i = 0; i < (1 << contpizza); i++)
    {
        int somatempo = 0;
        int somapizza = 0;
        for (int j = 0; j < contpizza; j++)
        {

            if (binarios[i][j] == 1)
            {
                somatempo = somatempo + matrizpizzatempo[j][0];
                somapizza = somapizza + matrizpizzatempo[j][1];
            }
        }
        matriz[i][0] = somatempo;
        matriz[i][1] = somapizza;
    }
    for (int i = 0; i < (1 << contpizza); i++)
    {
        if (matriz[i][0] > best && matriz[i][1] <= maxpizza)
        {
            best = matriz[i][0];
        }
    }
    cout << best << " min" << endl;

    auto end = chrono::high_resolution_clock::now();

    // Calcular a duração da execução
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Imprimir o tempo de execução em milissegundos
    cout << "Tempo de execucao: " << duration.count() << " milissegundos" << endl;
}
void geraBinarios(int contpizza, int maxpizza, int matripizzatempo[][2])
{
    auto start = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
    vector<vector<int>> binarios;
    for (int i = 0; i < (1 << contpizza); i++)
    {
        vector<int> digitsbin;
        for (int j = 0; j < contpizza; j++)
        {
            uint32_t aux = i;
            int digit = (aux >> j) & 0x1;
            digitsbin.push_back(digit);
        }
        binarios.push_back(digitsbin);
    }
    auto end = chrono::high_resolution_clock::now();

    // Calcular a duração da execução
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Imprimir o tempo de execução em milissegundos
    cout << "Tempo de execucao: " << duration.count() << " milissegundos" << endl;
    BestResult(binarios, maxpizza, matripizzatempo, contpizza);
}

int main()
{

    int maxpizza;

    int contpizza;

    for (;;)
    {
        cin >> contpizza;
        if (contpizza == 0)
        {
            break;
        }
        cin >> maxpizza;
        int matrizpizzatempo[contpizza][2];
        for (int i = 0; i < contpizza; i++)
        {
            for (unsigned j = 0; j < 2; j++)
            {
                cin >> matrizpizzatempo[i][j];
            }
        }
        geraBinarios(contpizza, maxpizza, matrizpizzatempo);
    }
}