#include <iostream>
#include <fstream>
using namespace std;

struct Alumno{
    int nl;
    double promedio;
};
int cantBloques (FILE *f);
void ordenarVectorBurbuja (Alumno vec[],int tam);

int main()
{
    FILE *f;
    f= fopen("Alumnos.Dat","wb");
    Alumno r;
    Alumno v[100];
    cout << "Ingrese numero de legajo:" << endl;
    cin >> r.nl;

    while (r.nl>0)
    {
    cout << "Ingrese promedio: " << endl;
    cin >> r.promedio;
    fwrite(&r,sizeof(Alumno),1,f);

    cout << "Ingrese numero de legajo: " << endl;
    cin >> r.nl;
    }

    fclose(f);

    f=fopen("Alumnos.Dat", "rb");

    int y = cantBloques(f);


    fread(v,sizeof(Alumno),y,f);

    ordenarVectorBurbuja(v,y);

    fseek(f,0,SEEK_SET);

    fclose(f);

    f=fopen("Alumnos.Dat","wb");

    fwrite(v,sizeof(Alumno),y,f);
    fseek(f,0,SEEK_SET);

    fclose(f);

    f=fopen("Alumnos.Dat", "rb");

    int i=0;

    while(fread(v,sizeof(Alumno),1,f))
    {
        cout << "Numero legajo: " << v[i].nl << "-------- Promedio: " << v[i].promedio << endl;
        i++;
    }
    fclose(f);

    return 0;
}

int cantBloques (FILE *f)
{
    int x=0;
    int pos= ftell(f);
    fseek(f,0,SEEK_END);
    x= ftell(f)/sizeof(Alumno);
    fseek(f,pos,SEEK_SET);
    return x;
}

void ordenarVectorBurbuja (Alumno vec[],int tam)
{
    Alumno aux;
    for (int i=0;i<tam-1;i++)
    {
        for (int j=0;j<tam-1-i;j++)
        {
            if(vec[j+1].nl < vec[j].nl)
            {
                aux=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
            }

        }
    }
}

/*
#include <iostream>

using namespace std;

struct Alumno{
    int nl;
    double promedio;
};

void ordenarVectorBurbuja (Alumno vec[],int tam);

int main()
{
    FILE *f;
    int contador=0;
    f= fopen("Alumnos.Dat","wb");
    Alumno r;
    Alumno v[100];
    cout << "Ingrese numero de legajo:" << endl;
    cin >> r.nl;

    while (r.nl>0)
    {
    cout << "Ingrese promedio: " << endl;
    cin >> r.promedio;
    fwrite(&r,sizeof(Alumno),1,f);

    cout << "Ingrese numero de legajo: " << endl;
    cin >> r.nl;
    contador++;
    }

    fclose(f);

    f=fopen("Alumnos.Dat", "rb");

    int y = contador;

    fread(v,sizeof(Alumno),y,f);

    ordenarVectorBurbuja(v,y);

    for (int i=0;i<y;i++)
    {
        cout << "Numero legajo: " << v[i].nl << "-------- Promedio: " << v[i].promedio << endl;
    }

    fclose(f);

    return 0;
}



void ordenarVectorBurbuja (Alumno vec[],int tam)
{
    Alumno aux;
    for (int i=0;i<tam-1;i++)
    {
        for (int j=0;j<tam-1-i;j++)
        {
            if(vec[j+1].nl < vec[j].nl)
            {
                aux=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
            }

        }
    }
    return;
}
*/
