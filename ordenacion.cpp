#include "ordenacion.h"


Cordena::Cordena()
{
  profundidad=0;
  profundidad_maxima=0;
};  

void Cordena::insercionSort() 
{
clave=0;  
    int i, j, index;
    for (i=1; i <v.size(); i++)
    {
        index = v.at(i);
        j = i-1;
        while (j >= 0 && v.at(j)>index)
	{
            v.at(j+1)=v.at(j);
            j--;
	    clave++;
	}
        v.erase(v.begin()+j+1);
        v.insert(v.begin()+j+1,index);
	
    }
contador_insercion.push_back(clave);
clave=0;
};

void Cordena::quickSort(int ini, int fin)  //divide y venceras
{ 
int x;
int i = ini ;int f = fin ;
int p = v[(i+f)/2] ;
profundidad++;

if(profundidad>profundidad_maxima)
  profundidad_maxima++;


    while (i<f)      //Mientras no se cruzen los indices   
        { 
          
	  while (v[i] < p) i++ ;  
          while (v[f] > p) f-- ;
	  if (i < f)                    // Si todavia no se cruzan los indices seguimos intercambiando
          { 
                x = v[i] ;
                v[i] = v[f] ;
                v[f] = x ;
                i++ ; f-- ;
		clave++;
          } ;
        } ; 
        if (ini < f) 
	{
	  
	  quickSort(ini,f) ; //ordeno lista de los menores al pivote
	  
	};
        if (i < fin)
	{  
	  
	  quickSort(i,fin-1) ; //ordeno lista de los mayores al pivote   
	  
	};  
	
profundidad--;

contador_quickSort.push_back(clave);

} ;

void Cordena::shellSort()
{
clave=0;  
       // saltos 
       for( int p = v.size() / 2; p > 0; p = p == 2 ? 1 : (int) ( p / 2.2 ) )
       {
           for( int i = p; i < v.size(); i++ )
           {
               int tmp = v[ i ];
               int j;
                   for(j = i; j >= p && tmp <  v[ j - p ] ; j -= p )
                   {
                     v[ j ] = v[ j - p ];
		     clave++; 
                   }

               v[ j ] = tmp;
           }
       }
contador_shellSort.push_back(clave);
clave=0;       
};

void Cordena::merge(int p,int q,int r)
{                       //unir ordenando  
 int n1=q-p+1;
 int n2=r-q; 
 int L[n1+1],R[n2+1];//crear arreglos
 
 
 
 for(int i=1;i<=n1;i++)  //asignar valor a L[]
 {  
     L[i]=v[p+i-1];
     clave++;
 };    
 for(int j=0;j<=n2;j++)  //asignar valor a R[]
 {  
     R[j]=v[q+j];
     clave++;
 }; 
 
 int i=1;
 int j=1;
 int k=p;
 
 while((i<=n1)&&(j<=n2))
 {
  if(L[i]<=R[j])
   {
     v[k]=L[i];
     k++;
     i++;
     clave++;
   }
  else
  {
     v[k]=R[j];
     k++;
     j++;
     clave++;     
   }                    
 }
 
 while(i<=n1)
    {
     v[k]=L[i];
     k++;
     i++;
     clave++;
    }
 while(j<=n2)
   {
    v[k]=R[j];
     k++;
     j++;
     clave++;
   }
contador_mergeSort.push_back(clave);
  
};

void Cordena::mergeSort(int p,int r)
{
 int q; 
  
 if(p<r)     
 {
  q=(p+r)/2;
  mergeSort(p,q);
  mergeSort(q+1,r);
  merge(p,q,r);
 }
};



void Cordena::insertaVector(vector<int>& ve)
{
  v=ve;    //cargamos el vector que nos pasan al crear el objeto
};  

void Cordena::muestraVector()
{
  for(int i=0;i<v.size();i++)
  {  
    if(i%10==0)
      cout << endl;     
    cout << v[i] << "\t";
  };
  cout << endl;  
};  

void Cordena::borrarVector()
{
  v.clear();  //borra el contenido del vector
};  

void Cordena::resultados()
{
  cout << "\n\n\n\t\t\tNUMERO DE COMPARACIONES\n";
  cout << "\t\t\t-----------------------\n\n";
  cout << "\t\t" << "INSERCION" << "\t" << "QUICKSORT" << "\t" << "SHELLSORT" << "\t" << "MERGESORT" << endl;
  for(int i=0;i<contador_insercion.size();i++)
  {  
    cout << "PRUEBA:" << i << "\t   " << contador_insercion[i] << "\t\t   " << contador_quickSort[i] << "\t\t   " << contador_shellSort[i] << "\t\t   " << contador_mergeSort[i] << endl  ;
  };  
   cout << endl;  
   cout << "PROFUNDIDAD RECURSIVIDAD QUICKSORT:" << profundidad_maxima << endl;
  };  