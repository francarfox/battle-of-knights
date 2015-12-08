#include "Opcion.h"

void gotoxy(int x, int y)
{   COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Opcion2(Caballero* miCaballero,Lista<Caballero*>* Caballeros,Lista<Item*>* miInventario,int& CantidadItems)
{   Torneo unTorneo(miCaballero->getNivel(),4,Caballeros);
    Torneo otroTorneo1(10,4,Caballeros);
    Torneo otroTorneo2(20,4,Caballeros);
    Torneo otroTorneo3(30,4,Caballeros);
    Torneo otroTorneo4(40,4,Caballeros);
    Torneo otroTorneo5(50,4,Caballeros);
    Torneo otroTorneo6(46,8,Caballeros);

    int opcion = 8;
    int tecla = 0;
    while(tecla != 27)  //ESC
    {   gotoxy(38,6); cout << "TORNEOS";
        gotoxy(25,8); cout << "[1] Torneo   Nvl: " << unTorneo.getNivel() << "   Oro: " << unTorneo.getComision();
        gotoxy(25,9); cout << "[2] Torneo   Nvl: " << otroTorneo1.getNivel() << "   Oro: " << otroTorneo1.getComision();
        gotoxy(25,10); cout << "[3] Torneo   Nvl: " << otroTorneo2.getNivel() << "   Oro: " << otroTorneo2.getComision();
        gotoxy(25,11); cout << "[4] Torneo   Nvl: " << otroTorneo3.getNivel() << "   Oro: " << otroTorneo3.getComision();
        gotoxy(25,12); cout << "[5] Torneo   Nvl: " << otroTorneo4.getNivel() << "   Oro: " << otroTorneo4.getComision();
        gotoxy(25,13); cout << "[6] Torneo   Nvl: " << otroTorneo5.getNivel() << "   Oro: " << otroTorneo5.getComision();
        gotoxy(25,14); cout << "[7] Liga de Legiones   Nvl: 50";
        gotoxy(25,15); cout << "[8] Crear Torneo       Nvl: ##";

        gotoxy(23,opcion); printf("%c",16);
        while(tecla != 27 && tecla != 13)   //ESC || ENTER
        {   gotoxy(0,24);
            tecla = getch();
            switch(tecla)
            {   case 72:    //subir
                    if(opcion-1 >= 8 && opcion <= 15)
                    {   gotoxy(23,opcion); printf("%c",32);
                        opcion = opcion-1;
                        gotoxy(23,opcion); printf("%c",16);
                    }
                    break;
                case 80:    //bajar
                    if(opcion >= 8 && opcion+1 <= 15)
                    {   gotoxy(23,opcion); printf("%c",32);
                        opcion = opcion+1;
                        gotoxy(23,opcion); printf("%c",16);
                    }
                    break;
                case 13:    //ENTER
                    opcion = opcion + 41;
                    break;
            }
        }
        switch(opcion)
        {   case 49:
                unTorneo.Inscribir(miCaballero,miInventario,CantidadItems);
                opcion = opcion - 41;
                tecla = 0;
                break;
            case 50:
                otroTorneo1.Inscribir(miCaballero,miInventario,CantidadItems);
                opcion = opcion - 41;
                tecla = 0;
                break;
            case 51:
                otroTorneo2.Inscribir(miCaballero,miInventario,CantidadItems);
                opcion = opcion - 41;
                tecla = 0;
                break;
            case 52:
                otroTorneo3.Inscribir(miCaballero,miInventario,CantidadItems);
                opcion = opcion - 41;
                tecla = 0;
                break;
            case 53:
                otroTorneo4.Inscribir(miCaballero,miInventario,CantidadItems);
                opcion = opcion - 41;
                tecla = 0;
                break;
            case 54:
                otroTorneo5.Inscribir(miCaballero,miInventario,CantidadItems);
                opcion = opcion - 41;
                tecla = 0;
                break;
            case 55:
                otroTorneo6.Inscribir(miCaballero,miInventario,CantidadItems);
                opcion = opcion - 41;
                tecla = 0;
                break;
            case 56:
            {   int nivel = 0;
                gotoxy(30,17); cout << "Ingresar Nivel: ";
                cin >> nivel;
                gotoxy(30,17); cout <<"                       ";
                if(nivel >= 10 && nivel <= 50)
                {   Torneo otroTorneo7(nivel,4,Caballeros);
                    otroTorneo7.Inscribir(miCaballero,miInventario,CantidadItems);
                }else
                {   gotoxy(26,21); cout << "                               ";
                    gotoxy(26,21); cout << "Nivel ingresado incorrecto";
                }
                opcion = opcion - 41;
                tecla = 0;
                break;
            }
        }
    }
    IteradorLista<Caballero*> it = Caballeros->iterador();
    while(it.tieneSiguiente())
    {   Caballero* unCaba = it.get();
        Caballero* otroCaba = it.siguiente();
        Batalla batalla(unCaba,otroCaba);
        batalla.Simular(unCaba,otroCaba);
        it.siguiente();
    }
}

void Opcion3(Caballero* miCaballero,Lista<Item*>* miInventario,int& CantidadItems)
{   int opcion = 3;
    int tecla = 0;
    while(tecla != 27)  //ESC
    {   gotoxy(41,opcion); printf("%c",16);
        while(tecla != 27 && tecla != 13)   //ESC || ENTER
        {   gotoxy(0,24);
            tecla = getch();
            switch(tecla)
            {   case 72:    //subir
                    if(opcion-1 >= 3 && opcion <= CantidadItems+2)
                    {   gotoxy(41,opcion); printf("%c",32);
                        opcion = opcion-1;
                        gotoxy(41,opcion); printf("%c",16);
                    }
                    break;
                case 80:    //bajar
                    if(opcion >= 3 && opcion+1 <= CantidadItems+2)
                    {   gotoxy(41,opcion); printf("%c",32);
                        opcion = opcion+1;
                        gotoxy(41,opcion); printf("%c",16);
                    }
                    break;
                case 13:    //ENTER
                    opcion = opcion + 46;
                    break;
                case 83:     //SUPR
                {   if(CantidadItems > 0)
                    {   miCaballero->setOro(miCaballero->getOro()+500);
                        gotoxy(10,9); cout << "            ";
                        gotoxy(10,9); cout << miCaballero->getOro();
                        int contador = 3;
                        IteradorLista<Item*> it = miInventario->iterador();
                        while(it.tieneSiguiente() && contador-3 <= CantidadItems)
                        {   if(contador == opcion)
                            {   it.remover(); CantidadItems--;
                                contador = 100;
                            }else
                            {   it.siguiente(); contador++;
                            }
                        }
                        for(int i=3; i<=CantidadItems+3; i++)
                        {   gotoxy(43,i); cout << "                              ";
                        }
                        contador = 3;
                        IteradorLista<Item*> it2 = miInventario->iterador();
                        while(it2.tieneSiguiente())
                        {   Item* unItem = it2.siguiente();
                            gotoxy(43,contador); cout << unItem->getNombre();
                            gotoxy(54,contador); cout << "Nvl " << unItem->getNivel();
                            gotoxy(61,contador); cout << "+" << unItem->getArmadura();
                            contador++;
                        }
                    }
                    if(opcion-1 >= 3 && opcion > CantidadItems+2)
                    {   gotoxy(41,opcion); printf("%c",32);
                        opcion = opcion-1;
                        gotoxy(41,opcion); printf("%c",16);
                    }
                    break;
                }
                case 9:     //TAB
                    gotoxy(41,opcion); printf("%c",32);
                    OpcionEquipo(miCaballero,miInventario,CantidadItems);
                    tecla = 27;
                    break;
            }
        }
        if(opcion == 49 && CantidadItems == 0)
        {   opcion = opcion - 46; tecla = 0;
        }else
        {   int contador = 49;
            IteradorLista<Item*> it = miInventario->iterador();
            while(it.tieneSiguiente() && contador-49 <= CantidadItems)
            {   Item* unItem = it.get();
                if(contador == opcion)
                {   if(miCaballero->getEquipo(unItem->getCategoria())->getNombre() == "...")
                    {   miCaballero->setEquipo(unItem);
                        it.remover(); CantidadItems--;

                        for(int i=0; i<Max_Items; i++)
                        {   gotoxy(6,i+14); cout << "                             ";
                            gotoxy(6,i+14); cout << i+1 << " " << miCaballero->getEquipo(i)->getNombre();
                            gotoxy(19,i+14); cout << "Nvl " << miCaballero->getEquipo(i)->getNivel();
                            gotoxy(26,i+14); cout << "+" << miCaballero->getEquipo(i)->getArmadura();
                        }
                        gotoxy(10,5); cout << "   ";
                        gotoxy(10,5); cout << miCaballero->getArmadura();
                        for(int i=3; i<=CantidadItems+3; i++)
                        {   gotoxy(43,i); cout << "                              ";
                        }
                        contador = 3;
                        IteradorLista<Item*> it2 = miInventario->iterador();
                        while(it2.tieneSiguiente())
                        {   Item* unItem = it2.siguiente();
                            gotoxy(43,contador); cout << unItem->getNombre();
                            gotoxy(54,contador); cout << "Nvl " << unItem->getNivel();
                            gotoxy(61,contador); cout << "+" << unItem->getArmadura();
                            contador++;
                        }
                        opcion = opcion - 46;
                        tecla = 0;
                    }
                    else
                    {   gotoxy(3,23); cout << "                                 ";
                        gotoxy(3,23); cout << "Ya tiene " << unItem->getNombre() << " equipado.";
                        opcion = opcion - 46;
                        tecla = 0;
                    }contador++;
                    if(opcion-1 >= 3 && opcion > CantidadItems+2)
                    {   gotoxy(41,opcion); printf("%c",32);
                        opcion = opcion-1;
                        gotoxy(41,opcion); printf("%c",16);
                    }
                }
                else
                {   it.siguiente();
                    contador++;
                }
            }
        }
    }
}

void OpcionEquipo(Caballero* miCaballero,Lista<Item*>* miInventario,int& CantidadItems)
{   int opcion = 14;
    int tecla = 0;
    while(tecla != 27)  //ESC
    {   gotoxy(4,opcion); printf("%c",16);
        while(tecla != 27 && tecla != 13)   //ESC || ENTER
        {   gotoxy(0,24);
            tecla = getch();
            switch(tecla)
            {   case 72:    //subir
                    if(opcion-1 >= 14 && opcion <= 21)
                    {   gotoxy(4,opcion); printf("%c",32);
                        opcion = opcion-1;
                        gotoxy(4,opcion); printf("%c",16);
                    }
                    break;
                case 80:    //bajar
                    if(opcion >= 14 && opcion+1 <= 21)
                    {   gotoxy(4,opcion); printf("%c",32);
                        opcion = opcion+1;
                        gotoxy(4,opcion); printf("%c",16);
                    }
                    break;
                case 13:    //ENTER
                    opcion = opcion + 35;
                    break;
                /*case 83:     //SUPR
                {   if(miCaballero->getEquipo(opcion-14)->getNombre() != "...")
                    {   Item* unItem = new Item;
                        miCaballero->setOro(miCaballero->getOro()+300);
                        gotoxy(10,10); cout << "            ";
                        gotoxy(10,10); cout << miCaballero->getOro();
                        miCaballero->getEquipo(opcion-14)->setNombre(unItem->getNombre());
                        miCaballero->getEquipo(opcion-14)->setCategoria(unItem->getCategoria());
                        miCaballero->getEquipo(opcion-14)->setNivel(unItem->getNivel());
                        miCaballero->getEquipo(opcion-14)->setArmadura(unItem->getArmadura());
                    }
                    for(int i=0; i<Max_Items; i++)
                    {   gotoxy(6,i+14); cout << "                             ";
                        gotoxy(6,i+14); cout << i+1 << " " << miCaballero->getEquipo(i)->getNombre();
                        gotoxy(19,i+14); cout << "Nvl " << miCaballero->getEquipo(i)->getNivel();
                        gotoxy(26,i+14); cout << "+" << miCaballero->getEquipo(i)->getArmadura();
                    }
                    gotoxy(10,5); cout << "   ";
                    gotoxy(10,5); cout << miCaballero->getArmadura();
                    break;
                }*/
                case 9:     //TAB
                    gotoxy(4,opcion); printf("%c",32);
                    Opcion3(miCaballero,miInventario,CantidadItems);
                    tecla = 27;
                    break;
            }
        }
        if(opcion >= 49)
        {   if(miCaballero->getEquipo(opcion-49)->getNombre() != "...")
            {   Item* unItem = new Item;
                Item* item = new Item( miCaballero->getEquipo(opcion-49)->getCategoria(),miCaballero->getEquipo(opcion-49)->getNivel() );
                miInventario->agregar( item );
                CantidadItems++;
                miCaballero->getEquipo(opcion-49)->setNombre(unItem->getNombre());
                miCaballero->getEquipo(opcion-49)->setCategoria(unItem->getCategoria());
                miCaballero->getEquipo(opcion-49)->setNivel(unItem->getNivel());
                miCaballero->getEquipo(opcion-49)->setArmadura(unItem->getArmadura());
            }
            for(int i=0; i<Max_Items; i++)
            {   gotoxy(6,i+14); cout << "                             ";
                gotoxy(6,i+14); cout << i+1 << " " << miCaballero->getEquipo(i)->getNombre();
                gotoxy(19,i+14); cout << "Nvl " << miCaballero->getEquipo(i)->getNivel();
                gotoxy(26,i+14); cout << "+" << miCaballero->getEquipo(i)->getArmadura();
            }
            gotoxy(10,5); cout << "   ";
            gotoxy(10,5); cout << miCaballero->getArmadura();

            for(int i=3; i<=CantidadItems+3; i++)
            {   gotoxy(43,i); cout << "                              ";
            }

            int contador = 3;
            IteradorLista<Item*> it = miInventario->iterador();
            while(it.tieneSiguiente())
            {   Item* unItem = it.siguiente();
                gotoxy(43,contador); cout << unItem->getNombre();
                gotoxy(54,contador); cout << "Nvl " << unItem->getNivel();
                gotoxy(61,contador); cout << "+" << unItem->getArmadura();
                contador++;
            }
            opcion = opcion - 35;
            tecla = 0;
        }
    }
}

int puestoRanking(Lista<Caballero*>* listaCaballeros,Caballero* miCaballero)
{   listaCaballeros->agregar(miCaballero);

    Lista<Caballero*>* resultado = new Lista<Caballero*>;
    Lista<Caballero*>* resultado2 = new Lista<Caballero*>;

    double unaReputacion = 100;
    while(unaReputacion > 0)
    {   IteradorLista<Caballero*> it = listaCaballeros->iterador();
        while(it.tieneSiguiente())
        {   Caballero* unCaba = it.siguiente();
            if(unaReputacion == unCaba->getReputacion())
                resultado->agregar(unCaba);
        } unaReputacion--;
    }
    int unNivel = 50;
    while(unNivel > 0)
    {   IteradorLista<Caballero*> it = resultado->iterador();

        while(it.tieneSiguiente())
        {   Caballero* unCaba = it.siguiente();
            if(unNivel == unCaba->getNivel())
                resultado2->agregar(unCaba);
        } unNivel--;
    }

    int puesto = 1;
    bool encontrado = false;
    IteradorLista<Caballero*> it = resultado2->iterador();
    for(int i=1; i<=Max_Rank; i++)
    while(it.tieneSiguiente() && !encontrado)
    {   Caballero* unCaba = it.siguiente();
        if(unCaba == miCaballero)
            encontrado = true;
        else
            puesto++;
    }

    IteradorLista<Caballero*> it2 = listaCaballeros->iterador();
    while(it2.tieneSiguiente())
    {   Caballero* unCaba = it2.get();
        if(unCaba == miCaballero)
            it2.remover();
        else
            it2.siguiente();
    }

    if(miCaballero->getNivel() < 10)
        puesto = 0;
    return puesto;
}

void Opcion4(Lista<Caballero*>* listaCaballeros,Caballero* miCaballero)
{   listaCaballeros->agregar(miCaballero);

    Lista<Caballero*>* resultado = new Lista<Caballero*>;
    Lista<Caballero*>* resultado2 = new Lista<Caballero*>;

    double unaReputacion = 100;
    while(unaReputacion > 0)
    {   IteradorLista<Caballero*> it = listaCaballeros->iterador();
        while(it.tieneSiguiente())
        {   Caballero* unCaba = it.siguiente();
            if(unaReputacion == unCaba->getReputacion())
                resultado->agregar(unCaba);
        } unaReputacion--;
    }
    int unNivel = 50;
    while(unNivel > 0)
    {   IteradorLista<Caballero*> it = resultado->iterador();

        while(it.tieneSiguiente())
        {   Caballero* unCaba = it.siguiente();
            if(unNivel == unCaba->getNivel())
                resultado2->agregar(unCaba);
        } unNivel--;
    }

    gotoxy(26,1); cout << "#   Nombre \t  Nivel  Reputacion";
    IteradorLista<Caballero*> it = resultado2->iterador();
    for(int i=1; i<=Max_Rank; i++)
    {   Caballero* unCaba = it.siguiente();
        gotoxy(26,i+2); cout << i;
        gotoxy(30,i+2); cout << unCaba->getNombre();
        gotoxy(43,i+2); cout << unCaba->getNivel();
        gotoxy(51,i+2); cout << unCaba->getReputacion() << " % ";
    }

    int tecla = 0;
    while(tecla != 27 && tecla != 13)
    {   gotoxy(0,24);
        tecla = getch();
    }

    IteradorLista<Caballero*> it2 = listaCaballeros->iterador();
    while(it2.tieneSiguiente())
    {   Caballero* unCaba = it2.get();
        if(unCaba == miCaballero)
            it2.remover();
        else
            it2.siguiente();
    }
}

void Opcion5()
{   string linea;
    int contador = 1;
    int tecla = 0;
    ArchivoTexto archivo("Ayuda.txt");
    while(archivo.leerLinea(linea))
    {   gotoxy(2,contador);
        cout << linea;
        contador++;
    }
    while(tecla != 27 && tecla != 13)
    {   gotoxy(0,24);
        tecla = getch();
    }
}
