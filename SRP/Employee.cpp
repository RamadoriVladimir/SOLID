#include <iostream>

// Ejemplo 3: Violación del SRP
class Employee 
{
public:
    void calculatePay() 
    {
        std::cout << "Calculando el pago del empleado." << std::endl;
    }
    
    void store() 
    {
        std::cout << "Guardando los datos del empleado." << std::endl;
    }
};

// Ejemplo 3: Aplicando SRP
class EmployeeBusinessLogic 
{
public:
    void calculatePay() 
    {
        std::cout << "Calculando el pago del empleado." << std::endl;
    }
};

class EmployeePersistence {
public:
    void store(const EmployeeBusinessLogic& employee) 
    {
        std::cout << "Guardando los datos del empleado." << std::endl;
    }
};

int main() {
    EmployeeBusinessLogic employeeLogic;
    EmployeePersistence employeePersistence;
    
    employeeLogic.calculatePay();
    employeePersistence.store(employeeLogic);
    
    return 0;
}