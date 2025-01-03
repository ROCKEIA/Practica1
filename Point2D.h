#ifndef POINT2D_H
#define POINT2D_H

#include <ostream> // Necesario para std::ostream

class Point2D {
public:
    // Atributos públicos
    double x; // Coordenada x
    double y; // Coordenada y

    // Constructor
    Point2D(double x = 0, double y = 0);

    // Métodos
    static double distance(const Point2D &a, const Point2D &b); // Calcula la distancia euclidiana

    // Operadores sobrecargados
    friend bool operator==(const Point2D &a, const Point2D &b); // Sobrecarga del operador ==
    friend bool operator!=(const Point2D &a, const Point2D &b); // Sobrecarga del operador !=
    friend std::ostream& operator<<(std::ostream &out, const Point2D &p); // Sobrecarga del operador <<
};

#endif // POINT2D_H

