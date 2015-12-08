#include "Batalla.h"

Batalla::Batalla(Caballero* miCaballero,Caballero* unCaballero)
{   this->Ganador = unCaballero;
}

Batalla::~Batalla()
{
}

int Batalla::CalculoDanio(int danio,int arm)
{   int resultado = danio - arm*danio/1000;
    return resultado;
}

void Batalla::MostrarCaballeros(Caballero* miCaballero,Caballero* unCaballero)
{   gotoxy(3,1); cout << miCaballero->getNivel() << "  " << miCaballero->getNombre();
    gotoxy(3,3); cout << "Vida:  " << miCaballero->getVida();
    gotoxy(14,3); cout << " / " << miCaballero->getVida() << endl;
    gotoxy(3,4); cout << "Mana:  " << miCaballero->getMana();
    gotoxy(14,4); cout << " / " << miCaballero->getMana();
    gotoxy(3,5); cout << "Arm:   " << miCaballero->getArmadura();;
    gotoxy(3,7); cout << "Reputacion:  " << miCaballero->getReputacion() << " %" << endl;
    gotoxy(3,8); cout << "Experiencia: " << miCaballero->porcentajeExp() << " %" << endl;

    gotoxy(58,1); cout << unCaballero->getNivel() << "  " << unCaballero->getNombre();
    gotoxy(58,3); cout << "Vida:  " << unCaballero->getVida();
    gotoxy(69,3); cout << " / " << unCaballero->getVida() << endl;
    gotoxy(58,4); cout << "Mana:  " << unCaballero->getMana();
    gotoxy(69,4); cout << " / " << unCaballero->getMana();
    gotoxy(58,5); cout << "Arm:   " << unCaballero->getArmadura();;
    gotoxy(58,7); cout << "Reputacion:  " << unCaballero->getReputacion() << " %" << endl;
    gotoxy(58,8); cout << "Experiencia: " << unCaballero->porcentajeExp() << " %" << endl;

    gotoxy(3,11); cout << "[1] Ataque.";
    gotoxy(3,12); cout << "[2] Meditar.";
    if(miCaballero->getTecnicas() > 2)
    {   gotoxy(3,13); cout << "[3] Corte.";
        if(miCaballero->getTecnicas() > 3)
        {   gotoxy(3,14); cout << "[4] Inmune.";
            if(miCaballero->getTecnicas() > 4)
            {   gotoxy(3,15); cout << "[5] Furia.";
                if(miCaballero->getTecnicas() > 5)
                {   gotoxy(3,16); cout << "[6] Vision.";
                    if(miCaballero->getTecnicas() > 6)
                    {   gotoxy(3,17); cout << "[7] Colera.";
                    }
                }
            }
        }
    }
}

void Batalla::MostrarTecnica(Caballero* miCaballero,int opcion)
{   for(int i=11; i<=16; i++)
    {   gotoxy(58,i); cout << "                     ";
    }
    switch(opcion)
    {   case 11:
            gotoxy(58,11); cout << "[1] Ataque.";
            gotoxy(58,12); cout << "Costo: " << 10+2*miCaballero->getNivel() << " mana.";
            gotoxy(58,13); cout << "Ataque normal de";
            gotoxy(58,14); cout << "danio espada.";
            break;
        case 12:
            gotoxy(58,11); cout << "[2] Meditar.";
            gotoxy(58,12); cout << "Costo: " << 0 << " mana.";
            gotoxy(58,13); cout << "Recupera +" << 400 << " mana.";
            break;
        case 13:
            gotoxy(58,11); cout << "[3] Corte.";
            gotoxy(58,12); cout << "Costo: " << 250 << " mana.";
            gotoxy(58,13); cout << 100 << "% danio espada";
            gotoxy(58,14); cout << "+" << 200 << " danio espada.";
            break;
        case 14:
            gotoxy(58,11); cout << "[4] Inmune.";
            gotoxy(58,12); cout << "Costo: " << 250 << " mana.";
            gotoxy(58,13); cout << "No puede atacar ni";
            gotoxy(58,14); cout << "ser atacado por";
            gotoxy(58,15); cout << 3 << " turnos.";
            gotoxy(58,16); cout << "Recarga: " << 7 << " turnos.";
            break;
        case 15:
            gotoxy(58,11); cout << "[5] Furia.";
            gotoxy(58,12); cout << "Costo: " << 400 << " mana.";
            gotoxy(58,13); cout << 150 << "% danio con " << 50 << "%";
            gotoxy(58,14); cout << "chance de " << 200 <<"%";
            gotoxy(58,15); cout << "danio espada.";
            break;
        case 16:
            gotoxy(58,11); cout << "[6] Vision.";
            gotoxy(58,12); cout << "Costo: " << 250 << " mana.";
            gotoxy(58,13); cout << "Aumenta +" << 1000 << " vida.";
            gotoxy(58,14); cout << "Recarga: " << 10 << " turnos.";
            break;
        case 17:
            gotoxy(58,11); cout << "[7] Colera.";
            gotoxy(58,12); cout << "Costo: " << 400 << " mana.";
            gotoxy(58,13); cout << "Reduce el danio";
            gotoxy(58,14); cout << "enemigo en " << 90 << "% por";
            gotoxy(58,15); cout << 5 << " turnos.";
            gotoxy(58,16); cout << "Recarga: " << 25 << " turnos.";
            break;
    }
}

void Batalla::InvocarTecnica(Caballero* miCaballero,Caballero* unCaballero,int& Vida1,int& Mana1,int& Arm1,int& Vida2,int& Mana2,int& Arm2,
                             int& opcion,int& tecla, int contador,int& inmune1,int& colera1,int& vision1,int inmune2)
{   int random = rand();
    switch(opcion)
    {   case 49:    //opcion '1'
        {   if(inmune1 > 2)
            {   if(inmune2 > 2)
                {   if(Mana1 >= 10+2*miCaballero->getNivel())
                    {   Mana1 = Mana1 - (10+2*miCaballero->getNivel());
                        if(!unCaballero->getResistencia(random))
                        {   Vida2 = Vida2 - CalculoDanio(miCaballero->getDanio(),Arm2);
                            gotoxy(27,contador); cout << "                            ";
                            gotoxy(27,contador+1); cout << "                            ";
                            gotoxy(27,contador); cout << miCaballero->getNombre() << "-->Ataque(1)["
                            << CalculoDanio(miCaballero->getDanio(),Arm2) << "]";
                        }else
                        {   gotoxy(27,contador); cout << "                            ";
                            gotoxy(27,contador+1); cout << "                            ";
                            gotoxy(27,contador); cout << "-->Ataque(1) resistido";
                        }
                    }else
                    {   gotoxy(27,contador); cout << "                            ";
                        gotoxy(27,contador+1); cout << "                            ";
                        gotoxy(27,contador); cout << "Mana insuficiente";
                    }
                }else
                {   gotoxy(27,contador); cout << "                            ";
                    gotoxy(27,contador+1); cout << "                            ";
                    gotoxy(27,contador); cout << "No puede ser atacado";
                }
            }else
            {   gotoxy(27,contador); cout << "                            ";
                gotoxy(27,contador+1); cout << "                            ";
                gotoxy(27,contador); cout << "No puede atacar";
            }
            opcion = opcion - 38;
            tecla = 0;
            break;
        }
        case 50:    //opcion '2'
        {   Mana1 = Mana1 + 400;
            if(Mana1 > miCaballero->getMana())
                Mana1 = miCaballero->getMana();
            gotoxy(27,contador); cout << "                            ";
            gotoxy(27,contador+1); cout << "                            ";
            gotoxy(27,contador); cout << miCaballero->getNombre() << "-->Meditar(1)";
            opcion = opcion - 38;
            tecla = 0;
            break;
        }
        case 51:    //opcion '3'
        {   if(inmune1 > 2)
            {   if(inmune2 > 2)
                {   if(Mana1 >= 250)
                    {   Mana1 = Mana1 - 250;
                        if(!unCaballero->getResistencia(random))
                        {   Vida2 = Vida2 - CalculoDanio(miCaballero->getDanio()+200,Arm2);
                            gotoxy(27,contador); cout << "                            ";
                            gotoxy(27,contador+1); cout << "                            ";
                            gotoxy(27,contador); cout << miCaballero->getNombre() << "-->Corte(1)["
                            << CalculoDanio(miCaballero->getDanio()+200,Arm2) << "]";
                        }else
                        {   gotoxy(27,contador); cout << "                            ";
                            gotoxy(27,contador+1); cout << "                            ";
                            gotoxy(27,contador); cout << "-->Corte(1) resistido";
                        }
                    }else
                    {   gotoxy(27,contador); cout << "                            ";
                        gotoxy(27,contador+1); cout << "                            ";
                        gotoxy(27,contador); cout << "Mana insuficiente";
                    }
                }else
                {   gotoxy(27,contador); cout << "                            ";
                    gotoxy(27,contador+1); cout << "                            ";
                    gotoxy(27,contador); cout << "No puede ser atacado";
                }
            }else
            {   gotoxy(27,contador); cout << "                            ";
                gotoxy(27,contador+1); cout << "                            ";
                gotoxy(27,contador); cout << "No puede atacar";
            }
            opcion = opcion - 38;
            tecla = 0;
            break;
        }
        case 52:    //opcion '4'
        {   if(inmune1 > 6)
            {   if(Mana1 >= 250)
                {   Mana1 = Mana1 - 250;
                    inmune1 = 0;
                    gotoxy(27,contador); cout << "                            ";
                    gotoxy(27,contador+1); cout << "                            ";
                    gotoxy(27,contador); cout << miCaballero->getNombre() << "-->Inmune(1)";
                    gotoxy(10,4); cout << "    ";
                    gotoxy(10,4); cout << Mana1;
                }else
                {   gotoxy(27,contador); cout << "                            ";
                    gotoxy(27,contador+1); cout << "                            ";
                    gotoxy(27,contador); cout << "Mana insuficiente";
                }
            }else
            {   gotoxy(27,contador); cout << "                            ";
                gotoxy(27,contador+1); cout << "                            ";
                gotoxy(27,contador); cout << "Tecnica en Recarga";
            }
            opcion = opcion - 38;
            tecla = 0;
            break;
        }
        case 53:    //opcion '5'
        {   if(inmune1 > 2)
            {   if(inmune2 > 2)
                {   if(Mana1 >= 400)
                    {   Mana1 = Mana1 - 400;
                        if(!unCaballero->getResistencia(random))
                        {   int danio = 0;
                            if(random%2 == 0) danio = CalculoDanio(2*miCaballero->getDanio(),Arm2); //200%
                            else danio = CalculoDanio((15*miCaballero->getDanio()/10),Arm2);        //150%
                            Vida2 = Vida2 - danio;
                            gotoxy(27,contador); cout << "                            ";
                            gotoxy(27,contador+1); cout << "                            ";
                            gotoxy(27,contador); cout << miCaballero->getNombre() << "-->Furia(1)["
                            << danio << "]";
                        }else
                        {   gotoxy(27,contador); cout << "                            ";
                            gotoxy(27,contador+1); cout << "                            ";
                            gotoxy(27,contador); cout << "-->Furia(1) resistido";
                        }
                    }else
                    {   gotoxy(27,contador); cout << "                            ";
                        gotoxy(27,contador+1); cout << "                            ";
                        gotoxy(27,contador); cout << "Mana insuficiente";
                    }
                }else
                {   gotoxy(27,contador); cout << "                            ";
                    gotoxy(27,contador+1); cout << "                            ";
                    gotoxy(27,contador); cout << "No puede ser atacado";
                }
            }else
            {   gotoxy(27,contador); cout << "                            ";
                gotoxy(27,contador+1); cout << "                            ";
                gotoxy(27,contador); cout << "No puede atacar";
            }
            opcion = opcion - 38;
            tecla = 0;
            break;
        }
        case 54:    //opcion '6'
        {   if(vision1 > 10)
            {   if(Mana1 >= 250)
                {   Mana1 = Mana1 - 250;
                    Vida1 = Vida1 + 1000;
                    vision1 = 0;
                    gotoxy(27,contador); cout << "                             ";
                    gotoxy(27,contador+1); cout << "                            ";
                    gotoxy(27,contador); cout << miCaballero->getNombre() << "-->Vision(1)";
                }else
                {   gotoxy(27,contador); cout << "                            ";
                    gotoxy(27,contador+1); cout << "                            ";
                    gotoxy(27,contador); cout << "Mana insuficiente";
                }
            }else
            {   gotoxy(27,contador); cout << "                            ";
                gotoxy(27,contador+1); cout << "                            ";
                gotoxy(27,contador); cout << "Tecnica en Recarga";
            }
            opcion = opcion - 38;
            tecla = 0;
            break;
        }
        case 55:    //opcion '7'
        {   if(colera1 > 25)
            {   if(Mana1 >= 400)
                {   Mana1 = Mana1 - 400;
                    Arm1 = 900;
                    colera1 = 0;
                    gotoxy(27,contador); cout << "                            ";
                    gotoxy(27,contador+1); cout << "                            ";
                    gotoxy(27,contador); cout << miCaballero->getNombre() << "-->Colera(1)";
                }else
                {   gotoxy(27,contador); cout << "                            ";
                    gotoxy(27,contador+1); cout << "                            ";
                    gotoxy(27,contador); cout << "Mana insuficiente";
                }
            }else
            {   gotoxy(27,contador); cout << "                            ";
                gotoxy(27,contador+1); cout << "                            ";
                gotoxy(27,contador); cout << "Tecnica en Recarga";
            }
            opcion = opcion - 38;
            tecla = 0;
            break;
        }
    }
}

void Batalla::ObtenerItem(Caballero* miCaballero,Lista<Item*>* miInventario,int& CantidadItems)
{   int random = rand();
    if(random%2 == 0)   //chance
    {   random = rand();
        Item* unItem;
        if(random%3 == 0){
            unItem = new Item(7,miCaballero->getNivel());
        }else{
            random = rand();
            unItem = new Item(random%7,miCaballero->getNivel());
        }
        miInventario->agregar(unItem); CantidadItems++;
        gotoxy(3,21); cout << "                                     ";
        gotoxy(3,21); cout << miCaballero->getNombre() << " ha obtenido " << unItem->getNombre();
        gotoxy(3,22); system("pause");
    }
}

void Batalla::Enemigo10(Caballero* miCaballero,Caballero* unCaballero,int& enemigo,int& Vida1,int& Mana1,int& Arm1,int& Vida2,int& Mana2,int& Arm2,
                             int& opcion,int& tecla, int contador,int& inmune1,int& colera1,int& vision1,int inmune2)
{   Sleep(1000);
    int opcion1 = opcion + 38;
    if(Mana1 > 10+2*miCaballero->getNivel())
    {   if(enemigo == 0 || Vida2 < CalculoDanio(miCaballero->getDanio()+200,Arm2))
        {   if(enemigo == 0)
            {   opcion1 = 51;
                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
            }else
            {   if(Vida2 < CalculoDanio(miCaballero->getDanio()+200,Arm2) && Mana1 >= 250)
                {   opcion1 = 51;
                    this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                }else
                {   opcion1 = 49;
                    this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                }
            }
        }else
        {   opcion1 = 49;
            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
        }
    }else
    {   opcion1 = 50;
        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
    }
}

void Batalla::Enemigo20(Caballero* miCaballero,Caballero* unCaballero,int& enemigo,int& Vida1,int& Mana1,int& Arm1,int& Vida2,int& Mana2,int& Arm2,
                             int& opcion,int& tecla, int contador,int& inmune1,int& colera1,int& vision1,int inmune2)
{   Sleep(1000);
    int opcion1 = opcion + 38;
    if(inmune1 > 2 && inmune2 > 2)
    {   if(Mana1 > 10+2*miCaballero->getNivel())
        {   if(Vida1 < 500 && inmune1 > 6)
            {   if(Mana1 >= 250)
                {   opcion1 = 52;
                    this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                }else
                {   opcion1 = 50;
                    this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                }
            }else
            {   if(enemigo == 0 || Vida2 < CalculoDanio(miCaballero->getDanio()+200,Arm2))
                {   if(enemigo == 0)
                    {   opcion1 = 51;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }else
                    {   if(Vida2 < CalculoDanio(miCaballero->getDanio()+200,Arm2) && Mana1 > 250)
                        {   opcion1 = 51;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   opcion1 = 49;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                    }
                }else
                {   opcion1 = 49;
                    this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                }
            }
        }else
        {   opcion1 = 50;
            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
        }
    }else
    {   opcion1 = 50;
        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
    }
}

void Batalla::Enemigo30(Caballero* miCaballero,Caballero* unCaballero,int& enemigo,int& Vida1,int& Mana1,int& Arm1,int& Vida2,int& Mana2,int& Arm2,
                             int& opcion,int& tecla, int contador,int& inmune1,int& colera1,int& vision1,int inmune2)
{   Sleep(1000);
    int opcion1 = opcion + 38;
    if(inmune1 > 2 && inmune2 > 2)
    {   if(Mana1 > 10+2*miCaballero->getNivel())
        {   if(Vida1 < 500)
            {   if(inmune1 < 7)
                {   if(Vida2 < CalculoDanio(2*miCaballero->getDanio(),Arm2) && Mana1 > 400)
                    {   opcion1 = 53;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }else
                    {   if(Vida1 < Vida2 && Mana1 > 250)
                        {   opcion1 = 51;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   opcion1 = 49;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                    }
                }else
                {   if(Vida2 < CalculoDanio(15*miCaballero->getDanio()/10,Arm2))
                    {   if(Vida2 < CalculoDanio(15*miCaballero->getDanio()/10,Arm2) && Mana1 > 400)
                        {   opcion1 = 53;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   if(Vida2 < CalculoDanio(miCaballero->getDanio()+200,Arm2) && Mana1 > 250)
                            {   opcion1 = 51;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }else
                            {   if(Vida2 < CalculoDanio(miCaballero->getDanio(),Arm2))
                                {   opcion1 = 49;
                                    this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                                }else
                                {   if(inmune1 > 6 && Mana1 > 250)
                                    {   opcion1 = 52;
                                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                                    }else
                                    {   opcion1 = 50;
                                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                                    }
                                }
                            }
                        }
                    }else
                    {   if(inmune1 > 6 && Mana1 > 250)
                        {   opcion1 = 52;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   opcion1 = 50;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                    }
                }
            }else
            {   if(enemigo == 0 || Vida2 < CalculoDanio(2*miCaballero->getDanio(),Arm2))
                {   if(enemigo == 0)
                    {   opcion1 = 53;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }else
                    {   if(Vida2 < CalculoDanio(2*miCaballero->getDanio(),Arm2) && Mana1 > 400)
                        {   opcion1 = 53;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   opcion1 = 49;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                    }
                }else
                {   if(Vida1 < Vida2 && Mana1 > 250)
                    {   opcion1 = 51;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }else
                    {   opcion1 = 49;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }
                }
            }
        }else
        {   opcion1 = 50;
            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
        }
    }else
    {   opcion1 = 50;
        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
    }
}

void Batalla::Enemigo40(Caballero* miCaballero,Caballero* unCaballero,int& enemigo,int& Vida1,int& Mana1,int& Arm1,int& Vida2,int& Mana2,int& Arm2,
                             int& opcion,int& tecla, int contador,int& inmune1,int& colera1,int& vision1,int inmune2)
{   Sleep(1000);
    int opcion1 = opcion + 38;
    if(inmune1 > 2 && inmune2 > 2)
    {   if(Mana1 > 10+2*miCaballero->getNivel())
        {   if(Vida1 < 500)
            {   if(inmune1 < 7)
                {   if(Vida2 < CalculoDanio(2*miCaballero->getDanio(),Arm2) && Mana1 > 400)
                    {   opcion1 = 53;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }else
                    {   if(Vida1 < Vida2 && Mana1 > 250)
                        {   opcion1 = 51;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   opcion1 = 49;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                    }
                }else
                {   if(Vida2 < CalculoDanio(15*miCaballero->getDanio()/10,Arm2))
                    {   if(Vida2 < CalculoDanio(15*miCaballero->getDanio()/10,Arm2) && Mana1 > 400)
                        {   opcion1 = 53;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                        if(Vida2 < CalculoDanio(miCaballero->getDanio()+200,Arm2) && Mana1 > 250)
                        {   opcion1 = 51;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   if(Vida2 < CalculoDanio(miCaballero->getDanio(),Arm2))
                            {   opcion1 = 49;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }else
                            {   if(inmune1 > 6 && Mana1 >= 250)
                                {   opcion1 = 52;
                                    this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                                }else
                                {   opcion1 = 50;
                                    this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                                }
                            }
                        }
                    }else
                    {   if(inmune1 > 6 && Mana1 >= 250)
                        {   opcion1 = 52;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   opcion1 = 50;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                    }
                }
            }else
            {   if(enemigo == 0 || Vida2 < CalculoDanio(2*miCaballero->getDanio(),Arm2))
                {   if(enemigo == 0)
                    {   opcion1 = 53;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }else
                    {   if(Vida2 < CalculoDanio(2*miCaballero->getDanio(),Arm2) && Mana1 > 400)
                        {   opcion1 = 53;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   if(Vida2 < CalculoDanio(miCaballero->getDanio()+200,Arm2) && Mana1 > 250)
                            {   opcion1 = 51;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }else
                            {   opcion1 = 49;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }
                        }
                    }
                }else
                {   if(Vida1 < Vida2 && Mana1 > 250)
                    {   opcion1 = 51;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }else
                    {   opcion1 = 49;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }
                }
            }
        }else
        {   opcion1 = 50;
            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
        }
    }else
    {   if(vision1 > 10 && Mana1 > 250)
        {   opcion1 = 54;
            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
        }else
        {   opcion1 = 50;
            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
        }
    }
}

void Batalla::Enemigo50(Caballero* miCaballero,Caballero* unCaballero,int& enemigo,int& Vida1,int& Mana1,int& Arm1,int& Vida2,int& Mana2,int& Arm2,
                             int& opcion,int& tecla, int contador,int& inmune1,int& colera1,int& vision1,int inmune2)
{   Sleep(1000);
    int opcion1 = opcion + 38;
    if(inmune1 > 2 && inmune2 > 2)
    {   if(Mana1 > 10+2*miCaballero->getNivel())
        {   if(Vida1 < 500)
            {   if(inmune1 < 7)
                {   if(Vida2 < CalculoDanio(2*miCaballero->getDanio(),Arm2) && Mana1 > 400)
                    {   opcion1 = 53;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }else
                    {   if(Vida1 < Vida2 && Mana1 > 250)
                        {   opcion1 = 51;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   opcion1 = 49;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                    }
                }else
                {   if(Vida2 < CalculoDanio(15*miCaballero->getDanio()/10,Arm2))
                    {   if(Vida2 < CalculoDanio(15*miCaballero->getDanio()/10,Arm2) && Mana1 > 400)
                        {   opcion1 = 53;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                        if(Vida2 < CalculoDanio(miCaballero->getDanio()+200,Arm2) && Mana1 > 250)
                        {   opcion1 = 51;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   if(Vida2 < CalculoDanio(miCaballero->getDanio(),Arm2))
                            {   opcion1 = 49;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }else
                            {   if(inmune1 > 6 && Mana1 >= 250)
                                {   if(colera1 > 4)
                                    {   opcion1 = 52;
                                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                                    }else
                                    {   opcion1 = 49;
                                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                                    }
                                }else
                                {   opcion1 = 50;
                                    this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                                }
                            }
                        }
                    }else
                    {   if(inmune1 > 6 && Mana1 >= 250)
                        {   if(colera1 > 4)
                            {   opcion1 = 52;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }else
                            {   opcion1 = 49;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }
                        }else
                        {   opcion1 = 50;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                    }
                }
            }else
            {   if(enemigo == 0 || Vida2 < CalculoDanio(2*miCaballero->getDanio(),Arm2))
                {   if(enemigo == 0)
                    {   opcion1 = 53;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }else
                    {   if(Vida2 < CalculoDanio(2*miCaballero->getDanio(),Arm2) && Mana1 > 400)
                        {   opcion1 = 53;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   if(Vida2 < CalculoDanio(miCaballero->getDanio()+200,Arm2) && Mana1 > 250)
                            {   opcion1 = 51;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }else
                            {   opcion1 = 49;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }
                        }
                    }
                }else
                {   if(Vida1 < Vida2 && Mana1 > 250)
                    {   if(inmune1 > 6 && Vida1 < 500)
                        {   opcion1 = 52;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   opcion1 = 51;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                    }else
                    {   opcion1 = 49;
                        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                    }
                }
            }
        }else
        {   opcion1 = 50;
            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
        }
    }else
    {   if(Vida1 < 600 && inmune2 > 2)
        {   if(vision1 > 10 && Mana1 > 250)
            {   opcion1 = 54;
                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
            }else
            {   if(Mana1 < 400)
                {   opcion1 = 50;
                    this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                }else
                {   if(inmune1 > 2 && inmune2 > 2)
                    {   if(colera1 > 25 && Mana1 > 400)
                        {   opcion1 = 55;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   if(vision1 > 10 && Mana1 > 250)
                            {   opcion1 = 54;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }else
                            {   opcion1 = 50;
                                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                            }
                        }
                    }else
                    {   if(vision1 > 10 && Mana1 > 250)
                        {   opcion1 = 54;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }else
                        {   opcion1 = 50;
                            this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
                        }
                    }
                }
            }
        }else
        {   if(vision1 > 10 && Mana1 > 250)
            {   opcion1 = 54;
                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
            }else
            {   opcion1 = 50;
                this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion1,tecla,contador,inmune1,colera1,vision1,inmune2);
            }
        }
    }
}

void Batalla::SimularEnemigo(Caballero* miCaballero,Caballero* unCaballero,int& enemigo,int& Vida1,int& Mana1,int& Arm1,int& Vida2,int& Mana2,int& Arm2,
                             int& opcion,int& tecla, int contador,int& inmune1,int& colera1,int& vision1,int inmune2)
{   if(miCaballero->getNivel() < 20)
    {   this->Enemigo10(miCaballero,unCaballero,enemigo,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion,tecla,contador,inmune1,colera1,vision1,inmune2);
    }else
    {   if(miCaballero->getNivel() < 30)
        {   this->Enemigo20(miCaballero,unCaballero,enemigo,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion,tecla,contador,inmune1,colera1,vision1,inmune2);
        }else
        {   if(miCaballero->getNivel() < 40)
            {   this->Enemigo30(miCaballero,unCaballero,enemigo,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion,tecla,contador,inmune1,colera1,vision1,inmune2);
            }else
            {   if(miCaballero->getNivel() < 50)
                {   this->Enemigo40(miCaballero,unCaballero,enemigo,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion,tecla,contador,inmune1,colera1,vision1,inmune2);
                }else
                {   this->Enemigo50(miCaballero,unCaballero,enemigo,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion,tecla,contador,inmune1,colera1,vision1,inmune2);
                }
            }
        }
    }
}

void Batalla::ActualizarBatalla(int Vida1,int Mana1,int Vida2,int Mana2,int inmune1,int vision1,int colera1)
{   if(Vida1 < 0) Vida1 = 0;
    if(Vida2 < 0) Vida2 = 0;
    gotoxy(10,3); cout << "    ";
    gotoxy(10,3); cout << Vida1;
    gotoxy(10,4); cout << "    ";
    gotoxy(10,4); cout << Mana1;
    gotoxy(65,3); cout << "    ";
    gotoxy(65,3); cout << Vida2;
    gotoxy(65,4); cout << "    ";
    gotoxy(65,4); cout << Mana2;
    gotoxy(16,14); cout << "  ";
    gotoxy(16,16); cout << "  ";
    gotoxy(16,17); cout << "  ";
    if(inmune1 < 7)
    {   gotoxy(16,14); cout << 7-inmune1;
    }
    if(vision1 < 10)
    {   gotoxy(16,16); cout << 10-vision1;
    }
    if(colera1 < 25)
    {   gotoxy(16,17); cout << 25-colera1;
    }
}

Caballero* Batalla::Luchar(Caballero* miCaballero,Caballero* unCaballero)
{   this->MostrarCaballeros(miCaballero,unCaballero);
    srand(time(0));
    int Vida1 = miCaballero->getVida();
    int Mana1 = miCaballero->getMana();
    int Arm1 = miCaballero->getArmadura();
    int Vida2 = unCaballero->getVida();
    int Mana2 = unCaballero->getMana();
    int Arm2 = unCaballero->getArmadura();
    int inmune1 = 7, inmune2 = 7;
    int vision1 = 11, vision2 = 11;
    int colera1 = 31, colera2 = 31;
    int enemigo = 0;
    int contador = 1;
    int opcion = 11;
    int tecla = 0;
    while(tecla != 27)  //ESC
    {   gotoxy(1,opcion); printf("%c",16);
        while(tecla != 27 && tecla != 13)   //ESC || ENTER
        {   this->MostrarTecnica(miCaballero,opcion);
            gotoxy(0,24);
            tecla = getch();
            switch(tecla)
            {   case 72:    //subir
                    if(opcion-1 >= 11 && opcion <= 10+miCaballero->getTecnicas())
                    {   gotoxy(1,opcion); printf("%c",32);
                        opcion = opcion-1;
                        gotoxy(1,opcion); printf("%c",16);
                    }
                    break;
                case 80:    //bajar
                    if(opcion >= 11 && opcion+1 <= 10+miCaballero->getTecnicas())
                    {   gotoxy(1,opcion); printf("%c",32);
                        opcion = opcion+1;
                        gotoxy(1,opcion); printf("%c",16);
                    }
                    break;
                case 13:    //ENTER
                    opcion = opcion + 38;
                    break;
            }
        }
        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion,tecla,contador,inmune1,colera1,vision1,inmune2);
        this->ActualizarBatalla(Vida1,Mana1,Vida2,Mana2,inmune1,vision1,colera1);

        inmune2++; colera2++; vision2++;
        if(colera2 > 4) Arm2 = unCaballero->getArmadura();

        if(Vida1 <= 0 || Vida2 <= 0)
        {   if(Vida2 <= 0)
            {   Ganador = miCaballero;
                miCaballero->setExperiencia( miCaballero->getExperiencia()+200 );
                miCaballero->setBGanadas( miCaballero->getBGanadas()+1 );
                miCaballero->subirNivel();
                gotoxy(3,20); cout << "El ganador es: " << miCaballero->getNombre();
                gotoxy(3,21); cout << "Ha ganado: +" << 200 << " Exp.";
                gotoxy(3,22); system("pause");
            }else if(Vida1 <= 0)
            {   unCaballero->setExperiencia( unCaballero->getExperiencia()+200 );
                unCaballero->setBGanadas( unCaballero->getBGanadas()+1 );
                unCaballero->subirNivel();
                gotoxy(3,20); cout << "El ganador es: " << unCaballero->getNombre();
                gotoxy(3,21); cout << "Ha ganado: +" << 200 << " Exp.";
                gotoxy(3,22); system("pause");
            }
            miCaballero->setBJugadas( miCaballero->getBJugadas()+1 );
            unCaballero->setBJugadas( unCaballero->getBJugadas()+1 );
            tecla = 27;
        }else
        {   contador++;
            this->SimularEnemigo(unCaballero,miCaballero,enemigo,Vida2,Mana2,Arm2,Vida1,Mana1,Arm1,opcion,tecla,contador,inmune2,colera2,vision2,inmune1);
            this->ActualizarBatalla(Vida1,Mana1,Vida2,Mana2,inmune1,vision1,colera1);
            gotoxy(0,24);

            if(Vida1 <= 0 || Vida2 <= 0)
            {   if(Vida2 <= 0)
                {   Ganador = miCaballero;
                    miCaballero->setExperiencia( miCaballero->getExperiencia()+250 );
                    miCaballero->setBGanadas( miCaballero->getBGanadas()+1 );
                    miCaballero->subirNivel();
                    gotoxy(3,20); cout << "El ganador es: " << miCaballero->getNombre();
                    gotoxy(3,21); cout << "Ha ganado: +" << 200 << " Exp.";
                    gotoxy(3,22); system("pause");
                }else if(Vida1 <= 0)
                {   unCaballero->setExperiencia( unCaballero->getExperiencia()+250 );
                    unCaballero->setBGanadas( unCaballero->getBGanadas()+1 );
                    unCaballero->subirNivel();
                    gotoxy(3,20); cout << "El ganador es: " << unCaballero->getNombre();
                    gotoxy(3,21); cout << "Ha ganado: +" << 200 << " Exp.";
                    gotoxy(3,22); system("pause");
                }
                miCaballero->setBJugadas( miCaballero->getBJugadas()+1 );
                unCaballero->setBJugadas( unCaballero->getBJugadas()+1 );
                tecla = 27;
            }
        }

        inmune1++; colera1++; vision1++;
        enemigo++;
        if(colera1 > 4) Arm1 = miCaballero->getArmadura();
        if(contador < 18) contador++;
        else contador = 1;
    }
    return Ganador;
}

bool Batalla::Entrenar(Caballero* miCaballero,Caballero* unCaballero,Lista<Item*>* miInventario,int& CantidadItems)
{   this->MostrarCaballeros(miCaballero,unCaballero);
    srand(time(0));
    int Vida1 = miCaballero->getVida();
    int Mana1 = miCaballero->getMana();
    int Arm1 = miCaballero->getArmadura();
    int Vida2 = unCaballero->getVida();
    int Mana2 = unCaballero->getMana();
    int  Arm2 = unCaballero->getArmadura();
    int inmune1 = 7, inmune2 = 7;
    int vision1 = 11;
    int colera1 = 31;
    int contador = 1;
    int opcion = 11;
    int tecla = 0;
    while(tecla != 27)  //ESC
    {   gotoxy(1,opcion); printf("%c",16);
        while(tecla != 27 && tecla != 13)   //ESC || ENTER
        {   this->MostrarTecnica(miCaballero,opcion);
            gotoxy(0,24);
            tecla = getch();
            switch(tecla)
            {   case 72:    //subir
                    if(opcion-1 >= 11 && opcion <= 10+miCaballero->getTecnicas())
                    {   gotoxy(1,opcion); printf("%c",32);
                        opcion = opcion-1;
                        gotoxy(1,opcion); printf("%c",16);
                    }
                    break;
                case 80:    //bajar
                    if(opcion >= 11 && opcion+1 <= 10+miCaballero->getTecnicas())
                    {   gotoxy(1,opcion); printf("%c",32);
                        opcion = opcion+1;
                        gotoxy(1,opcion); printf("%c",16);
                    }
                    break;
                case 13:    //ENTER
                    opcion = opcion + 38;
                    break;
            }
        }
        this->InvocarTecnica(miCaballero,unCaballero,Vida1,Mana1,Arm1,Vida2,Mana2,Arm2,opcion,tecla,contador,inmune1,colera1,vision1,inmune2);
        this->ActualizarBatalla(Vida1,Mana1,Vida2,Mana2,inmune1,vision1,colera1);
        gotoxy(0,24);

        contador++;
        int random = rand();

        if(inmune1 > 2)
        {   Sleep(1000);
            if(!miCaballero->getResistencia(random))
            {   Mana2 = Mana2 - (10+2*unCaballero->getNivel());
                Vida1 = Vida1 - CalculoDanio(unCaballero->getDanio(),Arm1);
                gotoxy(10,3); cout << "    ";
                gotoxy(10,3); cout << Vida1;
                gotoxy(27,contador); cout << "                         ";
                gotoxy(27,contador+1); cout << "                         ";
                gotoxy(27,contador); cout << unCaballero->getNombre() << "-->Ataque(1)["
                << CalculoDanio(unCaballero->getDanio(),Arm1) << "]";
            }else
            {   gotoxy(27,contador); cout << "                         ";
                gotoxy(27,contador+1); cout << "                         ";
                gotoxy(27,contador); cout << "-->Ataque(1) resistido";
            }
        }else
        {   Sleep(1000);
            gotoxy(27,contador); cout << "                         ";
            gotoxy(27,contador+1); cout << "                         ";
            gotoxy(27,contador); cout << "No puede ser atacado";
        }

        this->ActualizarBatalla(Vida1,Mana1,Vida2,Mana2,inmune1,vision1,colera1);

        if(Vida1 <= 0 || Vida2 <= 0)
        {   if(Vida2 <= 0)
            {   Ganador = miCaballero;
                miCaballero->setExperiencia( miCaballero->getExperiencia()+100 );
                miCaballero->setOro( miCaballero->getOro()+250 );
                miCaballero->subirNivel();
                gotoxy(3,21); cout << "Ha ganado: +" << 100 << " Exp. y +" << 250 << " Oro.";
                gotoxy(3,22); system("pause");
                this->ObtenerItem(miCaballero,miInventario,CantidadItems);
            }else if(Vida1 <= 0)
            {   unCaballero->setExperiencia( unCaballero->getExperiencia()+50 );
                unCaballero->setOro( unCaballero->getOro()+100 );
                unCaballero->subirNivel();
                gotoxy(3,21); cout << miCaballero->getNombre() << " ha perdido.";
                gotoxy(3,22); system("pause");
            }
            tecla = 27;
        }
        inmune1++; colera1++; vision1++;
        if(colera1 > 4) Arm1 = miCaballero->getArmadura();
        if(contador < 18) contador++;
        else contador = 1;
    }
    return Ganador;
}

Caballero* Batalla::Simular(Caballero* miCaballero,Caballero* unCaballero)
{   Caballero* Ganador;
    srand(time(0));
    int random = rand();
    switch(random%2)
    {   case 0: miCaballero->setExperiencia( miCaballero->getExperiencia()+50 );
                miCaballero->setBGanadas( miCaballero->getBGanadas()+1 );
                miCaballero->subirNivel();
                Ganador = miCaballero;
                break;
        case 1: unCaballero->setExperiencia( unCaballero->getExperiencia()+50 );
                unCaballero->setBGanadas( unCaballero->getBGanadas()+1 );
                unCaballero->subirNivel();
                Ganador = unCaballero;
                break;
    }
    miCaballero->setBJugadas( miCaballero->getBJugadas()+1 );
    unCaballero->setBJugadas( unCaballero->getBJugadas()+1 );
    return Ganador;
}
