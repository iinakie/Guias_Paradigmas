#include "include.cpp"

/*
1. Escriba un programa con una clase denominada Conductor cuyos atributos son:
nombre, tensión (en Volsts, V) y corriente eléctrica (en Amperes, A). Sus métodos
incluyen calcularResistencia (que utiliza la ley de Ohm para este cálculo R = V/I),
establecer y obtener corriente y tensión.
Genere una tabla donde calcula la resistencia de 10 conductores distintos.
*/

class Conductor {
private:
    string nombre; 
    double tension; // en Volts
    double corriente; // en Amperes
public:
    Conductor(string n, double t, double c) : nombre(n), tension(t), corriente(c) {}
    double calcularResistencia() {
        if (corriente == 0) {
            throw runtime_error("La corriente no puede ser cero para calcular la resistencia.");
        }
        return tension / corriente; // R = V / I
    }
    string getNombre() const { return nombre; }
    double getTension() const { return tension; }
    double getCorriente() const { return corriente; }
    void setTension(double t) { tension = t; }
    void setCorriente(double c) { corriente = c; }
};

//#########################################################################################################

/*
3. Cree un programa con una clase denominada Fecha, con los atributos dia, mes y año.
Se pide:
3.1. Construir un constructor default sin parámetros que construya un objeto para el
día 01/01/2000. Al mismo tiempo, construya los constructores donde se pueden
pasar solamente el día, el día y el mes, y el día, el mes y el año. Estos permitirán
establecer cambios a la fecha default (si sólo se ingresa la fecha 13, la fecha será
13/01/2000).
3.2. Construya los setters y los getters de los atributos, y un método para mostrar la
fecha ingresada.
3.3. Sobrecargue los operadores == y != para comparar las fechas.
*/
/*
class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    // Constructor default
    Fecha() : dia(1), mes(1), anio(2000) {}
    // Constructor con día
    Fecha(int d) : dia(d), mes(1), anio(2000) {}
    // Constructor con día y mes
    Fecha(int d, int m) : dia(d), mes(m), anio(2000) {}
    // Constructor con día, mes y año
    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}
    // Setters
    void setDia(int d) { dia = d; } 
    void setMes(int m) { mes = m; }
    void setAnio(int a) { anio = a; }
    // Getters
    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAnio() const { return anio; }
    // Mostrar fecha
    void mostrarFecha() const {
        cout << setfill('0') << setw(2) << dia << "/"
             << setfill('0') << setw(2) << mes << "/"
             << anio << endl;
    }
    // Sobrecarga de operadores
    bool operator==(const Fecha &otra) const {
        return (dia == otra.dia && mes == otra.mes && anio == otra.anio);
    }
    bool operator!=(const Fecha &otra) const {
        return !(*this == otra);
    }
};
*/

// ####################################################################################################################################################

/*
12. Para este ejercicio es necesario el utilizar “dynamic_cast”. Escriba un programa con
una clase base denominada “Aeronave” con un atributo “nombre” y un método virtual
“mostrarInfo”. Luego, genere tres clases derivadas: “AvionComercial” con atributo
“numPasajeros”, “Helicoptero” con atributo “capacidadCarga” y “Drone” con atributo
“autonomiaVuelo”. 
En la función main cree un vector de punteros a aeronaves y almacene diferentes tipos
de aeronaves (ponga más de un AvionComercial, Helicoptero y Drone). Utilice un loop
para recorrer este vector e identificar el tipo de aeronave utilizando “dynamic_cast”.
Para cada tipo de aeronave, imprima la información específica.
*/

class Aeronave {
protected:
    string nombre;
public:
    Aeronave(string n) : nombre(n) {}
    virtual void mostrarInfo() const = 0; // Método virtual puro
    virtual ~Aeronave() {}  // Destructor virtual
};  

class AvionComercial : public Aeronave {
private:
    int numPasajeros;
public:
    AvionComercial(string n, int np) : Aeronave(n), numPasajeros(np) {}
    void mostrarInfo() const override {
        cout << "Avion Comercial: " << nombre << ", Numero de Pasajeros: " << numPasajeros << endl;
    }
};

class Helicoptero : public Aeronave {  
private:
    double capacidadCarga; // en kg
public:
    Helicoptero(string n, double cc) : Aeronave(n), capacidadCarga(cc) {}
    void mostrarInfo() const override {
        cout << "Helicoptero: " << nombre << ", Capacidad de Carga: " << capacidadCarga << " kg" << endl;
    }
};

class Drone : public Aeronave {
private:
    double autonomiaVuelo; // en minutos
public:
    Drone(string n, double av) : Aeronave(n), autonomiaVuelo(av) {}
    void mostrarInfo() const override {
        cout << "Drone: " << nombre << ", Autonomia de Vuelo: " << autonomiaVuelo << " minutos" << endl;
    }
};
/*
En la función main cree un vector de punteros a aeronaves y almacene diferentes tipos
de aeronaves (ponga más de un AvionComercial, Helicoptero y Drone). Utilice un loop
para recorrer este vector e identificar el tipo de aeronave utilizando “dynamic_cast”.
Para cada tipo de aeronave, imprima la información específica.
*/
int main(){
    vector<Aeronave*> aeronaves;
    aeronaves.push_back(new AvionComercial("Boeing 747", 416));
    aeronaves.push_back(new Helicoptero("Apache", 2000));
    aeronaves.push_back(new Drone("DJI Phantom", 30));
    aeronaves.push_back(new AvionComercial("Airbus A320", 180));
    aeronaves.push_back(new Helicoptero("Black Hawk", 1500));
    aeronaves.push_back(new Drone("Parrot Anafi", 25));

    for (const auto &aeronave : aeronaves) {
        if (auto avion = dynamic_cast<AvionComercial*>(aeronave)) {
            avion->mostrarInfo();
        } else if (auto helicoptero = dynamic_cast<Helicoptero*>(aeronave)) {
            helicoptero->mostrarInfo();
        } else if (auto drone = dynamic_cast<Drone*>(aeronave)) {
            drone->mostrarInfo();
        } else {
            cout << "Tipo de aeronave desconocido." << endl;
        }
    }

    // Liberar memoria
    for (auto &aeronave : aeronaves) {
        delete aeronave;
    }
    return 0;
}