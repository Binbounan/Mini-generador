#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

bool esIdentificador(const string& entrada) {
    if (entrada.empty() || !(isalpha(entrada[0]) || entrada[0] == '_'))
        return false;
    for (size_t i = 1; i < entrada.size(); ++i) {
        if (!isalnum(entrada[i]) && entrada[i] != '_')
            return false;
    }
    return true;
}

bool esNumeroReal(const string& entrada) {
    bool tienePunto = false;
    bool tieneDigitoAntes = false;
    bool tieneDigitoDespues = false;

    for (size_t i = 0; i < entrada.size(); ++i) {
        if (entrada[i] == '.') {
            if (tienePunto)
                return false; // Más de un punto
            tienePunto = true;
        } else if (isdigit(entrada[i])) {
            if (!tienePunto)
                tieneDigitoAntes = true;
            else
                tieneDigitoDespues = true;
        } else {
            return false; // Caracter no permitido
        }
    }

    // Si no hay punto, es un entero válido (también considerado número real en este caso)
    if (!tienePunto)
        return true;

    // Debe tener un punto con al menos un dígito antes y después
    return tienePunto && tieneDigitoAntes && tieneDigitoDespues;
}

string detectarTipo(const string& entrada) {
    if (esIdentificador(entrada))
        return "Identificador";
    if (esNumeroReal(entrada))
        return "Numero Real";
    return "Error";
}

int main() {
    string linea;

    while (true) {
        cout << "Ingresa valores separados por espacios (o escribe 'salir' para terminar): ";
        getline(cin, linea);

        if (linea == "salir") {
            cout << "Programa terminado." << endl;
            break;
        }

        stringstream ss(linea);
        string valor;
        vector<string> resultados;

        while (ss >> valor) {
            string tipo = detectarTipo(valor);
            resultados.push_back("\"" + valor + "\" es de tipo: " + tipo);
        }

        for (const string& resultado : resultados) {
            cout << resultado << endl;
        }
    }

    return 0;
}
