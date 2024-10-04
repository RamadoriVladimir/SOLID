#include <iostream>

// Interfaz para Depósito
class DepositUI {
public:
    virtual void RequestDepositAmount() = 0;
};

// Interfaz para Retiro
class WithdrawUI {
public:
    virtual void RequestWithdrawAmount() = 0;
};

// Interfaz para Transferencia
class TransferUI {
public:
    virtual void RequestTransferAmount() = 0;
};

// Clase base para Transacciones
class Transaction {
public:
    virtual void Execute() = 0;
    virtual ~Transaction() = default;
};

// Clase de transacción de Depósito
class DepositTransaction : public Transaction {
public:
    DepositTransaction(DepositUI& ui) : itsDepositUI(ui) {}

    virtual void Execute() override {
        itsDepositUI.RequestDepositAmount();
        std::cout << "Procesando deposito..." << std::endl;
    }

private:
    DepositUI& itsDepositUI;
};

// Clase de transacción de Retiro
class WithdrawTransaction : public Transaction {
public:
    WithdrawTransaction(WithdrawUI& ui) : itsWithdrawUI(ui) {}

    virtual void Execute() override {
        itsWithdrawUI.RequestWithdrawAmount();
        std::cout << "Procesando retiro..." << std::endl;
    }

private:
    WithdrawUI& itsWithdrawUI;
};

// Clase de transacción de Transferencia
class TransferTransaction : public Transaction {
public:
    TransferTransaction(TransferUI& ui) : itsTransferUI(ui) {}

    virtual void Execute() override {
        itsTransferUI.RequestTransferAmount();
        std::cout << "Procesando transferencia..." << std::endl;
    }

private:
    TransferUI& itsTransferUI;
};

// Clase UI que implementa todas las interfaces
class UI : public DepositUI, public WithdrawUI, public TransferUI {
public:
    virtual void RequestDepositAmount() override {
        std::cout << "Ingrese el monto del deposito: ";
        double amount;
        std::cin >> amount;
        std::cout << "Monto ingresado: " << amount << std::endl;
    }

    virtual void RequestWithdrawAmount() override {
        std::cout << "Ingrese el monto del retiro: ";
        double amount;
        std::cin >> amount;
        std::cout << "Monto retirado: " << amount << std::endl;
    }

    virtual void RequestTransferAmount() override {
        std::cout << "Ingrese el monto de la transferencia: ";
        double amount;
        std::cin >> amount;
        std::cout << "Monto transferido: " << amount << std::endl;
    }
};

// Punteros globales para las interfaces segregadas
UI globalUI;
DepositUI& GdepositUI = globalUI;
WithdrawUI& GwithdrawUI = globalUI;
TransferUI& GtransferUI = globalUI;

int main() {
    DepositTransaction dt(GdepositUI);
    dt.Execute();

    WithdrawTransaction wt(GwithdrawUI);
    wt.Execute();

    TransferTransaction tt(GtransferUI);
    tt.Execute();

    return 0;
}
