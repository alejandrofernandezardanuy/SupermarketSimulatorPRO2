#ifndef __CONJ_BICIS__
#define __CONJ_BICIS__

#include <iostream>
#include<map>
class ConjBicis {
    private:
    //atributos(caracteristicas)
    map<string,int> bicis;
    public:
    //Metodos(funciones)
    ConjBicis();

    int num_bicis() const;
    int kms_bici(string idb) const;
    bool consultar_disponibilidad(string idb) const;

    void camiar_disponibilidad(string idb, bool d); 
    void nuevo_viaje(string idb, int kms);

    void leer_bicis();
    void escribir_bicis() const;
    void escribir_bici(string idb) const;
};
#endif