#include <iostream>
#include <cassert>

// Interfaz común para las formas geométricas
class Shape {
public:
    virtual void SetWidth(double w) = 0;
    virtual void SetHeight(double h) = 0;
    virtual double GetWidth() const = 0;
    virtual double GetHeight() const = 0;
    virtual ~Shape() = default;
};

// Implementación de la clase Rectangle
class Rectangle : public Shape {
public:
    void SetWidth(double w) override { itsWidth = w; }
    void SetHeight(double h) override { itsHeight = h; }
    double GetWidth() const override { return itsWidth; }
    double GetHeight() const override { return itsHeight; }

private:
    double itsWidth;
    double itsHeight;
};

// Implementación de la clase Square
class Square : public Shape {
public:
    void SetWidth(double w) override {
        itsSize = w;
    }
    void SetHeight(double h) override {
        itsSize = h;
    }
    double GetWidth() const override { return itsSize; }
    double GetHeight() const override { return itsSize; }

private:
    double itsSize;
};

// Función que utiliza punteros o referencias a la clase base (Shape)
void ResizeShape(Shape& shape) {
    shape.SetWidth(10);
    shape.SetHeight(5);
    std::cout << "Ancho: " << shape.GetWidth() << ", Altura: " << shape.GetHeight() << std::endl;
}

int main() {
    Rectangle rect;
    Square square;

    std::cout << "Redimensionando Rectangle:" << std::endl;
    ResizeShape(rect);

    std::cout << "Redimensionando Square:" << std::endl;
    ResizeShape(square);

    return 0;
}
