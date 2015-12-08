#ifndef TORNEO_H
#define TORNEO_H
#include "Batalla.h"

class Torneo
{
    public:
        Torneo(int,int,Lista<Caballero*>*);
        ~Torneo();
        int getComision();
        int getNivel();
        void Inscribir(Caballero*,Lista<Item*>*,int&);
        void Empezar(Caballero*,Lista<Item*>*,int&);
        void Empezar(Caballero*);
        void VerEstadisticas(Caballero*,int,int,int,int,int,int,int,int,int);

    private:
        long int Comision;
        int Nivel;
        int CantParticipantes;
        Caballero** Participantes;
};

#endif // TORNEO_H
