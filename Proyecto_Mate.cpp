// Proyecto_Mate.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//JULIO CESAR ESPINOZA VASQUEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <locale.h>



int main() {

    std::cout << " \tHola Bienvenido al taller del Machin\n\n ";
    std::cout << "Que mejoras deseas ponerle a tu coche?\n";
    std::cout << "HEAD, BLOCK, ECU, TURBO, EXHAUST, GEARBOX\n\n";

    // Lista de mejoras disponibles
    std::vector<std::string> mejoras = { "HEAD", "BLOCK", "ECU", "TURBO", "EXHAUST", "GEARBOX" };

    // Preguntar al usuario qué mejoras desea
    std::vector<std::string> mejoras_usuario;
    std::string mejora;
    while (mejoras_usuario.size() < 6 && mejora != "fin") {
        std::cout << "Ingrese una mejora para su vehiculo (o escriba 'fin' para terminar): ";
        std::cin >> mejora;
        if (find(mejoras.begin(), mejoras.end(), mejora) != mejoras.end()) {
            mejoras_usuario.push_back(mejora);
        }
        else if (mejora != "fin") {
            std::cout << "Mejora no disponible. Por favor seleccione otra. " << std::endl;
        }
    }

    // Mostrar combinaciones y permutaciones de mejorassssssssssss
    std::cout << std::endl << "Combinaciones de mejoras: " << std::endl;
    int contador = 0;
    for (int i = 1; i <= mejoras_usuario.size(); i++) {
        std::vector<int> indices(i);
        for (int j = 0; j < i; j++) {
            indices[j] = j;
        }
        bool terminado = false;
        while (!terminado) {
            std::vector<std::string> combinacion(i);
            for (int j = 0; j < i; j++) {
                combinacion[j] = mejoras_usuario[indices[j]];
            }
            contador++;
            std::cout << contador << ") ";
            for (auto const& m : combinacion) {
                std::cout << m << ",";
            }
            std::cout << std::endl;

            int j = i - 1;
            while (j >= 0 && indices[j] == (int)mejoras_usuario.size() - i + j) {
                j--;
            }
            if (j == -1) {
                terminado = true;
            }
            else {
                indices[j]++;
                for (int k = j + 1; k < i; k++) {
                    indices[k] = indices[k - 1] + 1;
                }
            }
        }
    }

    std::cout << std::endl << "Permutaciones de mejoras: " << std::endl;
    int contador2 = 0;
    std::sort(mejoras_usuario.begin(), mejoras_usuario.end());
    do {
        contador2++;
        std::cout << contador2 << ") ";
        for (auto const& m : mejoras_usuario) {
            std::cout << m << ", ";
        }
        std::cout << std::endl;
    } while (next_permutation(mejoras_usuario.begin(), mejoras_usuario.end()));


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
