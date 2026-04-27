/** @file ConjCajas.hh
    @brief Especificación de la clase ConjCajas
*/
#ifndef CONJ_CAJAS_HH
#define CONJ_CAJAS_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
#include <vector>
#endif

#include "Hora.hh"
#include "Caja.hh"

using namespace std;

/** @class ConjCajas
    @brief Es el conjunto de todas las cajas.
*/
class ConjCajas
{

private:
  vector<Caja> cajas; // El vector con todas las cajas.
public:



//constructora

  /** @brief Constructora por defecto.
   */
  ConjCajas();


  /** @brief Asigna los clientes a una caja vacia o con menos cola, ademas calcula i guarda la hora a la que el cliente acabara el pago, es decir
   * que dejara la caja. Por ultimo añade este cliente a la cola con su respectiva hora de salida.
    \pre <em>cierto</em>; idcl > 0; 23:59:59 >= hora >= 00:00:00; numero_productos_comprados >= 0; 23:59:59 >= hora_salida_cliente >= 00:00:00.
    \post Asigna el cliente a una caja, calcula la hora de salida del cliente y lo añade a la cola de dicha caja.
  */
  int caja_asignada(int idcl, const Hora &hora, int numero_productos_comprados, Hora &hora_salida_cliente);


  /** @brief Inicializa las cajas.
    \pre num_cajas > 0;
    \post Inicializa todas las cajas estando vacias.
  */
  void inicializar(int num_cajas);


  //modificadoras

  /** @brief Elimina todos aquellos clientes que han realizado el pago.
    \pre <em>cierto</em>
    \post Elimina a todos los clientes de la cola con una hora superior a h.
  */
  void vaciar_cajas(const Hora &h);


  //lectura escritura

  /** @brief Escribira la cola de clientes de la caja "idca".
    \pre n_cajas > idca > 0.
    \post Escribe con su correspondiente identificador la caja indicada, tambien
    escribira la cola de clientes de esta con su correspondiente hora de salida
  */
  void escribir_caja(int idca) const;


  /** @brief Escribe los clientes que hay en la cola de las cajas.
    \pre <em>cierto</em>.
    \post Escribe las cajas con sus correspondientes identificadores, 
    y la cola de clientes que hay en cada una de ellas con sus correspondientes horas de salida.
  */
  void escribir_cajas() const;


};

#endif
