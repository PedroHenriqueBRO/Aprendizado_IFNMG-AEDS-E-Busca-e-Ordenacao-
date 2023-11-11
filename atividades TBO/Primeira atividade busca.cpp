#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main(){
	ifstream arquivo;
	int aux;
	string name;
	int matrizmachines[15][15];
	int matriztimes[15][15];
	int matrizresultado[15][15];
	
	arquivo.open("arquivo.txt");
	for(unsigned p=0;p<10;p++){ 
	if(arquivo.is_open()){
		cout<<"aberto"<<endl; 

		for(unsigned i=0;i<3;i++){
			getline(arquivo,name);
		}
		for(unsigned i=0;i<15;i++){
			for(unsigned j=0;j<15;j++){
				arquivo>>aux;
				matrizmachines[i][j]=aux;
			}
			
		}
		for(unsigned i=0;i<15;i++){
			for(unsigned j=0;j<15;j++){
				cout<<matrizmachines[i][j]<<" ";
			}
			cout<<"\n ";
		}
		cout<<"\n ";
		for(unsigned i=0;i<2;i++){
			getline(arquivo,name);
		}
		
		
		for(unsigned i=0;i<15;i++){
			for(unsigned j=0;j<15;j++){
				arquivo>>aux;
				matriztimes[i][j]=aux;
			}
			
		}
		for(unsigned i=0;i<15;i++){
			for(unsigned j=0;j<15;j++){
				cout<<matriztimes[i][j]<<" ";
			}
			cout<<"\n ";
    }
		cout<<"\n ";
		 for(unsigned k=0;k<15;k++){
            for(unsigned l=0;l<15;l++){
                for(int p=0;p<16;p++){
                    if(matriztimes[k][l]==p){
                        matrizresultado[k][l]=matrizmachines[k][p-1];
                        break;}
                    }
                }
            }
            for(unsigned i=0;i<15;i++){
			for(unsigned j=0;j<15;j++){
				cout<<matrizresultado[i][j]<<" ";
			}
			cout<<"\n ";
		}
        getline(arquivo,name);
		}

         }
	return 0;
}

