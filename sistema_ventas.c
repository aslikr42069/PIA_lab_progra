#include "sistema_ventas.h"

articulo_t leerArticulo(char * nom, float pre){
 articulo_t art;
 strcpy(art.nombreArticulo, nom);
 art.precio = pre;
 return art;
}


void menuVentas(articulo_t * articulos, int numArt){
 puts("Articulo, Precio:");
 for(int i = 0; i < numArt; i++){
  printf("%d.) %s, %.2f\n", i + 1, articulos[i].nombreArticulo,
         articulos[i].precio);
 }
 printf("-----------------------\n");
}
