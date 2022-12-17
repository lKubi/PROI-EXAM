// 09/12/2022 Luis Fernando Pérez Moure
// Proba Práctica de PROI_7

#include <iostream>
#include "functions.h"

using namespace std;

int main(){
    string buffer;

    Libro miLibro;

    crearLibro(miLibro);

    int tam;
    Libro * arr_libros;

    cout << "\nCuantos libros quieres guardar: ";
    cin >> tam;
    getline(cin, buffer);

    if((arr_libros = new Libro [tam]) == NULL){
        cout << "Error" << endl;
    }

    leerLibrosArray(arr_libros, tam);

    string editorial;
    cout << "\nDe que editorial quieres mostrar los libros: ";
    getline(cin, editorial);

    mostrarPorEditorial(arr_libros, tam, editorial);

    string nombre;
    cout << "\nQue nombre le quieres poner al archivo? (Anhadir .txt al final): ";
    getline(cin, nombre);
    guardarFichero(arr_libros, tam, nombre);
    cout << "Archivo Guarado!";

    delete [] arr_libros;

}
