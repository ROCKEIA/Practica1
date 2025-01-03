#include<cmath>
#include "Point2D.h"

// El metodo constructor que tomara por defecto los ejes de las incognitas por el valor 0 en los dos
	  Point2D::Point2D(double x, double y) : x(x), y(y) {}
// El metodo que nos calcula la distancia que hay entre dos puntos
  static double distance(const Point2D &a, const Point2D &b){
	  
  return std::sqrt(std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2)));
  }
//El metodo que nos comprueba la igualdad de los puntos
  bool operator==(const Point2D &a, const Point2D &b){
      return a.x == b.x &&
             a.y == b.y
	    ; }
// El metodo que mos comprueba si los dos puntos son diferentes
  bool operator!=(const Point2D &a, const Point2D &b){
      return !(a==b);
  }
// El metodo que nos imprime el mensaje
  std::ostream& operator<<(std::ostream &out, const Point2D &p){
  out << "(" << p.x << "," << p.y << ")";
  return out ;
  
 }
    


