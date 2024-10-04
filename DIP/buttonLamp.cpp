/*Este ejemplo muestra una implementación directa donde un objeto Button controla un objeto Lamp.(Sin aplicar DIP)
#include <iostream>

// Clase Lamp (Lámpara)
class Lamp {
public:
    void TurnOn() {
        cout << "Lámpara encendida." << endl;
    }
    void TurnOff() {
        cout << "Lámpara apagada." << endl;
    }
};

// Clase Button (Botón)
class Button {
    Lamp& lamp;  
public:
    Button(Lamp& l) : lamp(l) {}

    void PressButton(bool isOn) {
        if (!isOn) {
            lamp.TurnOn(); 
        } else {
            lamp.TurnOff(); 
        }
    }
};

int main() {
    Lamp lamp; 
    Button button(lamp);  

    button.PressButton(true);   // Encender lámpara
    button.PressButton(false);  // Apagar lámpara

    return 0;
}
*/

// Aquí se aplica el DIP usando una clase abstracta para aislar la dependencia entre Button y Lamp.
#include <iostream>
using namespace std;

class ButtonClient
{
public:
    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
};

class Lamp : public ButtonClient
{
public:
    void TurnOn() override
    {
        cout << "Lámpara encendida." << endl;
    }
    void TurnOff() override
    {
        cout << "Lámpara apagada." << endl;
    }
};

class Button
{
private:
    ButtonClient &client; 
    virtual bool GetButtonState() = 0;

public:
    Button(ButtonClient &c) : client(c) {}

    void DetectState()
    {
        bool isOn = GetButtonState();
        if (!isOn)
        {
            client.TurnOn(); 
        }
        else
        {
            client.TurnOff(); 
        }
    }
};

// clase concreta que implementa el metodo GetButtonState de la clase Button.
class ButtonImplementation : public Button
{
public:
    ButtonImplementation(ButtonClient &c) : Button(c) {}
    bool GetButtonState() override
    {
        return true;
    }
};

int main()
{
    Lamp lamp;
    ButtonImplementation button(lamp); 

    button.DetectState(); 
    return 0;
}
