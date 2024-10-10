#include <iostream>
using namespace std;

const int N_TIPOS = 4;
const double precios[N_TIPOS] = {90, 100, 80, 150};  // 1-Ficción, 2-Novelas, 3-Cuentos, 4-Física Cuántica
const int descuentos[3][N_TIPOS] = {
    {5, 8, 9, 2},    // Descuentos para 1-2 libros
    {6, 16, 18, 2},  // Descuentos para 3-6 libros
    {8, 32, 36, 4}   // Descuentos para más de 7 libros
};

int ventasFisicaCuantica = 0;
int ventasFiccionDescuento6 = 0;
int ventasDescuentoNet200 = 0;
double totalImporteNeto = 0;

int obtenerDescuento(int cantidad, int tipo) {
    if (cantidad <= 2) return descuentos[0][tipo];
    if (cantidad <= 6) return descuentos[1][tipo];
    return descuentos[2][tipo];
}

void registrarVenta(double* preciosPtr, int (*descuentosPtr)[N_TIPOS], int* ventasFisicaCuanticaPtr, int* ventasFiccionDescuento6Ptr, int* ventasDescuentoNet200Ptr, double* totalImporteNetoPtr) {
    int tipoLibro, cantidadLibros;
    double descuentoNeto, importeTotal;

    cout << "Seleccione el tipo de libro (1-Ficción, 2-Novelas, 3-Cuentos, 4-Física Cuántica): ";
    cin >> tipoLibro;
    cout << "Ingrese la cantidad de libros: ";
    cin >> cantidadLibros;

    tipoLibro--; // Ajustar para indexar desde 0
    double precio = *(preciosPtr + tipoLibro);
    int descuento = obtenerDescuento(cantidadLibros, tipoLibro);
    double montoBruto = cantidadLibros * precio;
    descuentoNeto = (montoBruto * descuento) / 100.0;
    importeTotal = montoBruto - descuentoNeto;

    *totalImporteNetoPtr += importeTotal;

    // Actualizar métricas usando punteros
    if (tipoLibro == 3) (*ventasFisicaCuanticaPtr)++;
    if (tipoLibro == 0 && descuento == 6) (*ventasFiccionDescuento6Ptr)++;
    if (descuentoNeto >= 200) (*ventasDescuentoNet200Ptr)++;
}

void reporteVentas(int* ventasFisicaCuanticaPtr, int* ventasFiccionDescuento6Ptr, int* ventasDescuentoNet200Ptr, double* totalImporteNetoPtr) {
    cout << "Reporte de Ventas:" << endl;
    cout << "Cantidad de ventas de libros de Física Cuántica: " << *ventasFisicaCuanticaPtr << endl;
    cout << "Cantidad de ventas de libros de Ficción con descuento del 6%: " << *ventasFiccionDescuento6Ptr << endl;
    cout << "Cantidad de ventas con Descuento Neto >= 200: " << *ventasDescuentoNet200Ptr << endl;
    cout << "Total del Importe Neto: " << *totalImporteNetoPtr << endl;
}

int main() {
    int opcion;

    do {
        cout << "\nSeleccione una opción:\n";
        cout << "[1] Registro de ventas\n";
        cout << "[2] Reporte de ventas\n";
        cout << "[3] Salir\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVenta(precios, descuentos, &ventasFisicaCuantica, &ventasFiccionDescuento6, &ventasDescuentoNet200, &totalImporteNeto);
                break;
            case 2:
                reporteVentas(&ventasFisicaCuantica, &ventasFiccionDescuento6, &ventasDescuentoNet200, &totalImporteNeto);
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 3);

    return 0;
}