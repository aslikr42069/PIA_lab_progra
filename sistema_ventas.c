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
