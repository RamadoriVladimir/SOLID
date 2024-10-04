#include <iostream>
#include <vector>
#include <memory>

class PersistentObject {
public:
    virtual void Save() const = 0;
    virtual ~PersistentObject() = default;
};

// Objeto de prueba 
class MyPersistentObject : public PersistentObject {
public:
    MyPersistentObject(int value) : value(value) {}

    void Save() const override {
        std::cout << "Guardando objeto persistente con valor: " << value << std::endl;
    }

    int GetValue() const {
        return value;
    }

private:
    int value;
};

// Interfaz común para operaciones de lectura.
template <class T>
class ReadOnlySet {
public:
    virtual bool IsMember(const T&) const = 0;
    virtual ~ReadOnlySet() = default;
};

// Interfaz específica para conjuntos con capacidad de modificar.
template <class T>
class Set : public ReadOnlySet<T> {
public:
    virtual void Add(const T&) = 0;
    virtual void Delete(const T&) = 0;
};

// Implementación de un conjunto básico.
template <class T>
class BasicSet : public Set<T> {
public:
    void Add(const T& element) override {
        elements.push_back(element);
    }

    void Delete(const T& element) override {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    bool IsMember(const T& element) const override {
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

private:
    std::vector<T> elements;
};

// Implementación de un PersistentSet.
template <class T>
class PersistentSet : public ReadOnlySet<T> {
public:
    void Add(const T& element) {
        static_assert(std::is_base_of<PersistentObject, T>::value,
                      "T debe ser derivado de PersistentObject");
        elements.push_back(element);
    }

    bool IsMember(const T& element) const override {
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

    void SaveAll() const {
        for (const auto& element : elements) {
            element.Save();
        }
    }

private:
    std::vector<T> elements;
};

template <class T>
void PrintSet(const ReadOnlySet<T>& s, const std::vector<T>& testElements) {
    for (const auto& elem : testElements) {
        std::cout << "Elemento " << elem.GetValue() << (s.IsMember(elem) ? "" : "no") << "esta en el set." << std::endl;
    }
}

int main() {
    MyPersistentObject obj1(1);
    MyPersistentObject obj2(2);
    MyPersistentObject obj3(3);

    BasicSet<MyPersistentObject> basicSet;
    basicSet.Add(obj1);
    basicSet.Add(obj2);

    std::vector<MyPersistentObject> testObjects = {obj1, obj2, obj3};
    std::cout << "Probando BasicSet:" << std::endl;
    PrintSet(basicSet, testObjects);


    PersistentSet<MyPersistentObject> persistentSet;
    persistentSet.Add(obj1);
    persistentSet.Add(obj3);

    std::cout << "\nProbando PersistentSet:" << std::endl;
    PrintSet(persistentSet, testObjects);

    std::cout << "\nGuardando objetos de PersistentSet:" << std::endl;
    persistentSet.SaveAll();

    return 0;
}
