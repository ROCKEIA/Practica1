#include <iostream> // Incluye funcionalidades para entrada/salida estándar
#include <stdexcept> // Para manejar excepciones como std::out_of_range
#include "List.H" // Incluye la definición base de la clase List (suponiendo que ya existe)

template <typename T>
class ListArray : public List<T> { // Define una clase plantilla que hereda de List<T>
private:
    T* arr; // Puntero a un array dinámico que almacena los elementos
    int max; // Tamaño máximo actual del array
    int n; // Número de elementos actualmente almacenados en el array
    static const int MINSIZE = 10; // Tamaño mínimo del array (constante estática)

    // Método privado para redimensionar el array dinámico
    void resize(int new_size) {
        if (new_size < MINSIZE) { 
            new_size = MINSIZE; // Asegurarse de que el tamaño nunca sea menor que MINSIZE
        }
        T* new_arr = new T[new_size]; // Crear un nuevo array dinámico con el nuevo tamaño
        for (int i = 0; i < n; i++) { 
            new_arr[i] = arr[i]; // Copiar los elementos del array actual al nuevo array
        }
        delete[] arr; // Liberar la memoria del array anterior
        arr = new_arr; // Actualizar el puntero para que apunte al nuevo array
        max = new_size; // Actualizar el tamaño máximo permitido
    }

public:
    // Constructor por defecto: inicializa el array con el tamaño mínimo
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    // Destructor: libera la memoria dinámica asignada al array
    ~ListArray() {
        delete[] arr; // Liberar la memoria dinámica utilizada por el array
    }

    // Inserta un elemento en la posición especificada
    void insert(int pos, const T& value) {
        if (pos < 0 || pos > n) { 
            throw std::out_of_range("Index out of bounds"); // Lanza una excepción si el índice es inválido
        }
        if (n >= max) { 
            resize(max * 2); // Duplica el tamaño del array si ya está lleno
        }
        for (int i = n; i > pos; i--) { 
            arr[i] = arr[i - 1]; // Desplaza los elementos hacia la derecha para crear espacio
        }
        arr[pos] = value; // Inserta el nuevo valor en la posición especificada
        n++; // Incrementa el número de elementos
    }

    // Agrega un elemento al final del array
    void append(const T& value) {
        if (n >= max) { 
            resize(max * 2); // Duplica el tamaño del array si ya está lleno
        }
        arr[n++] = value; // Inserta el elemento al final y aumenta el contador
    }

    // Agrega un elemento al inicio del array
    void prepend(const T& value) {
        insert(0, value); // Llama a insert() para agregar el elemento en la posición 0
    }

    // Elimina el elemento en la posición especificada y devuelve su valor
    T remove(int pos) {
        if (pos < 0 || pos >= n) { 
            throw std::out_of_range("Index out of bounds"); // Lanza una excepción si el índice es inválido
        }
        T removed_element = arr[pos]; // Guarda el elemento a eliminar
        for (int i = pos; i < n - 1; i++) { 
            arr[i] = arr[i + 1]; // Desplaza los elementos hacia la izquierda
        }
        n--; // Reduce el número de elementos
        if (n < max / 4 && max / 2 >= MINSIZE) { 
            resize(max / 2); // Reduce el tamaño del array si es necesario
        }
        return removed_element; // Devuelve el elemento eliminado
    }

    // Sobrecarga del operador [] para acceder a los elementos por índice
    T operator[](int pos) const {
        if (pos < 0 || pos >= n) { 
            throw std::out_of_range("Index out of bounds"); // Lanza una excepción si el índice es inválido
        }
        return arr[pos]; // Devuelve el elemento en la posición especificada
    }

    // Sobrecarga del operador << para imprimir el array
    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "["; // Abre el corchete
        for (int i = 0; i < list.n; i++) {
            out << list.arr[i]; // Imprime cada elemento
            if (i < list.n - 1) {
                out << ", "; // Agrega una coma entre los elementos
            }
        }
        out << "]"; // Cierra el corchete
        return out; // Devuelve el flujo de salida
    }

    // Devuelve el número actual de elementos en el array
    int size() const {
        return n;
    }
};
