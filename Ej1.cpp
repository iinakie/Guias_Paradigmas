#include "include.cpp"

/*
1. Escriba un programa que, indicado un tipo de dato, devuelve el tamaño de la variable.
Utilice switch y enum
*/

/*
enum TipoDato { 
    ENTERO = 1, 
    FLOTANTE = 2, 
    DOBLE = 3, 
    CARACTER = 4, 
    BOOLEANO = 5
};

void mostrarMenu() {
    cout << "Seleccione un tipo de dato para conocer su tamaño:\n";
    cout << "1. Entero (int)\n";
    cout << "2. Flotante (float)\n";
    cout << "3. Doble (double)\n";
    cout << "4. Caracter (char)\n";
    cout << "5. Booleano (bool)\n";
}

void mostrarDatos(int opcion) {
    switch (opcion) {
        case ENTERO:
            cout << "El tamaño de un entero (int) es: " << sizeof(int) << " bytes\n";
            break;
        case FLOTANTE:
            cout << "El tamaño de un flotante (float) es: " << sizeof(float) << " bytes\n";
            break;
        case DOBLE:
            cout << "El tamaño de un doble (double) es: " << sizeof(double) << " bytes\n";
            break;
        case CARACTER:
            cout << "El tamaño de un caracter (char) es: " << sizeof(char) << " bytes\n";
            break;
        case BOOLEANO:
            cout << "El tamaño de un booleano (bool) es: " << sizeof(bool) << " bytes\n";
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione un número entre 1 y 5.\n";
            break;
    }
}

int main() {
    int opcion;
    mostrarMenu();
    cout << "Ingrese su opción (1-5): ";
    cin >> opcion;
    mostrarDatos(opcion);
    return 0;
}
*/
// ###################################################################################################################################################


/*
2. Escriba un programa donde se ingresen dos números separados por un espacio, luego
se ingrese una operación entre ellos (+, -, *, / y %) y devuelva el resultado. Para ello
utilice switch y enum.
*/
/*
enum Operacion{
    SUMA = 1,
    RESTA = 2,
    MULTIPLICACION = 3,
    DIVISION = 4,
    MODULO = 5
};

void Cuenta(){
    int num1, num2, operacion;
    cout << "Ingrese dos numeros separados por un espacio: ";
    cin >> num1 >> num2;
    cout << "Seleccione la operacion a realizar:\n";
    cout << "1. Suma (+)\n";
    cout << "2. Resta (-)\n";
    cout << "3. Multiplicacion (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Modulo (%)\n";
    cout << "Ingrese su opcion (1-5): ";
    cin >> operacion;

    switch (operacion) {
        case SUMA:
            cout << "La suma entre " << num1 << " y " << num2 << " es:" << num1 + num2 << endl;
            break;
        case RESTA:
            cout << "La suma entre " << num1 << " y " << num2 << " es:" << num1 - num2 << endl;
            break;
        case MULTIPLICACION:
            cout << "La suma entre " << num1 << " y " << num2 << " es:" << num1 * num2 << endl;
            break;
        case DIVISION:
            cout << "La suma entre " << num1 << " y " << num2 << " es:" << num1 / num2 << endl;
            break;
        case MODULO:
            cout << "La suma entre " << num1 << " y " << num2 << " es:" << num1 % num2 << endl;
            break;
        default:
            cout << "no elegiste ningun numero.";
            break;
    }
}

int main(){
    Cuenta();
}
*/

// ###################################################################################################################################################

/*
3. Utilizando recursión, verifique que el número ingresado es un número primo. ¿Cómo
podría hacer el algoritmo más eficiente? Implemente su respuesta.
*/
/*
void esPrimo(int num, int divisor){
    if (num < 2) {
        cout << num << " no es un numero primo." << endl;
        return;
    }
    if (divisor > sqrt(num)) {
        cout << num << " es un numero primo." << endl;
        return;
    }
    if (num % divisor == 0) {
        cout << num << " no es un numero primo." << endl;
        return;
    }
    esPrimo(num, divisor + 1);
}
int main(){
    int numero;
    cout << "Ingrese un numero para verificar si es primo: ";
    cin >> numero;
    esPrimo(numero, 2);
    return 0;
}

/*

// ###################################################################################################################################################
/*
4. Escriba un programa que, dado un string, devuelve la cantidad de caracteres e indica
si se trata de un palíndromo.
*/
/*
int esPalindromo(const string &str, int inicio, int fin) {
    if (inicio >= fin) {
        return 1; // Es palíndromo
    }
    if (str[inicio] != str[fin]) {
        return 0; // No es palíndromo
    }
    return esPalindromo(str, inicio + 1, fin - 1);
}

int main(){
    string palabra;
    cout << "Escribi una palabra para ver si es palindromo o no: " << endl;
    cin >> palabra;
    esPalindromo(palabra, 0, palabra.length() - 1) 
    ? cout << palabra << " es palindromo y tiene " << palabra.length() << " caracteres." << endl 
    : cout << palabra << " no es palindromo y tiene " << palabra.length() << " caracteres." << endl;
}
*/

// ####################################################################################################################################################

/*
5. Dado un array de números, escribir un programa que cuente la frecuencia de
ocurrencia de los mismos y grafique de la forma en que se muestra en el siguiente
ejemplo:
a = {3, 1, 2, 3, 4, 1, 2, 3, 4, 4}
Distribución de Frecuencia:
1 - ** (2)
2 - ** (2)
3 - *** (3)
4 - *** (3)
*/
/*
void frecuenciaOcurrencia(const vector<int> &arr) {
    map<int, int> frecuencia;
    for (int num : arr) {
        frecuencia[num]++;
    }
    cout << "Distribución de Frecuencia:\n";
    for (const auto &par : frecuencia) {
        cout << par.first << " - " << string(par.second, '*') << " (" << par.second << ")\n";
    }
}

int main() {
    vector<int> a = {3, 1, 2, 3, 4, 1, 2, 3, 4, 4, 4, 4};
    frecuenciaOcurrencia(a);
    return 0;
}
*/

// ####################################################################################################################################################

/*

*/