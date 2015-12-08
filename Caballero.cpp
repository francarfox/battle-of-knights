#include "Caballero.h"

Caballero::Caballero()
{   this->Nombre = "";
    this->Nivel = 1;
    this->BGanadas = 0;
    this->BJugadas = 0;
    this->Experiencia = 0;
    this->Oro = 0;
    this->Equipo = new Item[Max_Items];
}

Caballero::Caballero(string nombre)
{   this->Nombre = nombre;
    this->Nivel = 1;
    this->BGanadas = 0;
    this->BJugadas = 0;
    this->Experiencia = 0;
    this->Oro = 0;
    this->Equipo = new Item[Max_Items];
}

Caballero::Caballero(string nombre,int nivel)
{   this->Nombre = nombre;
    this->Nivel = nivel;
    this->BGanadas = 0;
    this->BJugadas = 0;
    this->Experiencia = this->expNecesaria() - 80*nivel;
    this->Oro = 0;
    this->Equipo = new Item[Max_Items];
    this->Equipo[Max_Items-1].setArmadura(20+10*this->getNivel());
}

Caballero::Caballero(string nombre,int nivel,int ganadas,int jugadas)
{   this->Nombre = nombre;
    this->Nivel = nivel;
    this->BGanadas = ganadas;
    this->BJugadas = jugadas;
    this->Experiencia = this->expNecesaria() - 80*nivel;
    this->Oro = 100000*nivel;
    this->Equipo = new Item[Max_Items];
    for(int i=0; i<Max_Items; i++)
    {   if(i != 7)
            this->Equipo[i].setArmadura(2*this->getNivel());
        else
            this->Equipo[i].setArmadura(50+20*this->getNivel());
    }
}

Caballero::Caballero(int nivel,int ganadas,int jugadas,long int exp,long int oro)
{   this->Nombre = "";
    this->Nivel = nivel;
    this->BGanadas = ganadas;
    this->BJugadas = jugadas;
    this->Experiencia = exp;
    this->Oro = oro;
    this->Equipo = new Item[Max_Items];
    for(int i=0; i<Max_Items; i++)
    {   if(i != 7)
            this->Equipo[i].setArmadura(2*this->getNivel());
        else
            this->Equipo[i].setArmadura(50+20*this->getNivel());
    }
}

Caballero::~Caballero()
{
}

string Caballero::getNombre()
{   return this->Nombre;
}

void Caballero::setNombre(string nombre)
{   this->Nombre = nombre;
}

int Caballero::getNivel()
{   return this->Nivel;
}

void Caballero::setNivel(int nivel)
{   this->Nivel = nivel;
}

int Caballero::getVida()
{   int vida = 500 + 50*this->getNivel();
    return vida;
}
int Caballero::getMana()
{   int mana = 200 + 30*this->getNivel();
    return mana;
}

int Caballero::getBGanadas()
{   return this->BGanadas;
}

void Caballero::setBGanadas(int ganadas)
{   this->BGanadas = ganadas;
}

int Caballero::getBJugadas()
{   return this->BJugadas;
}

void Caballero::setBJugadas(int jugadas)
{   this->BJugadas = jugadas;
}

double Caballero::getReputacion()
{   double reputacion = 0;
    if(this->BJugadas != 0)
        reputacion = 100*this->BGanadas/this->BJugadas;
    return reputacion;
}

long int Caballero::getExperiencia()
{   return this->Experiencia;
}

void Caballero::setExperiencia(long int experiencia)
{   this->Experiencia = experiencia;
}

long int Caballero::expNecesaria()
{   long int expNecesaria = 0;
    for( int i=1; i <= this->getNivel(); i++ )
        expNecesaria = expNecesaria + 100*i;
    return expNecesaria;
}

double Caballero::porcentajeExp()
{   double porcExp;
    porcExp = 100*(this->getExperiencia()-(expNecesaria()-100*this->getNivel()))
    / (expNecesaria()-(expNecesaria()-100*this->getNivel()));
    return porcExp;
}

long int Caballero::getOro()
{   return this->Oro;
}

void Caballero::setOro(long int oro)
{   this->Oro = oro;
}

Item* Caballero::getEquipo(int i)
{   return &this->Equipo[i];
}

void Caballero::setEquipo(Item* unItem)
{   this->Equipo[unItem->getCategoria()] = *unItem;
}

int Caballero::getArmadura()
{   int armadura = 0;
    for(int i=0; i<Max_Items-2; i++)
        armadura = armadura + this->Equipo[i].getArmadura();
    return armadura;
}

bool Caballero::getResistencia(int random)
{   bool resiste = false;
    int proba = 0;
    if(this->getEquipo(Max_Items-2)->getArmadura() != 0)
        proba = 500/this->getEquipo(Max_Items-2)->getArmadura();
    else
        proba = Infinito;
    if(random%proba == 0)
        resiste = true;
    return resiste;
}

int Caballero::getDanio()
{   int danio = 10+2*this->getNivel()+this->getEquipo(Max_Items-1)->getArmadura();
    return danio;
}

void Caballero::subirNivel()
{   if(this->getExperiencia() >= this->expNecesaria())
    {   if(this->Nivel < Max_Nivel)
            this->Nivel++;
    }
}

int Caballero::getTecnicas()
{   int tecnicas = 0;
    if(this->getNivel() < 10)
        tecnicas = 2;
    else
        if(this->getNivel() < 20)
            tecnicas = 3;
        else
            if(this->getNivel() < 30)
                tecnicas = 4;
            else
                if(this->getNivel() < 40)
                    tecnicas = 5;
                else
                    if(this->getNivel() < 50)
                        tecnicas = 6;
                    else
                        tecnicas = 7;
    return tecnicas;
}
