#ifndef SISTEMA_VENTAS_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SISTEMA_VENTAS_H 1

typedef struct articulo_t{
 char nombreArticulo[64];
 float precio;
 int cantidad;
}articulo_t;

typedef struct carrito_t{
 int tiposArt;
 int articulos[64];
 int cantidades[64];
}carrito_t;

void menuVentas(articulo_t * articulos, int numArt, carrito_t  * carrito);

void menuInventario(articulo_t * articulos, int * numArt);

#endif
