#include <iostream>
#include <vector> //para la manipulación de vectores
#include <string>
#include <fstream> // Para la generación de archivos

using namespace std;

//crea una clase para guardar los datos de los pacientes
class Paciente {
public:
    string id;
    string nombre;
    int edad;
    string genero;
    string direccion;
    string telefono;
    string fechaIngreso;
    string diagnostico;

    // Constructor
    Paciente(string _id, string _nombre, int _edad, string _genero, string _direccion, string _telefono, string _fechaIngreso, string _diagnostico)
        : id(_id), nombre(_nombre), edad(_edad), genero(_genero), direccion(_direccion), telefono(_telefono), fechaIngreso(_fechaIngreso), diagnostico(_diagnostico) {}
};

// Función para ingresar un nuevo paciente
void ingresarPaciente(vector<Paciente>& pacientes) {
    string id, nombre, genero, direccion, telefono, fechaIngreso, diagnostico;
    int edad;

    cout << "Ingrese el ID del paciente (DPI): ";
    cin >> id;
    cout << "Ingrese el nombre completo: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese el género: ";
    cin >> genero;
    cout << "Ingrese la dirección: ";
    cin.ignore();
    getline(cin, direccion);
    cout << "Ingrese el número de teléfono: ";
    cin >> telefono;
    cout << "Ingrese la fecha de ingreso: ";
    cin >> fechaIngreso;
    cout << "Ingrese el diagnóstico principal: ";
    cin.ignore();
    getline(cin, diagnostico);

    // Añadir el paciente al vector
    pacientes.push_back(Paciente(id, nombre, edad, genero, direccion, telefono, fechaIngreso, diagnostico));
    cout << "Paciente ingresado con éxito." << endl;
}

// Función principal para mostrar el menú
void mostrarMenu() {
    cout << "Sistema de Control de Pacientes\n";
    cout << "1. Ingreso de Paciente\n";
    cout << "2. Modificación de Datos del Paciente\n";
    cout << "3. Eliminar Paciente\n";
    cout << "4. Reporte General de Todos los Pacientes\n";
    cout << "5. Generar Archivo de Impresión\n";
    cout << "6. Buscar Paciente por ID\n"; // Nueva opción
    cout << "7. Salir\n";
    cout << "Seleccione una opción: ";
}


int main() {
    vector<Paciente> pacientes;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            ingresarPaciente(pacientes);
            break;
     /*    case 2:
            modificarPaciente(pacientes);
            break;
        case 3:
            eliminarPaciente(pacientes);
            break;
        case 4:
            reporteGeneral(pacientes);
            break;
        case 5:
            generarArchivo(pacientes);
            break;
        case 6:
            buscarPacientePorID(pacientes); // Llamada a la nueva función
            break; */
        case 7:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
        cout << endl;
    } while (opcion != 7);

    return 0;
}