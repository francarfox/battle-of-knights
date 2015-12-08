#ifndef ITEM_H
#define ITEM_H
#define Max_Items 8
#include <iostream>
using namespace std;


class Item
{
    public:
        Item();
        Item(int,int);
        ~Item();
        string getNombre();
        void setNombre(string);
        int getCategoria();
        void setCategoria(int);
        int getNivel();
        void setNivel(int);
        int getArmadura();
        void setArmadura(int);

    private:
        string Nombre;
        int Categoria;
        int Nivel;
        int Armadura;
};

#endif // ITEM_H
