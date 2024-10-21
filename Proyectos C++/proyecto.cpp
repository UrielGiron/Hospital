#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Función para ingresar un nuevo paciente
void ingresarPaciente(vector<string>& ids, vector<string>& nombres, vector<int>& edades, vector<string>& generos, vector<string>& direcciones, vector<string>& telefonos, vector<string>& fechasIngreso, vector<string>& diagnosticos) {
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

    ids.push_back(id);
    nombres.push_back(nombre);
    edades.push_back(edad);
    generos.push_back(genero);
    direcciones.push_back(direccion);
    telefonos.push_back(telefono);
    fechasIngreso.push_back(fechaIngreso);
    diagnosticos.push_back(diagnostico);

    cout << "Paciente ingresado con éxito." << endl;
}

// Función para modificar los datos de un paciente
void modificarPaciente(vector<string>& ids, vector<string>& nombres, vector<int>& edades, vector<string>& generos, vector<string>& direcciones, vector<string>& telefonos, vector<string>& fechasIngreso, vector<string>& diagnosticos) {
    string id;
    cout << "Ingrese el ID del paciente que desea modificar: ";
    cin >> id;

    for (size_t i = 0; i < ids.size(); ++i) {
        if (ids[i] == id) {
            cout << "Paciente encontrado. Ingrese los nuevos datos." << endl;
            cout << "Nombre completo: ";
            cin.ignore();
            getline(cin, nombres[i]);
            cout << "Edad: ";
            cin >> edades[i];
            cout << "Género: ";
            cin >> generos[i];
            cout << "Dirección: ";
            cin.ignore();
            getline(cin, direcciones[i]);
            cout << "Teléfono: ";
            cin >> telefonos[i];
            cout << "Fecha de ingreso: ";
            cin >> fechasIngreso[i];
            cout << "Diagnóstico principal: ";
            cin.ignore();
            getline(cin, diagnosticos[i]);

            cout << "Paciente modificado exitosamente." << endl;
            return;
        }
    }
    cout << "Paciente no encontrado." << endl;
}

// Función para eliminar un paciente
void eliminarPaciente(vector<string>& ids, vector<string>& nombres, vector<int>& edades, vector<string>& generos, vector<string>& direcciones, vector<string>& telefonos, vector<string>& fechasIngreso, vector<string>& diagnosticos) {
    string id;
    cout << "Ingrese el ID del paciente que desea eliminar: ";
    cin >> id;

    for (size_t i = 0; i < ids.size(); ++i) {
        if (ids[i] == id) {
            ids.erase(ids.begin() + i);
            nombres.erase(nombres.begin() + i);
            edades.erase(edades.begin() + i);
            generos.erase(generos.begin() + i);
            direcciones.erase(direcciones.begin() + i);
            telefonos.erase(telefonos.begin() + i);
            fechasIngreso.erase(fechasIngreso.begin() + i);
            diagnosticos.erase(diagnosticos.begin() + i);
            cout << "Paciente eliminado exitosamente." << endl;
            return;
        }
    }
    cout << "Paciente no encontrado." << endl;
}

// Función para mostrar el reporte general de pacientes
void reporteGeneral(const vector<string>& ids, const vector<string>& nombres, const vector<int>& edades, const vector<string>& generos, const vector<string>& direcciones, const vector<string>& telefonos, const vector<string>& fechasIngreso, const vector<string>& diagnosticos) {
    cout << "Reporte de Todos los Pacientes:" << endl;
    for (size_t i = 0; i < ids.size(); ++i) {
        cout << "ID: " << ids[i] << ", Nombre: " << nombres[i]
             << ", Edad: " << edades[i] << ", Género: " << generos[i]
             << ", Dirección: " << direcciones[i] << ", Teléfono: " << telefonos[i]
             << ", Fecha de Ingreso: " << fechasIngreso[i] << ", Diagnóstico: " << diagnosticos[i] << endl;
    }
}

// Función para generar un archivo con el reporte de pacientes
void generarArchivo(const vector<string>& ids, const vector<string>& nombres, const vector<int>& edades, const vector<string>& generos, const vector<string>& direcciones, const vector<string>& telefonos, const vector<string>& fechasIngreso, const vector<string>& diagnosticos) {
    ofstream archivo("reporte_pacientes.txt");
    if (archivo.is_open()) {
        archivo << "Reporte de Todos los Pacientes\n";
        archivo << "-----------------------------------\n";
        for (size_t i = 0; i < ids.size(); ++i) {
            archivo << "ID: " << ids[i] << ", Nombre: " << nombres[i]
                    << ", Edad: " << edades[i] << ", Género: " << generos[i]
                    << ", Dirección: " << direcciones[i] << ", Teléfono: " << telefonos[i]
                    << ", Fecha de Ingreso: " << fechasIngreso[i] << ", Diagnóstico: " << diagnosticos[i] << endl;
        }
        archivo.close();
        cout << "Archivo generado exitosamente: reporte_pacientes.txt" << endl;
    } else {
        cout << "Error al generar el archivo." << endl;
    }
}

// Función para buscar paciente por su ID
void buscarPacientePorID(const vector<string>& ids, const vector<string>& nombres, const vector<int>& edades, const vector<string>& generos, const vector<string>& direcciones, const vector<string>& telefonos, const vector<string>& fechasIngreso, const vector<string>& diagnosticos) {
    string id;
    cout << "Ingrese el ID del paciente que desea buscar: ";
    cin >> id;

    for (size_t i = 0; i < ids.size(); ++i) {
        if (ids[i] == id) {
            cout << "Paciente encontrado:" << endl;
            cout << "ID: " << ids[i] << endl;
            cout << "Nombre: " << nombres[i] << endl;
            cout << "Edad: " << edades[i] << endl;
            cout << "Género: " << generos[i] << endl;
            cout << "Dirección: " << direcciones[i] << endl;
            cout << "Teléfono: " << telefonos[i] << endl;
            cout << "Fecha de Ingreso: " << fechasIngreso[i] << endl;
            cout << "Diagnóstico: " << diagnosticos[i] << endl;
            return;
        }
    }

    cout << "Paciente no encontrado con el ID proporcionado." << endl;
}

// Función principal para mostrar el menú
void mostrarMenu() {
    cout << "Sistema de Control de Pacientes\n";
    cout << "1. Ingreso de Paciente\n";
    cout << "2. Modificación de Datos del Paciente\n";
    cout << "3. Eliminar Paciente\n";
    cout << "4. Reporte General de Todos los Pacientes\n";
    cout << "5. Generar Archivo de Impresión\n";
    cout << "6. Buscar Paciente por ID\n";
    cout << "7. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    vector<string> ids;
    vector<string> nombres;
    vector<int> edades;
    vector<string> generos;
    vector<string> direcciones;
    vector<string> telefonos;
    vector<string> fechasIngreso;
    vector<string> diagnosticos;

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarPaciente(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
            case 2:
                modificarPaciente(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
            case 3:
                eliminarPaciente(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
            case 4:
                reporteGeneral(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
            case 5:
                generarArchivo(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
            case 6:
                buscarPacientePorID(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
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