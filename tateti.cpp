#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool win(char tateti[3][3]){ //funcion que verifica que se haya hecho tateti;
  for (int c = 0; c <= 2; c++) { //recorremos filas y columnas
    if (tateti[c][0] != ' ' && tateti[c][0] == tateti[c][1] && tateti[c][0] == tateti[c][2]) return true;
    //tateti[c][0] != ' ' es para verificar que ningun lugar de la matriz este vacio
    if (tateti[0][c] != ' ' && tateti[0][c] == tateti[1][c] && tateti[0][c] == tateti[2][c]) return true;
  }
  //recorremos las diagonales
  if (tateti[0][0] != ' ' && tateti[0][0] == tateti[1][1] && tateti[0][0] == tateti[2][2]) return true;
  if (tateti[0][2] != ' ' && tateti[0][2] == tateti[1][1] && tateti[0][2] == tateti[2][0]) return true;
  // si hay tateti devuelve true, sino devuelve false;
  return false;
}

void print_board(char tateti[3][3]){ //para imprimir el tablero
	printf("\t     <1> <2> <3>\n");
     printf("\t<a> | %c | %c | %c |\n", tateti[0][0], tateti[0][1], tateti[0][2]);
     printf("\t    |---|---|---|\n");
     printf("\t<b> | %c | %c | %c |\n", tateti[1][0], tateti[1][1], tateti[1][2]);
     printf("\t    |---|---|---|\n");
     printf("\t<c> | %c | %c | %c |\n", tateti[2][0], tateti[2][1], tateti[2][2]);
}

int main(void) {
  char tateti[3][3] = { //en esta matriz guardamos los datos ingresados por el usuario (donde hay X y O)
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};
  printf("\n---Bienvenidos al TaTeTi---\n");
    print_board(tateti); 
  for (int i = 1; i <= 9; i++) { //9 vueltas porque el tateti tiene 9 rondas
  	char coord1;
    int coord2;
    if (i % 2 == 0){ //si es la ronda 2, 4, 6, 8, juega el jugador 2; sino juega el jugador 1
      printf("\n[O]Turno del jugador 2:\n");
      printf("[O]--> Pone las coordenadas que quieras\n");
      while (1) { //el while sirve para verificar que se ingresen coordenadas validas; mientras no se ingrese una coordenada valida, se repetira el while infinitamente
      scanf(" %c %d", &coord1, &coord2);
      if (coord1 > 'c' || coord1 < 'a') { //si la letra no es 'a', 'b', o 'c' imprime error
        printf("_-_-_-Ingresa una letra valida-_-_-_\n");
      } else
      if (coord2 > 3 || coord2 < 1) { //si el numero no es '1', '2', o '3' imprime error
        printf("_-_-_-Ingresa un numero valido-_-_-_\n");
      } else
        if (tateti[coord1 - 97][coord2-1] == ' '){ //coord1-97 es para convertir el caracter en numero. 'a'-97 = 0; 'b'-97 = 1; 'c'-97 = 2. 
		//Son los subindices que identifican las filas.
		//coord2 - 1 es para que 1 = 0; 2 = 1; 3 = 2. Para convertirlos en subindices que identifican las filas.
          tateti[coord1 - 97][coord2-1] = 'O'; // llenamos las coordenadas indicadas con 'O'
          break; // salimos del while porque se ingreso una cordenada valida
         }
        else printf("_-_-_-Ingresa otra coordenada-_-_-_\n"); //se pide ingresar una nueva coordenada y se repite el while
        }
      system("cls"); //limpiamos la terminal
      print_board(tateti);
      
    } else { //si es el turno 1, 3, 5, 7, o 9, juega el jugador 1. El codigo es igual pero adaptado a X
      printf("\n[X]Turno del jugador 1:\n");
     printf("[X]--> Pone las coordenadas que quieras\n");
     while (1) {
     scanf(" %c %d", &coord1, &coord2);
      if (coord1 > 'c' || coord1 < 'a') {
        printf("_-_-_-Ingresa una letra valida-_-_-_\n");
      } else
      if (coord2 > 3 || coord2 < 1) {
        printf("_-_-_-Ingresa un numero valido-_-_-_\n");
      } else
       if (tateti[coord1 - 97][coord2-1] == ' '){
         tateti[coord1 - 97][coord2-1] = 'X';
         break;
        }
       else printf("_-_-_-Ingresa otra coordenada-_-_-_\n");
       }
     }
     system("cls");
     print_board(tateti);
     if (win(tateti)) { //si alguno gano, imprime quien gano
       printf("Gano %c\n", i%2==0 ? 'O' : 'X');
       return 0; //y termina el programa
     } //si no gano nadie sigue el programa
   } //cuando sale del while (termino las 9 rondas) y no gano nadie, hubo empate
   printf("Empate\n");
  return 0;
}

