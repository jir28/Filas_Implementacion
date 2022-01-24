#include <stdio.h>
#include "EDLista.h"


//Imprime solo enteros
void Imprimir(TLista *pLs){
    TNodoLista *pNodo,* siguiente;
    for (pNodo = pLs->Encabezado;(pNodo);pNodo=siguiente){
        printf("Valor %i \n",*(int*)pNodo->Elem);
        siguiente = pNodo->Siguiente;
    }
}
//Buscar un entero en la lista
int BuscarLista(TLista *pLs,int obj){
    int compro = 0;
    TNodoLista *pNodo,* siguiente;
    for (pNodo = pLs->Encabezado;(pNodo);pNodo=siguiente){
        if(*(int*) (pNodo->Elem) == obj){
            compro = 1;
        }
        siguiente = pNodo->Siguiente;
    }
    return compro;
}

int main() {
    printf("Hello, World!\n");
    TLista lista;
    int num,despues,obj,rt;
    CrearLista(&lista,sizeof (num));
    despues = 15;
    AgregarAlInicio(&lista,&despues);
    num= 54;
    AgregarAlFinal(&lista,&num);
    num= 32;
    AgregarAlFinal(&lista,&num);
    num = 76;
    AgregarDespuesDe(&lista,&num,&despues);
    Imprimir(&lista);
    //Buscar un elemento de tipo entero en la lista
    obj = 15;
    rt =BuscarLista(&lista,obj);
    if (rt==1){
        printf("El elemento %d esta en la lista\n",obj);
    } else{ printf("El elemento %d no esta en la lista\n",obj);}
    /*EliminarInicio(&lista,&num);
    Imprimir(&lista);
    printf("\n");
    EliminarFinal(&lista,&num);
    Imprimir(&lista);
     */

    //Borra todos menos el primero
    num = 15;
    EliminarDeLista(&lista,&num,&num);
    Imprimir(&lista);
    printf("\n");
    return 0;
}
