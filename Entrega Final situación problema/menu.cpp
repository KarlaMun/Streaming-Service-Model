#include <bits/stdc++.h>
#include "../include/menu.hpp"
using namespace std;

int printMenu(){//Imprime el menú
  int n;
  cout<<"SERVICIO DE STREAMING\n";
  cout<<"================================\n";
  cout<<"0) Guardar película nueva\n";
  cout<<"1) Guardar serie nueva\n";
  cout<<"2) Guardar capítulo nuevo\n";
  cout<<"3) Calificar película\n";
  cout<<"4) Calificar capítulo\n";
  cout<<"5) Mostrar información película\n";
  cout<<"6) Mostrar información serie\n";
  cout<<"7) Mostrar información de episodio\n";
  cout<<"8) Mostrar biblioteca\n";
  cout<<"9) Mostrar película mejor calififcada\n";
  cout<<"10) Mostrar serie mejor calififcada\n";
  cout<<"11) Mostrar episodio mejor calififcado de cierta serie\n";
  cout<<"12) Fin\n";
  cout<<"Opción-> \n";
  cin>>n;
  return n;

}