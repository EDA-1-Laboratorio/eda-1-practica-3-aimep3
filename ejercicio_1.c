include <stdio.h>
include <stdlib.h>     
include <time.h>  

struct naipe {
    int puntos;         
    char palo;          
};

//definimos ciertos valores
void imprimirCarta(struct naipe carta) {
    if (carta.puntos == 1) printf("A");             //Si es 1, imprime A
    else if (carta.puntos == 11) printf("J");       //Si es 11, imprime J
    else if (carta.puntos == 12) printf("Q");       //Si es 12, imprime Q
    else if (carta.puntos == 13) printf("K");       //Si es 13, imprime K
    else printf("%d", carta.puntos);                //Si es del 2 al 10, imprime el número normal
    
    printf("%c", carta.palo);                       //Al final, imprime la letra del palo
}
int main() {
    srand(time(NULL));  //funcion para crear los números random
    
    struct naipe baraja[52];                 //arreglo de 52 cartas
    char palos[4] = {'C', 'T', 'D', 'E'};    //los 4 palos posibles
    int indice = 0;                          

    //Usamos dos ciclos: uno para los 4 palos y otro para los 13 números posibles
    for (int i = 0; i < 4; i++) {
        for (int p = 1; p <= 13; p++) {
            baraja[indice].puntos = p;       //asignamos el número a la carta
            baraja[indice].palo = palos[i];  //asignamos el palo
            indice++;                        //ahora a la siguiente carta
        }
    }

//"revolvemos" la baraja
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);            // Escogemos una posición al azar
        struct naipe temporal = baraja[i];   // Guardamos la carta actual temporalmente
        baraja[i] = baraja[j];               // Movemos la carta al azar a la posición actual
        baraja[j] = temporal;                // Ponemos la carta guardada en la posición al azar
    }

    //creamos las manos
    struct naipe player1[2];                 // Arreglo de 2 cartas para el jugador 1
    struct naipe player2[2];                 // Arreglo de 2 cartas para el jugador 2
    struct naipe river[3];                   // Arreglo de 3 cartas para la casa

    //vamos a ir "sacando" cartas una por una
    int carta_actual = 0;

    player1[0] = baraja[carta_actual++];     // Damos carta 1 al Jugador 1 y avanzamos
    player1[1] = baraja[carta_actual++];     // Damos carta 2 al Jugador 1 y avanzamos

    player2[0] = baraja[carta_actual++];     // Damos carta 1 al Jugador 2 y avanzamos
    player2[1] = baraja[carta_actual++];     // Damos carta 2 al Jugador 2 y avanzamos

    river[0] = baraja[carta_actual++];       // Ponemos carta 1 en el centro y avanzamos
    river[1] = baraja[carta_actual++];       // Ponemos carta 2 en el centro y avanzamos
    river[2] = baraja[carta_actual++];       // Ponemos carta 3 en el centro y avanzamos

    printf("--- MANO DEL JUGADOR 1 ---\n[");
    imprimirCarta(player1[0]);              
    printf("] [");
    imprimirCarta(player1[1]);              
    printf("]\n\n");

    printf("--- MANO DEL JUGADOR 2 ---\n[");
    imprimirCarta(player2[0]);
    printf("] [");
    imprimirCarta(player2[1]);
    printf("]\n\n");

    printf("--- CARTAS EN EL CENTRO (RIVER) ---\n[");
    imprimirCarta(river[0]);
    printf("] [");
    imprimirCarta(river[1]);
    printf("] [");
    imprimirCarta(river[2]);
    printf("]\n\n");

    return 0; 
}
