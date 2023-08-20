#include <iostream>

class Cat{
    public:
        Cat(int initialAge);
        ~Cat();
        int GetAge() const {
            return itsAge;
        }
        void SetAge(int age){
            itsAge = age;
        }
        void meow() const {
            std::cout << "Meow \n";
        }
    private:
        int itsAge;

};