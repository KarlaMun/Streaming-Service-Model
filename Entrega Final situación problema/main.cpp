#include "../include/clase.hpp"
#include "../include/menu.hpp"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  // freopen("Situacion_problema.txt", "w", stdout);
  vector<pelicula> peliculas;
  vector<series> seriess;

  // Definición de variables
  pelicula lasirenita("La Sirenita", "Comedia", 83);
  pelicula increibles("Los Increíbles", "Acción", 105);
  pelicula toystory("Toy Story", "Comedia", 81);
  pelicula nemo("Buscando a Nemo", "Comedia", 100);
  pelicula coraline("Coraline", "Terror", 100);
  pelicula cisnenegro("El cisne negro", "Drama", 108);

  series strangerthings("Stranger Things", "Terror");
  series theflash("The Flash", "Acción");

  episodio vanishing("The vanishing of Will Byers", "1", 49);
  episodio weirdo("The weirdo of maple street", "1", 56);
  episodio madmax("MADMAX", "2", 54);
  episodio trick("Trick or Treat, Freak", "2", 52);
  episodio pilot("Pilot", "1", 44);
  episodio fastestman("Fastest Man Alive", "1", 43);
  episodio mansaved("The man who saved central city", "2", 41);
  episodio twoworlds("Flash of Two Worlds", "2", 44);

  // Creación de base de datos
  peliculas.push_back(lasirenita);
  peliculas.push_back(increibles);
  peliculas.push_back(toystory);
  peliculas.push_back(nemo);
  peliculas.push_back(coraline);
  peliculas.push_back(cisnenegro);

  strangerthings.insert_episodio(vanishing);
  strangerthings.insert_episodio(weirdo);
  strangerthings.insert_episodio(madmax);
  strangerthings.insert_episodio(trick);
  theflash.insert_episodio(pilot);
  theflash.insert_episodio(fastestman);
  theflash.insert_episodio(mansaved);
  theflash.insert_episodio(twoworlds);

  seriess.push_back(strangerthings);
  seriess.push_back(theflash);

  // Cambio de calificaciones
  peliculas[0].update_calificacion(1);
  peliculas[0].update_calificacion(2);
  peliculas[0].update_calificacion(3);
  peliculas[0].update_calificacion(3);
  peliculas[0].update_calificacion(5);

  peliculas[1].update_calificacion(3);
  peliculas[1].update_calificacion(3);
  peliculas[1].update_calificacion(4);
  peliculas[1].update_calificacion(5);

  seriess[0].episodios[0].update_calificacion(3);
  seriess[1].episodios[0].update_calificacion(4);
  seriess[1].episodios[0].update_calificacion(5);
  seriess[1].episodios[1].update_calificacion(5);

  for (int i = 0; i < seriess.size(); i++) {
    seriess[i].update_calificacion();
  }

  // Despligue de menú en bucle
  int opcion = 0;
  while (true) {
    int opcion = printMenu();
    if (opcion == 0) {
      string nombre, genero;
      int min;
      cout << "Nombre: ";
      getline(cin, nombre);
      getline(cin, nombre);
      cout << "Género: ";
      cin >> genero;
      cout << "Duración en minutos: ";
      cin >> min;
      pelicula nuevaPeli(nombre, genero, min);
      peliculas.push_back(nuevaPeli);
    } else if (opcion == 1) {
      string nombre, genero;
      cout << "Nombre: ";
      getline(cin, nombre);
      getline(cin, nombre);
      cout << "Género: ";
      cin >> genero;
      series nuevaSerie(nombre, genero);
      seriess.push_back(nuevaSerie);
    } else if (opcion == 2) {
      string serie;
      cout << "Serie: ";
      cin >> serie;

      string nombre, temporada;
      int min;
      cout << "Nombre: ";
      getline(cin, nombre);
      getline(cin, nombre);
      cout << "Temporada (nombre o número): ";
      getline(cin, temporada);
      cout << "Duración en minutos: ";
      cin >> min;
      episodio nuevoEpi(nombre, temporada, min);
      for (int i = 0; i < seriess.size(); i++) {
        if (seriess[i].get_nombre() == serie) {
          seriess[i].insert_episodio(nuevoEpi);
          break;
        }
      }
    } else if (opcion == 3) {
      string pelicula;
      cout << "Película: ";
      getline(cin, pelicula);
      getline(cin, pelicula);
      int cali;
      cout << "Calificación (número entero del 1 al 5): ";
      cin >> cali;
      for (int i = 0; i < peliculas.size(); i++) {
        if (peliculas[i].get_nombre() == pelicula) {
          peliculas[i].update_calificacion(cali);
          break;
        }
      }
    } else if (opcion == 4) {
      string serie, capitulo;
      cout << "Serie: ";
      getline(cin, serie);
      getline(cin, serie);
      cout << "Capítulo: ";
      getline(cin, capitulo);
      int cali;
      cout << "Calificación (número entero del 1 al 5): ";
      cin >> cali;
      for (int i = 0; i < seriess.size(); i++) {
        if (seriess[i].get_nombre() == serie) {
          for (int j = 0; j < seriess[i].episodios.size(); j++) {
            if (seriess[i].episodios[j].get_nombre() == capitulo) {
              seriess[i].episodios[j].update_calificacion(cali);
              seriess[i].update_calificacion();
              break;
            }
          }
          break;
        }
      }
    } else if (opcion == 5) {
      string pelicula;
      cout << "Película: ";
      getline(cin, pelicula);
      getline(cin, pelicula);
      for (int i = 0; i < peliculas.size(); i++) {
        if (peliculas[i].get_nombre() == pelicula) {
          peliculas[i].imprime();
          break;
        }
      }
    } else if (opcion == 6) {
      string serie;
      cout << "Serie: ";
      getline(cin, serie);
      getline(cin, serie);
      for (int i = 0; i < seriess.size(); i++) {
        if (seriess[i].get_nombre() == serie) {
          seriess[i].imprime();
          break;
        }
      }
    } else if (opcion == 7) {
      string serie,capitulo;
      cout << "Serie: ";
      getline(cin, serie);
      getline(cin, serie);
      cout << "Capítulo: ";
      getline(cin, capitulo);
      for (int i = 0; i < seriess.size(); i++) {
        if (seriess[i].get_nombre() == serie) {
          for (int j = 0; j < seriess[i].episodios.size(); j++) {
            if (seriess[i].episodios[j].get_nombre() == capitulo) {
              seriess[i].episodios[j].imprime();
              break;
            }
          }
          break;
        }
      }
    } else if (opcion == 8) {
      for (auto peli : peliculas) {
        peli.imprime();
      }
      for (auto seri : seriess) {
        seri.imprime();
      }
    }else if (opcion == 9) {
      pelicula actual_pelicula;
      for(auto peli:peliculas){
        if(peli>actual_pelicula){
          actual_pelicula=peli;
        }
      }
      actual_pelicula.imprime();
    }else if (opcion == 10) {
      series actual_serie;
      for(auto seri:seriess){
        if(seri>actual_serie){
          actual_serie=seri;
        }
      }
      actual_serie.imprime();
    }else if (opcion == 11) {
      string serie;
      episodio actual_episodio;
      cout << "Serie: ";
      getline(cin, serie);
      getline(cin, serie);
      for (int i = 0; i < seriess.size(); i++) {
        if (seriess[i].get_nombre() == serie) {
          for (int j = 0; j < seriess[i].episodios.size(); j++) {
            if (seriess[i].episodios[j]> actual_episodio) {
              actual_episodio=seriess[i].episodios[j];
            }
          }
          break;
        }
      }
      actual_episodio.imprime();
    }else if (opcion == 12) {
      break;
    } else {
      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
      cout << "Por favor ingresa una opción válida" << endl;
      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    }
  }

  return 0;
}