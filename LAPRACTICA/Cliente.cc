#include "Cliente.hh"

Cliente::Cliente()
{
    productos_compra_no_quiere = 0;
}


void Cliente::quiere_comprar() const
{
    set<string>::const_iterator it = lista_productos.begin();
    while (it != lista_productos.end())
    {
        if(it!=lista_productos.begin()) cout << " ";
        cout << *it;
        ++it;
    }
    cout << endl;
}

void Cliente::salas_a_visitar() const
{
    set<string>::const_iterator it = salas_recorrido.begin();
    while (it != salas_recorrido.end())
    {
        if(it!=salas_recorrido.begin()) cout << " ";
        cout << *it;
        ++it;
    }

    cout << endl;
}

int Cliente::compra_y_no_quiere() const
{
    return productos_compra_no_quiere;
}

int Cliente::leer_lista_compra()
{
   
    
    
    string prod;
    cin >> prod;
    int cantidad, total = 0;
    
    while (prod!= "#") {
        set<string>::const_iterator it = lista_productos.find(prod);
        bool esta = it != lista_productos.end();
        cin >> cantidad;
        if (not esta)  productos_compra_no_quiere += cantidad;
        total += cantidad;
        cin >> prod;
    }

    return total;
}



bool Cliente::quiere_prod(const string& pr) const{

    auto it = lista_productos.find(pr);
    return it!=lista_productos.end();
}

void Cliente::anadir_sala(const string& sala) {
    salas_recorrido.insert(sala);
}


void Cliente::leer()
{
    string x;
    while(cin >> x and x != "#"){
        lista_productos.insert(x);
    }
}

int Cliente::num_productos() const
{
    return lista_productos.size();
}
