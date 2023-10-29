#include<stdlib.h>
#include<stdio.h>
void output(int vetor[],int cont){
    printf("%d\n",cont);
    int contador=0;
    for(int i=0;i<cont;i++){
        for(int j=0;j<15;j++){
            if(vetor[i]&(1<<j)){
              contador++;
            }
        }
        printf("%d ",contador);
        contador=0;
        for(int k=0;k<15;k++){
            if(vetor[i]&(1<<k)){
                printf("%d ",k);
            }
        }
printf("\n");
    }
    
}
void colecao(int W[],int m,int alvo){
int soma;

int cont=0;

int vetor[m];

for(int i=0;i<(1<<m);i++){
    soma=0;
    for(int j=0;j<m;j++){
        if(i & (1<<j) && (soma&W[j])==0){
            soma=soma|W[j];
            vetor[cont]=W[j];
            cont++;
        }
    }
    if(soma==alvo){
      output(vetor,cont);
      return;
    }
		cont = 0;
    
} 

}



int main(){
int alvo=0;

int n;

int m;

scanf("%d",&n);

scanf("%d",&m);

int W[m];
int mask=0;
int quantidade;
int elemento;
for(int i=0;i<m;i++){

scanf("%d",&quantidade);

for(int i=0;i<quantidade;i++){
    scanf("%d",&elemento);
    mask=mask|(1<<elemento);
    
}
W[i]=mask;
mask=0;
}
for(int i=0;i<n;i++){
    alvo=alvo | (1<<i);
}
colecao(W,m,alvo);

return 0;
}
