#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cstring>

// Ejemplo 1: Diseño que no cumple con OCP
class Circle1 {
public:
    void draw() { std::cout << "Dibujando circulo\n"; }
};

class Square1 {
public:
    void draw() { std::cout << "Dibujando cuadrado\n"; }
};

// Esta función viola OCP 
void drawAllShapes1(const std::vector<void*>& shapes) {
    for (auto shape : shapes) {
        if (typeid(shape) == typeid(Circle1*))
            static_cast<Circle1*>(shape)->draw();
        else if (typeid(shape) == typeid(Square1*))
            static_cast<Square1*>(shape)->draw();
    }
}

// Ejemplo 2: Diseño que cumple con OCP
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override { std::cout << "Dibujando circulo\n"; }
};

class Square : public Shape {
public:
    void draw() const override { std::cout << "Dibujando cuadrado\n"; }
};

void drawAllShapes(const std::vector<Shape*>& shapes) {
    for (const auto& shape : shapes) {
        shape->draw();
    }
}

// Ejemplo 3: Añadiendo ordenamiento a las formas
class OrderedShape : public Shape {
public:
    virtual bool precedes(const Shape& other) const = 0;
    bool operator<(const Shape& other) const { return precedes(other); }
};

class OrderedCircle : public OrderedShape {
public:
    void draw() const override { std::cout << "Dibujando circulo ordenado\n"; }
    bool precedes(const Shape& other) const override {
        return typeid(*this).name() < typeid(other).name();
    }
};

class OrderedSquare : public OrderedShape {
public:
    void draw() const override { std::cout << "Dibujando cuadrado ordenado\n"; }
    bool precedes(const Shape& other) const override {
        return typeid(*this).name() < typeid(other).name();
    }
};

void drawAllShapesOrdered(std::vector<OrderedShape*>& shapes) {
    std::sort(shapes.begin(), shapes.end(), 
              [](const OrderedShape* a, const OrderedShape* b) { return a->precedes(*b); });
    for (const auto& shape : shapes) {
        shape->draw();
    }
}

// Ejemplo 4: Implementación basada en tabla para ordenamiento
class TableOrderedShape : public Shape {
private:
    static const char* typeOrderTable[];

public:
    virtual ~TableOrderedShape() = default;
    bool precedes(const Shape& other) const {
        const char* thisType = typeid(*this).name();
        const char* argType = typeid(other).name();
        int thisOrd = -1, argOrd = -1;

        for (int i = 0; typeOrderTable[i] != nullptr; ++i) {
            if (strcmp(typeOrderTable[i], thisType) == 0) thisOrd = i;
            if (strcmp(typeOrderTable[i], argType) == 0) argOrd = i;
            if (thisOrd >= 0 && argOrd >= 0) break;
        }

        return thisOrd < argOrd;
    }
};

const char* TableOrderedShape::typeOrderTable[] = {
    "Circle",
    "Square",
    nullptr
};

class TableOrderedCircle : public TableOrderedShape {
public:
    void draw() const override { std::cout << "Dibujando circulo (ordenado por tabla)\n"; }
};

class TableOrderedSquare : public TableOrderedShape {
public:
    void draw() const override { std::cout << "Dibujando cuadrado (ordenado por tabla)\n"; }
};

int main() {
    std::vector<Shape*> shapes = {new Circle(), new Square()};
    drawAllShapes(shapes);

    std::vector<OrderedShape*> orderedShapes = {new OrderedCircle(), new OrderedSquare()};
    drawAllShapesOrdered(orderedShapes);

    std::vector<TableOrderedShape*> tableOrderedShapes = {new TableOrderedCircle(), new TableOrderedSquare()};
    std::sort(tableOrderedShapes.begin(), tableOrderedShapes.end(),
              [](const TableOrderedShape* a, const TableOrderedShape* b) { return a->precedes(*b); });
    for (const auto& shape : tableOrderedShapes) {
        shape->draw();
    }

    for (auto shape : shapes) delete shape;
    for (auto shape : orderedShapes) delete shape;
    for (auto shape : tableOrderedShapes) delete shape;

    return 0;
}