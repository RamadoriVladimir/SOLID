#include <iostream>
#include <string>
using namespace std;

// Implementación concreta de notificación por Email
class EmailNotifier
{
public:
    void sendEmail(string message)
    {
        cout << "Enviando Email: " << message << endl;
    }
};

// Implementación concreta de notificación por SMS
class SMSNotifier
{
public:
    void sendSMS(string message)
    {
        cout << "Enviando SMS: " << message << endl;
    }
};

// Clase que depende directamente de las implementaciones concretas
class NotificationService
{
private:
    EmailNotifier emailNotifier;
    SMSNotifier smsNotifier; 

public:
    void notifyByEmail(string message)
    {
        emailNotifier.sendEmail(message); 
    }

    void notifyBySMS(string message)
    {
        smsNotifier.sendSMS(message); 
    }
};

int main()
{
    NotificationService notificationService;

    notificationService.notifyByEmail("Hola desde Email");
    notificationService.notifyBySMS("Hola desde SMS");

    return 0;
}
