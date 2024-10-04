#include <iostream>
#include <string>
using namespace std;

// Interfaz para los diferentes métodos de notificación
class INotifier
{
public:
    virtual void send(string message) = 0; 
    virtual ~INotifier() = default;
};

// Implementación concreta de notificación por Email
class EmailNotifier : public INotifier
{
public:
    void send(string message) override
    {
        cout << "Enviando Email: " << message << endl;
    }
};

// Implementación concreta de notificación por SMS
class SMSNotifier : public INotifier
{
public:
    void send(string message) override
    {
        cout << "Enviando SMS: " << message << endl;
    }
};

// Clase que utiliza la abstracción para enviar notificaciones
class NotificationService
{
private:
    INotifier &notifier; 

public:
    NotificationService(INotifier &notifier) : notifier(notifier) {}

    void notify(string message)
    {
        notifier.send(message); 
    }
};

int main()
{
    EmailNotifier emailNotifier;
    SMSNotifier smsNotifier;

    NotificationService emailService(emailNotifier);
    NotificationService smsService(smsNotifier);

    emailService.notify("Hola desde Email");
    smsService.notify("Hola desde SMS");

    return 0;
}
