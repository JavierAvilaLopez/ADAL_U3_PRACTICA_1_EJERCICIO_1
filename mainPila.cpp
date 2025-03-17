#include<iostream>
using namespace std;
#include"Pila.h"

int main()
{
  char operacion;
  int num;
  Pila *pila;
  do{
    cin>>operacion;
    switch(operacion)
      {
      case 'N':
	pila=new Pila();
	break;
      case 'A':
	cin>>num;
	pila->apilar(num);
	  break;
      case 'D':
	if(pila->estaVacia())
	  cout<<"VACIA"<<endl;
	else
	  cout<<pila->desapilar()<<endl;
	break;
      case 'B':
	delete pila;
	break;
      case 'S':
	  break;	  	  
      }
  }while(operacion!='S');
}
