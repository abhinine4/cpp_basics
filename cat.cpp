#include "cat.hpp"

Cat::Cat(int initialAge){
    itsAge = initialAge;
}

Cat::~Cat(){

}

int main(){
    Cat Frisky(6);
    std::cout << Frisky.GetAge() << std::endl;
    Frisky.meow();
    Frisky.SetAge(7);
    std::cout << Frisky.GetAge() << std::endl;
    return 0;
}