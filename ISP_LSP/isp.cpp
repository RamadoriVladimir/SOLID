#include <iostream>

// Definición de las interfaces pequeñas y específicas
class IPrinter {
public:
    virtual void print() = 0; 
    virtual ~IPrinter() = default;
};

class IScanner {
public:
    virtual void scan() = 0;
    virtual ~IScanner() = default;
};

class IFax {
public:
    virtual void fax() = 0; 
    virtual ~IFax() = default;
};

// Clase que implementa solo la funcionalidad de impresión
class SimplePrinter : public IPrinter {
public:
    void print() override {
        std::cout << "Printing a document..." << std::endl;
    }
};

// Clase que implementa solo la funcionalidad de escaneo
class SimpleScanner : public IScanner {
public:
    void scan() override {
        std::cout << "Scanning a document..." << std::endl;
    }
};

// Clase que implementa la funcionalidad de fax
class SimpleFax : public IFax {
public:
    void fax() override {
        std::cout << "Sending a fax..." << std::endl;
    }
};

// Clase multifuncional que implementa impresión, escaneo y fax
class MultiFunctionDevice : public IPrinter, public IScanner, public IFax {
public:
    void print() override {
        std::cout << "Printing a document..." << std::endl;
    }

    void scan() override {
        std::cout << "Scanning a document..." << std::endl;
    }

    void fax() override {
        std::cout << "Sending a fax..." << std::endl;
    }
};


int main() {

    IPrinter* printer = new SimplePrinter();
    printer->print(); 

    IScanner* scanner = new SimpleScanner();
    scanner->scan(); 

    IFax* fax = new SimpleFax();
    fax->fax(); 

    MultiFunctionDevice mfd;
    mfd.print();
    mfd.scan();
    mfd.fax();

    delete printer;
    delete scanner;
    delete fax;

    return 0;
}
