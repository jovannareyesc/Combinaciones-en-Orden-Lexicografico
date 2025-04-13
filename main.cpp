#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdlib>

int* conjunto(int n);
void imprimir_conjunto(int arr[], int tam);
void generar_combinaciones(int n, int r, unsigned long long &contador);
long double factorial(int n);
long double combinaciones(int n, int r);

using namespace std;
using namespace filesystem;

int main() {
    int n;
    int r;
    unsigned long long contador_combinaiones;

    cout << "Este programa genera las r-Combinaciones del conjunto {1, 2, ..., n}, con n menores o iguales a 1574." << endl;
    do {
        cout << "Introduzca el tamaño \"n\" del conjunto: ";
        cin >> n;
    }while (n < 1 || n > 1574);
    do {
        cout << "Introduzca el tamaño \"r\" de los subconjuntos con combinaciones: ";
        cin >> r;
    }while (r < 0 || r > n);

    cout << endl;
    cout << "Combinaciones posibles (coeficiente binomial): " << combinaciones(n, r) << endl;
    cout << endl;
    cout << "Lista de combinaciones: " << endl;

    generar_combinaciones(n, r, contador_combinaiones);

    if (combinaciones(n, r) == contador_combinaiones) {
        cout << "El coeficiente binomial y el contador de conjuntos coinciden, ambos son de " << contador_combinaiones << "." <<endl;
    }
    else {
        cout << "El coeficiente binomial y el contador de conjuntos NO coinciden, hubo un error." << endl;

    }

    string n_string = to_string(n);
    string r_string = to_string(r);
    string file = "\"combinaciones_n(" + n_string + ")_r(" + r_string + ")\"" ;

    path currentDir = current_path();
    string pathStr = currentDir.string();
    cout << "El archivo con extensión .csv se encuentra en la dirección: " << pathStr << " con el nombre de " << file << endl;

    return 0;
}

void imprimir_conjunto(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << arr[i];
        if (i != tam - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

void generar_combinaciones(int n, int r, unsigned long long &contador) {
    int s[r];
    for (int i = 0; i < r; i++) {
        s[i] = i + 1;
    }

    string n_string = to_string(n);
    string r_string = to_string(r);
    string file = "combinaciones_n(" + n_string + ")_r(" + r_string + ").csv" ;

    ofstream outFile(file);
    outFile << "NumCombinacion, Combinaciones," << endl << "1,";
    outFile << "\"";
    for (int i = 0; i < r; i++) {
        outFile << s[i];
        if (i != r - 1) {
            outFile << ", ";
        }
    }
    outFile << "\"," << endl;

    contador = 1;
    cout << contador << ".- ";
    imprimir_conjunto(s, r);

    while (true) {
        int m = r - 1;
        int val_max = n;

        while (m >= 0 && s[m] == val_max) {
            m--;
            val_max--;
        }
        if (m < 0) {
            break;
        }

        s[m]++;

        for (int i = m + 1; i < r; i++) {
            s[i] = s[i - 1] + 1;
        }

        contador++;
        outFile << contador << ",";
        outFile << "\"";
        for (int i = 0; i < r; i++) {
            outFile << s[i];
            if (i != r - 1) {
                outFile << ", ";
            }
        }
        outFile << "\"," << endl;

        cout << contador << ".- ";
        imprimir_conjunto(s, r);
    }
}

long double factorial(int n) {
    if (n == 0) {
        return 1;
    }
    long double fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
    }
    return fac;
}

long double combinaciones(int n, int r){
    int aux = n - r;
    return factorial(n) / (factorial(aux) * factorial(r));
}
