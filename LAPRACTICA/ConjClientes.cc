#include "ConjClientes.hh"

ConjClientes::ConjClientes()
{
}

int ConjClientes::compra_y_no_quiere(int id)
{
    int x = clientes[id-1].compra_y_no_quiere();
    return x;

}

void ConjClientes::compran_y_no_quieren() const
{
    set<int>::const_iterator it = clientes_noquiereycompra.begin();
    while (it != clientes_noquiereycompra.end())
    {
        if (it != clientes_noquiereycompra.begin()) cout << " ";
        cout << *it;
        ++it;
    }
    cout << endl;
}

void ConjClientes::quiere_comprar(int id) const
{
    clientes[id-1].quiere_comprar();
}

void ConjClientes::salas_a_visitar(int id) const
{
    clientes[id-1].salas_a_visitar();
}

int ConjClientes::leer_lista_compra(int id)
{
    int total = clientes[id-1].leer_lista_compra();
    int x = clientes[id-1].compra_y_no_quiere();
    if (x!= 0) clientes_noquiereycompra.insert(id); 
    return total;
}

void ConjClientes::nuevo_cliente(const Cliente &c)
{
    clientes.push_back(c);
}
