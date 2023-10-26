#include <stdio.h>
#include <stdlib.h>
#include "sistema_ventas.h"


int main(void){
 //TODO: Implementar codigo de empleo
 char archivo[] = "ventas.dat";
 char masterContra[] = "mollerGeo";
 FILE * fp = fopen(archivo, "rb");
 if(fp == NULL){
  printf("Error: No se pudo leer %s\n", archivo);
  return 1;
 }

 int num_articulos = 0;
 articulo_t articulos[20];
 while(!feof(fp)){
  if(fread(&articulos[num_articulos], sizeof(articulo_t), 1, fp) > 0){
   num_articulos++;
  }
 }
 fclose(fp);
 fp = fopen(archivo, "wb");

 carrito_t carrito;
 carrito.tiposArt = 0;
 for(int i = 0; i < 64; i++){
  carrito.articulos[i] = 0;
  carrito.cantidades[i] = 0;
 }

 int cont = 1;
 int opcion;
 while(cont){
  opcion = 0;
  while(opcion < 1 || opcion > 3){
   puts("1.) Ventas\n2.) Modificar Inventorio\n3.) Salir\nOpcion: ");
   scanf(" %d", &opcion);
  }
 
 switch(opcion){
  case 1:
   rewind(fp);
   menuVentas(articulos, num_articulos, &carrito);
   fwrite(articulos, sizeof(articulo_t), num_articulos, fp);
   break;
  case 2:
   rewind(fp);
   int intentos = 3;
   char contrasena[256];
   contrasena[0] = '\0';
   while(strncmp(contrasena, masterContra, strlen(masterContra)) != 0){
    if(intentos <= 0){
     break;
    }
    printf("Intentos Restantes: %d\nContrasena: ", intentos);
    scanf(" %[^\n]", contrasena);
    if(strncmp(contrasena, masterContra, strlen(masterContra)) != 0){
     intentos--;
    }
   }
   if(intentos <= 0){
    break;
   }
   menuInventario(articulos, &num_articulos);
   fwrite(articulos, sizeof(articulo_t), num_articulos, fp);
   break;
  case 3:
   cont = 0;
   break;
  }
 }
 fclose(fp);
 return 0;
}
