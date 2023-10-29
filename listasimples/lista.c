#include<stdio.h>
#include<stdlib.h>
#include"lista.h"
void inicializa_lista(Lista *ap_lista) {
     *ap_lista = NULL; }

void insere_fim(Lista *ap_lista, int valor) {
  No *novo = (No*)malloc(sizeof(No));
  No *auxiliar=(No*)malloc(sizeof(No));
  if (novo) {
    novo->valor = valor;
    novo->proximo = NULL;
    if (*ap_lista == NULL) {
      *ap_lista = novo;
    } else {
      auxiliar = *ap_lista;
      for(;auxiliar->proximo;) {
        auxiliar = auxiliar->proximo;
      }
      auxiliar->proximo = novo;
    }
  }
}

void insere_inicio(Lista *ap_lista, int valor) {
  No *novo = (No*)malloc(sizeof(No));

  if (novo) {
    novo->valor = valor;
    novo->proximo = *ap_lista;
    *ap_lista = novo;
  }
  
}

int remove_fim(Lista *ap_lista) {
No * penult;
  No *ult=*ap_lista;
  int valor;
  if(*ap_lista==NULL){
    printf("ERRO LISTA VAZIA ");
  }
  if (*ap_lista!=NULL) {
    if((*ap_lista)->proximo==NULL){
      valor=(*ap_lista)->valor;
      free(*ap_lista);
      *ap_lista=NULL;
      return valor;
    }
    else{
       for(;ult->proximo;){
        penult=ult;
        ult=ult->proximo;

       }
       valor=ult->valor;
       free(ult);
       penult->proximo=NULL;
       return valor;

    }
    
  }
  
  
  
}

int remove_inicio(Lista *ap_lista) {

  int valor;
  if (*ap_lista!=NULL) {
    No *aux = *ap_lista;
    valor = aux->valor;
    *ap_lista = aux->proximo;
    return valor;
  }
  else{ 
  printf("ERRO LISTA VAZIA ");
   }
  
}

int remove_ocorrencias(Lista *ap_lista, int valor) {
  int ocorrencias_removidas = 0;
  No *atual = *ap_lista;
  No *anterior = NULL;

  while (atual != NULL) {
    if (atual->valor == valor) {
      if (anterior == NULL) {
        *ap_lista = atual->proximo;
        free(atual);
        atual = *ap_lista;
      } else {
        anterior->proximo = atual->proximo;
        free(atual);
        atual = anterior->proximo;
      }

      ocorrencias_removidas++;
    } else {
      anterior = atual;
      atual = atual->proximo;
    }
  }

  return ocorrencias_removidas;
}

int busca(Lista lista, int valor) {
   No * aux=(No*)malloc(sizeof(No));

  int contador = 0;
  if (lista!=NULL) {
    aux=lista;
    if (aux->valor == valor) {
      return contador;
    }

    else {
      for(;aux->proximo;){
        aux = aux->proximo;
        contador++;
        if (aux->valor == valor) {
          return contador;
        }
      }
    }

    return -1;
  }
}

void imprime(Lista lista) {
No* aux=(No*)malloc(sizeof(No));
   aux= lista;
  printf("\n(");
  if(lista==NULL){
    printf("LISTA SEM ITENS");
  }
  for(;aux!=NULL;) {
    
    printf("%d", aux->valor);
    aux = aux->proximo;
    if(aux!=NULL){
        printf(",");
    }
  }
  printf(")\n");
}

void desaloca_lista(Lista *ap_lista) {
  No *atual = *ap_lista;
  No *proximo;

  for (;atual != NULL;) {
    proximo = atual->proximo;
    free(atual);
    atual = proximo;
  }

  *ap_lista = NULL;
}