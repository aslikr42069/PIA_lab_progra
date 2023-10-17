#include <stdio.h>
#include <stdlib.h>
#include "sistema_ventas.h"


int main(void){
 //TODO: Implementar codigo de empleo
 char archivo[] = "ventas.dat";
 FILE * fp = fopen(archivo, "r");
 if(fp == NULL){
  printf("Error: No se pudo leer %s\n", archivo);
  return 1;
 }
 
 char tmpNom[64];
 float tmpPre;
 int num_articulos = 0;
 articulo_t articulos[16];

 while(fscanf(fp, "%s %f", tmpNom, &tmpPre) > 0){
  articulos[num_articulos++] = leerArticulo(tmpNom, tmpPre);
 }
 
 int cont = 1;
 int opcion;
 while(cont){
  opcion = 0;
  while(opcion < 1 || opcion > 3){
   puts("1.) Ventas\n2.) Inventorio\n3.) Salir\nOpcion: ");
   scanf(" %d", &opcion);
  }
  

 switch(opcion){
  case 1:
   menuVentas(articulos, num_articulos);
   break;
  case 2:
   break;
  case 3:
   cont = 0;
   break;
  }
 }
 return 0;
}
