#include "Arvore.h"
#include<stdio.h>
#include<stdlib.h>
bool insere(Arvore* ap_arv, int x){
 if(*ap_arv==NULL){
   No *Novo=(No*)malloc(sizeof(No));
   *ap_arv=Novo;
   Novo->dir=NULL;
   Novo->esq=NULL;
   Novo->valor=x;
   return true;
 }

   if(x>(*ap_arv)->valor){
    return insere(&(*ap_arv)->dir,x);
  }
  else if(x<(*ap_arv)->valor){
    return insere(&(*ap_arv)->esq,x);
  }
 return false;
}



bool remove_(Arvore * ap_arv, int x){
  
  if(busca(*ap_arv,x)==false){
    return false;
  }
  if((*ap_arv)->valor>x){
        return remove_(&((*ap_arv)->esq),x);
    }
    else if((*ap_arv)->valor<x){
        return remove_(&((*ap_arv)->dir),x);
    } 

  if((*ap_arv)->valor==x){
    if( ((*ap_arv)->dir==NULL) && ((*ap_arv)->esq==NULL) ){
        (*ap_arv)=NULL;
        return true;
    }
    else if( ((*ap_arv)->dir==NULL) || ((*ap_arv)->esq==NULL)){
      if(((*ap_arv)->dir) == NULL){
        (*ap_arv) = ((*ap_arv)->esq);
        return true;
      }else{
        (*ap_arv) = ((*ap_arv)->dir);
        return true;


    } }
    else {
        if((*ap_arv)->esq->dir == NULL){
        (*ap_arv)->valor = (*ap_arv)->esq->valor;
        remove_(&((*ap_arv)->esq),(*ap_arv)->valor);
        return true;
        } 
        else {
            Arvore aux=(*ap_arv);
            aux=aux->esq;
            for(;aux->dir!=NULL;){
                aux=aux->dir;
            }
            (*ap_arv)->valor=aux->valor;
            remove_(&((*ap_arv)->esq),aux->valor);
            free(aux);
            
        return true; }
       
    } }
return false;
}

bool busca(Arvore arv, int x){
if((arv)==NULL){
  return false;
}
if((arv)->valor==x){
  return true;
}
  if(x>(arv)->valor){
    return busca(arv->dir,x);
  }
  else if(x<(arv)->valor){
    return busca(arv->esq,x);
  }
 return false;
}

void imprime_rec(Arvore arv) {
  if (arv == NULL) {
    printf(".");
    return;
  }
  printf("[%d:e=", arv->valor);
  imprime_rec(arv->esq);
  printf(",d=");
  imprime_rec(arv->dir);
  printf("]");
}

void imprime(Arvore arv) {
  imprime_rec(arv);
  printf("\n");
}