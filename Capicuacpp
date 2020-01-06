#include <iostream>
#include <string.h>
#include <conio.h>
//Practica de Pilas y Colas. Verificar si un numero ingresado por el usuario es capicua.
using namespace std;

struct nodo{
char info;
nodo* sgte;
};

void push(nodo*&,char);
char pop(nodo*&);
void encolar(nodo*&,nodo*&,char);
char desencolar(nodo*&,nodo*&);
void esCapicua(nodo*&,nodo*&,nodo*&,int);

int main()
{
    nodo*pila=NULL;
    nodo*frente=NULL;
    nodo*fin=NULL;
    cout << "Ingrese caracteres (Terminar con '-'):";
    char c;
    int cantCaracteres=0;
    cin >> c;
    while ( c!='-')
    {
        cantCaracteres++;
        push(pila,c);
        encolar(frente,fin,c);
    cin>> c;
    }
    if(cantCaracteres==0)
        cout << "No se ingreso ningun numero valido" << endl;
    else
        esCapicua(pila,frente,fin,cantCaracteres);


getch();
 return 0;
}

void push(nodo*& pila, char c){

nodo*p = new nodo();

p->info=c;
p->sgte=pila;

pila=p;
return;
}

char pop(nodo*& pila){

nodo*p = pila;

char c= p->info;
pila=p->sgte;

delete p;
return c;

}

void encolar(nodo*&inicio,nodo*&fin,char c)
{
    nodo* p = new nodo();

    p->info=c;
    p->sgte=NULL;

    if(inicio==NULL)
        inicio=p;
    else
        fin->sgte=p;

    fin=p;
    return;
}

char desencolar(nodo*&inicio,nodo*&fin)
{
    nodo * p = inicio;
    char c= p->info;
    inicio=p->sgte;
    if(inicio==NULL)
        fin=NULL;
    delete p;
    return c;
}

void esCapicua(nodo*&pila,nodo*&frente,nodo*&fin, int cantcaracteres)
{
    char c[cantcaracteres];
    char x[cantcaracteres];
    for (int i=0;i<cantcaracteres;i++)
    {
        c[i]=pop(pila);
        x[i]=desencolar(frente,fin);
    }
    cout << "Pila: ";
    for (int i=0;i<cantcaracteres;i++)
    {
        cout << c[i];
    }
    cout << "\n";
    cout << "Cola: ";
      for (int i=0;i<cantcaracteres;i++)
    {
        cout << x[i];
    }
    cout << "\n";
    if(strncmp(c,x,cantcaracteres)==0)
        cout << "El numero ingresado es capicua" << endl;
    else
        cout << "El numero ingresado no es capicua" << endl;
    return;
}
