#include <stdio.h>
#include <stdlib.h>
#include "Arboles.h"

nodoArbol *inicArbol(){
    return NULL;
}

nodoArbol *crearNodoArbol(persona cargada){
    nodoArbol *aux = malloc(sizeof(nodoArbol));

    aux->dato = cargada;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbol *buscar(nodoArbol *arbol,int legajoBuscado){
    nodoArbol *rta = NULL;

    if(arbol!=NULL){
        if(arbol->dato.legajo == legajoBuscado){
            rta = arbol;
        }
        else{
            if(legajoBuscado > arbol->dato.legajo){
                rta = buscar(arbol->der,legajoBuscado);
            }
            else{
                rta = buscar(arbol->izq,legajoBuscado);
            }
        }
        return rta;
    }

}

nodoArbol *insertar(nodoArbol *arbol, persona cargada){
    if(arbol == NULL){
        arbol = crearNodoArbol(cargada);
    }
    else{
        if(cargada.legajo > arbol->dato.legajo){
            arbol->der = insertar(arbol->der,cargada);
        }
        else{
            arbol->izq = insertar(arbol->izq,cargada);
        }
    }
    return arbol;
}

void preOrder(nodoArbol *arbol){
    if(arbol != NUll){
        mostrarPersona(arbol->dato);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

void inOrder(nodoArbol *arbol){
    if(arbol!=NULL){
        inOrder(arbol->izq);
        mostrarPersona(arbol->dato);
        inOrder(arbol->der);
    }
}

void posOrder(nodoArbol *arbol){
    if(arbol!=NULL){
        posOrder(arbol->izq);
        posOrder(arbol->der);
        mostrarPersona(arbol->dato);
    }
}

void mostrarPersona(persona dato){
    printf("%s \n",dato.nombre);
    printf("%d \n",dato.edad);
    printf("%d \n",dato.legajo);
    printf("-------------------- \n");
}
