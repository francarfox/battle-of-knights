#ifndef BATALLA_H
#define BATALLA_H
#include "Opcion.h"
#include <ctime> //Para funcion srand.

class Batalla
{   public:
        Batalla(Caballero*,Caballero*);
        ~Batalla();
        int CalculoDanio(int,int);
        void MostrarCaballeros(Caballero*,Caballero*);
        void MostrarTecnica(Caballero*,int);
        void InvocarTecnica(Caballero*,Caballero*,int&,int&,int&,int&,int&,int&,int&,int&,int,int&,int&,int&,int);
        void ObtenerItem(Caballero*,Lista<Item*>*,int&);
        void Enemigo10(Caballero*,Caballero*,int&,int&,int&,int&,int&,int&,int&,int&,int&, int,int&,int&,int&,int);
        void Enemigo20(Caballero*,Caballero*,int&,int&,int&,int&,int&,int&,int&,int&,int&, int,int&,int&,int&,int);
        void Enemigo30(Caballero*,Caballero*,int&,int&,int&,int&,int&,int&,int&,int&,int&, int,int&,int&,int&,int);
        void Enemigo40(Caballero*,Caballero*,int&,int&,int&,int&,int&,int&,int&,int&,int&, int,int&,int&,int&,int);
        void Enemigo50(Caballero*,Caballero*,int&,int&,int&,int&,int&,int&,int&,int&,int&, int,int&,int&,int&,int);
        void SimularEnemigo(Caballero*,Caballero*,int&,int&,int&,int&,int&,int&,int&,int&,int&,int,int&,int&,int&,int);
        void ActualizarBatalla(int,int,int,int,int,int,int);
        Caballero* Luchar(Caballero*,Caballero*);
        bool Entrenar(Caballero*,Caballero*,Lista<Item*>*,int&);
        Caballero* Simular(Caballero*,Caballero*);

    private:
        Caballero* Ganador;
};


#endif // BATALLA_H
