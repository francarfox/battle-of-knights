#ifndef OPCION_H
#define OPCION_H
#include "Lista.h"
#include "Caballero.h"
#include "Torneo.h"
#include "archivoTexto.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define Max_Rank 20

struct Opcion
{
};

void gotoxy(int x, int y);
void Opcion2(Caballero* miCaballero,Lista<Caballero*>* Caballeros,Lista<Item*>* miInventario,int& CantidadItems);
void Opcion3(Caballero* miCaballero,Lista<Item*>* inventario,int& CantidadItems);
void OpcionEquipo(Caballero* miCaballero,Lista<Item*>* miInventario,int& CantidadItems);
int puestoRanking(Lista<Caballero*>* Caballeros,Caballero* miCaballero);
void Opcion4(Lista<Caballero*>* Caballeros,Caballero* miCaballero);
void Opcion5();

#endif // OPCION_H
