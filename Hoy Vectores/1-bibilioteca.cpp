#include <iostream>
#include <string>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio;
    string ISBN;
};

void agregarLibro(Libro biblioteca[], int &totalLibros) {
    if (totalLibros >= 100) {
        cout << "¡Biblioteca llena!\n";
        return;
    }

    cout << "Ingrese título: ";
    cin.ignore();
    getline(cin, biblioteca[totalLibros].titulo);

    cout << "Ingrese autor: ";
    getline(cin, biblioteca[totalLibros].autor);

    cout << "Ingrese año: ";
    cin >> biblioteca[totalLibros].anio;

    cout << "Ingrese ISBN: ";
    cin >> biblioteca[totalLibros].ISBN;

    totalLibros++;
    cout << "Libro agregado.\n";
}

void mostrarLibros(const Libro biblioteca[], int totalLibros) {
    if (totalLibros == 0) {
        cout << "No hay libros registrados.\n";
        return;
    }

    cout << "\n--- LIBROS REGISTRADOS ---\n";
    for (int i = 0; i < totalLibros; i++) {
        cout << "Título: " << biblioteca[i].titulo << endl;
        cout << "Autor: " << biblioteca[i].autor << endl;
        cout << "Año: " << biblioteca[i].anio << endl;
        cout << "ISBN: " << biblioteca[i].ISBN << "\n\n";
    }
}

void buscarLibro(const Libro biblioteca[], int totalLibros) {
    string ISBN;
    cout << "Ingrese ISBN a buscar: ";
    cin >> ISBN;

    bool encontrado = false;
    for (int i = 0; i < totalLibros; i++) {
        if (biblioteca[i].ISBN == ISBN) {
            cout << "\nLibro encontrado:\n";
            cout << "Título: " << biblioteca[i].titulo << endl;
            cout << "Autor: " << biblioteca[i].autor << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Libro no registrado.\n";
    }
}

int main() {
    Libro biblioteca[100];
    int totalLibros = 0;
    int opcion;

    do {
        cout << "\n--- MENÚ BIBLIOTECA ---\n";
        cout << "1. Agregar libro\n";
        cout << "2. Mostrar todos los libros\n";
        cout << "3. Buscar libro por ISBN\n";
        cout << "4. Salir\n";
        cout << "Ingrese opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarLibro(biblioteca, totalLibros); break;
            case 2: mostrarLibros(biblioteca, totalLibros); break;
            case 3: buscarLibro(biblioteca, totalLibros); break;
            case 4: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 4);

    return 0;
}