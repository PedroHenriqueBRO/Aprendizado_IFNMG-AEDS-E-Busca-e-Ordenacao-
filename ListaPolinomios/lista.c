#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"polinomio.h"
void inicializa_polinomio(Lista * ap_lista){
    No *Nocabeca=(No*)malloc(sizeof(No));
    *ap_lista=Nocabeca;
    Nocabeca->antec=Nocabeca;
    Nocabeca->prox=Nocabeca;
}

void define_coeficiente(Polinomio pol, int grau, int coef){
    if (grau >= 0 && coef != 0)
    {
        No* aux= pol->prox;
        No* novo = (No*) malloc(sizeof(No));
        novo->valor.coef = coef;
        novo->valor.grau = grau;

        while(novo->valor.grau > aux->valor.grau){
            if(aux->prox == pol){
                novo->prox = pol;
                novo->antec = pol->antec;
                pol->antec->prox = novo;
                pol->antec = novo;
                return;
            }
            aux = aux->prox;
        }

        novo->prox = aux;
        novo->antec = aux;
        aux->antec->prox = novo;
        aux->antec = novo;
    }
    
}
void soma(Polinomio res, Polinomio a, Polinomio b){
zera(res);
No *auxA=a->prox;
No *auxB=b->prox;
int cont=0;
int coef=0;
for(;auxA!=a;){
    for(;auxB!=b;auxB=auxB->prox){
            if(auxA->valor.grau==auxB->valor.grau){
                coef=coef+auxA->valor.coef+auxB->valor.coef;
                cont++;
            }
            if(auxB->prox==b&&coef!=0){
                define_coeficiente(res,auxA->valor.grau,coef);
            }

        }
        if(cont==0){
            define_coeficiente(res,auxA->valor.grau,auxA->valor.coef);
        }
        cont=0;
        auxA=auxA->prox;
        auxB=b->prox;
        coef=0;
}

auxA=a->prox;

for(;auxB!=b;){
    for(;auxA!=a;auxA=auxA->prox){
            if(auxA->valor.grau==auxB->valor.grau){
                cont++;
            }
    }
    if(cont==0){
        define_coeficiente(res,auxB->valor.grau,auxB->valor.coef);
    }
    cont=0;
    auxA=a->prox;
    auxB=auxB->prox;
}
}
void subtrai(Polinomio res, Polinomio a, Polinomio b){
zera(res);
No *auxA=a->prox;
No *auxB=b->prox;
int cont=0;
int coef=0;
for(;auxA!=a;){
    for(;auxB!=b;auxB=auxB->prox){
            if(auxA->valor.grau==auxB->valor.grau){
                coef=coef+auxA->valor.coef-auxB->valor.coef;
                cont++;
            }
            if(auxB->prox==b&&coef!=0){
                define_coeficiente(res,auxA->valor.grau,coef);
            }

        }
        if(cont==0){
            define_coeficiente(res,auxA->valor.grau,auxA->valor.coef);
        }
        cont=0;
        auxA=auxA->prox;
        auxB=b->prox;
        coef=0;
}

auxA=a->prox;

for(;auxB!=b;){
    for(;auxA!=a;auxA=auxA->prox){
            if(auxA->valor.grau==auxB->valor.grau){
                cont++;
            }
    }
    if(cont==0){
        define_coeficiente(res,auxB->valor.grau,-auxB->valor.coef);
    }
    cont=0;
    auxA=a->prox;
    auxB=auxB->prox;
}

}

void zera(Polinomio pol){
No *aux=pol->prox;
No *remove=aux;
for(;aux!=pol;){
    remove=aux->prox;
    pol->prox=remove;
    free(aux);
    aux=remove;

}
pol->antec=pol;
}
void imprime(Lista lista){
    No *aux=lista->prox;

    printf("[");
    for(;aux!=lista;){
        printf("(%d,%d)",aux->valor.grau,aux->valor.coef);
        if(aux->prox!=lista){
            printf(",");
        }
        aux=aux->prox;
    }
    printf("]\n");
}
void desaloca_polinomio(Lista *ap_pol){
No *aux=(*ap_pol)->prox;
No *remove=aux;
for(;aux!=*ap_pol;){
    remove=aux->prox;
    (*ap_pol)->prox=remove;
    free(aux);
    aux=remove;

}
free(*ap_pol);
}






