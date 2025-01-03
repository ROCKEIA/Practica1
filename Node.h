#include <ostream>

template <typename T>
class Node {
public:
    T data; // Dato almacenado en el nodo
    Node* next; // Puntero al siguiente nodo en la estructura

    // Constructor por defecto
    Node() : data(T()), next(nullptr) {}

    // Constructor parametrizado
    Node(const T& value, Node* nextNode = nullptr) : data(value), next(nextNode) {}

    // Destructor
    ~Node() {}

    // Sobrecarga del operador << para imprimir el nodo
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;
        return out;
    }
};
