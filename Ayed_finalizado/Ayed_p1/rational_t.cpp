// rational_t.cpp
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

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// Pauta de estilo [87]: 3 líneas de separación entre métodos

// Pauta de estilo [83]: Tipo retornado en línea anterior al método
int rational_t::get_num() const
{
  return num_;
}

int rational_t::get_den() const
{
  return den_;
}

void rational_t::set_num(const int n)
{
  num_ = n;
}

void rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}

double rational_t::value() const
{ 
  return double(get_num()) / get_den();
}

// Comparaciones
bool rational_t::is_equal(const rational_t& r, const double precision) const
{
  // Calculamos la diferencia entre los valores absolutos de los numeradores
  // y denominadores y comparamos el resultado con la precisión especificada.
  return (abs(num_ * r.den_ - den_ * r.num_) < precision);
}

bool rational_t::is_greater(const rational_t& r, const double precision) const
{
  // Calculamos la diferencia entre los productos cruzados y comparamos el
  // resultado con la precisión especificada.
  return (num_ * r.den_ - r.num_ * den_ > precision);
}

bool rational_t::is_less(const rational_t& r, const double precision) const
{
  // Calculamos la diferencia entre los productos cruzados y comparamos el
  // resultado con la precisión especificada.
  return (r.num_ * den_ - num_ * r.den_ > precision);
}

// Operaciones
rational_t rational_t::add(const rational_t& r)
{
  // Multiplicamos cruzadamente para obtener un denominador común.
  int new_num = num_ * r.den_ + den_ * r.num_;
  int new_den = den_ * r.den_;
  return rational_t(new_num, new_den);
}

rational_t rational_t::substract(const rational_t& r)
{
  // Multiplicamos cruzadamente para obtener un denominador común.
  int new_num = num_ * r.den_ - den_ * r.num_;
  int new_den = den_ * r.den_;
  return rational_t(new_num, new_den);
}

rational_t rational_t::multiply(const rational_t& r)
{
  // Multiplicamos los numeradores y los denominadores.
  int new_num = num_ * r.num_;
  int new_den = den_ * r.den_;
  return rational_t(new_num, new_den);
}

rational_t rational_t::divide(const rational_t& r)
{
  // Dividimos multiplicando por el inverso de la fracción.
  int new_num = num_ * r.den_;
  int new_den = den_ * r.num_;
  return rational_t(new_num, new_den);
}

// E/S
void rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
