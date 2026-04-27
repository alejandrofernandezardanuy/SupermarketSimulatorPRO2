/** @file Caja.hh
    @brief Especificación de la clase Caja
*/
#ifndef CAJA_HH
#define CAJA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
#include <vector>
#include <utility>
#endif

#include "Hora.hh"

using namespace std;

/** @class Caja
    @brief Representa la classe caja, es decir, una caja donde los clientes pasaran para realizar el pago al finalizar su compra y
     paso por la tienda.
*/
class Caja
{

private:
  list<pair<int, Hora>> cola_clientes; // Es la cola de clientes de una caja con su respectivo id y hora de salida.

public:
  // constructoras
  /** @brief Constructora por definicion.
   */
  Caja();


  /** @brief Añade el id del cliente y su hora de salida a la cola.
    \pre  23:59:59 >= hora_salida_cilente >= 00:00:00; 0 < idcl <= numero_clientes;
    \post Añade a la cola de clientes el cliente que le pasemos con su respectiva hora de salida de la caja.
  */
  void anadir_cliente(int idcl, Hora hora_salida_cliente);


  // consultoras
  /** @brief Consulta el tamaño de la cola.
   \pre <em>cierto</em>
   \post Retorna el numero correspondiente al tamaño de la cola.
 */
  int mida_cola() const;


  /** @brief devuelve la hora de salida del ultimo cliente.
    \pre <em>cierto</em>
    \post Esta funcion consulta y devuelve la hora a la que saldra el ultimo cliente de la cola.
  */
  Hora hora_salida_ultimo_cola();


  /** @brief Consulta si la caja esta vacia o no.
    \pre <em>cierto</em>
    \post Retorna true si la cola_de_clientes esta vacia.
  */
  bool esta_vacia() const;


  // modificadoras

  /** @brief  Elimina los clientes con una hora mayor a "h".
    \pre <em>cierto</em>; 23:59:59 >= h >= 00:00:00;
    \post Elimina de la cola de la caja a todos aquellos clientes que han finalizado el pago despues de la hora que indicamos.
  */
  void vaciar_caja(const Hora &h);


  // lectura escritura
  /** @brief  Escribe la cola de clientes de una caja.
    \pre idca >= 1
    \post. Se escribe la lista de los identificadores de clientes en la cola (o siendo atendido) con su respectiva hora de salida.
    */
  void escribir_caja() const;





};

#endif
