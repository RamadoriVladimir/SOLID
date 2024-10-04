#include <iostream>
#include <vector>

//sin OCP

/*
class Product {
public:
    Product(const std::string& name, double price) : name(name), price(price) {}

    double getPrice() const {
        return price;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    double price;
};

class Invoice {
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    double calculateTotal() {
        double total = 0.0;
        for (const auto& product : products) {
            total += product.getPrice();
        }
        total += calculateTax(total); // Impuesto fijo
        return total;
    }

private:
    std::vector<Product> products;

    double calculateTax(double amount) {
        return amount * 0.1; // Impuesto fijo del 10%
    }
};

int main() {
    Invoice invoice;
    invoice.addProduct(Product("Laptop", 1000.0));
    invoice.addProduct(Product("Mouse", 50.0));

    std::cout << "Total: " << invoice.calculateTotal() << std::endl;
    return 0;
}
*/

//con OCP

class TaxStrategy {
public:
    virtual double calculateTax(double amount) const = 0;
};

// Estrategia de impuesto fijo
class FixedTax : public TaxStrategy {
public:
    double calculateTax(double amount) const override {
        return amount * 0.1; 
    }
};

// Estrategia de impuesto variable
class VariableTax : public TaxStrategy {
public:
    double calculateTax(double amount) const override {
        return amount * (amount > 500 ? 0.15 : 0.05); 
    }
};

class Product {
public:
    Product(const std::string& name, double price) : name(name), price(price) {}

    double getPrice() const {
        return price;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    double price;
};

class Invoice {
public:
    Invoice(const TaxStrategy& taxStrategy) : taxStrategy(taxStrategy) {}

    void addProduct(const Product& product) {
        products.push_back(product);
    }

    double calculateTotal() {
        double total = 0.0;
        for (const auto& product : products) {
            total += product.getPrice();
        }
        total += taxStrategy.calculateTax(total); 
        return total;
    }

private:
    std::vector<Product> products;
    const TaxStrategy& taxStrategy; 
};

int main() {
    FixedTax fixedTax;
    VariableTax variableTax;

    Invoice invoice1(fixedTax);
    invoice1.addProduct(Product("Laptop", 1000.0));
    invoice1.addProduct(Product("Mouse", 50.0));
    std::cout << "Importe total con impuesto fijo: " << invoice1.calculateTotal() << std::endl;

    Invoice invoice2(variableTax);
    invoice2.addProduct(Product("Laptop High-End", 2000.0));
    invoice2.addProduct(Product("Mouse Basico", 30.0));
    std::cout << "Importe total con impuesto variable: " << invoice2.calculateTotal() << std::endl;

    return 0;
}
