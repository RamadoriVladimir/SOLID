#include <iostream>

// Ejemplo 1: Violación del SRP
/*
class Rectangle 
{
public:
    void draw() 
    {
        std::cout << "Dibujando rectángulo" << std::endl;
    }
    
    double area() 
    {
        return width * height;
    }

private:
    double width;
    double height;
};
*/

// Ejemplo 1: Aplicando SRP
class GeometricRectangle 
{
public:
    double area() 
    {
        return width * height;
    }

private:
    double width;
    double height;
};

class GraphicalRectangle 
{
public:
    void draw() 
    {
        std::cout << "Dibujando rectangulo" << std::endl;
    }
};