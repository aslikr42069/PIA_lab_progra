#include "sistema_ventas.h"



void menuVentas(articulo_t * articulos, int numArt, carrito_t * carrito){
 int cont = 1;
 int opcion;
 int unidades;
 while(cont){
 puts("Articulo, Precio, Cantidad en Inventorio:");
 for(int i = 0; i < numArt; i++){
  printf("%d.) %s, %.2f, %d\n", i + 1, articulos[i].nombreArticulo,
          articulos[i].precio, articulos[i].cantidad);
  }
  
  puts("-----------------------");
  printf("%d.) Pagar\n", numArt + 1);
  printf("%d.) Salir\n", numArt + 2);
  printf("Opcion: "); 
  scanf(" %d", &opcion);
  if(opcion >= numArt + 2){
   cont = 0;
   break;
  }

  if(opcion == numArt + 1){
   float total = 0;
   float pagado;
   puts("Articulo -- Unidades Compradas -- Precio por Unidad");
   for(int i = 0; i < carrito->tiposArt; i++){
    printf("%d.) %s -- %d -- %f\n", i + 1, 
    articulos[carrito->articulos[i]].nombreArticulo,
    carrito->cantidades[i], articulos[carrito->articulos[i]].precio);
    
    total += ((float) carrito->cantidades[i]) * articulos[carrito->articulos[i]].precio;
    articulos[carrito->articulos[i]].cantidad -= carrito->cantidades[i];
    carrito->cantidades[i] = 0;
   }
   puts("-----------------------"); 
   printf("Total: %.2f\n", total);
   puts("Cantidad que cliente pago: ");
   scanf(" %f", &pagado);
   printf("Cambio: %.2f\n", total - pagado);
   carrito->tiposArt = 0;
   return;
  }
  // Se llega aqui si se eligio el numero de un articulo
  int unico = 1;
  int indice;
  for(int i = 0; i < carrito->tiposArt; i++){
   if((opcion - 1) == carrito->articulos[i]){
    unico = 0;
    indice = i;
   }
  }
  
  if(unico){
   carrito->articulos[carrito->tiposArt] = opcion - 1;
   indice = carrito->tiposArt;
   carrito->tiposArt += 1;
  }

  unidades = 0;
  while(unidades <= 0 || carrito->cantidades[indice] + unidades >
        articulos[carrito->articulos[indice]].cantidad){
   printf("Unidades de Articulos que se va a comprar: ");
   scanf(" %d", &unidades); 
  }
  carrito->cantidades[indice] += unidades;
 }
}

void menuInventario(articulo_t * articulos, int * numArt){
 int opcion;
 while(1){
  opcion = 0;
  while(opcion < 1 || opcion > (*numArt) + 2){
   for(int i = 0; i < *numArt; i++){
    printf("%d.) %s, %.2f, %d\n", i + 1, articulos[i].nombreArticulo,
            articulos[i].precio, articulos[i].cantidad);
   }
   puts("------------------");
   printf("%d.) Agregar Articulo\n", (*numArt) + 1);
   printf("%d.) Salir\nOpcion: ", (*numArt) + 2);
   scanf(" %d", &opcion);
  }
  if(opcion == (*numArt) + 2){
   break;
  }
  if(opcion == (*numArt) + 1){
   printf("Nombre del Articulo: ");
   scanf(" %[^\n]", articulos[(*numArt)].nombreArticulo);
   printf("Precio del Articulo: ");
   scanf(" %f", &articulos[(*numArt)].precio);
   printf("Cantidad de Articulo en el Inventario: ");
   scanf(" %d", &articulos[(*numArt)].cantidad);
   (*numArt)++;
   continue;
  }

  int articulo = opcion - 1;
  opcion = 0;
  while(opcion < 1 || opcion > 4){
   puts("1.) Modificar Precio");
   puts("2.) Quitar articulo");
   puts("3.) Cambiar Cantidad en Inventorio");
   puts("4.) Salir");
   scanf(" %d", &opcion);
  }
  switch(opcion){
   case 1:
    puts("Nuevo Precio: ");
    scanf(" %f", &articulos[articulo].precio);
    break;
   case 2:
    for(int i = articulo; i < (*numArt) - 1; i++){
     articulos[i] = articulos[i + 1];
    }
    (*numArt)--;
    break;
   case 3:
    puts("Cantidad en Inventario: ");
    scanf(" %d", &articulos[articulo].cantidad);
    break;
   case 4:
    break;
  }
  
 }
}
