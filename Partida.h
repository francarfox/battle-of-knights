#ifndef PARTIDA_H
#define PARTIDA_H
#include "Lista.h"
#include "Caballero.h"
#include "Item.h"
#include "archivoRegistros.h"
#include <windows.h>


struct Partida
{   int ContadorC;
    int Nivel;
    int Ganadas;
    int Jugadas;
    int Exp;
    int Oro;

    int CategoriaE;
    int NivelE;

    int ContadorI;
    int CategoriaI;
    int NivelI;
};

struct PartidaN
{   char Nombre;
};

void CargarPartida(Caballero* miCaballero,Lista<Caballero*>* Caballeros,int& contadorC,
                    Lista<Item*>* miInventario,int& contadorI);
void GuardarPartida(Caballero* miCaballero,Lista<Caballero*>* Caballeros,int contadorC,
                    Lista<Item*>* miInventario,int contadorI);
void CargarCaballeros(Lista<Caballero*>* listaCaballeros,int& CantidadCabas);

#endif // PARTIDA_H
