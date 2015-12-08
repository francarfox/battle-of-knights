#include "Opcion.h"
#include "Partida.h"

void MenuIntro()
{   gotoxy(32,4); cout << "BATTLE OF KNIGHTS" << endl;
    gotoxy(32,8); cout << "Continuar Partida" << endl;
    gotoxy(32,9); cout << "  Nueva Partida" << endl;
}

void MenuNombre(Caballero* miCaballero)
{   string nombre;
    gotoxy(32,4); cout << "BATTLE OF KNIGHTS" << endl;
    gotoxy(32,8); cout << "Ingresar Nombre:" << endl;
    gotoxy(37,10); cin >> nombre; miCaballero->setNombre(nombre);
}

void MenuPrincipal()
{   system("cls");
    gotoxy(32,4); cout << "BATTLE OF KNIGHTS" << endl;
    gotoxy(34,8); cout << "Entrenamiento" << endl;
    gotoxy(34,9); cout << " Ver Torneos" << endl;
    gotoxy(34,10); cout << "  Caballero" << endl;
    gotoxy(34,11); cout << "   Ranking" << endl;
    gotoxy(34,12); cout << "    Ayuda" << endl;
    gotoxy(34,13); cout << "    Salir" << endl;
}

void MenuOpcion3(Lista<Caballero*>* listaCaballeros,Caballero* miCaballero,Lista<Item*>* miInventario)
{   gotoxy(3,1); cout << miCaballero->getNivel() << "  " << miCaballero->getNombre();
    gotoxy(3,3); cout << "Vida:  " << miCaballero->getVida();
    gotoxy(14,3); cout << " / " << miCaballero->getVida() << endl;
    gotoxy(3,4); cout << "Mana:  " << miCaballero->getMana();
    gotoxy(14,4); cout << " / " << miCaballero->getMana();
    gotoxy(3,5); cout << "Arm:   " << miCaballero->getArmadura();
    gotoxy(3,7); cout << "Rep:   " << miCaballero->getBGanadas() << " / " << miCaballero->getBJugadas();
    gotoxy(27,7); cout << miCaballero->getReputacion() << " %" << endl;
    gotoxy(3,8); cout << "Exp:   " << miCaballero->getExperiencia() << " / " << miCaballero->expNecesaria();
    gotoxy(27,8); cout << miCaballero->porcentajeExp() << " %" << endl;
    gotoxy(3,9); cout << "Oro:   " << miCaballero->getOro();
    gotoxy(3,10); cout << "Rank:  " << puestoRanking(listaCaballeros,miCaballero);
    gotoxy(3,12); printf("%c",30); printf("%c",31); cout << " Equipo:";
    for(int i=0; i<Max_Items; i++)
    {   gotoxy(6,i+14); cout << i+1 << " " << miCaballero->getEquipo(i)->getNombre();
        gotoxy(19,i+14); cout << "Nvl " << miCaballero->getEquipo(i)->getNivel();
        gotoxy(26,i+14); cout << "+" << miCaballero->getEquipo(i)->getArmadura();
    }

    gotoxy(40,1); printf("%c",30); printf("%c",31); cout << " Inventario:";
    int contador = 3;
    IteradorLista<Item*> it = miInventario->iterador();
    while(it.tieneSiguiente())
    {   Item* unItem = it.siguiente();
        gotoxy(43,contador); cout << unItem->getNombre();
        gotoxy(54,contador); cout << "Nvl " << unItem->getNivel();
        gotoxy(61,contador); cout << "+" << unItem->getArmadura();
        contador++;
    }
}

int main()
{   system("color 06");
    Caballero* miCaballero = new Caballero("Knight");
    Lista<Caballero*>* Caballeros = new Lista<Caballero*>;
    int CantidadCabas = 0;
    Lista<Item*>* miInventario = new Lista<Item*>;
    int CantidadItems = 1;

    int opcion = 8;
    int tecla = 1;
    //Introduccion
    MenuIntro();
    while(tecla != 0)  //ESC
    {
        gotoxy(30,opcion); printf("%c",16);
        gotoxy(50,opcion); printf("%c",17);
        while(tecla != 13)   //ENTER
        {   gotoxy(0,24);
            tecla = getch();
            switch(tecla)
            {   case 72:    //Subir
                    if(opcion-1 >= 8 && opcion <= 9)
                    {   gotoxy(30,opcion); printf("%c",32);
                        gotoxy(50,opcion); printf("%c",32);
                        opcion = opcion-1;
                        gotoxy(30,opcion); printf("%c",16);
                        gotoxy(50,opcion); printf("%c",17);
                    }
                    break;
                case 80:    //Bajar
                    if(opcion >= 8 && opcion+1 <= 9)
                    {   gotoxy(30,opcion); printf("%c",32);
                        gotoxy(50,opcion); printf("%c",32);
                        opcion = opcion+1;
                        gotoxy(30,opcion); printf("%c",16);
                        gotoxy(50,opcion); printf("%c",17);
                    }
                    break;
                case 13:    //ENTER
                    opcion = opcion + 41;
                    break;
            }
        }
        switch(opcion)
        {   case 49:
                system("cls");
                CargarCaballeros(Caballeros,CantidadCabas);
                CargarPartida(miCaballero,Caballeros,CantidadCabas,miInventario,CantidadItems);
                opcion = 8;
                tecla = 0;
                break;
            case 50:
                system("cls");
                MenuNombre(miCaballero);
                CargarCaballeros(Caballeros,CantidadCabas);
                Item* unItem = new Item(7,1);
                miInventario->agregar(unItem);
                opcion = 8;
                tecla = 0;
                break;
        }
    }

    //Interfaz de la Aplicacion
    MenuPrincipal();
    while(tecla != 1)  //ESC
    {
        gotoxy(32,opcion); printf("%c",16);
        gotoxy(48,opcion); printf("%c",17);
        while(tecla != 13)   //ENTER
        {   gotoxy(0,24);
            tecla = getch();
            switch(tecla)
            {   case 72:    //Subir
                    if(opcion-1 >= 8 && opcion <= 13)
                    {   gotoxy(32,opcion); printf("%c",32);
                        gotoxy(48,opcion); printf("%c",32);
                        opcion = opcion-1;
                        gotoxy(32,opcion); printf("%c",16);
                        gotoxy(48,opcion); printf("%c",17);
                    }
                    break;
                case 80:    //Bajar
                    if(opcion >= 8 && opcion+1 <= 13)
                    {   gotoxy(32,opcion); printf("%c",32);
                        gotoxy(48,opcion); printf("%c",32);
                        opcion = opcion+1;
                        gotoxy(32,opcion); printf("%c",16);
                        gotoxy(48,opcion); printf("%c",17);
                    }
                    break;
                case 13:    //ENTER
                    opcion = opcion + 41;
                    break;
            }
        }
        switch(opcion)
        {   case 49:    //opcion '1'
            {   system("cls");
                Caballero* unCaballero = new Caballero("Knight",miCaballero->getNivel());
                Batalla batalla(miCaballero,unCaballero);
                batalla.Entrenar(miCaballero,unCaballero,miInventario,CantidadItems);
                MenuPrincipal();
                opcion = opcion - 41;
                tecla = 0;
                break;
            }
            case 50:    //opcion '2'
            {   system("cls");
                Opcion2(miCaballero,Caballeros,miInventario,CantidadItems);
                MenuPrincipal();
                opcion = opcion - 41;
                tecla = 0;
                break;
            }
            case 51:    //opcion '3'
                system("cls");
                MenuOpcion3(Caballeros,miCaballero,miInventario);
                Opcion3(miCaballero,miInventario,CantidadItems);
                MenuPrincipal();
                opcion = opcion - 41;
                tecla = 0;
                break;
            case 52:    //opcion '4'
                system("cls");
                Opcion4(Caballeros,miCaballero);
                MenuPrincipal();
                opcion = opcion - 41;
                tecla = 0;
                break;
            case 53:    //opcion '5'
                system("cls");
                Opcion5();
                MenuPrincipal();
                opcion = opcion - 41;
                tecla = 0;
                break;
            case 54:    //opcion '6'
            {   opcion = opcion - 41;
                tecla = 1;
                break;
            }
        }
    }
    GuardarPartida(miCaballero,Caballeros,CantidadCabas,miInventario,CantidadItems);
    return 0;
}
