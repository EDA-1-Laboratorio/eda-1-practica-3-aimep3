#include <stdio.h>
#include <math.h>

//Definir nuevo tipo de dato que represente a un círculo
struct circulo {
    float x, y, radio;//coordenadas del centro y del radio
};

// Función para calcular distancia entre centros
float distancia(struct circulo c1, struct circulo c2) { //funcion que nos da un número decimal poniendo como parametros 2 circulos
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2)); //raiz cuadrada de la suma de los cuadrados para darnos la distancia entre los centros
}

int main() {
    struct circulo c1, c2; //crea dos circulos
    
    printf("=== INTERSECCION DE CIRCULOS ===\n");
    
    // Pedir datos del primer círculo
    printf("\nPrimer circulo:\n");
    printf("Centro (x y): ");
    scanf("%f %f", &c1.x, &c1.y); //siginifica que va a leer un número decimal %f y &c1.x irección de memoria donde está guardado x al igual que el de y
    printf("Radio: ");
    scanf("%f", &c1.radio);
    
    // Pedir datos del segundo círculo
    printf("\nSegundo circulo:\n");
    printf("Centro (x y): ");
    scanf("%f %f", &c2.x, &c2.y);
    printf("Radio: ");
    scanf("%f", &c2.radio);
    
    // Calcular distancia creando una nueva variable y se guarda en d
    float d = distancia(c1, c2);
    
    printf("\n=== RESULTADO ===\n");
    
    //Si distancia es menor o igual a la suma de radios los círculos están separdos
    //Si distancia es mayor o igual a la diferencia absoluta de radios un círculo está dentro del otro
    
    if (d <= c1.radio + c2.radio && d >= fabs(c1.radio - c2.radio)) { //&& esto significa que ambas deben de ser verdaderas y fabs () es solo valor absoluto
        printf("LOS CIRCULOS SE INTERSECTAN\n");
        
        // Calcular área de intersección
        float area;
        
        // Si son iguales
         if (d == 0 && c1.radio == c2.radio) {   //se debe cumplir que tengan mismo centro y mismo radio
            area = M_PI * c1.radio * c1.radio; // se calcula el área ya que la intersección pues es la misma área
            printf("Los circulos son IDENTICOS\n");
        }
        // DESPUÉS verificar si uno está dentro del otro
        else if (d <= fabs(c1.radio - c2.radio)) { //para ver si uno esta detro del otro
            float radio_menor = (c1.radio < c2.radio) ? c1.radio : c2.radio; //Si c1.radio es menor que c2.radio, toma c1.radio, si no, toma c2.radio y guarda en radio_menor
            area = M_PI * radio_menor * radio_menor;
            printf("Un circulo esta DENTRO del otro\n");
        }
        // Intersección normal
        else {
            float a = c1.radio; //guardar c1.radio en la nueva variable a 
            float b = c2.radio; //guardar c2.radio en la variable b
            area = a * a * acos((d*d + a*a - b*b)/(2*d*a)) + //radio al cuadrado del arcoseno de el coseno del ángulo del sector circular para calcular el área de c1
                   b * b * acos((d*d + b*b - a*a)/(2*d*b)) - // lo mismo que el de arriba pero para c2
                   0.5 * sqrt((-d+a+b)*(d+a-b)*(d-a+b)*(d+a+b)); // calcula el área formada por los dos centros y un punto de intersección
        }
        
        printf("Area de interseccion: %.2f unidades cuadradas\n", area);
        
    } else {
        printf("LOS CIRCULOS NO SE INTERSECTAN\n");  //si ninguna de las condiciones pasadas son corretas pues no hay área donde se junten
        printf("Area de interseccion: 0.00 unidades cuadradas\n");
    }
    
    return 0;
}
