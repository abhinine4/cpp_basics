#include <iostream>

class Cat{
    public:
        Cat(int initialAge);
        ~Cat();
        int GetAge() const;
        void SetAge(int age);
        void meow();
    private:
        int itsAge;
};

// we can define functions outside class like below 
// constructor
Cat::Cat(int initialAge){
    itsAge = initialAge;
}

// destructor
Cat::~Cat(){

}

// always use const with get()
int Cat::GetAge() const{
    return itsAge;
}

void Cat::SetAge(int age){
    itsAge = age;
}

void Cat::meow(){
    std::cout<< "Meow \n";
}

int main(){
    Cat Frisky(5);
    std::cout << Frisky.GetAge() << std::endl;
    Frisky.meow();
    Frisky.SetAge(7);
    std::cout << Frisky.GetAge() << std::endl;
    return 0;
}
