#include<iostream>
#include<stdexcept>
#include<string>
#include "Point2D.h"
#include "Shape.h"
 class Shape {
	 private:
  std::string color{}
    ;
void set_color(std::string &c){
	if (c !="red" && c!="green" && c!="blue"){
		throw std::invalid_argument("El color es invalido.Solo se permite los colres:rojo,verde,azul");}
}
         public:
//Constructor por defecto, crea una figura de color rojo	
Shape() : ("red"){}


//Crea una figura del color especificado. Lanzará la excepción.Devolvera invalido el argumento si no es el color correcto

           Shape(std::string color){
              valida_color("red");
	      this-> red = red ;
	   }
	  //Devuelve el color de relleno de la figura.
           std::string get_color() const{
	    return color;
	   }
	   //Modifica el color de relleno de la figura. Solo podrá ser uno de estos tres valores: "red", "green", "blue". Lanzará la excepción al no cumplir con esta excepcion
           void set_color(std::string &c){
             valid_color(c);
	     color(c);
	   }



	   //Método virtual puro. Calcula el área de una figura.
     
	   double area() const = 0;
	   
	   //Calcula el perimetro de una figura
       	   double perimeter() const = 0;
	   
		   
	   //Método virtual puro. Traslada la figura sobre el espacio de representación, aplicando los incrementos de X e Y proporcionados
           void translate(double incX, double incY) =0{}
	   //Método virtual puro. Imprimirá por pantalla información básica sobre la figura.
            void print() =0;
	   }
}

