#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    size_t age;

public:
    Animal(const string& _name, size_t _age) : name(_name), age(_age) {}


    string getName() const { return name; }
    size_t getAge() const { return age; }

    void setName(const string& _name) { name = _name; }
    void setAge(size_t _age) { age = _age; }


    virtual void sound() const = 0;
    virtual void type() const = 0;
    virtual void show() const = 0;
};

class Dog : public Animal {
public:
    Dog(const string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        cout << "Woof" << endl;
    }

    void type() const override {
        cout << "Dog" << endl;
    }

    void show() const override {
        cout << "Name: " << name << ", Age: " << age << ", Type: Dog, Sound: Woof" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(const string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        cout << "Meow" << endl;
    }

    void type() const override {
        cout << "Cat" << endl;
    }

    void show() const override {
        cout << "Name: " << name << ", Age: " << age << ", Type: Cat, Sound: Meow" << endl;
    }
};

class Parrot : public Animal {
public:
    Parrot(const string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        cout << "Squawk" << endl;
    }

    void type() const override {
        cout << "Parrot" << endl;
    }

    void show() const override {
        cout << "Name: " << name << ", Age: " << age << ", Type: Parrot, Sound: Squawk" << endl;
    }
};

class Hamster : public Animal {
public:
    Hamster(const string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        cout << "Squeak" << endl;
    }

    void type() const override {
        cout << "Hamster" << endl;
    }

    void show() const override {
        cout << "Name: " << name << ", Age: " << age << ", Type: Hamster, Sound: Squeak" << endl;
    }
};

class HomeZoo {
private:
    Animal** zoo;
    size_t size;

public:
    HomeZoo() : zoo(nullptr), size(0) {}

    ~HomeZoo() {
        for (size_t i = 0; i < size; ++i) {
            delete zoo[i];
        }
        delete[] zoo;
    }

    size_t getSize() const {
        return size;
    }

    Animal* getAnimal(size_t index) const {
        if (index < size) {
            return zoo[index];
        }
        return nullptr;
    }

    void addAnimal() {
        string type, name;
        size_t age;

        cout << "Enter animal type (Dog/Cat/Parrot/Hamster): ";
        cin >> type;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter age: ";
        cin >> age;

        Animal* newAnimal = nullptr;

        if (type == "Dog") {
            newAnimal = new Dog(name, age);
        }
        else if (type == "Cat") {
            newAnimal = new Cat(name, age);
        }
        else if (type == "Parrot") {
            newAnimal = new Parrot(name, age);
        }
        else if (type == "Hamster") {
            newAnimal = new Hamster(name, age);
        }
        else {
            cout << "Invalid animal type." << endl;
            return;
        }

        Animal** temp = new Animal * [size + 1];
        for (size_t i = 0; i < size; ++i) {
            temp[i] = zoo[i];
        }
        temp[size] = newAnimal;
        delete[] zoo;
        zoo = temp;
        ++size;
    }

    void showAllAnimals() const {
        for (size_t i = 0; i < size; ++i) {
            zoo[i]->show();
        }
    }

    void sellAnimal() {
        string name;
        cout << "Enter the name of the animal to sell: ";
        cin >> name;

        for (size_t i = 0; i < size; ++i) {
            if (zoo[i]->getName() == name) {
                delete zoo[i];
                for (size_t j = i; j < size - 1; ++j) {
                    zoo[j] = zoo[j + 1];
                }
                --size;
                cout << "Animal sold." << endl;
                return;
            }
        }

        cout << "Animal not found." << endl;
    }

    void sellAllAnimals() {
        for (size_t i = 0; i < size; ++i) {
            delete zoo[i];
        }

        delete[] zoo;
        zoo = nullptr;
        size = 0;

        cout << "All animals sold." << endl;
    }
};

int main() {
    HomeZoo zoo;

    char choice;

    do {
        cout << "\nChoose an option:\n"
            << "1. Add an animal\n"
            << "2. Sell an animal\n"
            << "3. Show all animals\n"
            << "4. Sell all animals\n"
            << "5. Exit\n"
            << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
        case '1':
            zoo.addAnimal();
            break;
        case '2':
            zoo.sellAnimal();
            break;
        case '3':
            zoo.showAllAnimals();
            break;
        case '4':
            zoo.sellAllAnimals();
            break;
        case '5':
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }

    } while (choice != '5');

    return 0;
}
