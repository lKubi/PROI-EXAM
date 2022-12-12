#include <iostream>
#include "functions.h"
#include <string.h>
#include <fstream>

using namespace std;

void crearLibro(Libro &l){

    string buffer;
    cout << "Introduce el titulo del libro (cadena): ";
    getline(cin, l.titulo);
    cout << "\nIntroduce el ISBN del libro (entero): ";
    cin >> l.ISBN;
    getline(cin, buffer);
    cout << "\nIntroduce la editorial del libro (cadena): ";
    getline(cin, l.editorial);
    do{
        cout << "\nIntroduce el tipo del libro (0- Electronico, 1- Tapa Blanda, 2- Tapa dura): ";
        cin >> l.tipoLibro;
        getline(cin, buffer);
    }while(l.tipoLibro < 0 || l.tipoLibro > 2);
}

/* FUNCION PARA PASAR DE ENUMERADO A TEXTO PERO NO ME DEJABA USAR ENUMERADOS

char * int_a_TipodeLibro(int tipoLibro){
    switch (tipoLibro){
        case 0:
            return "Electronico";
            break;
        case 1:
            return "Tapa Blanda";
            break;
        case 2:
            return "Tapa dura";
            break;
    };
}
*/

void mostrarLibro(Libro l){
    cout << "Titulo: " << l.titulo << endl;
    cout << "ISBN: " << l.ISBN << endl;
    cout << "Editorial: " << l.editorial << endl;
    cout << "Tipo de Libro (0- Electronico, 1- Tapa Blanda, 2- Tapa dura): " << l.tipoLibro << endl;
}

void leerLibrosArray(Libro arr_libros [], int tam){
    for(int i = 0; i < tam; i++){
        cout << "\nLibro " << i+1 << endl;
        crearLibro(arr_libros[i]);
    }
}

void mostrarPorEditorial(Libro arr_libros [], int tam, string editorial){

    for(int i = 0; i < tam; i++){
        if(arr_libros[i].editorial == editorial){
            cout << endl;
            mostrarLibro(arr_libros [i]);
        }
    }
}

void guardarFichero(Libro arr_libros [], int tam, string nombre){
    ofstream fichero;
    int contador [3] = {0, 0, 0};

    for(int i = 0; i < tam; i++){
        switch (arr_libros[i].tipoLibro){
            case 0:
                contador [0]++;
                break;
            case 1:
                contador [1]++;
                break;
            case 2:
                contador [2]++;
                break;
        };
    }

    fichero.open(nombre);
    if(!fichero){
        cout << "Error!";
        exit(-1);
    }

    fichero << "Electronico: " << contador[0] << endl;
    fichero << "Tapa blanda: " << contador[1] << endl;
    fichero << "Tapa dura: " << contador[2] << endl;

    fichero.close();
}
