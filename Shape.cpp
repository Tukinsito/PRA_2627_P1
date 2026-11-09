#include "Shape.h"
#include <stdexcept>
#include <string>

// Constructor por defecto
Shape::Shape() : color("red") {}

// Constructor con parámetro (delega la validación en set_color)
Shape::Shape(std::string color) {
    set_color(color);
}

// Devuelve el color actual
std::string Shape::get_color() const {
    return color;
}

// Modifica el color si es válido ("red", "green", "blue")
void Shape::set_color(std::string c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Color invalido. Debe ser 'red', 'green' o 'blue'.");
    }
    color = c;
}
