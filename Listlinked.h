#include <ostream>
#include "List.H"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first; // Puntero al primer nodo de la lista
    int n; // Número de elementos en la lista

public:
    // Constructor por defecto: inicializa la lista como vacía
    ListLinked() : first(nullptr), n(0) {}

    // Destructor: libera la memoria ocupada por los nodos
    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next; // Situar un puntero auxiliar en el siguiente nodo
            delete first; // Liberar la memoria del nodo actual
            first = aux; // Actualizar first para que apunte al siguiente nodo
        }
    }

    // Sobrecarga del operador [] para acceder a los elementos por índice
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Index out of bounds"); // Verificación de rango
        }
        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->next; // Avanzar hasta el nodo deseado
        }
        return current->data; // Devolver el dato del nodo
    }

    // Sobrecarga del operador << para imprimir la lista
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        out << "[";
        while (current != nullptr) {
            out << current->data; // Imprimir el dato del nodo actual
            if (current->next != nullptr) {
                out << ", "; // Separar elementos con comas
            }
            current = current->next; // Avanzar al siguiente nodo
        }
        out << "]";
        return out;
    }
};
        
