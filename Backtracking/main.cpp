/*******************************
Mauricio Cortés
A00816689
Análisis y Diseño de Algoritmos
Prof. Román Martinez
15/04/2016
Tarea 10
*******************************/

#include <cstdlib>
#include <iostream>
using namespace std;
const int n = 9;  // cantidad de nodos

int grafo[n][n] =  {{0,1,1,0,0,0,0,0,0},
                    {1,0,1,1,1,0,0,0,0},
                    {1,1,0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,1,0,0},
                    {0,1,1,1,0,1,1,1,0},
                    {0,0,1,0,1,0,0,1,0},
                    {0,0,0,1,1,0,0,1,1},
                    {0,0,0,0,1,1,1,0,1},
                    {0,0,0,0,0,0,1,1,0}};



int vcolor[n+1];

bool valido(int i)
{
     int j = 1;
     bool sw = true;

     while (j < i && sw)
     {  if (grafo[i-1][j-1] && vcolor[i] == vcolor[j]) // 1 es true, 0 es false
            sw = false;
        j++;
     }
     return sw;
}

void coloreado (int i, int &contComb, int m, int ColorInicial)
{
     if(valido(i))//El nodo cumple con el criterio de seleccion
       if(i == n)//Se obtiene la solucion
       {  cout << "-------------------------------------- \n";
          for (int x = ColorInicial; x <= n; x++)//Despliega la solucion
            cout << "Nodo " << x << " se pinta del color #" << vcolor[x] << "\n";

          contComb++;
       }
       else
         for (int color=1; color <= m; color++)//por cada hijo h de r
         {  vcolor[i+1] = color;
            coloreado(i+1, contComb, m, ColorInicial);//Busqueda depth first
         }
}

int main()
{
    int contComb=0, CantColores, ColorInicial;
    cout << "Con cuantos colores quieres colorear el mapa? " << endl;
    cin >> CantColores;
    cout << "Con que numero de color deseas iniciar a pintar el mapa? " << endl;
    cin >> ColorInicial;

    coloreado(0, contComb, CantColores, ColorInicial);
    cout << endl << "Se realizan " << contComb << " Combinaciones" << endl << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
