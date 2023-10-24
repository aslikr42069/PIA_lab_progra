#include "sistema_ventas.h"



void menuVentas(articulo_t * articulos, int numArt){
 puts("Articulo, Precio:");
 for(int i = 0; i < numArt; i++){
  printf("%d.) %s, %.2f\n", i + 1, articulos[i].nombreArticulo,
         articulos[i].precio);
 }
 printf("-----------------------\n");
}
