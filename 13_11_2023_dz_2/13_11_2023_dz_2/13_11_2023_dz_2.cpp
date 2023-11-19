#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
    size_t age;

public:
    Animal(const std::string& _name, size_t _age) : name(_name), age(_age) {}

    // Getters
    std::string getName() const { return name; }
    size_t getAge() const { return age; }

    // Setters
    void setName(const std::string& _name) { name = _name; }
    void setAge(size_t _age) { age = _age; }

    // Abstract methods
    virtual void sound() const = 0;
    virtual void type() const = 0;
    virtual void show() const = 0;
};

class Dog : public Animal {
public:
    Dog(const std::string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        std::cout << "Woof" << std::endl;
    }

    void type() const override {
        std::cout << "Dog" << std::endl;
    }

    void show() const override {
        std::cout << "Name: " << name << ", Age: " << age << ", Type: Dog, Sound: Woof" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        std::cout << "Meow" << std::endl;
    }

    void type() const override {
        std::cout << "Cat" << std::endl;
    }

    void show() const override {
        std::cout << "Name: " << name << ", Age: " << age << ", Type: Cat, Sound: Meow" << std::endl;
    }
};

class Parrot : public Animal {
public:
    Parrot(const std::string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        std::cout << "Squawk" << std::endl;
    }

    void type() const override {
        std::cout << "Parrot" << std::endl;
    }

    void show() const override {
        std::cout << "Name: " << name << ", Age: " << age << ", Type: Parrot, Sound: Squawk" << std::endl;
    }
};

class Hamster : public Animal {
public:
    Hamster(const std::string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        std::cout << "Squeak" << std::endl;
    }

    void type() const override {
        std::cout << "Hamster" << std::endl;
    }

    void show() const override {
        std::cout << "Name: " << name << ", Age: " << age << ", Type: Hamster, Sound: Squeak" << std::endl;
    }
};

class HomeZoo {
private:
    Animal** zoo;
    size_t size;

public:
    HomeZoo() : zoo(nullptr), size(0) {}

    ~HomeZoo() {
        // Delete all animals
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
        std::string type, name;
        size_t age;

        std::cout << "Enter animal type (Dog/Cat/Parrot/Hamster): ";
        std::cin >> type;

        std::cout << "Enter name: ";
        std::cin >> name;

        std::cout << "Enter age: ";
        std::cin >> age;

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
            std::cout << "Invalid animal type." << std::endl;
            return;
        }

        // Add an animal to the zoo
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
        // Display information for all animals in the zoo
        for (size_t i = 0; i < size; ++i) {
            zoo[i]->show();
        }
    }

    void sellAnimal() {
        std::string name;
        std::cout << "Enter the name of the animal to sell: ";
        std::cin >> name;

        for (size_t i = 0; i < size; ++i) {
            if (zoo[i]->getName() == name) {
                delete zoo[i];
                for (size_t j = i; j < size - 1; ++j) {
                    zoo[j] = zoo[j + 1];
                }
                --size;
                std::cout << "Animal sold." << std::endl;
                return;
            }
        }

        std::cout << "Animal not found." << std::endl;
    }

    void sellAllAnimals() {
        // Delete all animals
        for (size_t i = 0; i < size; ++i) {
            delete zoo[i];
        }

        // Clear the array
        delete[] zoo;
        zoo = nullptr;
        size = 0;

        std::cout << "All animals sold." << std::endl;
    }
};

int main() {
    HomeZoo zoo;

    char choice;

    do {
        std::cout << "\nChoose an option:\n"
            << "1. Add an animal\n"
            << "2. Sell an animal\n"
            << "3. Show all animals\n"
            << "4. Sell all animals\n"
            << "5. Exit\n"
            << "Enter your choice (1-5): ";
        std::cin >> choice;

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
            std::cout << "Invalid choice. Please enter a number from 1 to 5." << std::endl;
        }

    } while (choice != '5');

    return 0;
}
