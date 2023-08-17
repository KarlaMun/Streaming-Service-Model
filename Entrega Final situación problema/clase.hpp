#ifndef CLASE_H
#define CLASE_H

#include <bits/stdc++.h>
using namespace std;

class video{
public:
  video(); // constructor
  video(string nombre_, string genero_, int duracion_); // constructor
  video(string nombre_, int duracion_); // constructor
  video(string nombre_, string genero_); // constructor
  void set_id(); //definir id con semilla
  void set_nombre(string nombre); // definir nombre
  void set_genero(string genero); //definir genero
  void set_duracion(int minutos); //definir duracion
  void set_calificacion(double calif); //definir calificacion
  void set_num_reviews(int cero); //definir num reseñas
  int get_num_reviews(); // obtener num reseñas
  int get_id(); // obtener id
  string get_nombre(); // obtener nombre
  string get_genero(); // obtener genero
  double get_calificacion(); // obtener calificacion
  int get_duracion(); // obtener duracion
  virtual void imprime(); // Display de información
  void update_calificacion(int numero); // actualizar calificacion
  friend bool operator <(video a, video b); // comparar calificaciones entre videos
  friend bool operator >(video a, video b); // comparar calificaciones entre videos

private:
  string nombre; // nombre del video
  string genero; // genero cinematográfico
  double calificacion; // calificacion promedio con decimales
  int duracion; // duracion en minutos neta

protected:
  int id; // Identificador
  int num_reviews; // numero de reseñas dadas
};

class episodio:public video{
public:
  episodio(); // constructor
  episodio(string nombre_, string temporada_, int duracion_); // constructor
  void set_id(int tamaño_vector); //definir id con tamaño de la serie
  void set_temporada(string temporada); //definir temporada
  string get_temporada(); // obtener temporada
  virtual void imprime(); // Display de información

private:
  string temporada; // numero de temporada
};

class series: public video{
private:
public:
  vector<episodio> episodios; // almacenar capitulos
  series(); // constructor
  series(string nombre_, string genero_); // constructor
  void insert_episodio(episodio capitulo); // insertar capitulo nuevo
  void update_calificacion(); // actualizar calificacion
  void update_duracion(); // actualizar duracion
  virtual void imprime(); // Display de información
};

class pelicula: public video{
public:
  pelicula();//constructor
  pelicula(string nombre, string genero, int duracion); // constructor
virtual void imprime(); // Display de información
};

#endif //CLASE_H