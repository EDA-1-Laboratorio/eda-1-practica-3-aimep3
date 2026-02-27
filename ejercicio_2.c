#include <stdio.h>
//se define la estrutura
struct pizza {
    int tamano;
    int toppings;
    float precio;
};

int validarTamano(int t) {
    return t == 10 || t == 15 || t == 20;
}

int main() {
    int num;
    float total = 0, descuento = 0;
    int contador[3] = {0}; //para el descuento por tamaños
    
    printf("¿Cuántas pizzas desea ordenar?: ");
    scanf("%d", &num);
    while (num <= 0) {
        printf("Número inválido. Ingrese nuevamente: ");
        scanf("%d", &num);
    }
    
    struct pizza pedido[num];
    
    for (int i = 0; i < num; i++) {
        printf("Pizza %d\n", i + 1);
        
        printf("Tamaño (10, 15, 20): ");
        scanf("%d", &pedido[i].tamano);
        while (!validarTamano(pedido[i].tamano)) {
            printf("Tamaño inválido. Use 10, 15 o 20: ");
            scanf("%d", &pedido[i].tamano);
        }
        
        printf("Toppings (1-5): ");
        scanf("%d", &pedido[i].toppings);
        while (pedido[i].toppings < 1 || pedido[i].toppings > 5) {
            printf("Cantidad inválida (1-5): ");
            scanf("%d", &pedido[i].toppings);
        }
        
        //precio
        if (pedido[i].tamano == 10) pedido[i].precio = 100;
        else if (pedido[i].tamano == 15) pedido[i].precio = 150;
        else pedido[i].precio = 200;
        
        if (pedido[i].tamano == 10) contador[0]++;
        else if (pedido[i].tamano == 15) contador[1]++;
        else contador[2]++;
        
        total += pedido[i].precio;
    }
    //descuento
    if (contador[0] >= 2) descuento += (contador[0] / 2) * 100;
    if (contador[1] >= 2) descuento += (contador[1] / 2) * 150;
    if (contador[2] >= 2) descuento += (contador[2] / 2) * 200;
    
    for (int i = 0; i < num; i++) {
        printf("Pizza %d: %d - %d topping - $%.2f\n", i + 1, pedido[i].tamano, pedido[i].toppings, pedido[i].precio);
    }
    
    printf("Subtotal: $%.2f\n", total);
    printf("Descuento 2x1: -$%.2f\n", descuento);
    printf("Total: $%.2f\n", total - descuento);
    return 0;
}
