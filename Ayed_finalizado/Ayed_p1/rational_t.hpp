// rational_t.hpp
// Autor: Ángel Vladislav Alonso Yemelyantseva
// Fecha: 08 feb 2024
// Email: alu0101489827@ull.edu.es
// Versión: 1.0
// Asignatura: Algoritmos y Estructuras de Datos
// Práctica Nº: 1
// Comentarios: Se indican entre [] las pautas de estilo aplicadas de
// "C++ Programming Style Guidelines"
// https://geosoft.no/development/cppstyle.html

// Pauta de estilo [92]: Comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// Valor de tolerancia o presición.
# define EPSILON 1e-6

using namespace std;

// Dados dos números reales a, b ∈ R, comprueba diferentes operaciones entre ellos
class rational_t
{
  // Pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  // Constructor
  rational_t(const int = 0, const int = 1);

  // Destructor
  ~rational_t() {}
  
  // Pauta de estilo [71]: Indentación a 2 espacios
  // Getters
  int get_num() const;
  int get_den() const;
  
  // Setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const;

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);
  
  void write(ostream& = cout) const;
  void read(istream& = cin);
  
private:
  // Pauta de estilo [11]: Nombre de los atributos seguido de "_"
  // Numerador y denominador pedidos por consola por el usuario
  // Utilizados posteriormente en operaciones
  int num_, den_;
};
