#include "../include/clase.hpp"
#include <bits/stdc++.h>

using namespace std;

int semilla=0;


  video::video(){
    id=0;
    nombre=""; 
    genero=""; 
    calificacion=0;
    duracion=0; 
    num_reviews=0;
  }

  video::video(string nombre_, string genero_, int duracion_){
    id=0;
    nombre=nombre_; 
    genero=genero_; 
    calificacion=0;
    duracion=duracion_; 
    num_reviews=0;
  }

  video::video(string nombre_, int duracion_){
    id=0;
    nombre=nombre_; 
    genero=""; 
    calificacion=0;
    duracion=duracion_; 
    num_reviews=0;
  }

  video::video(string nombre_, string genero_){
    id=0;
    nombre=nombre_; 
    genero=genero_; 
    calificacion=0;
    duracion=0; 
    num_reviews=0;
  }
    
  void video::set_id(){
    id=semilla;
    semilla++;
  }

  void video::set_nombre(string nombre_){
    nombre=nombre_;
  }

  void video::set_genero(string genero_){
    genero=genero_;
  } 

  void video::set_duracion(int minutos){
    duracion=minutos;
  } 

  void video::set_calificacion(double calif){
    calificacion=calif;
  }

  int video::get_id(){
    return id;
  }

  string video::get_nombre(){
    return nombre;
  } 

  string video::get_genero(){
    return genero;
  } 

  double video::get_calificacion(){
    return calificacion;
  }

  int video::get_duracion(){
    return duracion;
  }

  void video::set_num_reviews(int cero){
    num_reviews=0;
  }

  int video::get_num_reviews(){
    return num_reviews;
  }

  void video::update_calificacion(int numero){
    double suma_anterior=num_reviews*calificacion;
    suma_anterior+=numero;
    num_reviews++;
    calificacion=suma_anterior/num_reviews;
  } 

  void video::imprime(){
    cout<<"--------------------------------------------\n";
    cout<<"Nombre: "<<get_nombre()<<"\n";
    cout<<"Género: "<<get_genero()<<"\n";
    cout<<"Duración: "<<get_duracion()<<" minutos \n";
    cout<<"Calificación: "<<get_calificacion()<<"\n";
    cout<<"--------------------------------------------\n";
  }


  bool operator <(video a, video b){
    if(a.get_calificacion()>b.get_calificacion()){
      return false;
    }
    return true;
  }

  bool operator >(video a, video b){
    if(a.get_calificacion()>b.get_calificacion()){
      return true;
    }
    return false;
  }


// Funciones miembro de clase episodio
  episodio::episodio(){
    set_nombre("");
    set_temporada("");
    set_duracion(0);
    set_calificacion(0);
    set_num_reviews(0);
    set_id(0);
  }

  episodio::episodio(string nombre_, string temporada_, int duracion_):video(nombre_,duracion_){
    set_temporada(temporada_);
  }

  void episodio::set_id(int tamaño_vector){
    id=tamaño_vector;
  } 

  void episodio::set_temporada(string temporada_){
    temporada=temporada_;
  } 

  string episodio::get_temporada(){
    return temporada;
  }

  void episodio::imprime(){
    cout<<"--------------------------------------------\n";
    cout<<"Episodio\n";
    cout<<"Nombre: "<<get_nombre()<<"\n";
    cout<<"Temporada: "<<get_temporada()<<"\n";
    cout<<"Duración: "<<get_duracion()<<" minutos\n";
    cout<<"Calificación: "<<get_calificacion()<<"\n";
    cout<<"--------------------------------------------\n";
  }

// Funciones miembro de clase series
  series::series(){
    set_nombre("");
    set_genero("");
    set_duracion(0);
    set_calificacion(0);
    set_id();
    episodios={};
  }

  series::series(string nombre_, string genero_):video(nombre_,genero_){
    set_id();
    episodios={};
  }

  void series::insert_episodio(episodio capitulo){
    episodios.push_back(capitulo);
    update_duracion();
    update_calificacion();
    capitulo.set_id(episodios.size()-1);
  }

  void series::update_calificacion(){
    double calificacion_total=0;
    double cont=0;
    for(int i=0;i<episodios.size();i++){
      if(episodios[i].get_num_reviews()!=0){
        calificacion_total+=episodios[i].get_calificacion();
        cont++;
      }
    }
    set_calificacion(calificacion_total/cont);
  }

  void series::update_duracion(){
    int duracion_total=0;
    for(int i=0;i<episodios.size();i++){
      duracion_total+=episodios[i].get_duracion();
    }
    set_duracion(duracion_total);
  } 
void series::imprime(){
    cout<<"--------------------------------------------\n";
    cout<<"Serie\n";
    cout<<"Nombre: "<<get_nombre()<<"\n";
    cout<<"Género: "<<get_genero()<<"\n";
    cout<<"Duración: "<<get_duracion()<<" minutos\n";
    cout<<"Calificación: "<<get_calificacion()<<"\n";
    cout<<"--------------------------------------------\n";
  }

// Funciones miembro de clase pelicula
  pelicula::pelicula(){
    set_nombre("");
    set_genero("");
    set_duracion(0);
    set_calificacion(0);
    set_num_reviews(0);
    set_id();
  }

   pelicula::pelicula(string nombre_, string genero_, int duracion_): video(nombre_,genero_,duracion_){
    set_id();
  }

void pelicula::imprime(){
    cout<<"--------------------------------------------\n";
    cout<<"Película\n";
    cout<<"Nombre: "<<get_nombre()<<"\n";
    cout<<"Género: "<<get_genero()<<"\n";
    cout<<"Duración: "<<get_duracion()<<" minutos\n";
    cout<<"Calificación: "<<get_calificacion()<<"\n";
    cout<<"--------------------------------------------\n";
  }
