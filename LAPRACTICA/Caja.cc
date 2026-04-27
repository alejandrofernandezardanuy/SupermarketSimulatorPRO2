#include "Caja.hh"

Caja::Caja()
{
}



void Caja::escribir_caja() const
{   
    list<pair<int,Hora>>::const_iterator it = cola_clientes.begin();
    while (it != cola_clientes.end())
    {
        cout << (*it).first << " ";
        (*it).second.escribir_hora();
        cout << " ";
        ++it;
    }
    cout << endl;

}

void Caja::vaciar_caja(const Hora &h)
{
    list<pair<int,Hora>>::iterator it = cola_clientes.begin();
    while (it != cola_clientes.end() and (*it).second.menor(h)){
        it = cola_clientes.erase(it);
    }
}

Hora Caja::hora_salida_ultimo_cola() {
    list<pair<int,Hora>>::iterator it = cola_clientes.end();
    --it;
    return (*it).second;
}

void Caja::anadir_cliente(int idcl, Hora hora_salida_cliente) 
{
    pair<int,Hora>x;
    x.first = idcl;
    x.second = hora_salida_cliente;
    cola_clientes.insert(cola_clientes.end(),x);


}


bool Caja::esta_vacia() const
{
    return cola_clientes.empty();
}

int Caja::mida_cola() const
{
    return cola_clientes.size();
}
