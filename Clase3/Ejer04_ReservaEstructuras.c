#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//ESTRUCTURAS PARA LA APLICACIÓN
typedef struct Arma
{
    char * Tipo;
    int Bonus;
    int Ataque;
}Arma;

typedef struct Armadura
{
    char * Tipo;
    int Bonus;
    int Defensa;
}Armadura;

typedef struct Personaje
{
    char * Tipo;
    Arma  * Ataque;
    Armadura * Defensa;
}Personaje;


//ARREGLOS DE CADENA
char * TiposDePersonajes[] = {"Mago", "Hada", "Orco", "Guerrera", "Escudero", "Elfo"};
char * TiposDeArmas[] = {"Espada", "Arco", "Hacha", "Cuchillo", "Espada Milenaria", "Latigo"};
char * TiposDeArmaduras[] = {"Coraza de Metal", "Casco", "Hombreras de Plata", "Botas de guerra", "Greba", "Escudo"};


//DECLARACIÓN DE FUNCIONES
Armadura * CrearArmadura(int Defensa, int Bonus);
Personaje * CrearPersonaje();
void CargarArmadura(Personaje ** MiPersonaje, int Defensa, int Bonus);


//PROGRAMA PRINCIPAL
int main()
{
    srand (time(NULL));
    Personaje * nuevoPersonaje = CrearPersonaje();
    CargarArmadura(&nuevoPersonaje, rand() % 6, rand() % 6);

    printf("%s", nuevoPersonaje->Defensa->Tipo);
    getchar();
    return 0;
}


//DEFINICIÓN DE FUNCIONES
Personaje * CrearPersonaje()
{
    return (Personaje *) malloc(sizeof(Personaje));
}

void CargarArmadura(Personaje ** MiPersonaje, int Defensa, int Bonus)
{
    Armadura * nuevaArmadura  = CrearArmadura(Defensa, Bonus);
    (*MiPersonaje)->Defensa = nuevaArmadura;
}

Armadura * CrearArmadura(int Defensa, int Bonus)
{
    Armadura * nuevaArmadura = (Armadura *) malloc(sizeof(Armadura));
    int aletorio = rand() % 6;
    
    nuevaArmadura->Defensa = Defensa;
    nuevaArmadura->Bonus = Bonus;
    
    int tamanio = strlen(TiposDeArmaduras[aletorio]);
    nuevaArmadura->Tipo = (char *) malloc( tamanio * sizeof(char));
    strcpy(nuevaArmadura->Tipo, TiposDeArmaduras[aletorio]);

    return nuevaArmadura;
}