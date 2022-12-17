#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define MAXCADENA 50

#include <iostream>
using namespace std;;

//QUERIA USAR ENUMERADOS PERO NO ME DEJA LEERLOS POR TECLADO
// enum tipo_libro {ELECTRONICO, TAPA_DURA, TAPA_BLANDA};

struct Libro{
    int ISBN;
    string titulo;
    string editorial;
    int tipoLibro;
};

void crearLibro(Libro &l);
void mostrarLibro(Libro l);
void leerLibrosArray(Libro arr_libros [], int tam);
void mostrarPorEditorial(Libro arr_libros [], int tam, string editorial);
void guardarFichero(Libro arr_libros [], int tam, string editorial);

#endif // FUNCTIONS_H_INCLUDED
