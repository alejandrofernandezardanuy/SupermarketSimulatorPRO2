/** @file Cliente.hh
    @brief Especificación de la clase Cliente
*/
#ifndef CLIENTE_HH
#define CLIENTE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
#endif

using namespace std;

/** @class Cliente
    @brief Representa la clase cliente, es decir, tiene todos los atributos de un cliente que ha entrado a comprar a la tienda.
*/
class Cliente
{

private:
  set<string> lista_productos;    // La lista de productos que quiere comprar.
  set<string> salas_recorrido;    // Las salas por las que tiene que pasar.
  int productos_compra_no_quiere; // El numero de productos que compra y no quiere.

public:
  

// constructoras
  /** @brief Constructora base clase cliente.
   */
  Cliente();


  /** @brief Añade una sala a la lista de salas que tiene que visitar el cliente.
    \pre <em>cierto</em>
    \post Añade una sala al set de la lista de salas que tiene que visitar el cliente.
  */
  void anadir_sala(const string &sala);


// consultoras
  /** @brief Devuelve el numero de productos.
    \pre <em>cierto</em>
    \post Devuelve el numero de productos, es decir, el tamaño del set lista_productos.
  */
  int num_productos() const;


  /** @brief Consulta si el cliente quiere dicho producto.
    \pre <em>cierto</em>
    \post Devuelve true si el producto esta en la lista de productos inicial.
  */
  bool quiere_prod(const string &pr) const;


// modificadoras
// lectura escritura
  /** @brief  Devuelve el numero productos compra_y_no_quiere.
        \pre <em>cierto</em>
        \post  Devolvera el numero de productos que el cliente ha comprado cuando
        no tenia pensado hacerlo en un principio.
      */
  int compra_y_no_quiere() const;


  /** @brief Escribe las salas que el cliente tiene que visitar.
    \pre <em>cierto</em>
    \post La funcion salas_a_visitar escribe las salas por las que el cliente tiene que pasar para poder comprar todos los articulos deseados.
  */
  void salas_a_visitar() const;


  /** @brief  Devuelve el numero de productos comprados, guarda los productos que compra y no quiere.
    \pre <em>cierto</em>
    \post Calcula el numero de productos que el cliente ha comprado,
    tambien anota la cantidad de aquellos productos que el cliente no queria comprar en un principio.
  */
  int leer_lista_compra();


  /** @brief Lee los productos que quiere comprar.
    \pre <em>cierto</em>
    \post Lee los productos que el cliente quiere comprar y los anota en lista_productos.
  */
  void leer();


  /** @brief Escribe los productos que quiere comprar
    \pre <em>cierto</em>
    \post  Esta funcion escribe la lista de productos que el cliente desea comprar, previamente anotados.
  */
  void quiere_comprar() const;

};

#endif
