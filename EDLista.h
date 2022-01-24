//
// Created by Jair on 21/01/22.
//

#ifndef FILAS_IMPLEMENTACION_EDLISTA_H
#define FILAS_IMPLEMENTACION_EDLISTA_H

#include <stdlib.h>
#include <memory.h>

typedef enum
{
    LS_PRIMERO,
    LS_SIGUIENTE,
    LS_ANTERIOR
} TMovimiento_LS;

typedef struct TNodoLista
{
    void* Elem;
    struct TNodoLista *Siguiente;
} TNodoLista;

typedef struct
{
    TNodoLista *Encabezado, *Actual;
    int TamanioDato;
} TLista;

void CrearLista(TLista *pL, int TamanioDato)
{
    pL->Encabezado = pL->Actual = NULL;
    pL->TamanioDato = TamanioDato;
}

int ListaVacia(TLista L)
{
    return (L.Encabezado==NULL);
}

int AgregarAlFinal(TLista *pL, void* pE)
{
    TNodoLista *pNodo = (TNodoLista*)
            malloc (sizeof(TNodoLista));//Crea elemento
    pL->Actual=pL->Encabezado;

    while (pL->Actual->Siguiente!=NULL)
        pL->Actual=pL->Actual->Siguiente;

    pNodo->Siguiente = pL->Actual->Siguiente;
    pL->Actual->Siguiente=pNodo;

    pNodo->Elem=malloc(pL->TamanioDato);
    memcpy(pNodo->Elem, pE, pL->TamanioDato);
    pL->Actual=pNodo;

    return 1;
}

int AgregarAlInicio (TLista *pL, void * pE){
    TNodoLista *pNodo = (TNodoLista*)
            malloc(sizeof(TNodoLista));
    pNodo->Siguiente= pL->Encabezado;
    pL->Encabezado = pL->Actual= pNodo;
    pNodo->Elem= malloc (pL->TamanioDato);
    memcpy(pNodo->Elem, pE, pL->TamanioDato);
    return 1;
}

int AgregarDespuesDe(TLista *pL, void* pE, void* pDespues){
    void *Aux;//Nuevo apuntador
    TNodoLista *pNodo = (TNodoLista*)
            malloc (sizeof(TNodoLista));//Crea Elemento
    pL->Actual=pL->Encabezado;//Actual apunta al principio
    Aux = malloc(pL->TamanioDato);
    memcpy(Aux, pDespues, pL->TamanioDato);
    while (pL->Actual->Siguiente!= NULL && memcmp(pL->Actual-> Elem, Aux, sizeof(int))!=0)
        pL->Actual=pL->Actual->Siguiente;
    pNodo->Siguiente=pL->Actual->Siguiente;
    pL->Actual->Siguiente=pNodo;
    pNodo->Elem=malloc(pL->TamanioDato);
    memcpy(pNodo->Elem, pE, pL->TamanioDato);
    pL->Actual=pNodo;
    return 1;
}
int EliminarInicio(TLista *pL, void* pE)
{
    TNodoLista *pAux = pL->Encabezado;
    pL->Actual = pL->Encabezado;
    pL->Encabezado = pL->Actual->Siguiente;
    memcpy(pE, pAux->Elem, pL->TamanioDato);
    free(pAux->Elem);
    free(pAux);
    return 1;
}

int EliminarFinal(TLista *pL, void* pE){
    pL->Actual=pL->Encabezado;//Actual apunta al principio
    while(pL->Actual->Siguiente->Siguiente!=NULL)
        pL->Actual=pL->Actual->Siguiente;
    TNodoLista *pAux = pL->Actual->Siguiente;
    pL->Actual->Siguiente=NULL;
    memcpy(pE, pAux->Elem, pL->TamanioDato);
    free(pAux->Elem);
    free(pAux);
    return 1;
}

//Borra todos menos el primero
int EliminarDeLista(TLista *pL, void *pE, void *pABorrar){
    void* Auxb;
    pL->Actual = pL->Encabezado;
    Auxb = malloc(pL->TamanioDato);
    memcpy(Auxb, pABorrar, pL->TamanioDato);
    while(pL->Actual->Siguiente->Siguiente!=NULL && memcmp(pL->Actual->Siguiente->Elem, Auxb, sizeof (int ))!=0)
        pL->Actual=pL->Actual->Siguiente;
    TNodoLista  *pAux = pL->Actual->Siguiente;
    pL->Actual->Siguiente = pL->Actual->Siguiente->Siguiente;
    memcpy(pE, pAux->Elem, pL->TamanioDato);
    free(pAux->Elem);
    free(Auxb);
    return 1;
}

#endif //FILAS_IMPLEMENTACION_EDLISTA_H
