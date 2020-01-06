#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int anio, a, b, c, d, e, dia,mes;
    int M,N;
cout <<"***************** CALCULO DE FECHA DE PASCUA Y CARNAVAL **************" << endl;
cout << "" <<endl;
cout << "Ingrese el anio (1583-2299) que desea calcular la Pascua, y sus dias de carnaval: ";
cin >> anio;
cout << "" <<endl;

if (anio<1583 || anio >2299)
    cout << "Error. Ingrese un anio dentro del rango valido (1583-2299)" << endl;
else{
    if 	(anio >= 1583 && anio <= 1699)
         {  M = 22;
            N = 2; }
	else
        if (anio >= 1700 && anio <= 1799)
        {M = 23;
        N = 3;}
	else
        if (anio >= 1800 && anio <= 1899)
        { M = 23;
        N = 4; }
	else
        if (anio >= 1900 && anio <= 2099)
        { M = 24;
        N = 5; }
	else
        if (anio >= 2100 && anio <= 2199)
        { M = 24;
        N = 6; }
	else
        if (anio >= 2200 && anio <= 2299)
        { M = 25;
        N = 0; }

    a = anio % 19;                              //Calculos
	b = anio % 4;
	c = anio % 7;
	d = (19 * a + M) % 30;
	e = (2 * b + 4 * c + 6 * d + N) % 7;

	if (d + e < 10)                             //Pascuas que caen en Marzo
    {
        dia=d+e+22;
        mes=3;
        cout << "El Domingo de Pascuas es el dia " << dia << "/"<< mes <<"." << endl;

    }
    else                                        //Pascuas que caaen en Abril
    {   dia=d+e-9;
        mes=4;

        if (dia==26)                        //Excepciones
            dia=19;
        if (dia==25 && e==6 && a>10)
            dia=18;

        cout << "El Domingo de Pascuas es el dia " << dia << "/"<< mes <<"." << endl;
    }

// Calculo dia de carnaval

int dias_carnaval; //El Martes de Carnaval es 47 dias antes al Domingo de Pascuas
dias_carnaval=47-dia;

mes=mes-1;

if(mes==3)
{
    dia=31;  //Pongo la variable dia en el maximo de dias del mes
    if(dias_carnaval>=dia)  //Puede suceder que todavia los dias que me faltan restar superen los 31 dias, entonces tengo que volver a cambiar de mes, repito procedimiento anterior
    {
    dias_carnaval=dias_carnaval-dia;
    mes=mes-1;
    }
}
if(mes==2){
    if((anio%4==0 && anio%100!=0)||anio%400==0) //El año puede ser bisiesto o no
        dia=29;
    else
        dia=28;
}

int martes_carnaval, lunes_carnaval;
martes_carnaval=dia-dias_carnaval;
lunes_carnaval=martes_carnaval-1;

cout << "" <<endl;
cout << "El Martes de Carnaval es el dia " << martes_carnaval <<"/"<<mes<<"." << endl;

if (martes_carnaval==1)
{
    mes=mes-1;
    if((anio%4==0 && anio%100!=0)||anio%400==0)
        lunes_carnaval=29;
    else
        lunes_carnaval=28;
}
cout << "" <<endl;
cout << "El Lunes de Carnaval es el dia " << lunes_carnaval << "/"<< mes <<"." << endl;


getch();
return 0;
}
}
