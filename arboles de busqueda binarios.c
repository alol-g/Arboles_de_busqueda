#include<stdio.h>
#include<windows.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ROJO_T     "\x1b[31m"
#define VERDE_T        "\x1b[32m"
#define AMARILLO_T        "\x1b[33m"
#define AZUL_T   "\x1b[34m"
#define MAGENTA_T  "\x1b[35m"
#define RESET_COLOR    "\x1b[0m"

/* Estructuras y tipos */
typedef struct _nodo {
   struct _nodo *izquierdo;
	 int dato;
   struct _nodo *derecho;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;
void margen(int c,int f);
void InOrden(Arbol a);
void Borrar(Arbol *a, int dat);
int Buscar(Arbol a, int dat);
int EsHoja(pNodo r);
void gotoxy(int x,int y);
void Insertar(Arbol *a, int dat);
void VaciarArbol(Arbol *a);
void cuadro(int c,int f);
main()

{
	Arbol ArbolInt=NULL;
   int altura;
   int nnodos;
   int dato,ope;
do
{

margen(1,1);
gotoxy(35,3);
printf("Arboles de busqueda binarios");
cuadro(18,7);
gotoxy(30,8);
printf("1.-Insertar");
cuadro(52,7);
gotoxy(60,8);
printf("2.-Buscar");
cuadro(18,11);
gotoxy(30,12);
printf("3.-Eliminar");
cuadro(52,11);
gotoxy(60,12);
printf("4.-Vaciar");
cuadro(33,15);
gotoxy(45,16);
printf("5.-Salir");
gotoxy(20,20);
printf("Operacion: ");
scanf("%d",&ope);
gotoxy(52,26);
system("pause");
system("cls");
switch(ope)
	{
		case 1:
		    margen(1,1);
            gotoxy(40,3);
            printf("Insertar datos");
           	gotoxy(20,8);
		    printf(MAGENTA_T"Dato: "RESET_COLOR);
		    gotoxy(28,8);
			scanf("%d",&dato);
			Insertar(&ArbolInt, dato);
		    printf("\n");
		    gotoxy(28,10);
			InOrden(ArbolInt);
			gotoxy(20,12);
			system("pause");
			system("cls");
			break;
		case 2:
			margen(1,1);
            gotoxy(40,3);
            printf("Busqueda");
           	gotoxy(20,8);
			printf("Dato a buscar: ");
			scanf("%d",&dato);
			if(Buscar(ArbolInt,dato))
			{
					gotoxy(20,10);
				printf(VERDE_T"El numero se encuentra en el arbol"RESET_COLOR);
					gotoxy(20,12);
				InOrden(ArbolInt);
			}
			else 
			{
					gotoxy(20,10);
				printf(ROJO_T"El numero no se encuentra en el arbol"RESET_COLOR);
			}
		    gotoxy(20,15);
			system("pause");
			system("cls");
			break;
		case 3:
			margen(1,1);
            gotoxy(40,3);
            printf("Eliminar x dato");
           	gotoxy(20,8);
	    	printf("Inserte dato: ");
		    scanf("%d",&dato);
		    gotoxy(20,10);
		    InOrden(ArbolInt);
		    gotoxy(20,12);
			system("pause");
			system("cls");
			margen(1,1);
            gotoxy(40,3);
            printf("Eliminar x dato");
			gotoxy(20,8);
			printf(VERDE_T"Numero %d eliminado "RESET_COLOR,dato);
			gotoxy(20,9);
			Borrar(&ArbolInt,dato);
			gotoxy(20,10);
			InOrden(ArbolInt);
		    gotoxy(20,12);
			system("pause");
			system("cls");
			break;
		case 4:
			margen(1,1);
            gotoxy(45,3);
            printf("Vaciar");
            gotoxy(20,10);
		    InOrden(ArbolInt);
		    gotoxy(20,12);
			system("pause");
			system("cls");
			margen(1,1);
            gotoxy(45,3);
            printf("Vaciar");
		    VaciarArbol(&ArbolInt);
		    gotoxy(20,10);
		    printf(VERDE_T"Vacio"RESET_COLOR);
		    gotoxy(20,12);
			system("pause");
			system("cls");
			//VACIAR
			break;
			
	}	
}while(ope!=5);	
}


	void margen(int c,int f)
{
	int i,a=10;
	gotoxy(c,f);
	printf(AMARILLO_T"%c",218);
	//cuadro pqueño
		gotoxy(a+18,f+1);
	printf("%c",218);
		gotoxy(a+18,f+2);
	printf("%c",179);
		gotoxy(a+61,f+2);
	printf("%c",179);
		for(i=0;i<42;i++)
	{
		//-
	gotoxy((a+18)+(i*1)+1,2);
	printf("%c",196);
					//-
	gotoxy((a+18)+(i*1)+1,4);
		printf("%c",196);
	}
gotoxy((a+18)+(i*1)+1,2);
printf("%c",191);
gotoxy((a+18)+(i*1)+1,4);
printf("%c",217);
gotoxy(a+18,f+3);
printf("%c",192);
	//cuadro grande 
	for(i=0;i<98;i++)
	{
		//-
	gotoxy(c+(i*1)+1,f);
	printf("%c",196);	
					//-
	gotoxy(c+(i*1)+1,28);
		printf("%c",196);
	}
	
	gotoxy(c+(i*1)+1,f);
	printf("%c",191);
		
		for(i=0;i<26;i++)
	{
		//l
	gotoxy(c,f+(i*1)+1);
	printf("%c",179);
	gotoxy(100,f+(i*1)+1);
	printf("%c",179);
	
	}
    gotoxy(c,f+(i*1)+1);
	printf("%c",192);
	gotoxy(100,f+(i*1)+1);
	printf("%c"RESET_COLOR,217);
}

void cuadro(int c,int f)
 {
 	int a,i;
 	gotoxy(c,f);
 	printf(MAGENTA_T"%c",218);
 
 	gotoxy(c,f+1);
 	printf("%c",179);
 	gotoxy(c,f+2);
 	printf("%c",192);
 	for(i=0;i<30;i++)
 	{
 		gotoxy(c+(i*1)+1,f);
 		printf("%c",196);
 		gotoxy(c+(i*1)+1,f+2);
 		printf("%c",196);
	 }
	 gotoxy(c+(i*1)+1,f);
 	printf("%c",191);
	    gotoxy(c+(i*1)+1,f+1);
 		printf("%c",179);
	 	gotoxy(c+(i*1)+1,f+2);
 		printf("%c"RESET_COLOR,217);
 	
 }


void gotoxy(int x,int y)
 {  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 //funciones
 
/* Insertar un dato en el árbol ABB */
void Insertar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;

   /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }

   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) return;
   /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
      el nodo raiz */
   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
   }
   /* Si el dato es menor que el que contiene el nodo padre, lo insertamos
      en la rama izquierda */
   else if(dat < padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
   }
   /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos
      en la rama derecha */
   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
  }

}

void InOrden(Arbol a)
{
   if(a->izquierdo) InOrden(a->izquierdo);
   printf("%d, ", a->dato);
   if(a->derecho) InOrden(a->derecho);
}
/* Comprobar si un árbol es vacío */
int Vacio(Arbol r)
{
   return r==NULL;
}


int Buscar(Arbol a, int dat)
{
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato)
	  { return TRUE;
	
	  } /* dato encontrado */
      else if(dat < actual->dato) actual = actual->izquierdo; /* Seguir */
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE; /* No está en árbol */
}

void Borrar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;
   actual = *a;
   /* Mientras sea posible que el valor esté en el árbol */
   while(!Vacio(actual)) {
      if(dat == actual->dato) { /* Si el valor está en el nodo actual */
         if(EsHoja(actual)) { /* Y si además es un nodo hoja: lo borramos */
            if(padre) /* Si tiene padre (no es el nodo raiz) */
               /* Anulamos el puntero que le hace referencia */
                if(padre->derecho == actual) padre->derecho = NULL;
                else if(padre->izquierdo == actual) padre->izquierdo = NULL;
                 free(actual); /* Borrar el nodo */
                 actual = NULL;
                return;
         }
         else { /* Si el valor está en el nodo actual, pero no es hoja */
            padre = actual;
            /* Buscar nodo más izquierdo de rama derecha */
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            /* O buscar nodo más derecho de rama izquierda */
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            /* Intercambiar valores de no a borrar u nodo encontrado
               y continuar, cerrando el bucle. El nodo encontrado no tiene
               por qué ser un nodo hoja, cerrando el bucle nos aseguramos
               de que sólo se eliminan nodos hoja. */
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { /* Todavía no hemos encontrado el valor, seguir buscándolo */
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }

   }
   
}

void VaciarArbol(Arbol *a) {
    if (!Vacio(*a)) {
        VaciarArbol(&((*a)->izquierdo));
        VaciarArbol(&((*a)->derecho));
	
        free(*a);
        *a = NULL;
    }
  
}


/* Comprobar si un nodo es hoja */
int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}
