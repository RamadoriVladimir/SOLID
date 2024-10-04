#include <iostream>
using namespace std;

// Clase de terceros que no puede ser modificada
class Lamp
{
public:
    void switchOn()
    {
        cout << "Lámpara encendida." << endl;
    }
    void switchOff()
    {
        cout << "Lámpara apagada." << endl;
    }
};

// Interfaz que el cliente espera
class ButtonClient
{
public:
    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
};

// Adapter que adapta Lamp a ButtonClient
class LampAdapter : public ButtonClient
{
private:
    Lamp &lamp; 

public:
    LampAdapter(Lamp &l) : lamp(l) {}

    void TurnOn() override
    {
        lamp.switchOn();
    }

    void TurnOff() override
    {
        lamp.switchOff();
    }
};

// Clase Button
class Button
{
private:
    ButtonClient &client; // Dependencia de la abstracción

public:
    Button(ButtonClient &c) : client(c) {}

    void PressButton(bool isOn)
    {
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

int main()
{
    Lamp lamp; 
    LampAdapter adapter(lamp); 

    Button button(adapter); 

    button.PressButton(true); 
    button.PressButton(false); 

    return 0;
}
