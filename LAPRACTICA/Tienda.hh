/** @file Tienda.hh
    @brief Especificación de la clase Tienda
*/
#ifndef TIENDA_HH
#define TIENDA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include "BinTree.hh"
#endif


#include "ConjClientes.hh"
#include "Cliente.hh"

using namespace std;

/** @class Tienda
    @brief Representa la clase tienda, es decir, la tienda que hemos creado (Megathlon).
*/
class Tienda {

private:
  BinTree<string> salas;

  /** @brief Calcula el recorrido del cliente para comprar sus productos.
      \pre n >= 0; 
      \post Crea el subarbol de las salas a visitar y lo devuelve.
  */                             
  BinTree<string> crear_subarbol(const BinTree<string> &salas, Cliente& c, int &n) const;


  /** @brief Indica todas las instrucciones que debe seguir el cliente para realizar su compra.
      \pre <em>cierto</em>
      \post Escribe las indicaciones que debe seguir el cliente para llegar a todas las salas que necesita visitar.
  */ 
  void instrucciones(const BinTree<string>& subarbol) const;


  public:

  void escribir_subarbol_instrucciones(Cliente &c, int id) const;

  //constructora
  /** @brief es una constructora vacia de la clase Tienda.
  */
  Tienda();

 
 //lectura escritura
  /** @brief Lee la estructura de la tienda.
    \pre <em>cierto</em>
    \post Lee y guarda el arbol de las salas que compondran la tienda.
  */
  void leer_salas();


  /** @brief Escribe la tienda.
    \pre <em>cierto</em>
    \post Escribe el arbol de la tienda.
  */
  void escribir_salas() const;

};

#endif
