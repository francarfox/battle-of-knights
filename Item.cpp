#include "Item.h"

Item::Item()
{   this->Nombre = "...";
    this->Categoria = Max_Items;
    this->Nivel = 0;
    this->Armadura = 0;
}

Item::Item(int categoria,int nivel)
{   this->Categoria = categoria;
    switch(this->Categoria)
    {   case 0: this->setNombre("Casco"); break;
        case 1: this->setNombre("Hombreras"); break;
        case 2: this->setNombre("Guantes"); break;
        case 3: this->setNombre("Pechera"); break;
        case 4: this->setNombre("Cinturon"); break;
        case 5: this->setNombre("Botas"); break;
        case 6: this->setNombre("Escudo"); break;
        case 7: this->setNombre("Espada"); break;
        case Max_Items: this->setNombre("..."); break;
    }
    this->Nivel = nivel;
    if(this->Categoria < 7)
        this->Armadura = 2*nivel;
    else
        if(this->Categoria == 7)
            this->Armadura = 50+20*nivel;
        else
            this->Armadura = 0;
}

Item::~Item()
{
}

string Item::getNombre()
{   return this->Nombre;
}

void Item::setNombre(string nombre)
{   this->Nombre = nombre;
}

int Item::getCategoria()
{   return this->Categoria;
}

void Item::setCategoria(int categoria)
{   this->Categoria = categoria;
}

int Item::getNivel()
{   return this->Nivel;
}

void Item::setNivel(int nivel)
{   this->Nivel = nivel;
}

int Item::getArmadura()
{   return this->Armadura;
}

void Item::setArmadura(int armadura)
{   this->Armadura = armadura;
}
