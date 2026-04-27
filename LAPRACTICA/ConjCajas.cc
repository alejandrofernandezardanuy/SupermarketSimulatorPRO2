#include "ConjCajas.hh"

ConjCajas::ConjCajas()
{
}

void ConjCajas::inicializar(int num_cajas)
{   
    vector<Caja> vector(num_cajas);
    cajas = vector;
}

void ConjCajas::escribir_caja(int idca) const
{   
    cajas[idca-1].escribir_caja();
}

void ConjCajas::escribir_cajas() const
{   
    for (int i = 0; i < cajas.size(); ++i) {
        cout << "Caja " << i+1 << ": ";
        cajas[i].escribir_caja();
    }
}


void ConjCajas::vaciar_cajas(const Hora &h)
{
    for (int i = 0; i < cajas.size(); ++i) {
        cajas[i].vaciar_caja(h);
    }
}

int ConjCajas::caja_asignada(int idcl, const Hora &hora, int numero_productos_comprados, Hora &hora_salida_cliente) 
{
    
    Hora ultimo(23,59,59);
    int id_caja_asignada = 0;
    int i = 0;
    bool vacia = false;
    while(i<cajas.size() and not vacia) {
        if(cajas[i].esta_vacia()) {
            vacia = true;
            id_caja_asignada = i+1;
        } 
        else if(cajas[i].hora_salida_ultimo_cola().menor(ultimo)){ 
            ultimo = cajas[i].hora_salida_ultimo_cola();
            id_caja_asignada = i+1;
        } else if (cajas[i].hora_salida_ultimo_cola().igual(ultimo) and cajas[i].mida_cola() < cajas[id_caja_asignada -1].mida_cola()) {
            id_caja_asignada = i +1;
        }
        
        ++i;

    }
  
   
    hora_salida_cliente = hora;
    int h;
    if(not cajas[id_caja_asignada-1].esta_vacia()) h = cajas[id_caja_asignada-1].hora_salida_ultimo_cola().pasar_a_seg() + 4 + numero_productos_comprados + 10;  
    else h = hora_salida_cliente.pasar_a_seg() + 4 + numero_productos_comprados + 10;
    hora_salida_cliente.pasar_a_hms(h);
    cajas[id_caja_asignada-1].anadir_cliente(idcl,hora_salida_cliente);
    return id_caja_asignada;
}
