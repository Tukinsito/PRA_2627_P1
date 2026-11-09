#include "Circle.h"
#include <cmath>

// Constructor por defecto
Circle::Circle() : Shape("red"), center(Point2D(0, 0)), radius(1.0) {}

// Constructor parametrizado
Circle::Circle(std::string color, Point2D center, double radius) 
    : Shape(color), center(center), radius(radius) {}

// Getters y Setters
Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

// Métodos heredados de Shape
double Circle::area() const {
    return M_PI * std::pow(radius, 2);
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY) {
    center = Point2D(center.x + incX, center.y + incY);
}

void Circle::print() const {
    std::cout << *this;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "[Circle: color=" << c.get_color()
        << "; center=" << c.center 
        << "; radius=" << c.radius << "]";
    return out;
}
