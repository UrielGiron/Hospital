#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Funcion para cargar los datos desde el archivo
void cargarDatos(vector<string>& ids, vector<string>& nombres, vector<int>& edades, vector<string>& generos, vector<string>& direcciones, vector<string>& telefonos, vector<string>& fechasIngreso, vector<string>& diagnosticos) {
    ifstream archivo("base_datos.txt");
    if (archivo.is_open()) {
        string id, nombre, genero, direccion, telefono, fechaIngreso, diagnostico;
        int edad;
        while (archivo >> id >> edad) {
            archivo.ignore(); // Ignorar el salto de linea
            getline(archivo, nombre);
            getline(archivo, genero);
            getline(archivo, direccion);
            archivo >> telefono;
            archivo.ignore();
            getline(archivo, fechaIngreso);
            getline(archivo, diagnostico);

            ids.push_back(id);
            edades.push_back(edad);
            nombres.push_back(nombre);
            generos.push_back(genero);
            direcciones.push_back(direccion);
            telefonos.push_back(telefono);
            fechasIngreso.push_back(fechaIngreso);
            diagnosticos.push_back(diagnostico);
        }
        archivo.close();
    }
}

// Funcion para guardar los datos en el archivo
void guardarDatos(const vector<string>& ids, const vector<string>& nombres, const vector<int>& edades, const vector<string>& generos, const vector<string>& direcciones, const vector<string>& telefonos, const vector<string>& fechasIngreso, const vector<string>& diagnosticos) {
    ofstream archivo("base_datos.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < ids.size(); ++i) {
            archivo << ids[i] << " " << edades[i] << "\n"
                    << nombres[i] << "\n"
                    << generos[i] << "\n"
                    << direcciones[i] << "\n"
                    << telefonos[i] << "\n"
                    << fechasIngreso[i] << "\n"
                    << diagnosticos[i] << "\n";
        }
        archivo.close();
    } else {
        cout << "Error al guardar los datos." << endl;
    }
}

// Funcion para ingresar un paciente
void ingresarPaciente(vector<string>& ids, vector<string>& nombres, vector<int>& edades, vector<string>& generos, vector<string>& direcciones, vector<string>& telefonos, vector<string>& fechasIngreso, vector<string>& diagnosticos) {
    string id, nombre, genero, direccion, telefono, fechaIngreso, diagnostico;
    int edad;

    // Validacion de ID unico
    bool idUnico;
    do {
        idUnico = true;
        cout << "Ingrese el ID del paciente (DPI): ";
        cin >> id;
        for (const auto& existingId : ids) {
            if (id == existingId) {
                cout << "Error: El ID ya existe. Ingrese un ID único." << endl;
                idUnico = false;
                break;
            }
        }
    } while (!idUnico);

    cin.ignore(); // Limpia el buffer antes de getline
    do {
        cout << "Ingrese el nombre completo: ";
        getline(cin, nombre);
        if (nombre.empty()) {
            cout << "Error: El nombre es obligatorio." << endl;
        }
    } while (nombre.empty());

    do {
        cout << "Ingrese la edad: ";
        cin >> edad;
        if (edad <= 0) {
            cout << "Error: La edad debe ser un numero positivo." << endl;
        }
    } while (edad <= 0);

    cin.ignore(); // Limpiar buffer antes de getline
    do {
        cout << "Ingrese el genero: ";
        getline(cin, genero);
        if (genero.empty()) {
            cout << "Error: El genero es obligatorio." << endl;
        }
    } while (genero.empty());

    do {
        cout << "Ingrese la direccion: ";
        getline(cin, direccion);
        if (direccion.empty()) {
            cout << "Error: La direccion es obligatoria." << endl;
        }
    } while (direccion.empty());

    do {
        cout << "Ingrese el numero de telefono: ";
        cin >> telefono;
        if (telefono.empty() || telefono.find_first_not_of("0123456789") != string::npos) {
            cout << "Error: El telefono debe ser un numero positivo." << endl;
        }
    } while (telefono.empty() || telefono.find_first_not_of("0123456789") != string::npos);

    cin.ignore(); // Limpiar buffer antes de getline
    do {
        cout << "Ingrese la fecha de ingreso: ";
        getline(cin, fechaIngreso);
        if (fechaIngreso.empty()) {
            cout << "Error: La fecha de ingreso es obligatoria." << endl;
        }
    } while (fechaIngreso.empty());

    do {
        cout << "Ingrese el diagnostico principal: ";
        getline(cin, diagnostico);
        if (diagnostico.empty()) {
            cout << "Error: El diagnostico es obligatorio." << endl;
        }
    } while (diagnostico.empty());

    ids.push_back(id);
    nombres.push_back(nombre);
    edades.push_back(edad);
    generos.push_back(genero);
    direcciones.push_back(direccion);
    telefonos.push_back(telefono);
    fechasIngreso.push_back(fechaIngreso);
    diagnosticos.push_back(diagnostico);

    cout << "Paciente ingresado con exito." << endl;
}

// Funcion para modificar los datos de un paciente
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
            cout << "Genero: ";
            cin.ignore();
            getline(cin, generos[i]); // Consume el salto de linea
            cout << "Direccion: ";
            getline(cin, direcciones[i]);
            cout << "Telefono: ";
            cin >> telefonos[i];
            cout << "Fecha de ingreso: ";
            cin >> fechasIngreso[i];
            cout << "Diagnostico principal: ";
            cin.ignore();
            getline(cin, diagnosticos[i]);

            cout << "Paciente modificado exitosamente." << endl;
            return;
        }
    }
    cout << "Paciente no encontrado." << endl;
}

// Funcion para eliminar un paciente
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

// Funcion para generar un reporte de todos los pacientes
void reporteGeneral(const vector<string>& ids, const vector<string>& nombres, const vector<int>& edades, const vector<string>& generos, const vector<string>& direcciones, const vector<string>& telefonos, const vector<string>& fechasIngreso, const vector<string>& diagnosticos) {
    cout << "Reporte de Todos los Pacientes:" << endl;
    for (size_t i = 0; i < ids.size(); ++i) {
        cout << "ID: " << ids[i] << ", Nombre: " << nombres[i]
             << ", Edad: " << edades[i] << ", Genero: " << generos[i]
             << ", Direccion: " << direcciones[i] << ", Telefono: " << telefonos[i]
             << ", Fecha de Ingreso: " << fechasIngreso[i] << ", Diagnostico: " << diagnosticos[i] << endl;
    }
}

// Funcion para generar un archivo con el reporte de los pacientes
void generarArchivo(const vector<string>& ids, const vector<string>& nombres, const vector<int>& edades, const vector<string>& generos, const vector<string>& direcciones, const vector<string>& telefonos, const vector<string>& fechasIngreso, const vector<string>& diagnosticos) {
    ofstream archivo("reporte_pacientes.txt");
    if (archivo.is_open()) {
        archivo << "Reporte de Todos los Pacientes\n";
        archivo << "-----------------------------------\n";
        for (size_t i = 0; i < ids.size(); ++i) {
            archivo << "ID: " << ids[i] << ", Nombre: " << nombres[i]
                    << ", Edad: " << edades[i] << ", Genero: " << generos[i]
                    << ", Direccion: " << direcciones[i] << ", Telefono: " << telefonos[i]
                    << ", Fecha de Ingreso: " << fechasIngreso[i] << ", Diagnostico: " << diagnosticos[i] << endl;
        }
        archivo.close();
        cout << "Archivo generado exitosamente: reporte_pacientes.txt" << endl;
    } else {
        cout << "Error al generar el archivo." << endl;
    }
}

// Funcion para buscar un paciente por ID
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
            cout << "Genero: " << generos[i] << endl;
            cout << "Direccion: " << direcciones[i] << endl;
            cout << "Telefono: " << telefonos[i] << endl;
            cout << "Fecha de Ingreso: " << fechasIngreso[i] << endl;
            cout << "Diagnostico: " << diagnosticos[i] << endl;
            return;
        }
    }

    cout << "Paciente no encontrado con el ID proporcionado." << endl;
}

// Funcion para mostrar el menu
void mostrarMenu() {
    cout << "Sistema de Control de Pacientes\n";
    cout << "1. Ingreso de Paciente\n";
    cout << "2. Modificacion de Datos del Paciente\n";
    cout << "3. Reporte General de Todos los Pacientes\n";
    cout << "4. Buscar Paciente por ID\n";
    cout << "5. Generar Archivo de Impresion\n";
    cout << "6. Eliminar Paciente\n";
    cout << "7. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    // Vectores para almacenar los datos de los pacientes
    vector<string> ids;
    vector<string> nombres;
    vector<int> edades;
    vector<string> generos;
    vector<string> direcciones;
    vector<string> telefonos;
    vector<string> fechasIngreso;
    vector<string> diagnosticos;

    cargarDatos(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);

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
                reporteGeneral(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
            case 4:
                buscarPacientePorID(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
            case 5:
                generarArchivo(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
            case 6:
                eliminarPaciente(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
            case 7:
                cout << "Saliendo del sistema..." << endl;
                guardarDatos(ids, nombres, edades, generos, direcciones, telefonos, fechasIngreso, diagnosticos);
                break;
            default:
                cout << "Opcion no válida. Intente de nuevo." << endl;
        }
        cout << endl;
    } while (opcion != 7);

    return 0;
}