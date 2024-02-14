// main_rational_t.cpp
// Autor: Ángel Vladislav Alonso Yemelyantseva
// Fecha: 08 feb 2024
// Email: alu0101489827@ull.edu.es
// Versión: 1.0
// Asignatura: Algoritmos y Estructuras de Datos
// Práctica Nº: 1
// Comentarios: Se indican entre [] las pautas de estilo aplicadas de
// "C++ Programming Style Guidelines"
// https://geosoft.no/development/cppstyle.html
// Compilación: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

// Pauta de estilo [92]: Comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>

// Pauta de estilo [41]: Ficheros de cabecera agrupados y separados
#include "rational_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3), c;

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  // FASE II
  rational_t x(1, 3), y(2, 3);
  x.write();
  y.write();
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;
  cout << "x > y? " << (x.is_greater(y) ? "true" : "false") << endl;
  cout << "x < y? " << (x.is_less(y) ? "true" : "false") << endl;

  // FASE III
  cout << "a + b: ";
  a.add(b).write();
  
  cout << "b - a: ";
  b.substract(a).write();

  cout << "a * b: ";
  a.multiply(b).write();
  
  cout << "a / b: ";
  a.divide(b).write();
  
  return 0;
}
