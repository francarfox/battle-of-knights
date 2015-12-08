#include "Torneo.h"

Torneo::Torneo(int nivel,int participantes,Lista<Caballero*>* Caballeros)
{   if(nivel < 10)
    {   this->Nivel = 10;
        this->Comision = 1000;
    }
    else
    {   this->Nivel = nivel;
        this->Comision = 200*nivel+225*participantes;
    }
    this->CantParticipantes = participantes;
    this->Participantes = new Caballero*[CantParticipantes-1];
    int contador = 0;
    int unNivel = nivel;
    //if(participantes == 4)
    {   while(unNivel <= 50 && contador < CantParticipantes-1)
        {   IteradorLista<Caballero*> it = Caballeros->iterador();
            while(it.tieneSiguiente())
            {   Caballero* unCaba = it.siguiente();
                if(unNivel == unCaba->getNivel())
                {   this->Participantes[contador] = unCaba;
                    contador++;
                }//else unNivel++;
            }
            unNivel++;
        }
    }/*else
    {   while(unNivel > 0 && contador < CantParticipantes-1)
        {   IteradorLista<Caballero*> it = Caballeros->iterador();
            while(it.tieneSiguiente())
            {   Caballero* unCaba = it.siguiente();
                if(unNivel == unCaba->getNivel())
                {   this->Participantes[contador] = unCaba;
                    contador++;
                }
            }
            unNivel--;
        }
    }*/
}

Torneo::~Torneo()
{
}

int Torneo::getComision()
{   return this->Comision;
}

int Torneo::getNivel()
{   return this->Nivel;
}

void Torneo::Inscribir(Caballero* miCaballero,Lista<Item*>* miInventario,int& CantidadItems)
{   if(miCaballero->getNivel() >= this->Nivel)
    {   if(miCaballero->getOro() >= this->Comision)
        {   miCaballero->setOro( miCaballero->getOro()-this->Comision);
            system("cls");
            gotoxy(30,10);cout << "El Torneo va a empezar . . . ";
            Sleep(2500);
            gotoxy(30,10);cout << "                             ";
            if(this->CantParticipantes == 4)
                this->Empezar(miCaballero,miInventario,CantidadItems);
            else
                this->Empezar(miCaballero);
            system("cls");
        }else
        {   gotoxy(26,21); cout << "                                 ";
            gotoxy(26,21); cout << miCaballero->getNombre() <<" no tiene Oro suficiente";
        }
    }else
    {   gotoxy(26,21); cout << "                               ";
        gotoxy(26,21); cout << miCaballero->getNombre() <<" no tiene Nivel requerido";
    }
}

void Torneo::Empezar(Caballero* miCaballero,Lista<Item*>* miInventario,int& CantidadItems)
{   Caballero* unGanador = new Caballero;
    Batalla unaBatalla(miCaballero,unGanador);
    srand(time(0));
    int random = rand()%3;
    int caba1, caba2;
    switch(random)
    {   case 0: caba1 = 1; caba2 = 2; break;
        case 1: caba1 = 0; caba2 = 2; break;
        case 2: caba1 = 0; caba2 = 1; break;
    }
    unGanador = unaBatalla.Simular(Participantes[caba1],Participantes[caba2]);

    Batalla batalla( miCaballero,Participantes[random] );
    if(batalla.Luchar(miCaballero,Participantes[random]) == miCaballero)
    {   system("cls");
        Batalla batalla2( miCaballero,unGanador );
        unGanador = batalla2.Luchar( miCaballero,unGanador );
    }else
    {   unGanador = unaBatalla.Simular( Participantes[random],unGanador );
    }

    random = rand();
    Item* unItem = new Item(random%8,this->getNivel());

    if(miCaballero == unGanador)
    {   miInventario->agregar(unItem);
        CantidadItems++;
        miCaballero->setOro( miCaballero->getOro()+2*this->Comision );
    }else
    {   unGanador->setEquipo(unItem);
        unGanador->setOro( unGanador->getOro()+2*this->Comision );
    }

    gotoxy(3,20); cout << "                         ";
    gotoxy(3,21); cout << "                         ";
    gotoxy(3,20); cout << "El ganador es: " << unGanador->getNombre();
    gotoxy(3,21); cout << "Ha obtenido: " << unItem->getNombre() << " y +" << 2*this->Comision << " Oro.";
    gotoxy(3,22); system("pause");
}

void Torneo::Empezar(Caballero* miCaballero)
{   Caballero* unGanador = new Caballero;
    Batalla unaBatalla(miCaballero,unGanador);
    srand(time(0));
    int rondas = 0;
    int caba1, caba2, caba3, caba4, caba5, caba6, caba7, caba8;
    caba1 = caba2 = caba3 = caba4 = caba5 = caba6 = caba7 = caba8 = 0;
    int random = rand()%7;
    while(rondas < 7)
    {   this->VerEstadisticas(miCaballero,caba1,caba2,caba3,caba4,caba5,caba6,caba7,caba8,rondas);
        Batalla batalla(miCaballero,Participantes[random]);
        unGanador = batalla.Luchar(miCaballero,Participantes[random]);
        if(unGanador == miCaballero) caba8++;
        switch(random)
        {   case 0:
                if(unGanador == Participantes[random]) caba1++;
                unGanador = unaBatalla.Simular(Participantes[1],Participantes[2]); if(unGanador == Participantes[1]) caba2++; else caba3++;
                unGanador = unaBatalla.Simular(Participantes[3],Participantes[4]); if(unGanador == Participantes[3]) caba4++; else caba5++;
                unGanador = unaBatalla.Simular(Participantes[5],Participantes[6]); if(unGanador == Participantes[5]) caba6++; else caba7++;
                break;
            case 1:
                if(unGanador == Participantes[random]) caba2++;
                unGanador = unaBatalla.Simular(Participantes[0],Participantes[2]); if(unGanador == Participantes[0]) caba1++; else caba3++;
                unGanador = unaBatalla.Simular(Participantes[3],Participantes[4]); if(unGanador == Participantes[3]) caba4++; else caba5++;
                unGanador = unaBatalla.Simular(Participantes[5],Participantes[6]); if(unGanador == Participantes[5]) caba6++; else caba7++;
                break;
            case 2:
                if(unGanador == Participantes[random]) caba3++;
                unGanador = unaBatalla.Simular(Participantes[0],Participantes[1]); if(unGanador == Participantes[0]) caba1++; else caba2++;
                unGanador = unaBatalla.Simular(Participantes[3],Participantes[4]); if(unGanador == Participantes[3]) caba4++; else caba5++;
                unGanador = unaBatalla.Simular(Participantes[5],Participantes[6]); if(unGanador == Participantes[5]) caba6++; else caba7++;
                break;
            case 3:
                if(unGanador == Participantes[random]) caba4++;
                unGanador = unaBatalla.Simular(Participantes[0],Participantes[1]); if(unGanador == Participantes[0]) caba1++; else caba2++;
                unGanador = unaBatalla.Simular(Participantes[2],Participantes[4]); if(unGanador == Participantes[2]) caba3++; else caba5++;
                unGanador = unaBatalla.Simular(Participantes[5],Participantes[6]); if(unGanador == Participantes[5]) caba6++; else caba7++;
                break;
            case 4:
                if(unGanador == Participantes[random]) caba5++;
                unGanador = unaBatalla.Simular(Participantes[0],Participantes[1]); if(unGanador == Participantes[0]) caba1++; else caba2++;
                unGanador = unaBatalla.Simular(Participantes[2],Participantes[3]); if(unGanador == Participantes[2]) caba3++; else caba4++;
                unGanador = unaBatalla.Simular(Participantes[5],Participantes[6]); if(unGanador == Participantes[5]) caba6++; else caba7++;
                break;
            case 5:
                if(unGanador == Participantes[random]) caba6++;
                unGanador = unaBatalla.Simular(Participantes[0],Participantes[1]); if(unGanador == Participantes[0]) caba1++; else caba2++;
                unGanador = unaBatalla.Simular(Participantes[2],Participantes[3]); if(unGanador == Participantes[2]) caba3++; else caba4++;
                unGanador = unaBatalla.Simular(Participantes[4],Participantes[6]); if(unGanador == Participantes[4]) caba5++; else caba7++;
                break;
            case 6:
                if(unGanador == Participantes[random]) caba7++;
                unGanador = unaBatalla.Simular(Participantes[0],Participantes[1]); if(unGanador == Participantes[0]) caba1++; else caba2++;
                unGanador = unaBatalla.Simular(Participantes[2],Participantes[3]); if(unGanador == Participantes[2]) caba3++; else caba4++;
                unGanador = unaBatalla.Simular(Participantes[4],Participantes[5]); if(unGanador == Participantes[4]) caba5++; else caba6++;
                break;
        }
        rondas++; random++;
        if(random > 7) random = 0;
    }
    this->VerEstadisticas(miCaballero,caba1,caba2,caba3,caba4,caba5,caba6,caba7,caba8,rondas);
    if(caba8 > caba1 && caba8 > caba2 && caba8 > caba3 && caba8 > caba4 && caba8 > caba5 && caba8 > caba6 && caba8 > caba7 )
    {   Caballero* dragon = new Caballero("Gran Dragon",55,1,1);
        Batalla batalla(miCaballero,dragon);
        system("cls");
        gotoxy(25,10);cout << "Batalla contra el Gran Dragon . . . ";
        Sleep(2500);
        gotoxy(25,10);cout << "                                    ";
        if(batalla.Luchar(miCaballero,dragon) == miCaballero)
        {   random = rand()%8;
            if(random == 7)
            {   miCaballero->getEquipo(random)->setArmadura( miCaballero->getEquipo(random)->getArmadura()+100 );
                gotoxy(3,20); cout << "                         ";
                gotoxy(3,21); cout << "                                                            ";
                gotoxy(3,20); cout << "El ganador es: " << unGanador->getNombre();
                gotoxy(3,21); cout << "Ha obtenido: +" << 100 << " Danio en " << miCaballero->getEquipo(random)->getNombre();
                gotoxy(3,22); system("pause");
            }
            else
            {   miCaballero->getEquipo(random)->setArmadura( miCaballero->getEquipo(random)->getArmadura()+20 );
                gotoxy(3,20); cout << "                         ";
                gotoxy(3,21); cout << "                                                            ";
                gotoxy(3,20); cout << "El ganador es: " << unGanador->getNombre();
                gotoxy(3,21); cout << "Ha obtenido: +" << 20 << " de Arm en " << miCaballero->getEquipo(random)->getNombre();
                gotoxy(3,22); system("pause");
            }
        }else
        {   for(int i=0; i<8; i++)
            {   miCaballero->getEquipo(i)->setArmadura( miCaballero->getEquipo(i)->getArmadura()/2 );
            }
            gotoxy(3,20); cout << "                         ";
            gotoxy(3,21); cout << "                                                                ";
            gotoxy(3,20); cout << "El ganador es: " << dragon->getNombre();
            gotoxy(3,21); cout << "Sus Items resultaron afectados . . . ";
            gotoxy(3,22); system("pause");
        }
    }
    gotoxy(3,20); cout << "                           ";
    gotoxy(3,21); cout << "                                                          ";
    gotoxy(3,21); cout << "Liga de Legiones Finalizada . . . ";
    gotoxy(3,22); system("pause");
}

void Torneo::VerEstadisticas(Caballero* miCaballero,int caba1,int caba2,int caba3,int caba4,int caba5,int caba6,int caba7,int caba8,int rondas)
{   system("cls");
    gotoxy(32,7); cout << "LIGA DE LEGIONES";
    int ganados = 7;
    int contador = 9;
    for(int i=0; i<8; i++)
    {   if(caba1 == ganados)
        {   gotoxy(30,contador); cout << this->Participantes[0]->getNombre();
            gotoxy(42,contador); cout << caba1 << "\t" << rondas;
            contador++;
        }
        if(caba2 == ganados)
        {   gotoxy(30,contador); cout << this->Participantes[1]->getNombre();
            gotoxy(42,contador); cout << caba2 << "\t" << rondas;
            contador++;
        }
        if(caba3 == ganados)
        {   gotoxy(30,contador); cout << this->Participantes[2]->getNombre();
            gotoxy(42,contador); cout << caba3 << "\t" << rondas;
            contador++;
        }
        if(caba4 == ganados)
        {   gotoxy(30,contador); cout << this->Participantes[3]->getNombre();
            gotoxy(42,contador); cout << caba4 << "\t" << rondas;
            contador++;
        }
        if(caba5 == ganados)
        {   gotoxy(30,contador); cout << this->Participantes[4]->getNombre();
            gotoxy(42,contador); cout << caba5 << "\t" << rondas;
            contador++;
        }
        if(caba6 == ganados)
        {   gotoxy(30,contador); cout << this->Participantes[5]->getNombre();
            gotoxy(42,contador); cout << caba6 << "\t" << rondas;
            contador++;
        }
        if(caba7 == ganados)
        {   gotoxy(30,contador); cout << this->Participantes[6]->getNombre();
            gotoxy(42,contador); cout << caba7 << "\t" << rondas;
            contador++;
        }
        if(caba8 == ganados)
        {   gotoxy(30,contador); cout << miCaballero->getNombre();
            gotoxy(42,contador); cout << caba8 << "\t" << rondas;
            contador++;
        }
        ganados--;
    }
    gotoxy(25,21); system("pause");
    system("cls");
}
