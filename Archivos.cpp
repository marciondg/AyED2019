#include <iostream>
#include <stdio.h>
/* Dado un archivo de no mas de 100 registros de tipo NL/PROM
Recorrerlo buscar el legajo numero 30
Si el legajo existe copiarlo a un vector y listarlo, si no existe emitir un mensaje

*/
using namespace std;

struct Alumno{
    int legajo;
    double promedio;
    };

// int cantBloques (FILE*, Alumno &r); No lo usé


int main()
{
    Alumno r;
    Alumno v[100];
    int i,esta;
    i=esta=0;

    FILE* f;

    f = fopen("Alumnos.Dat","wb");

    cout <<"Ingrese numero de legajo: " << endl;
    cin >> r.legajo;

    while (r.legajo>0)
            {
            cout <<"Ingrese promedio del alumno: " << endl;
            cin >> r.promedio;
            fwrite(&r,sizeof(Alumno),1,f);
            cout <<"Ingrese numero de legajo: " << endl;
            cin >> r.legajo;
            }
    fclose(f);

    f = fopen("Alumnos.Dat", "rb");

    //int y=cantBloques(f,r); Al final no lo usé

    fseek(f,0,SEEK_SET);
    fread(&r,sizeof(Alumno),1,f);

    while(!feof(f))
    {
        if (r.legajo==30)
            {
            esta=1;
            fseek(f,0,SEEK_SET);
            while(fread(&r,sizeof(Alumno),1,f))
            {
                v[i].legajo=r.legajo;
                v[i].promedio = r.promedio;
                cout << "Numero de legajo: " << v[i].legajo << " --------- Promedio: " << v[i].promedio << endl;
                i++;
            }
            }
    else
        fread(&r,sizeof(Alumno),1,f);
    }
    fclose(f);

    if (esta!=1)
        cout << "No se encontro legajo 30" << endl;

    return 0;
}

/*
int cantBloques (FILE* f, Alumno &r)
{
    int p= ftell(f);
    int x=0;

    fseek(f,0,SEEK_END); // pongo puntero en el final del archivo.
    x= ftell(f)/sizeof(r);
    fseek(f,p,SEEK_SET); // devuelvo a donde estaba
    return x;
}
*/
