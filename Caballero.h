#ifndef CABALLERO_H
#define CABALLERO_H
#include "Item.h"
#define Max_Nivel 50
#define Infinito 1000000

class Caballero
{
    public:
        Caballero();
        Caballero(string);
        Caballero(string,int);
        Caballero(string,int,int,int);
        Caballero(int,int,int,long int,long int);
        ~Caballero();
        string getNombre();
        void setNombre(string);
        int getNivel();
        void setNivel(int);
        int getVida();
        int getMana();
        int getBGanadas();
        void setBGanadas(int);
        int getBJugadas();
        void setBJugadas(int);
        double getReputacion();
        long int getExperiencia();
        void setExperiencia(long int);
        long int expNecesaria();
        double porcentajeExp();
        long int getOro();
        void setOro(long int);
        Item* getEquipo(int);
        void setEquipo(Item*);
        int getArmadura();
        bool getResistencia(int);
        int getDanio();
        void subirNivel();
        int getTecnicas();

    private:
        string Nombre;
        int Nivel;
        int BGanadas;
        int BJugadas;
        long int Experiencia;
        long int Oro;
        Item* Equipo;
};

#endif // CABALLERO_H
