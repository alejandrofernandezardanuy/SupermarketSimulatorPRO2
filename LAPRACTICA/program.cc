
/**
 * @mainpage 
 * Este es mi proyecto sobre la reorganizacion de Megathlon, en el cual podemos gestionar las salas por las que pasan los clientes 
 * para realizar su compra y asi hacerlos pasar por otras salas i maximizar los beneficios de la tienda en cuestion.
 * Con el conjunto de datos que se recopilaran podremos tambien gestionar tiempos de pago en las diferentes cajas, y poder minimizar
 * los tiempos de espera de los clientes. Gracias a este programa la tienda Megathlon podra mejorar en diferentes aspectos y realizar un 
 * servicio mas satisfactorio para los clientes, podiendo asi, seguir creciendo en el mercado.
 */


/** @file program.cc
 * 
    @brief Programa principal del proyecto.
*/




#include "Cliente.hh"
#include "ConjClientes.hh"
#include "ConjCajas.hh"
#include "Tienda.hh"
#ifndef NO_DIAGRAM
#include<iostream>
#endif
using namespace std;






int main() {
    Tienda t;
    ConjClientes ccl;
    ConjCajas cca;
    t.leer_salas();
    t.escribir_salas();
    int num_cajas;
    cin >> num_cajas;
    cca.inicializar(num_cajas);
    cout << "Hay " << num_cajas << " cajas" << endl;
    cout << endl;
    string op;
    int id = 1;
    while(cin >> op and op != "fin") {
        if (op == "nuevo_cliente") {
            cout << "#" << op << endl;
            Cliente c;
            c.leer();

            t.escribir_subarbol_instrucciones(c,id);
            ccl.nuevo_cliente(c);
            
            id++;
        } else if (op == "quiere_comprar") {
            int idc;
            cin >> idc;
            cout << "#" << op << " " << idc << endl;
            ccl.quiere_comprar(idc);
        } else if (op == "salas_a_visitar") {
            int idcl;
            cin >> idcl;
            cout << "#" << op << " " << idcl << endl;
            ccl.salas_a_visitar(idcl);
        
        } else if ( op == "escribir_caja") {
            int idca;
            cin >> idca;
            Hora h;
            h.leer_hora();
            cout << "#" << op << " " << idca << " ";
            h.escribir_hora();
            cout << endl;
            cca.vaciar_cajas(h);
            cca.escribir_caja(idca);
        } else if (op == "escribir_cajas") {
            Hora h;
            h.leer_hora();
            cout << "#" << op << " ";
            h.escribir_hora();
            cout << endl;
            cca.vaciar_cajas(h);
            cca.escribir_cajas();
        } else if (op == "pago_cliente") {//1 11:05:05 alimentacion 5 zapatos 1 fitnes 2 #
            int idcl;
            cin >> idcl;
            Hora h, hora_salida_cliente;
            h.leer_hora();
            cout << "#" << op <<  " " << idcl << " ";
            h.escribir_hora();
            cout << endl; 
            cca.vaciar_cajas(h);
            int num_productos_comprados = ccl.leer_lista_compra(idcl);//devuelve el numero de items, actualiza los productos que compra y no quiere(comparar)
            int idca = cca.caja_asignada(idcl,h,num_productos_comprados, hora_salida_cliente); //añade a la cola de la caja asignada el cliente, calcula la hora salida
            cout << "Cliente " << idcl << " compra " << num_productos_comprados << " items" << endl;
            cout << "Cliente " << idcl << " va a caja " << idca << " y sale a las ";
            hora_salida_cliente.escribir_hora();
            cout << endl;
        } else if (op == "compra_y_no_quiere") {
            int idc;
            cin >> idc;
            cout << "#" << op << " " <<  idc << endl;
            cout << ccl.compra_y_no_quiere(idc) << endl;
        } else if (op == "compran_y_no_quieren") {
             cout << "#" << op << endl;
            ccl.compran_y_no_quieren();
        } 
        cout << endl;
    }
    cout << "#" << op << endl;
}