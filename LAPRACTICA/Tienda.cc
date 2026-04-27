#include "Tienda.hh"

Tienda::Tienda()
{
}

void Tienda::leer_salas()
{
    salas.setInputOutputFormat(BinTree<string>::VISUALFORMAT);
    cin >> salas;
}


void Tienda::escribir_salas() const
{
    cout << "Organizacion de las salas:" << endl;
    cout << salas << endl;
}

BinTree<string> Tienda::crear_subarbol(const BinTree<string> &salas, Cliente& c, int &n) const
{
    BinTree<string> subarbol;
    if (n == 0 or salas.empty()) return subarbol;
    else
    {
        bool esta = c.quiere_prod(salas.value());
        if(esta) --n;
        BinTree<string> e = crear_subarbol(salas.left(),c,n);
        BinTree<string> d = crear_subarbol(salas.right(),c,n);
        if(esta or not e.empty() or not d.empty()) {
            subarbol = BinTree<string>(salas.value(), e, d);
            c.anadir_sala(salas.value());
        }
        

        return subarbol;
    }

    

    
}

void Tienda::instrucciones(const BinTree<string>& t) const
{
        cout << t.value() << endl;
        if (not t.left().empty()) {
            cout << "left" << endl;
            instrucciones (t.left());
            cout << "back" << endl;
        }
        if (not t.right().empty()) {
            cout << "right" << endl;
            instrucciones (t.right());
            cout << "back" << endl;
        }
        
}


void Tienda::escribir_subarbol_instrucciones(Cliente& c, int id) const{
    int n = c.num_productos();

    BinTree<string> s = crear_subarbol(salas,c,n);
    cout << "Subarbol del cliente " << id << ":" << endl;
    s.setInputOutputFormat(BinTree<string>::VISUALFORMAT);
    cout << s << endl;
    
    cout << "Recorrido por la tienda del cliente " << id << ":"<< endl;
    instrucciones(s);
}
