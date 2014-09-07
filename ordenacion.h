#if !defined(_ORDENACION_H_)
#define _ORDENACION_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>


using namespace std;

class Cordena
{
private:
    vector<int> v;    //el vector a ordenar
    
    vector<int> contador_insercion; //contadores de comparaciones de los distintos metodos  
    vector<int> contador_quickSort;  
    vector<int> contador_shellSort; 
    vector<int> contador_mergeSort;
    int clave;  //numero comparaciones
    int profundidad;
    int profundidad_maxima;
public:
     Cordena();   //constructor 
     void insercionSort(); 
     void quickSort(int ini, int fin);
     void shellSort();  
     void merge(int p,int q,int r);  //metodo que usa el mergesort
     void mergeSort(int p,int r);     
     void insertaVector(vector<int>& ve);  //cargar vector ve
     int devuelveVector();     //devuelve vector
     void muestraVector();     //muestra en pantalla el vector
     void borrarVector();      //borramos el contenido del vector 
     void resultados();        //mostrar estadisticas
};























#endif
