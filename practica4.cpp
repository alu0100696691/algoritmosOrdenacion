#include "ordenacion.h"

using namespace std;

main()
{
int pruebas=0;


  vector<int> datos;   //vector donde guardaremos los numeros desordenados
  Cordena prueba;      //creamos el objeto de la clase Cordena

  cout << "\n\nNUMERO DE PRUEBAS: ";
  cin >> pruebas;
  
  for(int n=0;n<pruebas;n++)
  {  
      srand ( time(NULL) );
      
      for(int i=0;i<50;i++)
      {
	datos.push_back(rand()%9999);   // creamos un vector con datos aleatorios
      };
      
      prueba.insertaVector(datos);   //datos desordenados
      cout << "\n\nDATOS DESORDENADOS-" << "NUMERO DE PRUEBA:" << n << endl ;
      prueba.muestraVector();
      
      
      prueba.insertaVector(datos);   //metodo insercion
      prueba.insercionSort();
      cout << "\n\nMETODO INSERCION-" << "NUMERO DE PRUEBA:" << n << endl ;
      prueba.muestraVector();
      
      
      
      prueba.insertaVector(datos);    //metodo quickSort
      prueba.quickSort(0,datos.size());
      cout << "\n\nMETODO QUICKSORT-" << "NUMERO DE PRUEBA:" << n << endl ;
      prueba.muestraVector();
      
      
      prueba.insertaVector(datos);    //metodo shellSort
      prueba.shellSort();
      cout << "\n\nMETODO SHELLSORT-" << "NUMERO DE PRUEBA:" << n << endl ;
      prueba.muestraVector();
      
      
      prueba.insertaVector(datos);      // metodo mergesort
      prueba.mergeSort(0,datos.size());
      cout << "\n\nMETODO MERGESORT-" << "NUMERO DE PRUEBA:" << n << endl ;
      prueba.muestraVector(); 
      
      prueba.borrarVector();   // reinicializamos los vectores para nueva prueba
      datos.clear();
      
  };  
  prueba.resultados();
};  