#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

typedef struct {
     int legajo;
     char nombre[20];
     int edad;
} persona;

typedef struct nodoArbol {
     persona dato;
     struct nodoArbol * izq;
     struct nodoArbol * der;
} nodoArbol;

nodoArbol*inicArbol();
nodoArbol *crearNodoArbol(persona cargada);

void preOrder(nodoArbol *arbol);
void inOrder(nodoArbol *arbol);
void posOrder(nodoArbol *arbol);

void mostrarPersona(persona dato);



#endif // ARBOLES_H_INCLUDED
