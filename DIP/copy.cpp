/*Este ejemplo representa el primer enfoque donde el módulo Copy depende directamente de los módulos de bajo nivel ReadKeyboard y WritePrinter.

#include <iostream>

// Funciones de bajo nivel
char ReadKeyboard() {
    char c;
    cin >> c;
    return c;
}

void WritePrinter(char c) {
    cout << "Imprimiendo: " << c << endl;
}

// Función Copy (depende de funciones de bajo nivel)
void Copy() {
    while (true) {
        char c = ReadKeyboard(); 
        if (c == 'q') break;  
        WritePrinter(c);   
    }
}

int main() {
    Copy();
    return 0;
}
*/

// Este ejemplo, representa el uso de DIP. Se utilizan clases abstractas para definir las interfaces Reader y Writer, haciendo que el código sea más flexible y reutilizable.
#include <iostream>
using namespace std;

// Interfaz Reader
class Reader
{
public:
    virtual char Read() = 0;
};

// interfaz Writer
class Writer
{
public:
    virtual void Write(char c) = 0; 
};

// Clase Copy (depende de abstracciones)
class Copy
{
public:
    void CopyFunction(Reader &reader, Writer &writer)
    {
        while (true)
        {
            char c = reader.Read(); 
            if (c == 'q')
                break;       
            writer.Write(c); 
        }
    }
};

// Implementación concreta de Reader (Lee del teclado)
class KeyboardReader : public Reader
{
public:
    char Read() override
    {
        char c;
        cin >> c;
        return c;
    }
};

// Implementación concreta de Writer (Escribe en la impresora)
class PrinterWriter : public Writer
{
public:
    void Write(char c) override
    {
        cout << "Imprimiendo: " << c << endl;
    }
};

int main()
{
    KeyboardReader reader;
    PrinterWriter writer;  
    Copy copy;

    copy.CopyFunction(reader, writer); 

    return 0;
}
