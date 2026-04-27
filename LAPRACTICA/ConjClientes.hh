/** @file ConjClientes.hh
    @brief Especificación de la clase ConjClientes
*/
#ifndef CONJ_CLIENTES_HH
#define CONJ_CLIENTES_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <set>
#include <map>
#endif

#include "Cliente.hh"

using namespace std;

/** @class ConjClientes
    @brief Es el conjunto de todos los clientes de la tienda.
*/
class ConjClientes
{

private:
  vector<Cliente> clientes;          // conjunto actual de clientes con s identificador
  set<int> clientes_noquiereycompra; // id de clientes pasados que han comprado articulos no queridos previamente.

public:
  // constructora
  /** @brief Constructora por defecto.
   */
  ConjClientes();

  /** @brief Devuelve los productos que compra y no quiere el cliente.
      \pre numero_clientes > id >= 0
      \post Devuelve los productos que compra y no quiere el cliente indicado.
    */
  int compra_y_no_quiere(int id);


  /** @brief Introduce el cliente en la lista de clientes
    \pre <em>cierto</em>;
    \post Introduce el nuevo cliente en el conjunto de clientes.
  */
  void nuevo_cliente(const Cliente &c);

  /** @brief Devuelve los productos que compran y no quieren los clientes.
      \pre <em>cierto</em>.
      \post Devuelve los productos que compran y no quieren todos los clientes.
    */
  void compran_y_no_quieren() const;


//lectura escritura
  /** @brief Devuelve la lista de productos que quiere comprar.
    \pre 0 < id < num_clientes.
    \post Escribe la lista de productos que  quiere comprar el cliente "id".
  */
  void quiere_comprar(int id) const;


  /** @brief Escribe las salas que va a visitar el cliente.
    \pre 0 < id < num_clientes.
    \post Escribe las salas que va a visitar el cliente "id".
  */
  void salas_a_visitar(int id) const;

  /** @brief Lee la lista de productos que ha comprado el cliente, y devuelve los productos.
    \pre <em>cierto</em>
    \post Lee la lista de productos que ha comprado el cliente id, y devuelve la suma de productos.
  */
  int leer_lista_compra(int id);

};

#endif
