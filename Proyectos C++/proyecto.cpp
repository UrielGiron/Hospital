#include <iostream>
#include <limits> // Para manejar la entrada
#include <string> // Para usar std::string y getline
#include <fstream> // Para manejar archivos

using namespace std;

// Declaración de funciones
void IngresarPaciente();
/* void ModificarPaciente();
void EliminarPaciente();
void BuscarPaciente();
void ListarPacientes();
void ArchivoPacientes(); */
void EsperarTecla();
void LimpiarPantalla();

int main() {
    int opcion;

    // Ciclo para mostrar el menú hasta que se decida salir
    do {
        // Mostrar el menú
        LimpiarPantalla();
        cout << "Menú de opciones:" << endl;
        cout << "1. Ingresar paciente" << endl;
      /*   cout << "2. Modificar paciente" << endl;
        cout << "3. Eliminar paciente" << endl;
        cout << "4. Buscar paciente" << endl;
        cout << "5. Listar pacientes" << endl;
        cout << "6. Archivo de pacientes" << endl; */
        cout << "7. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Validar la entrada para asegurarse de que sea un entero
        if(cin.fail()) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada no válida
            opcion = -1; // Asignar una opción inválida
        }

        switch(opcion) {
            case 1:
                IngresarPaciente();
                break;
          /*   case 2:
                ModificarPaciente();
                break;
            case 3:
                EliminarPaciente();
                break;
            case 4:
                BuscarPaciente();
                break;
            case 5:
                ListarPacientes();
                break;
            case 6:
                ArchivoPacientes();
                break; */
            case 7:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida, por favor seleccione una opción válida." << endl;
                EsperarTecla();
                break;
        }
    } while(opcion != 7);

    return 0;
}

// Función para limpiar la pantalla
void LimpiarPantalla() {
    // Dependiendo del sistema operativo, se usa "cls" para Windows y "clear" para Unix/Linux/macOS
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función para esperar a que el usuario presione una tecla
void EsperarTecla() {
    cout << "Presione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar cualquier entrada pendiente
    cin.get(); // Esperar a que el usuario presione Enter
}



// Subalgoritmo para ingresar un paciente
struct Paciente {
    string dpi;
    string nombreCompleto;
    int edad;
    string genero;
    string direccion;
    string telefono;
    string fechaIngreso;
    string diagnosticoPrincipal;
};

bool esNumeroPositivo(int numero) {
    return numero > 0;
}

void ingresarPaciente(Paciente& paciente) {
    cout << "Ingrese el Número de Identificación (DPI): ";
    cin >> paciente.dpi;

    cout << "Ingrese el Nombre Completo: ";
    cin.ignore(); // Ignora el salto de línea del cin anterior
    getline(cin, paciente.nombreCompleto);

    // Validar edad
    do {
        cout << "Ingrese la Edad (debe ser un número positivo): ";
        cin >> paciente.edad;

        if (!esNumeroPositivo(paciente.edad)) {
            cout << "Error: La edad debe ser un número positivo.\n";
        }
    } while (!esNumeroPositivo(paciente.edad));

    cout << "Ingrese el Género: ";
    cin.ignore();
    getline(cin, paciente.genero);

    cout << "Ingrese la Dirección: ";
    getline(cin, paciente.direccion);

    // Validar número de teléfono
    do {
        cout << "Ingrese el Número de Teléfono (debe ser un número positivo): ";
        cin >> paciente.telefono;

        if (paciente.telefono.empty() || !isdigit(paciente.telefono[0])) {
            cout << "Error: El número de teléfono debe ser un valor válido.\n";
        }
    } while (paciente.telefono.empty() || !isdigit(paciente.telefono[0]));

    cout << "Ingrese la Fecha de Ingreso: ";
    cin.ignore();
    getline(cin, paciente.fechaIngreso);

    cout << "Ingrese el Diagnóstico Principal: ";
    getline(cin, paciente.diagnosticoPrincipal);
}

void mostrarPaciente(const Paciente& paciente) {
    cout << "\nDetalles del Paciente:\n";
    cout << "DPI: " << paciente.dpi << endl;
    cout << "Nombre Completo: " << paciente.nombreCompleto << endl;
    cout << "Edad: " << paciente.edad << endl;
    cout << "Género: " << paciente.genero << endl;
    cout << "Dirección: " << paciente.direccion << endl;
    cout << "Número de Teléfono: " << paciente.telefono << endl;
    cout << "Fecha de Ingreso: " << paciente.fechaIngreso << endl;
    cout << "Diagnóstico Principal: " << paciente.diagnosticoPrincipal << endl;
}
