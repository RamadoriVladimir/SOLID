#include <iostream>
#include <string>

// Ejemplo 2: Violación del SRP
/*
class Modem 
{
public:
    virtual void dial(const std::string& pno) = 0;
    virtual void hangup() = 0;
    virtual void send(char c) = 0;
    virtual char recv() = 0;
};
*/

// Ejemplo 2: Aplicando SRP y ante posible cambio

class Connection 
{
public:
    virtual void dial(const std::string& pno) = 0;
    virtual void hangup() = 0;
};

class DataChannel 
{
public:
    virtual void send(char c) = 0;
    virtual char recv() = 0;
};

class ModemImplementation : public Connection, public DataChannel 
{
public:
    void dial(const std::string& pno) override
    {
        std::cout << "Marcando a " << pno << "..." << std::endl;
    }

    void hangup() override 
    {
        std::cout << "Colgando..." << std::endl;
    }

    void send(char c) override 
    {
        std::cout << "Enviando mensaje: " << c << std::endl;
    }

    char recv() override 
    {
        std::cout << "Mensaje recibido." << std::endl;
        return 'X';  
    }
};

int main() 
{
    ModemImplementation modem;
    std::string numero;

    std::cout << "Ingrese el numero a marcar: ";
    std::cin >> numero;
    modem.dial(numero);

    modem.send('A');

    char mensaje = modem.recv();
    std::cout << "Caracter recibido: " << mensaje << std::endl;

    modem.hangup();

    return 0;
}