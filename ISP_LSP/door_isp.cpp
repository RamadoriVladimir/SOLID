#include <iostream>

class TimerClient {
public:
    virtual void TimeOut(int timeOutId) = 0;
    virtual ~TimerClient() = default;
};

class Door {
public:
    virtual void Lock() = 0;
    virtual void Unlock() = 0;
    virtual bool IsDoorOpen() = 0;
    virtual ~Door() = default;
};


class Timer {
public:
    void Register(int timeout, int timeOutId, TimerClient* client) {
        if (client != nullptr) {
            std::cout << "Registrando cliente con ID de timeout: " << timeOutId 
                      << " y timeout: " << timeout << " ms" << std::endl;
            client->TimeOut(timeOutId);
        } else {
            std::cerr << "Error: Cliente no válido." << std::endl;
        }
    }
};

class TimedDoor : public Door, public TimerClient {
public:
    void Lock() override {
        std::cout << "La puerta está bloqueada." << std::endl;
    }

    void Unlock() override {
        std::cout << "La puerta está desbloqueada." << std::endl;
    }

    bool IsDoorOpen() override {
        return true;
    }

    void TimeOut(int timeOutId) override {
        std::cout << "El timeout ha expirado con ID: " << timeOutId << std::endl;
        std::cout << "¡Alarma activada! La puerta ha estado abierta demasiado tiempo." << std::endl;
    }
};

int main() {
    TimedDoor myTimedDoor;
    Timer myTimer; 

    myTimer.Register(5000, 1, &myTimedDoor);  // Simula un timeout de 5000ms con ID 1

    myTimedDoor.Lock();
    myTimedDoor.Unlock();

    if (myTimedDoor.IsDoorOpen()) {
        std::cout << "La puerta esta abierta." << std::endl;
    }

    return 0;
}
