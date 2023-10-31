
#include "listaCinema.h"
#include "listaFilmes.h"
#include "consulta.h"
#include <iostream>


#include <chrono> // Medir tempo

using namespace std;


int main() {

  cout << "Iniciando tempo" << endl;
  // Iniciar a contagem de tempo
  auto start = chrono::high_resolution_clock::now();

  auto start2 = chrono::high_resolution_clock::now();

  
  auto end2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
 
  

  Filmes filme;
  
  listaCinema cine;
  cine.lerArquivo("C:/Users/xtron/Desktop/GithubProjects/Projeto TBO/cinemas.txt");
  

  int op = -1;
  int op2 = -1;
  
  vector<Cinema> c = cine.getListaCinemas();
  vector<Filme> f = filme.getFilmeList(); 

  system("pause");

  int dadoA,dadoB;
  float preco; 
  string genero_tipo;
  string substringGeneroTipo; 
  bool confirmacao = false;
  int opcaoConfirma; 
  Coordenada coord; 
  double disMax;
  
  while(op != 0){ 
    system("cls || clear");
    cout << "( 1 ) - Filtros de Filme" << endl; 
    cout << "( 2 ) - Filtros de Cinemas" << endl;
    cout << "( 3 ) - Buscar Filmes" << endl; 
    cout << "( 4 ) - Buscar Cinemas" << endl;
    cout << "( 0 ) - Sair" << endl;
    cout << "--> ";
    cin >> op;

    switch(op){ 
      case 1 :
        // FILTROS DE FILMES
        
        op2 = -1; 
        while(op2 != 0){
          
          system( "cls" );
          cout << "---- Filtros de Filmes ---- " << endl; 
          cout << "( 1 ) - Ano Especifico" << endl; 
          cout << "( 2 ) - Intervalo de Anos" << endl; 
          cout << "( 3 ) - Intervalo de duracao" << endl; 
          cout << "( 4 ) - Generos" << endl; 
          cout << "( 5 ) - Tipos" << endl; 
          cout << "( 6 ) - Limpa todos os Filtros" << endl; 
          cout << "( 0 ) - Voltar ao Menu Anterior" << endl; 

          cout << "--> ";
          cin >> op2;
          switch(op2){
            case 1 : 
              // FILTRA FILME - ANO ESPECIFICO
              cout<<" Digite o ano:"<<endl;
              cin>>dadoA;
              
              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;
              

              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;
              if(confirmacao){
                start2 = chrono::high_resolution_clock::now();
                 
  
                f=consulta::verificaFilmesAnoEspec( dadoA,f);

                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");

                }


            break;

            case 2 : 
              // FILTRA FILME - INTERVALO ANOS
              cout<<"Digite o ano de inicio e de fim:"<<endl;
              cin>>dadoA;
              cin>>dadoB;
              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;
              

              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;
              if(confirmacao){
                start2 = chrono::high_resolution_clock::now();
                f=consulta::verificaFilmesAnoEspec( dadoA,dadoB,f);
              
                
                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
              }



            break;

            case 3 : 
              // FILTRA FILME - INTERVALO DURAÇÃO
              cout<<"Digite a duração minima e maxima"<<endl;

              cin>>dadoA;
              cin>>dadoB;
      
              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              
              cin >> opcaoConfirma;
              

              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;
              if(confirmacao){
                start2 = chrono::high_resolution_clock::now();
                f=consulta::verificaduracao(dadoA,dadoB, f);
                
                
                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
                }
                    
            break;

            case 4 : 
              // FILTRA FILME - GENEROS
              cout<<"Digite o(s) Genero(s):"<<endl;
              cin>>genero_tipo;
              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;
              

              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;
             if(confirmacao) {
              start2 = chrono::high_resolution_clock::now();
                
              f=consulta::verificaGenero(genero_tipo,f);
              end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
              }
            break;

            case 5 : 
              // FILTRA FILME - TIPOS
              cout<<"Digite o(s) Tipo(s):"<<endl;
              cin>>genero_tipo;
              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;

              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;
              if (confirmacao){
                start2 = chrono::high_resolution_clock::now();
                
                f=consulta::verificaTipo(genero_tipo, f);

                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
                }
            break;

            case 6 :
              start2 = chrono::high_resolution_clock::now();
                
              f = filme.getFilmeList();
              cout << "Filtros de Filme removidos" << endl << endl;
              
                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
            break;
            case 0: 
            break;
            default :
            cout << "Opcao invalida" << endl;
          }
          
        }
        
      break;
      case 2 :
        op2 = -1;
        system( "cls" ); 
        while(op2 != 0){

          system("cls");
          cout << "---- Filtros de Cinemas ---- " << endl; 

          cout << "( 1 ) - Contem Filme lancado no Ano" << endl; 
          cout << "( 2 ) - Contem Filme lancado no intervalo de Anos" << endl; 
          cout << "( 3 ) - Contem Filme com este Intervalo de duracao" << endl; 
          cout << "( 4 ) - Contem Filme com este(s) Genero(s)" << endl; 
          cout << "( 5 ) - Contem Filme com este(s) Tipo(s)" << endl; 
          cout << "( 6 ) - Preco do ingresso" << endl; 
          cout << "( 7 ) - Distancia dessa coordenada" << endl; 
          cout << "( 8 ) - Limpa todos os Filtros" << endl; 
          cout << "( 0 ) - Voltar ao Menu Anterior" << endl;

          cout << "--> ";
          cin >> op2; 

          switch(op2){
            case 1 :
              system("cls");

              cout << "Digite o Ano: " << endl; 

              cin >> dadoA;


              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;


              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;

              if(confirmacao){
                start2 = chrono::high_resolution_clock::now();
                
                c = consulta::filtraPorAno(dadoA, c, f);

                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
              } 


            break;

            case 2: 
              system("cls");

              cout << "Digite o Ano Inicial: " << endl; 
              cin >> dadoA;


              cout << "Digite o Ano Final: " << endl; 
              cin >> dadoB;

              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;


              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;

              if(confirmacao){
                start2 = chrono::high_resolution_clock::now();
                
                c = consulta::filtraPorAno(dadoA, dadoB, c, f);
                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
              } 


            break;

            case 3: 
              system("cls");

              cout << "Digite o Intervalo Inicial: " << endl; 
              cin >> dadoA;


              cout << "Digite o Intervalo Final: " << endl; 
              cin >> dadoB;

              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;


              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;

              if(confirmacao){
                start2 = chrono::high_resolution_clock::now();
                
                c = consulta::filtraPorDuracao(dadoA, dadoB, c, f);
                
                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
              } 

            break;

            case 4: 
              system("cls");
              genero_tipo = " ";
              substringGeneroTipo = " ";

              cout << "I  - Escreva -x- para representar que terminou de inserir os Generos" << endl << endl;

              while(genero_tipo != "-x-"){
                cout << "Digite o Genero: " << endl; 
                cin >> genero_tipo;
                 
              

              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;

              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;

              if(confirmacao&&genero_tipo!="-x-"){

                start2 = chrono::high_resolution_clock::now();

                c = consulta::filtraGenero(genero_tipo, c, f);

                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
              }
              }
                
              
            
            break;

            case 5: 
              system("cls");

              genero_tipo = "";
              substringGeneroTipo = "";
              cout << "I  - Escreva -x- para representar que terminou de inserir os Tipos" << endl << endl;

              while(genero_tipo != "-x-"){
                cout << "Digite o Tipo: " << endl; 
                cin >> genero_tipo;
                if(genero_tipo != "-x-")
                  substringGeneroTipo += genero_tipo + ";;"; 
              }

              cout << "---->   " << substringGeneroTipo << endl;
              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;


              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;

              if(confirmacao){
                start2 = chrono::high_resolution_clock::now();
                
                c = consulta::filtraTipo(substringGeneroTipo, c, f);
                
                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
              } 
              
            break;

            case 6: 

            system("cls");

              cout << "Digite o Preco Maximo: " << endl; 
              cin >> preco;

              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;


              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;

              if(confirmacao){

                start2 = chrono::high_resolution_clock::now();
                
                c = consulta::filtraPrecoMax(preco, c);

                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
              } 

            break;

            case 7: 
              system("cls");

              cout << "Digite o Ponto X: "; 
              cin >> coord.x; 

              cout << "Digite o Ponto y: "; 
              cin >> coord.y;

              cout << "Digite a distancia Max: "; 
              cin >> disMax;



              cout << "1 - Confirma " << endl;
              cout << "O - Retorna ao menu anterior" << endl;
              cout << "--> ";
              cin >> opcaoConfirma;


              opcaoConfirma == 1 ? confirmacao = true : confirmacao = false;

              if(confirmacao){

                start2 = chrono::high_resolution_clock::now();
                


                c = consulta::filtraCinemasPorDistancia(coord, disMax, c);

                end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
              } 
            break;

            case 8 : 

            start2 = chrono::high_resolution_clock::now();
                


              c = cine.getListaCinemas();
              cout << "Filtros de Cinema removidos" << endl << endl;
              
              end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
            break;

            case 0:
            break;

            default:
            cout << "Opcao invalida" << endl;            
          }

        }
         
        
      break;

      case 3: 

        start2 = chrono::high_resolution_clock::now();
                
        cout << "Encontrados: " << consulta::imprimeFilmes(f) << endl;
        
        end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
      break;

      case 4:
        start2 = chrono::high_resolution_clock::now();
                
        cout << "Encontrados: " << consulta::imprimeCinemas(c) << endl; 
        
        end2 = chrono::high_resolution_clock::now();
                duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                cout << "Tempo de execucao: " << duration2.count() << " milissegundos" << endl;
                system("pause");
      break;
      
      default :
        cout << "Opcao invalida" << endl;
    }
    
  }
  

  // Finalizar a contagem de tempo
  auto end = chrono::high_resolution_clock::now();

  // Calcular a duração da execução
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

  // Imprimir o tempo de execução em milissegundos
  cout << "Tempo de execucao: " << duration.count() << " milissegundos" << endl;
}