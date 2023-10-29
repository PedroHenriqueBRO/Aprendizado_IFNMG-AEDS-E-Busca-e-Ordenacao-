#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"
void inicializa_lista(Lista * ap_lista){
    No *Nocabeca=(No*)malloc(sizeof(No));
    *ap_lista=Nocabeca;
    Nocabeca->antec=Nocabeca;
    Nocabeca->prox=Nocabeca;
}
void insere_inicio(Lista ap_lista, TipoDado valor){
    No *Novo=(No*)malloc(sizeof(No));
    if(ap_lista->prox!=ap_lista){
        Novo->valor=valor;
        Novo->prox=ap_lista->prox;
        ap_lista->prox->antec=Novo;
        ap_lista->prox=Novo;
        Novo->antec=ap_lista;


    }
    else{
        Novo->valor=valor;
        ap_lista->prox=Novo;
        Novo->antec=ap_lista;
        ap_lista->antec=Novo;
        Novo->prox=ap_lista;
    }
}
void insere_fim(Lista ap_lista, TipoDado valor){
    No *Novo=(No*)malloc(sizeof(No));
    if(ap_lista->prox!=ap_lista){
        Novo->valor=valor;
        ap_lista->antec->prox=Novo;
        Novo->antec=ap_lista->antec;
        Novo->prox=ap_lista;
        ap_lista->antec=Novo;
        
        } 
        else{
            Novo->valor=valor;
            ap_lista->prox=Novo;
            Novo->antec=ap_lista;
            ap_lista->antec=Novo;
            Novo->prox=ap_lista;
        }
        }
TipoDado remove_fim(Lista ap_lista){
    TipoDado valor;
    No *aux=ap_lista->antec;
    if(ap_lista->prox!=ap_lista){
    ap_lista->antec->antec->prox=ap_lista;
    valor=ap_lista->antec->valor;
    
    ap_lista->antec=ap_lista->antec->antec;
    free(aux);
    return valor;
    }
    
        
    
}
TipoDado remove_inicio(Lista ap_lista){
    TipoDado valor;
    No *aux=ap_lista->prox;
    if(ap_lista->prox!=ap_lista){
        aux=ap_lista->prox;
        valor=ap_lista->prox->valor;
        ap_lista->prox->prox->antec=ap_lista;
        ap_lista->prox=ap_lista->prox->prox;
        free(aux);
        return valor;
    }
    
    }
int remove_ocorrencias(Lista ap_lista, TipoDado valor){
    No *aux=ap_lista->prox;
    int cont=0;
    No *remover=aux;
    for(;aux!=ap_lista;){
       if(aux->valor.grau==valor.grau&&aux->valor.coef==valor.coef){
        aux->antec->prox=aux->prox;
        aux->prox->antec=aux->antec;
        remover=aux->prox;
        cont++;
        free(aux);
        aux=remover;
        continue;
       }
      aux=aux->prox;
      remover=aux;
    }
return cont;
}
int busca(Lista lista, TipoDado valor){
    No *aux=lista->prox;
    int cont=0;
    for(;aux!=lista;){
       if(aux->valor.grau==valor.grau&&aux->valor.coef==valor.coef){
       return cont;
       }
       cont++;
       aux=aux->prox;

    }
return -1;

}
int coeficiente_do_grau(Lista lista, int grau){
    No *aux=lista->prox;
    int valor;
    for(;aux!=lista;){
        if(aux->valor.grau==grau){
        valor=aux->valor.coef;
        return valor;
        }
        aux=aux->prox;

    }
    return 0;
}
void imprime(Lista lista){
    No *aux=lista->prox;
    
    printf("\n[");
    for(;aux!=lista;){
        printf("(%d,%d)",aux->valor.grau,aux->valor.coef);
        if(aux->prox!=lista){
            printf(",");
        }
        aux=aux->prox;
    }
    printf("]\n");
}
void desaloca_lista(Lista *ap_lista){
No *aux=(*ap_lista)->prox;
for(;aux!=*ap_lista;){
    aux->antec->prox=aux->prox;
    aux->prox->antec=aux->antec;
    free(aux);
    aux=(*ap_lista)->prox;

}
}





