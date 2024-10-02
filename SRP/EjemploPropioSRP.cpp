#include <iostream>
#include <string>

//sin SRP

/*
class User {
public:
    User(const std::string& name) : name(name) {}

    void saveToDatabase() {
        std::cout << "Guardando usuario: " << name << " en base de datos." << std::endl;
    }

    void sendEmail() {
        std::cout << "Enviando email a: " << name << std::endl;
    }

private:
    std::string name;
};

int main() {
    User user("Lucas");
    user.saveToDatabase();
    user.sendEmail();
    return 0;
}
*/

//con SRP

class User {
public:
    User(const std::string& name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
};

class UserRepository {
public:
    void save(const User& user) {
        std::cout << "Guardando usuario: " << user.getName() << " en base de datos." << std::endl;
    }
};

class EmailService {
public:
    void sendEmail(const User& user) {
        std::cout << "Enviando email a: " << user.getName() << std::endl;
    }
};

int main() {
    User user("Lucas");
    UserRepository repository;
    EmailService emailService;

    repository.save(user);
    emailService.sendEmail(user);
    return 0;
}
