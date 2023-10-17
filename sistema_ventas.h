#ifndef SISTEMA_VENTAS_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#define SISTEMA_VENTAS_H 1

typedef struct articulo_t{
 char nombreArticulo[64]; 
 float precio;
}articulo_t;

articulo_t leerArticulo(char * nom, float pre);

void menuVentas(articulo_t * articulos, int numArt);

#endif
