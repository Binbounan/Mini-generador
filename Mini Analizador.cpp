#include <iostream>

#include <string>

#include <cctype>

#include <sstream>



using namespace std;



string detectarTipo(const string& entrada) {

    bool esEntero = true, esReal = true;

    int puntoDecimal = 0;



    // Verificar cada carácter de la entrada

    for (size_t i = 0; i < entrada.size(); ++i) {

        if (entrada[i] == '.') {

            puntoDecimal++;

            if (puntoDecimal > 1) {

                esEntero = false;

                esReal = false;

                break;

            }

        } else if (!isdigit(entrada[i]) && !(i == 0 && (entrada[i] == '-' || entrada[i] == '+'))) {

            esEntero = false;

            esReal = false;

            break;

        }

    }



    if (esEntero && puntoDecimal == 0)

        return "Entero";

    if (esReal && puntoDecimal == 1)

        return "Número Real";



    return "Cadena";

}



int main() {

    string entrada;



    while (true) {

        cout << "Ingresa un valor (o escribe 'salir' para terminar): ";

        getline(cin, entrada);



        if (entrada == "salir") {

            cout << "Programa terminado." << endl;

            break;

        }



        string tipo = detectarTipo(entrada);

        cout << "El valor '" << entrada << "' es de tipo: " << tipo << endl;

    }



    return 0;

}