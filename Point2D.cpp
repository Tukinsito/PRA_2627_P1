#include <ostream>
#include <cmath>
#include "Point2D.h"

// Constructor
Point2D::Point2D(double x, double y) : x(x), y(y) {}

// Distancia euclidiana entre dos puntos
double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

// Operador de igualdad
bool Point2D::operator==(const Point2D &other) const {
    return x == other.x && y == other.y;
}

// Operador de desigualdad
bool Point2D::operator!=(const Point2D &other) const {
    return !(*this == other);
}

// Sobrecarga del operador << para impresión
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
