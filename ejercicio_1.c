import random
from collections import Counter #para contar las cartas

class Naipe: #definimos nuestras cartas
    def __init__(self, puntos, palo):
        self.puntos = puntos
        self.palo = palo

    def __str__(self): #definimos valores especiales
        nombres = {1: 'A', 11: 'J', 12: 'Q', 13: 'K'}
        nombre = nombres.get(self.puntos, str(self.puntos))
        return f"[{nombre}{self.palo}]"

def evaluar_mano(cartas_jugador, cartas_centro):
    todas_las_cartas = cartas_jugador + cartas_centro
    
    #revisamos solo los números y no el palo
    valores = [carta.puntos for carta in todas_las_cartas]
    
    #cuenta cuántas veces se repite cada número
    conteo = Counter(valores)
    
    # Ordenamos de mayor a menor frecuencia (para ver primero las tercias o pares)
    frecuencias = list(conteo.values())
    frecuencias.sort(reverse=True)
    
    #evaluamos qué combinación tiene
    if 4 in frecuencias:
        return 7, "Póker (4 iguales)"
    elif 3 in frecuencias and 2 in frecuencias:
        return 6, "Full House (Tercia y un Par)"
    elif 3 in frecuencias:
        return 4, "Tercia (3 iguales)"
    elif frecuencias.count(2) >= 2:
        return 3, "Doble Par"
    elif 2 in frecuencias:
        return 2, "Un Par"
    else:
        carta_mas_alta = max(valores)
        if 1 in valores: carta_mas_alta = 14 
        return 1, f"Carta Alta"

def preguntar_jugador(numero_jugador):
    respuesta = input(f"Jugador {numero_jugador}, ¿quieres seguir jugando? (si/no): ").lower()
    return respuesta == 'si' 

print("Bienvenido a la ludopatia\n")

palos = ['♥', '♣', '♦', '♠'] 
baraja = [Naipe(p, palo) for palo in palos for p in range(1, 14)]
random.shuffle(baraja)

#repartimos las cartas iniciales
player1 = [baraja.pop(), baraja.pop()]
player2 = [baraja.pop(), baraja.pop()]
centro = [baraja.pop(), baraja.pop(), baraja.pop()]

print("RONDA 1")
print(f"Mano Jugador 1: {player1[0]} {player1[1]}")
print(f"Mano Jugador 2: {player2[0]} {player2[1]}")
print(f"Cartas en el centro: {centro[0]} {centro[1]} {centro[2]}\n")

if not preguntar_jugador(1):
    print("\nEl Jugador 1 se rinde y el Jugador 2 GANA automáticamente")
    exit() # Termina el programa
if not preguntar_jugador(2):
    print("\nl Jugador 2 se rinde y el Jugador 1 GANA automáticamente")
    exit()

#comenzamos la segunda ronda
centro.append(baraja.pop()) #agregamos la 4ta carta al centro
print("\nRONDA 2")
print(f"Cartas en el centro: {centro[0]} {centro[1]} {centro[2]} {centro[3]}\n")

if not preguntar_jugador(1):
    print("\nEl Jugador 1 se rinde y el Jugador 2 GANA automáticamente")
    exit()
if not preguntar_jugador(2):
    print("\nEl Jugador 2 se rinde y el Jugador 1 GANA automáticamente")
    exit()

#comenzamos la tercera ronda
centro.append(baraja.pop()) #agregamos la 5ta carta al centro
print("\nRONDA 3")
print(f"Cartas en el centro finales: {centro[0]} {centro[1]} {centro[2]} {centro[3]} {centro[4]}\n")

if not preguntar_jugador(1):
    print("\nEl Jugador 1 se rinde y el Jugador 2 GANA automáticamente")
    exit()
if not preguntar_jugador(2):
    print("\nEl Jugador 2 se rinde y el Jugador 1 GANA automáticamente")
    exit()

#ultima evaluacion
print("\nResultados")
#evaluamos las manos de los jugadores con las del centro
nivel_p1, jugada_p1 = evaluar_mano(player1, centro)
nivel_p2, jugada_p2 = evaluar_mano(player2, centro)

print(f"Jugador 1 armó: {jugada_p1}")
print(f"Jugador 2 armó: {jugada_p2}\n")

if nivel_p1 > nivel_p2:
    print("Ganó el jugador 1")
elif nivel_p2 > nivel_p1:
    print("Ganó el jugador 2")
else:
    print("GG, empate, nos echamos otra?:)")
