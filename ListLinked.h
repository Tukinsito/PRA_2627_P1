#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first; // Puntero al primer nodo
        int n;          // Número de elementos en la lista

    public:
        // Constructor sin argumentos
        ListLinked() : first(nullptr), n(0) {}

        // Destructor para liberar memoria
        ~ListLinked() {
            Node<T>* current = first;
            while (current != nullptr) {
                Node<T>* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }

        // Sobrecarga del operador [] para lectura y escritura
        T& operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }
            Node<T>* current = first;
            for (int i = 0; i < pos; ++i) {
                current = current->next;
            }
            return current->data;
        }

        // Sobrecarga del operador [] constante
        T operator[](int pos) const {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }
            Node<T>* current = first;
            for (int i = 0; i < pos; ++i) {
		    current = current->next;
            }
            return current->data;
        }

        // Sobrecarga global del operador <<
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            Node<T>* current = list.first;
            while (current != nullptr) {
                out << current->data << " ";
                current = current->next;
            }
            return out;
        }
    };

#endif // LIST_LINKED_H
