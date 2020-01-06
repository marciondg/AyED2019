#include <iostream>
#include <fstream>
/* 103) Dado un archivo de registros de alumnos ARCHA sin ningun orden donde cada registro
contiene: a) Apellido y Nombre del alumno (34 caracteres) b) Numero de legajo (6 dlgitos) c)
Division asignada (3 dlgitos)
Se debe desarrollar el algoritmo y codificacion del programa que imprima el listado de alumnos por
division ordenado por division y numero de legajo crecientes, a razon de 55 alumnos por hoja.
*/
using namespace std;

struct ARCHA{
char apeYNomb[34];
int legajo;
int division;
};

struct Nodo {
ARCHA info;
Nodo * sgte;
};

Nodo * insertarOrdenado(Nodo*&, ARCHA);
void leerArchivo(Nodo*&, FILE*);
void recorrerLista(Nodo*);

int main()
{
    Nodo * lista = NULL;
    FILE * f = fopen("archivo.dat","wb+");
    ARCHA r;
    cout << "Ingrese division" << endl;

    cin >> r.division;

    while (r.division>0)
    {
        cout << "Ingrese legajo" << endl;
        cin >> r.legajo;
        cout << "Ingrese apellido y nombre" << endl;
        cin >> r.apeYNomb;
        fwrite(&r,sizeof(ARCHA),1,f);

        cout << "Ingrese division" << endl;
        cin >> r.division;
    }
    fseek(f,0,SEEK_SET);
    leerArchivo(lista,f);
    recorrerLista(lista);

    return 0;
}


Nodo* insertarOrdenado(Nodo*& lista, ARCHA x)
    {
        Nodo *p = new Nodo();
        p->info=x;

        if(lista==NULL || (x.division<lista->info.division)||(x.division==lista->info.division && x.legajo<lista->info.legajo))// si lista esta vacia, o si el valor a ingresar es mas chico que la 1° posicion
        {
            p->sgte=lista;
            lista=p;

        }else{
            Nodo* q = lista;
            while(q->sgte!=NULL&&(x.division>q->sgte->info.division ||(x.division==q->sgte->info.division&& x.legajo>q->sgte->info.legajo)))
                q=q->sgte; // avanzo.

            p->sgte=q->sgte;
            q->sgte=p;

        }
        return p;
    }

void leerArchivo(Nodo*&lista, FILE* arch){

ARCHA regAux;
while (fread(&regAux,sizeof(ARCHA),1,arch))
      insertarOrdenado(lista,regAux);
    }

void recorrerLista(Nodo* lista){
    int contador= 0;
    cout << "------------------------------------" << endl;
    cout << "Division: " << lista->info.division << endl;
    int auxiliar=lista->info.division;

    while (lista!=NULL){
    if(auxiliar!=lista->info.division){
    cout << "------------------------------------" << endl;
    cout << "Division: " << lista->info.division << endl;
    }
    cout << "Legajo: " << lista->info.legajo << "\t";
    cout << "Apellido y nombre: " << lista->info.apeYNomb << endl;
    auxiliar= lista->info.division;
    lista=lista->sgte;

    contador++;
    if (contador>55) //Razon de 55 alumnos por hoja

        {   cout << "\n";
            cout << ".--.-.-.-.-.-.-.-.Nueva hoja.--.-.-.-.-.-.-.-." << endl;

        contador=0;
    }

    }


}
