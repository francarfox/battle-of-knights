#include "Partida.h"

void CargarPartida(Caballero* miCaballero,Lista<Caballero*>* Caballeros,int& contadorC,
                   Lista<Item*>* inventario,int& contadorI)
{   Partida partida;
    ArchivoRegistros archivo;
    crear(archivo,"BOK.dat",60);

    try
    {
        leer(archivo,&partida);
    }
    catch(string i)
    {
        system("cls");
        cout << "No se ha encontrado el archivo: BOK.dat\n";
        system("pause");
    }

    contadorC = partida.ContadorC;
    contadorI = partida.ContadorI;
    miCaballero->setNivel(partida.Nivel);
    miCaballero->setBGanadas(partida.Ganadas);
    miCaballero->setBJugadas(partida.Jugadas);
    miCaballero->setExperiencia(partida.Exp);
    miCaballero->setOro(partida.Oro);

    IteradorLista<Caballero*> it = Caballeros->iterador();
    for(int i=0; i<contadorC; i++)
    {   leer(archivo,&partida);
        Caballero* unCaba = it.siguiente();
        //Caballero* caba = new Caballero(partida.Nivel,partida.Ganadas,partida.Jugadas,partida.Exp,partida.Oro);
        //Caballeros->agregar(caba);
        unCaba->setNivel(partida.Nivel);
        unCaba->setBGanadas(partida.Ganadas);
        unCaba->setBJugadas(partida.Jugadas);
        unCaba->setExperiencia(partida.Exp);
        unCaba->setOro(partida.Oro);
    }

    for(int i=0; i<Max_Items; i++)
    {   leer(archivo,&partida);
        Item* unItem = new Item(partida.CategoriaE,partida.NivelE);
        miCaballero->getEquipo(i)->setNombre(unItem->getNombre());
        miCaballero->getEquipo(i)->setCategoria(unItem->getCategoria());
        miCaballero->getEquipo(i)->setNivel(unItem->getNivel());
        miCaballero->getEquipo(i)->setArmadura(unItem->getArmadura());
    }

    for(int i=0; i<contadorI; i++)
    {   leer(archivo,&partida);
        Item* unItem = new Item(partida.CategoriaI,partida.NivelI);
        inventario->agregar(unItem);
    }

    PartidaN partidaN;
    string linea = "";
    while(!fin(archivo))
    {   leer(archivo,&partidaN);
        linea = linea + partidaN.Nombre;
        cout << partidaN.Nombre << endl;
    }
    miCaballero->setNombre(linea);
    destruir(archivo);
}

void GuardarPartida(Caballero* miCaballero,Lista<Caballero*>* Caballeros,int contadorC,
                    Lista<Item*>* miInventario,int contadorI)
{   Partida partida;
    ArchivoRegistros archivo;
    system("del BOK.dat");
    crear(archivo,"BOK.dat",60);
    partida.ContadorC = contadorC;
    partida.ContadorI = contadorI;
    partida.Nivel = miCaballero->getNivel();
    partida.Ganadas = miCaballero->getBGanadas();
    partida.Jugadas = miCaballero->getBJugadas();
    partida.Exp = miCaballero->getExperiencia();
    partida.Oro = miCaballero->getOro();
    escribir(archivo,&partida);

    IteradorLista<Caballero*> it = Caballeros->iterador();
    for(int i=0; i<contadorC; i++)
    {   Caballero* unCaba = it.siguiente();
        partida.Nivel = unCaba->getNivel();
        partida.Ganadas = unCaba->getBGanadas();
        partida.Jugadas = unCaba->getBJugadas();
        partida.Exp = unCaba->getExperiencia();
        partida.Oro = unCaba->getOro();
        escribir(archivo,&partida);
    }

    for(int i=0; i<Max_Items; i++)
    {   partida.CategoriaE = miCaballero->getEquipo(i)->getCategoria();
        partida.NivelE = miCaballero->getEquipo(i)->getNivel();
        escribir(archivo,&partida);
    }

    IteradorLista<Item*> it2 = miInventario->iterador();
    for(int i=0; i<contadorI; i++)
    {   Item* unItem = it2.siguiente();
        partida.CategoriaI = unItem->getCategoria();
        partida.NivelI = unItem->getNivel();
        escribir(archivo,&partida);
    }
    PartidaN partidaN;
    string linea = miCaballero->getNombre();
    for(unsigned int i=0; i<linea.length(); i++)
    {   partidaN.Nombre = linea[i];
        escribir(archivo,&partidaN);
    }
    destruir(archivo);
}

void CargarCaballeros(Lista<Caballero*>* lista,int& CantidadCabas)
{   Caballero* caba1 = new Caballero("Julius",50,3000,3100); lista->agregar(caba1); CantidadCabas++;
    Caballero* caba2 = new Caballero("Tigro",50,2600,2850); lista->agregar(caba2); CantidadCabas++;
    Caballero* caba3 = new Caballero("Ogre",50,2500,2800); lista->agregar(caba3); CantidadCabas++;
    Caballero* caba4 = new Caballero("Eddark",49,2450,2700); lista->agregar(caba4); CantidadCabas++;
    Caballero* caba5 = new Caballero("Mitolog",49,2400,2600); lista->agregar(caba5); CantidadCabas++;
    Caballero* caba6 = new Caballero("Maximu",48,2320,2500); lista->agregar(caba6); CantidadCabas++;
    Caballero* caba7 = new Caballero("Infernal",47,2260,2500); lista->agregar(caba7); CantidadCabas++;
    Caballero* caba8 = new Caballero("Blast",46,2200,2450); lista->agregar(caba8); CantidadCabas++;
    Caballero* caba9 = new Caballero("Thunder",45,2100,2400); lista->agregar(caba9); CantidadCabas++;
    Caballero* caba10 = new Caballero("Cesar",44,2000,2300); lista->agregar(caba10); CantidadCabas++;
    Caballero* caba11 = new Caballero("Phanto",43,1900,2200); lista->agregar(caba11); CantidadCabas++;
    Caballero* caba12 = new Caballero("Saint",42,1850,2100); lista->agregar(caba12); CantidadCabas++;
    Caballero* caba13 = new Caballero("Elver",41,1800,2100); lista->agregar(caba13); CantidadCabas++;
    Caballero* caba14 = new Caballero("Coraza",41,1750,2000); lista->agregar(caba14); CantidadCabas++;
    Caballero* caba15 = new Caballero("David",40,1700,1900); lista->agregar(caba15); CantidadCabas++;
    Caballero* caba16 = new Caballero("Kill",40,1670,1900); lista->agregar(caba16); CantidadCabas++;
    Caballero* caba17 = new Caballero("Dash",40,1640,1900); lista->agregar(caba17); CantidadCabas++;
    Caballero* caba18 = new Caballero("Thronn",39,1550,1800); lista->agregar(caba18); CantidadCabas++;
    Caballero* caba19 = new Caballero("Dragon",38,1430,1750); lista->agregar(caba19); CantidadCabas++;
    Caballero* caba20 = new Caballero("Black",37,1380,1700); lista->agregar(caba20); CantidadCabas++;
    Caballero* caba21 = new Caballero("Campos",36,1300,1650); lista->agregar(caba21); CantidadCabas++;
    Caballero* caba22 = new Caballero("Linus",35,1260,1500); lista->agregar(caba22); CantidadCabas++;
    Caballero* caba23 = new Caballero("Stream",34,1200,1400); lista->agregar(caba23); CantidadCabas++;
    Caballero* caba24 = new Caballero("Divex",33,1170,1320); lista->agregar(caba24); CantidadCabas++;
    Caballero* caba25 = new Caballero("Exort",32,1130,1300); lista->agregar(caba25); CantidadCabas++;
    Caballero* caba26 = new Caballero("Berlin",31,1100,1300); lista->agregar(caba26); CantidadCabas++;
    Caballero* caba27 = new Caballero("Freez",31,1050,1300); lista->agregar(caba27); CantidadCabas++;
    Caballero* caba28 = new Caballero("Mamuth",30,1000,1200); lista->agregar(caba28); CantidadCabas++;
    Caballero* caba29 = new Caballero("Homer",30,960,1200); lista->agregar(caba29); CantidadCabas++;
    Caballero* caba30 = new Caballero("Hachem",30,930,1200); lista->agregar(caba30); CantidadCabas++;
    Caballero* caba31 = new Caballero("Cobrax",29,900,1150); lista->agregar(caba31); CantidadCabas++;
    Caballero* caba32 = new Caballero("Hunter",28,850,1000); lista->agregar(caba32); CantidadCabas++;
    Caballero* caba33 = new Caballero("Bosch",27,800,950); lista->agregar(caba33); CantidadCabas++;
    Caballero* caba34 = new Caballero("Peter",26,760,900); lista->agregar(caba34); CantidadCabas++;
    Caballero* caba35 = new Caballero("Ghost",25,650,850); lista->agregar(caba35); CantidadCabas++;
    Caballero* caba36 = new Caballero("Wallk",24,600,820); lista->agregar(caba36); CantidadCabas++;
    Caballero* caba37 = new Caballero("Corvinus",23,580,780); lista->agregar(caba37); CantidadCabas++;
    Caballero* caba38 = new Caballero("Madwaq",22,550,750); lista->agregar(caba38); CantidadCabas++;
    Caballero* caba39 = new Caballero("Verbot",21,500,700); lista->agregar(caba39); CantidadCabas++;
    Caballero* caba40 = new Caballero("Mesias",21,480,650); lista->agregar(caba40); CantidadCabas++;
    Caballero* caba41 = new Caballero("Arturo",20,450,650); lista->agregar(caba41); CantidadCabas++;
    Caballero* caba42 = new Caballero("Liberty",20,435,650); lista->agregar(caba42); CantidadCabas++;
    Caballero* caba43 = new Caballero("Espart",20,420,620); lista->agregar(caba43); CantidadCabas++;
    Caballero* caba44 = new Caballero("Claude",19,400,600); lista->agregar(caba44); CantidadCabas++;
    Caballero* caba45 = new Caballero("Alado",18,370,570); lista->agregar(caba45); CantidadCabas++;
    Caballero* caba46 = new Caballero("Cirius",17,330,530); lista->agregar(caba46); CantidadCabas++;
    Caballero* caba47 = new Caballero("Golden",16,290,490); lista->agregar(caba47); CantidadCabas++;
    Caballero* caba48 = new Caballero("Simbol",15,250,450); lista->agregar(caba48); CantidadCabas++;
    Caballero* caba49 = new Caballero("Santy",15,240,440); lista->agregar(caba49); CantidadCabas++;
    Caballero* caba50 = new Caballero("Marcus",14,230,400); lista->agregar(caba50); CantidadCabas++;
    Caballero* caba51 = new Caballero("Frezz",14,210,350); lista->agregar(caba51); CantidadCabas++;
    Caballero* caba52 = new Caballero("Carson",13,200,300); lista->agregar(caba52); CantidadCabas++;
    Caballero* caba53 = new Caballero("Demon",13,180,270); lista->agregar(caba53); CantidadCabas++;
    Caballero* caba54 = new Caballero("Preson",12,170,260); lista->agregar(caba54); CantidadCabas++;
    Caballero* caba55 = new Caballero("Hector",12,160,250); lista->agregar(caba55); CantidadCabas++;
    Caballero* caba56 = new Caballero("Grifo",11,150,240); lista->agregar(caba56); CantidadCabas++;
    Caballero* caba57 = new Caballero("Blindd",11,140,200); lista->agregar(caba57); CantidadCabas++;
    Caballero* caba58 = new Caballero("Lester",10,130,200); lista->agregar(caba58); CantidadCabas++;
    Caballero* caba59 = new Caballero("Promez",10,120,200); lista->agregar(caba59); CantidadCabas++;
    Caballero* caba60 = new Caballero("Jordan",10,110,200); lista->agregar(caba60); CantidadCabas++;
}
